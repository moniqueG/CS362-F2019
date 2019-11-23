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

    printf("Begin Testing playMine(1, gold, &G, handPos) trash copper gain gold\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    int r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[gold] = 1;
    int handPos = 0;

    int returnVal;
    // call the refactoredfunction
    returnVal = playMine(1, gold, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == -1,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.supplyCount[gold] == 1,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing playMine(2, silver, &G, handPos) trash copper gain silver:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[silver] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(2, silver, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == 0,__LINE__); 
    newAssert(G.supplyCount[silver] == 0,__LINE__); 
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.hand[p][0] != mine,__LINE__); 
    newAssert(G.deckCount[p] == 5,__LINE__); 


    printf("Test completed!\n");





    printf("Begin Testing playMine(2, copper, &G, handPos) trash gold gain copper:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = gold;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[copper] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(2, copper, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == 0,__LINE__); 
    newAssert(G.supplyCount[copper] == 0,__LINE__); 
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.hand[p][0] != mine,__LINE__); 


    printf("Test completed!\n");





    printf("Begin Testing playMine(3, copper, &G, handPos) trash estate gain copper:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = estate;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[copper] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(3, copper, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == -1,__LINE__); 
    newAssert(G.supplyCount[copper] == 1,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.hand[p][0] == mine,__LINE__); 


    printf("Test completed!\n");





    printf("Begin Testing playMine(1, treasure_map + 1, &G, handPos) trash gold gain unavilable:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = gold;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[copper] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(1, treasure_map + 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == -1,__LINE__); 
    newAssert(G.supplyCount[copper] == 1,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.hand[p][0] == mine,__LINE__); 


    printf("Test completed!\n");





    printf("Begin Testing playMine(1, curse - 1, &G, handPos) trash gold gain unavilable:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = gold;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[copper] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(1, curse - 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == -1,__LINE__); 
    newAssert(G.supplyCount[copper] == 1,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.hand[p][0] == mine,__LINE__); 


    printf("Test completed!\n");




    printf("Begin Testing playMine(1, ambassador, &G, handPos) trash smithy gain ambassador:\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[p] = 5;
    G.hand[ p ][ 0 ] = mine;
    G.hand[ p ][ 1 ] = smithy;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.numBuys = 0;
    G.coins = 0;
    G.discardCount[p] = 0;
    G.supplyCount[ambassador] = 1;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMine(1, ambassador, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(returnVal == -1,__LINE__); 
    newAssert(G.supplyCount[ambassador] == 1,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.hand[p][0] == mine,__LINE__); 


    printf("Test completed!\n");



    return 0;
}
