#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int testCasesPassed = 0;
int testCasesFailed = 0;



 int newAssert(int condition, int lineNumber){
    if(condition == 0){
        // printf("Fail at line %d\n\n", lineNumber);
        testCasesFailed++;
        return -1;
    }
    else{
        testCasesPassed++;
    }
    return 0;
 }


int checkTribute(struct gameState *post) {
    struct gameState pre, orig;
    memcpy (&pre, post, sizeof(struct gameState));
    memcpy (&orig, post, sizeof(struct gameState));


    int r,i;
    int p = pre.whoseTurn;
    int otherPlayer = pre.whoseTurn - 1;
    if(otherPlayer == -1){
        otherPlayer=1;
    }


    int tributeRevealedCards[2] = {-1, -1};
    if(pre.deckCount[otherPlayer] == 1){
        tributeRevealedCards[0] = pre.deck[otherPlayer][0];
        if(pre.discardCount[otherPlayer] == 1){
            tributeRevealedCards[1] = pre.deck[otherPlayer][0];
        }
    }
    else if(pre.deckCount[otherPlayer] == 0){
        if(pre.discardCount[otherPlayer] == 1){
            tributeRevealedCards[0] = pre.deck[otherPlayer][0];
        }
        else if(pre.discardCount[otherPlayer] == 2){
            tributeRevealedCards[0] = pre.deck[otherPlayer][0];
            tributeRevealedCards[1] = pre.deck[otherPlayer][1];
        }
    }
    else{
        tributeRevealedCards[0] = pre.deck[otherPlayer][pre.deckCount[otherPlayer] - 1];
        tributeRevealedCards[1] = pre.deck[otherPlayer][pre.deckCount[otherPlayer] - 2];
    }

    //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
    //    p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);

    r = cardEffectTribute(post);

    //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
    //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);

    for (i = 0; i < 2; i ++) {
        if(tributeRevealedCards[i] != -1){
            pre.handCount[otherPlayer]--;
            pre.discard[otherPlayer][pre.discardCount[otherPlayer]] = tributeRevealedCards[i];
            pre.discardCount[otherPlayer]++;
            if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold) {
                pre.coins += 2;
            }
            else if (tributeRevealedCards[i] == great_hall || tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens ) {
                pre.hand[p][pre.handCount[p]] = pre.deck[p][pre.deckCount[p] - 1];
                pre.deck[p][pre.deckCount[p] - 1] = -1;
                pre.deckCount[p]--;
                pre.handCount[p]++;

                pre.hand[p][pre.handCount[p]] = pre.deck[p][pre.deckCount[p] - 1];
                pre.deck[p][pre.deckCount[p] - 1] = -1;
                pre.deckCount[p]--;
                pre.handCount[p]++;
            }
            else if (tributeRevealedCards[i] == adventurer || tributeRevealedCards[i] == council_room || tributeRevealedCards[i] == feast ||
                    tributeRevealedCards[i] == mine || tributeRevealedCards[i] == remodel || tributeRevealedCards[i] == smithy || tributeRevealedCards[i] == village ||
                    tributeRevealedCards[i] == baron || tributeRevealedCards[i] == steward || tributeRevealedCards[i] == tribute || tributeRevealedCards[i] == ambassador ||
                    tributeRevealedCards[i] == cutpurse || tributeRevealedCards[i] == embargo || tributeRevealedCards[i] == outpost ||
                    tributeRevealedCards[i] == salvager || tributeRevealedCards[i] == sea_hag || tributeRevealedCards[i] == treasure_map){

                pre.numActions+=2;

            }


            if(tributeRevealedCards[i] == tributeRevealedCards[i + 1]){
                i++;
                pre.handCount[otherPlayer]--;
                pre.discard[otherPlayer][pre.discardCount[otherPlayer]] = tributeRevealedCards[i];
                pre.discardCount[otherPlayer]++;
            }
        }
    }




    r = newAssert(pre.numActions == post->numActions &&
                pre.coins == post->coins &&
                pre.handCount[otherPlayer] == post->handCount[otherPlayer] &&
                pre.handCount[p] == post->handCount[p] &&
                pre.deckCount[otherPlayer] == post->deckCount[otherPlayer] &&
                pre.deckCount[p] == post->deckCount[p] &&
                pre.discardCount[otherPlayer] == post->discardCount[otherPlayer] &&
                pre.discardCount[p] == post->discardCount[p] &&
                pre.discard[otherPlayer][pre.discardCount[otherPlayer]-1] == post->discard[otherPlayer][post->discardCount[otherPlayer]-1] &&
                pre.discard[otherPlayer][pre.discardCount[otherPlayer]-2] == post->discard[otherPlayer][post->discardCount[otherPlayer]-2], __LINE__);

    if(r == -1){
        printf("cardEffectTribute ORIGINAL: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d, TB1 - %d, TB2 - %d\n",
            pre.whoseTurn, pre.handCount[pre.whoseTurn], pre.numActions,pre.coins, pre.discardCount[pre.whoseTurn], pre.playedCardCount, tributeRevealedCards[0], tributeRevealedCards[1]);
        printf("cardEffectTribute EXPECTED: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d\n",
            pre.whoseTurn, pre.handCount[pre.whoseTurn], pre.numActions,pre.coins, pre.discardCount[pre.whoseTurn], pre.playedCardCount);
        printf("cardEffectTribute ACTUAL: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d\n\n",
            post->whoseTurn, post->handCount[post->whoseTurn], post->numActions,post->coins, post->discardCount[post->whoseTurn], post->playedCardCount);
    }


    return 0;
}

