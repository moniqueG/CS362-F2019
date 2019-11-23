#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
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


int checkMinion(int choice1, int choice2, struct gameState *post, int handPos) {
    struct gameState pre, orig;
    memcpy (&pre, post, sizeof(struct gameState));
    memcpy (&orig, post, sizeof(struct gameState));


    int r,i;

    //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
    //    p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);

    r = playMinion(choice1, choice2, post, handPos);

    //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
    //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);


    pre.numActions++;

    if (choice1 > 0) {
        pre.coins = pre.coins + 2;
        pre.playedCards[pre.playedCardCount] = pre.hand[pre.whoseTurn][handPos];
        pre.playedCardCount++;

        pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]] = pre.hand[pre.whoseTurn][handPos];
        pre.discardCount[pre.whoseTurn]++;
        if(pre.handCount[pre.whoseTurn] <= 1){
            pre.hand[pre.whoseTurn][handPos] = -1;
        }
        else{
            pre.hand[pre.whoseTurn][handPos] = pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn] - 1];
            pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn] - 1] = -1;
        }
        pre.handCount[pre.whoseTurn]--;
    }
    else if (choice2 > 0) {
        while(pre.handCount[pre.whoseTurn]>0){
            pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]] = pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1];
            pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]-1] = -1;
            pre.handCount[pre.whoseTurn]--;
            pre.discardCount[pre.whoseTurn]++;
        }
        for(int i = 0; i < 4; i++){
            pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]] = pre.deck[pre.whoseTurn][pre.deckCount[pre.whoseTurn] - 1];
            pre.handCount[pre.whoseTurn]++;
            pre.deckCount[pre.whoseTurn]--;
        }

        int otherPlayer = pre.whoseTurn - 1;
        if(otherPlayer == -1){
            otherPlayer = 1;
        }
        if(pre.handCount[otherPlayer] >= 5){
            while(pre.handCount[otherPlayer]>0){
                pre.discard[otherPlayer][pre.discardCount[otherPlayer]] = pre.hand[otherPlayer][pre.handCount[otherPlayer]-1];
                pre.hand[otherPlayer][pre.handCount[otherPlayer]-1] = -1;
                pre.handCount[otherPlayer]--;
                pre.discardCount[otherPlayer]++;
            }
            for(int i = 0; i < 4; i++){
                pre.hand[pre.whoseTurn][pre.handCount[otherPlayer]] = pre.deck[otherPlayer][pre.deckCount[otherPlayer] - 1];
                pre.handCount[otherPlayer]++;
                pre.deckCount[otherPlayer]--;
            }
        }

    }


    r = newAssert(memcmp(&pre, post, sizeof(struct gameState)) == 0, 0);

    if(r == -1){
        printf("playMinion ORIGINAL: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d\n",
            orig.whoseTurn, orig.handCount[orig.whoseTurn], orig.numActions,orig.coins, orig.discardCount[orig.whoseTurn], orig.playedCardCount);

        printf("playMinion EXPECTED: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d\n",
            pre.whoseTurn, pre.handCount[pre.whoseTurn], pre.numActions,pre.coins, pre.discardCount[pre.whoseTurn], pre.playedCardCount);

        printf("playMinion ACTUAL: p - %d, HC - %d, NA - %d, C - %d, DiC - %d, PCC - %d\n\n",
            post->whoseTurn, post->handCount[post->whoseTurn], post->numActions,post->coins, post->discardCount[post->whoseTurn], post->playedCardCount);
    }
    return 0;
}

int main(){
    // set your card array
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    srand(time(NULL));
    int seed = 1000;
    // declare the game state
    struct gameState G;

    printf("Begin Random Tests playBaron\n");
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

        G.handCount[p] = (rand() % (MAX_DECK -1)) + 1;
        G.deckCount[p] = (rand() % (MAX_DECK - 4)) + 4;
        G.discardCount[p] = rand() % (MAX_DECK - G.handCount[p]);


        int otherPlayer = p - 1;
        if(otherPlayer == -1){
            otherPlayer=1;
        }

        G.handCount[otherPlayer] = rand() % MAX_DECK;
        /*ensure at leasrt 4 cards in other player's deck to avoid shuffle*/
        G.deckCount[otherPlayer] = (rand() % (MAX_DECK - 4)) + 4;
        G.discardCount[otherPlayer] = rand() % (MAX_DECK - G.handCount[otherPlayer]);

        G.playedCardCount = rand() % MAX_DECK;

        memset(G.playedCards,-1,MAX_DECK*sizeof(G.hand[p][0]));

        for(i = 0; i < G.playedCardCount; i++){
            G.playedCards[i] = rand() % 27;
        }


        memset(G.hand[p],-1,MAX_DECK*sizeof(G.hand[p][0]));
        memset(G.deck[p],-1,MAX_DECK*sizeof(G.hand[p][0]));
        memset(G.discard[p],-1,MAX_DECK*sizeof(G.hand[p][0]));

        memset(G.hand[otherPlayer],-1,MAX_DECK*sizeof(G.hand[p][0]));
        memset(G.deck[otherPlayer],-1,MAX_DECK*sizeof(G.hand[p][0]));
        memset(G.discard[otherPlayer],-1,MAX_DECK*sizeof(G.hand[p][0]));

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

        int handPos = rand() % G.handCount[p];
        G.hand[p][handPos] = minion;

        G.numActions = rand() % 50;
        G.coins = rand() % 100;
       

        int choice1 = rand() % 2;
        int choice2 = choice1 - 1;
        if(choice2 == -1){
            choice2 = 1;
        }


        // call the refactoredfunction
        checkMinion(choice1, choice2, &G, handPos);

printf("Iteration: %d\tChoice1: %d\tChoice2: %d\tHandPos: %d\n",j+1, choice1, choice2, handPos);

    }

    printf("#Test cases passed: %d\n#Test cases failed: %d\n", testCasesPassed, testCasesFailed);

    return 0;
}
