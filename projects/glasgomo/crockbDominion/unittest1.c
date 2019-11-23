#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



 int newAssert(int condition, int lineNumber){
    if(condition == 0){
        printf("Fail at line %d\n\n", lineNumber);
    }
    return 0;
 }




int main(){
    // set your card array
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    int p = 0;
    int seed = 1000;
    // declare the game state
    struct gameState G;

    printf("Begin Testing baron() has estate; wants to discard:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    int r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 1;
    // call the refactoredfunction
    playBaron(1, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 4,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.hand[p][0] == baron,__LINE__);
    newAssert(G.hand[p][1] == copper,__LINE__);
    newAssert(G.hand[p][2] == silver,__LINE__);
    newAssert(G.hand[p][3] == gold,__LINE__);
    newAssert(G.hand[p][4] == -1,__LINE__);
    newAssert(G.handCount[p] == 4,__LINE__);
    newAssert(G.supplyCount[estate] == 1,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): has estate; no discard; multiply estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;
    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 2;

    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 1,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): has estate; no discard; 1 estate in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 1;

    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): has estate; no discard; no estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 0;
    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] != estate,__LINE__);
    newAssert(G.discardCount[p] == 0,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");




    printf("Begin Testing someFunction(): no estate; no discard; multiply estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 2;

    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 1,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): no estate; no discard; 1 estate in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 1;

    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): no estate; no discard; no estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 0;

    // call the refactoredfunction
    playBaron(0, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] != estate,__LINE__);
    newAssert(G.discardCount[p] == 0,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): no estate; yes discard; multiply estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 2;
    // call the refactoredfunction
    playBaron(1, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 1,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): no estate; yes discard; 1 estate in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    r = initializeGame(2, k, seed, &G); 
    // initialize a new game
    G.handCount[p] = 5;
    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 1;
    // call the refactoredfunction
    playBaron(1, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] == estate,__LINE__);
    newAssert(G.discardCount[p] == 1,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");



    printf("Begin Testing someFunction(): no estate; yes discard; no estates in supply\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    memset(&G, 23, sizeof(struct gameState));

    // set the game state
    r = initializeGame(2, k, seed, &G); 

    // initialize a new game
    G.handCount[p] = 5;

    // set any other variables
    G.hand[ p ][ 0 ] = baron;
    G.hand[ p ][ 1 ] = adventurer;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = gold;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[estate] = 0;

    // call the refactoredfunction
    playBaron(1, &G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numBuys == 1,__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.discard[p][0] != estate,__LINE__);
    newAssert(G.discardCount[p] == 0,__LINE__);
    newAssert(G.supplyCount[estate] == 0,__LINE__);
    printf("Test completed!\n");




    return 0;
}