int main(){
    // set your card array
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    int seed = 1000;
    // declare the game state
    struct gameState G;

    printf("Begin Random Tests cardEffectTribute\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //

    int j = 0;

    for(j = 0; j < 500; j++){

        memset(&G, 23, sizeof(struct gameState));
        // set the game state
        int p = rand() % 2;

        // initialize a new game
        int r = initializeGame(2, k, seed, &G); 


        // set any other variables
        G.whoseTurn = p;
        int i = 0;

        /*must have at least minion in hand*/

        G.handCount[p] = (rand() % (50 -1)) + 1;
        G.deckCount[p] = (rand() % (50 - 4)) + 4;
        G.discardCount[p] = rand() % (50 - G.handCount[p]);


        int otherPlayer = p - 1;
        if(otherPlayer == -1){
            otherPlayer=1;
        }

        G.handCount[otherPlayer] = rand() % 50;
        G.deckCount[otherPlayer] = (rand() % 50);

        if(G.deckCount[otherPlayer] == 1){
            G.discardCount[otherPlayer] = rand() % 2;
        }
        else if(G.deckCount[otherPlayer] == 0){
            G.discardCount[otherPlayer] = rand() % 3;
        }
        else{
            G.discardCount[otherPlayer] = rand() % (50 - G.handCount[otherPlayer]);
        }

        G.playedCardCount = rand() % 50;

        memset(G.playedCards,-1,50*sizeof(G.hand[p][0]));

        for(i = 0; i < G.playedCardCount; i++){
            G.playedCards[i] = rand() % 27;
        }


        memset(G.hand[p],-1,50*sizeof(G.hand[p][0]));
        memset(G.deck[p],-1,50*sizeof(G.hand[p][0]));
        memset(G.discard[p],-1,50*sizeof(G.hand[p][0]));

        memset(G.hand[otherPlayer],-1,50*sizeof(G.hand[p][0]));
        memset(G.deck[otherPlayer],-1,50*sizeof(G.hand[p][0]));
        memset(G.discard[otherPlayer],-1,50*sizeof(G.hand[p][0]));

        for(i = 0; i < G.handCount[p]; i++){
            G.hand[p][i] = rand() % 27;
        }

        for(i = 0; i < G.deckCount[p]; i++){
            G.deck[p][i] = rand() % 27;
        }

        for(i = 0; i < G.discardCount[p]; i++){
            G.discard[p][i] = rand() % 27;
        }


        for(i = 0; i < G.handCount[otherPlayer]; i++){
            G.hand[otherPlayer][i] = rand() % 27;
        }

        for(i = 0; i < G.deckCount[otherPlayer]; i++){
            G.deck[otherPlayer][i] = rand() % 27;
        }

        for(i = 0; i < G.discardCount[otherPlayer]; i++){
            G.discard[otherPlayer][i] = rand() % 27;
        }

        G.numActions = rand() % 50;
        G.coins = rand() % 100;


        // call the refactoredfunction

        checkTribute(&G);

        printf("Iteration: %d\n",j + 1);

    }

    printf("#Test cases passed: %d\n#Test cases failed: %d\n", testCasesPassed, testCasesFailed);

    return 0;
}


