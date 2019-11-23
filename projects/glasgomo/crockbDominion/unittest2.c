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

    printf("Begin Testing minion() coins choice;\n");
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
    G.hand[ p ][ 0 ] = minion;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = estate;
    G.hand[ p ][ 3 ] = estate;
    G.hand[ p ][ 4 ] = estate;

    G.handCount[ p + 1 ] = 5;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    int handPos = 0;

    int returnVal;
    // call the refactoredfunction
    returnVal = playMinion(1, 0, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numActions == 1,__LINE__); 
    newAssert(G.coins == 2,__LINE__); 
    newAssert(G.hand[p][0] != minion,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 
    newAssert((G.hand[ p + 1 ][ 0 ] == copper) && (G.hand[ p + 1 ][ 1 ] == copper) && (G.hand[ p + 1 ][ 2 ] == copper) && (G.hand[ p + 1 ][ 3 ] == copper) && (G.hand[ p + 1 ][ 4 ] == copper),__LINE__); 
    newAssert(G.handCount[ p + 1 ] = 5,__LINE__);

    printf("Test completed!\n");




    printf("Begin Testing minion() discard choice; \n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.deckCount[p] = 10; 
    G.handCount[p] = 5;
    G.hand[ p ][ 0 ] = minion;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = silver;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = silver;

    G.deckCount[p + 1] = 10; 
    G.handCount[ p + 1 ] = 5;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // returnVal;
    // call the refactoredfunction
    returnVal = playMinion(0, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numActions == 1,__LINE__); 
    newAssert((G.hand[ p ][ 0 ] != silver) || (G.hand[ p ][ 1 ] != silver) || (G.hand[ p ][ 2 ] != silver) || (G.hand[ p ][ 3 ] != silver),__LINE__); 
    newAssert((G.hand[ p ][ 0 ] != minion),__LINE__); 
    newAssert((G.hand[ p ][ 4 ] == -1),__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.deckCount[p] == 6,__LINE__); 
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.handCount[p + 1] == 4,__LINE__); 
    newAssert(G.deckCount[p + 1] == 6,__LINE__); 
    newAssert((G.hand[ p + 1 ][ 0 ] != copper) || (G.hand[ p + 1 ][ 1 ] != copper) || (G.hand[ p + 1 ][ 2 ] != copper) || (G.hand[ p + 1 ][ 3 ] != copper),__LINE__); 
    newAssert((G.hand[ p + 1 ][ 4 ] == -1),__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing minion() neither choice error\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.deckCount[p] = 10; 
    G.handCount[p] = 5;
    G.hand[ p ][ 0 ] = minion;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = silver;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = silver;

    G.deckCount[p + 1] = 10; 
    G.handCount[ p + 1 ] = 5;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // returnVal;
    // call the refactoredfunction
    returnVal = playMinion(0, 0, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numActions == 0,__LINE__); 
    newAssert((G.hand[ p ][ 4 ] == silver) && (G.hand[ p ][ 1 ] == silver) && (G.hand[ p][ 2 ] == silver) && (G.hand[ p][ 3 ] == silver),__LINE__); 
    newAssert((G.hand[ p ][ 0 ] == minion),__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.deckCount[p] == 10,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.handCount[p + 1] == 5,__LINE__); 
    newAssert(G.deckCount[p + 1] == 10,__LINE__); 
    newAssert((G.hand[ p + 1 ][ 0 ] == copper) && (G.hand[ p + 1 ][ 1 ] == copper) && (G.hand[ p + 1 ][ 2 ] == copper) && (G.hand[ p + 1 ][ 3 ] == copper),__LINE__); 
    newAssert((G.hand[ p + 1 ][ 4 ] == copper),__LINE__); 
    newAssert(returnVal == -1,__LINE__); 

    printf("Test completed!\n");




    printf("Begin Testing minion() both choice error\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.deckCount[p] = 10; 
    G.handCount[p] = 5;
    G.hand[ p ][ 0 ] = minion;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = silver;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = silver;

    G.deckCount[p + 1] = 10; 
    G.handCount[ p + 1 ] = 5;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playMinion(1, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numActions == 0,__LINE__); 
    newAssert((G.hand[ p ][ 4 ] == silver) && (G.hand[ p ][ 1 ] == silver) && (G.hand[ p][ 2 ] == silver) && (G.hand[ p][ 3 ] == silver),__LINE__); 
    newAssert((G.hand[ p ][ 0 ] == minion),__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.deckCount[p] == 10,__LINE__); 
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.handCount[p + 1] == 5,__LINE__); 
    newAssert(G.deckCount[p + 1] == 10,__LINE__); 
    newAssert((G.hand[ p + 1 ][ 0 ] == copper) && (G.hand[ p + 1 ][ 1 ] == copper) && (G.hand[ p + 1 ][ 2 ] == copper) && (G.hand[ p + 1 ][ 3 ] == copper),__LINE__); 
    newAssert((G.hand[ p + 1 ][ 4 ] == copper),__LINE__); 
    newAssert(returnVal == -1,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing minion() discard choice; other player only has 4 cards\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    // initialize a new game
    r = initializeGame(2, k, seed, &G); 
    // set any other variables
    G.deckCount[p] = 10; 
    G.handCount[p] = 5;
    G.hand[ p ][ 0 ] = minion;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = silver;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = silver;

    G.deckCount[p + 1] = 10; 
    G.handCount[ p + 1 ] = 4;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;

    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // returnVal;
    // call the refactoredfunction
    returnVal = playMinion(0, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.numActions == 1,__LINE__); 
    newAssert((G.hand[ p ][ 0 ] != silver) || (G.hand[ p ][ 1 ] != silver) || (G.hand[ p ][ 2 ] != silver) || (G.hand[ p ][ 3 ] != silver),__LINE__); 
    newAssert((G.hand[ p ][ 0 ] != minion),__LINE__); 
    newAssert((G.hand[ p ][ 4 ] == -1),__LINE__); 
    newAssert(G.coins == 0,__LINE__); 
    newAssert(G.deckCount[p] == 6,__LINE__); 
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.handCount[p + 1] == 4,__LINE__); 
    newAssert(G.deckCount[p + 1] == 10,__LINE__); 
    newAssert((G.hand[ p + 1 ][ 0 ] == copper) && (G.hand[ p + 1 ][ 1 ] == copper) && (G.hand[ p + 1 ][ 2 ] == copper) && (G.hand[ p + 1 ][ 3 ] == copper),__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");

    return 0;
}
