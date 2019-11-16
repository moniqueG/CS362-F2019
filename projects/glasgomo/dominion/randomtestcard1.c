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


int checkBaron(int choice1, struct gameState *post, int firstEstate) {
    struct gameState pre, orig;
    memcpy (&pre, post, sizeof(struct gameState));
    memcpy (&orig, post, sizeof(struct gameState));


    int r,i;

    r = cardEffectBaron(choice1, post);

    pre.numBuys++;

    if (choice1 > 0 && firstEstate != -1) {
        pre.coins = pre.coins + 4;
        pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]] = estate;
        pre.discardCount[pre.whoseTurn]++;
        for(i = firstEstate; i < pre.handCount[pre.whoseTurn]; i++){
            pre.hand[pre.whoseTurn][i] = pre.hand[pre.whoseTurn][i+1];
        }
        pre.hand[pre.whoseTurn][i] = -1;
        pre.handCount[pre.whoseTurn]--;
    }
    else if (firstEstate == -1) {
        if(pre.supplyCount[estate] > 0){
            pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]] = estate;
            pre.discardCount[pre.whoseTurn]++;
            pre.supplyCount[estate]--;
        }
    }


    r = newAssert(memcmp(&pre, post, sizeof(struct gameState)) == 0, 0);

    if(r == -1){
        printf("cardEffectBaron ORIGINAL: p - %d, HC - %d, NB - %d, C - %d, DiC - %d, EsS - %d\n",
            orig.whoseTurn, orig.handCount[orig.whoseTurn], orig.numBuys,orig.coins, orig.discardCount[orig.whoseTurn], orig.supplyCount[estate]);

        printf("cardEffectBaron EXPECTED: p - %d, HC - %d, NB - %d, C - %d, DiC - %d, EsS - %d\n",
            pre.whoseTurn, pre.handCount[pre.whoseTurn], pre.numBuys,pre.coins, pre.discardCount[pre.whoseTurn], pre.supplyCount[estate]);

        printf("cardEffectBaron ACTUAL: p - %d, HC - %d, NB - %d, C - %d, DiC - %d, EsS - %d\n\n",
            post->whoseTurn, post->handCount[post->whoseTurn], post->numBuys,post->coins, post->discardCount[post->whoseTurn], post->supplyCount[estate]);
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

    printf("Begin Random Tests cardEffectBaron\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //

    int j = 0;

    for(j = 0; j < 1000; j++){

        // set the game state
        memset(&G, 23, sizeof(struct gameState));

        // initialize a new game
        int r = initializeGame(2, k, seed, &G); 


        // set any other variables
        int p = rand() % 2;
        G.whoseTurn = p;
        int firstEstate = -1;
        int i = 0;

        G.handCount[p] = rand() % MAX_DECK;

        memset(G.hand[p],-1,MAX_DECK*sizeof(G.hand[p][0]));
        for(i = 0; i < G.handCount[p]; i++){
            G.hand[p][i] = rand() % 27;
            if(G.hand[p][i] == estate && firstEstate == -1){
                firstEstate = i;
            }
        }


        G.numBuys = rand() % 50;
        G.coins = rand() % 100;
        G.discardCount[p] = rand() % (MAX_DECK - G.handCount[p]);
        G.supplyCount[estate] = rand() % 15;

        int choice1 = rand() % 2;

        // call the refactoredfunction
        checkBaron(choice1, &G, firstEstate);

    printf("Iteration: %d\tChoice1: %d\tFirst Estate: %d\n",j + 1, choice1, firstEstate);
    }

printf("#Test cases passed: %d\n#Test cases failed: %d\n", testCasesPassed, testCasesFailed);

    return 0;
}