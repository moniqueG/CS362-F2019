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

    printf("Begin Testing ambassador(); attempt to return no copy of card to supply which currently has no copies; enough copies in hand\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    int handPos = 0;

    int returnVal;
    // call the refactoredfunction
    returnVal = playAmbassador(1, 0, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.discardCount[p] == 1,__LINE__); 
    newAssert(G.discard[p][0] == ambassador,__LINE__); 
    newAssert(G.playedCards[0] == ambassador,__LINE__); 
    newAssert(G.playedCardCount == 1,__LINE__); 
    newAssert(G.hand[p][0] != ambassador,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");



    printf("Begin Testing ambassador(); attempt to return 1 copy of card to supply which currently has no copies; enough copies in hand\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(1, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 3,__LINE__); 
    newAssert(G.supplyCount[silver] == 0,__LINE__); 
    newAssert(G.discardCount[p] == 1,__LINE__); 
    newAssert(G.discard[p][0] == ambassador,__LINE__); 
    newAssert(G.playedCards[0] == ambassador,__LINE__); 
    newAssert(G.playedCardCount == 1,__LINE__); 
    newAssert(G.hand[p][0] != ambassador,__LINE__); 
    newAssert(G.hand[p][0] != silver || G.hand[p][1] != silver || G.hand[p][2] != silver || G.hand[p][3] != silver || G.hand[p][4] != silver,__LINE__); 
    newAssert(G.discardCount[p + 1] == 1,__LINE__); 
    newAssert(G.discard[p + 1][0] == silver,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");





    printf("Begin Testing ambassador(); attempt to return 1 copy of card to supply which currently has no copies; enough copies in hand\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //

    // set the game state
    memset(&G, 23, sizeof(struct gameState));

    // initialize a new game
    r = initializeGame(2, k, seed, &G); 

    // set any other variables
    G.deckCount[p] = 5;
    G.handCount[p] = 5;
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 5;
    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = silver;
    G.hand[ p + 1 ][ 1 ] = silver;
    G.hand[ p + 1 ][ 2 ] = silver;
    G.hand[ p + 1 ][ 3 ] = silver;
    G.hand[ p + 1 ][ 4 ] = silver;

    G.supplyCount[copper] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(2, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 3,__LINE__); 
    newAssert(G.supplyCount[copper] == 0,__LINE__); 
    newAssert(G.discardCount[p] == 1,__LINE__); 
    newAssert(G.discard[p][0] == ambassador,__LINE__); 
    newAssert(G.playedCards[0] == ambassador,__LINE__); 
    newAssert(G.playedCardCount == 1,__LINE__); 
    newAssert(G.hand[p][0] != ambassador,__LINE__); 
    newAssert(((G.hand[p][0] == copper) + (G.hand[p][1] == copper) + (G.hand[p][2] == copper) + (G.hand[p][3] == copper) + (G.hand[p][4] == copper)) <  2,__LINE__); 
    newAssert(G.discardCount[p + 1] == 1,__LINE__); 
    newAssert(G.discard[p + 1][0] == copper,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing ambassador(); attempt to return -1 copies of card to supply\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(1, -1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.discardCount[p] == 0,__LINE__); 
    newAssert(G.playedCardCount == 0,__LINE__); 
    newAssert(G.hand[p][0] == ambassador,__LINE__); 
    newAssert(returnVal == -1,__LINE__); 

    printf("Test completed!\n");






    printf("Begin Testing ambassador(); attempt to return 3 copies of card to supply\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(1, 3, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.discardCount[p] == 0,__LINE__); 
    newAssert(G.playedCardCount == 0,__LINE__); 
    newAssert(G.hand[p][0] == ambassador,__LINE__); 
    newAssert(returnVal == -1,__LINE__); 
    printf("Test completed!\n");








    printf("Begin Testing ambassador(); attempt to return 2 copies of card to supply which currently has no copies; not enough copies in hand\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(1, 2, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.discardCount[p] == 0,__LINE__); 
    newAssert(G.playedCardCount == 0,__LINE__); 
    newAssert(G.hand[p][0] == ambassador,__LINE__); 
    newAssert(returnVal == -1,__LINE__); 
    printf("Test completed!\n");









    printf("Begin Testing ambassador(); return 0 copies of card to  supply which currently has 1 copy\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //

    // set the game state
    memset(&G, 23, sizeof(struct gameState));

    // initialize a new game
    r = initializeGame(2, k, seed, &G); 

    // set any other variables
    G.deckCount[p] = 5;
    G.handCount[p] = 5;
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = silver;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 5;
    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = silver;
    G.hand[ p + 1 ][ 1 ] = silver;
    G.hand[ p + 1 ][ 2 ] = silver;
    G.hand[ p + 1 ][ 3 ] = silver;
    G.hand[ p + 1 ][ 4 ] = silver;

    G.supplyCount[copper] = 1;
    G.supplyCount[ambassador] = 1;
    G.supplyCount[silver] = 1;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(2, 0, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 4,__LINE__); 
    newAssert(G.supplyCount[copper] == 0,__LINE__); 
    newAssert(G.supplyCount[ambassador] == 1,__LINE__); 
    newAssert(G.supplyCount[silver] == 1,__LINE__); 
    newAssert(G.discardCount[p] == 1,__LINE__); 
    newAssert(G.discard[p][0] == ambassador,__LINE__); 
    newAssert(G.playedCards[0] == ambassador,__LINE__); 
    newAssert(G.playedCardCount == 1,__LINE__); 
    newAssert(G.hand[p][0] != ambassador,__LINE__); 
    newAssert(((G.hand[p][0] == copper) + (G.hand[p][1] == copper) + (G.hand[p][2] == copper) + (G.hand[p][3] == copper) + (G.hand[p][4] == copper)) ==  2,__LINE__); 
    newAssert(G.discardCount[p + 1] == 1,__LINE__); 
    newAssert(G.discard[p + 1][0] == copper,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");






    printf("Begin Testing ambassador(); attempt to return 1 copy of card to supply which currently has no copies; more than enough copies in hand\n");
    //
    // set the state of your variables
    // comment on what this is going to test
    //

    // set the game state
    memset(&G, 23, sizeof(struct gameState));

    // initialize a new game
    r = initializeGame(2, k, seed, &G); 

    // set any other variables
    G.deckCount[p] = 5;
    G.handCount[p] = 5;
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 5;
    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = silver;
    G.hand[ p + 1 ][ 1 ] = silver;
    G.hand[ p + 1 ][ 2 ] = silver;
    G.hand[ p + 1 ][ 3 ] = silver;
    G.hand[ p + 1 ][ 4 ] = silver;

    G.supplyCount[copper] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(2, 1, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 3,__LINE__); 
    newAssert(G.supplyCount[copper] == 0,__LINE__); 
    newAssert(G.discardCount[p] == 2,__LINE__); 
    newAssert(G.discard[p][0] == ambassador,__LINE__); 
    newAssert(G.playedCards[0] == ambassador,__LINE__); 
    newAssert(G.playedCardCount == 1,__LINE__); 
    newAssert(G.hand[p][0] != ambassador,__LINE__); 
    newAssert(((G.hand[p][0] == copper) + (G.hand[p][1] == copper) + (G.hand[p][2] == copper) + (G.hand[p][3] == copper) + (G.hand[p][4] == copper)) <  2,__LINE__); 
    newAssert(G.discardCount[p + 1] == 1,__LINE__); 
    newAssert(G.discard[p + 1][0] == copper,__LINE__); 
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");






    printf("Begin Testing ambassador(); attempt to return 2 copies of ambassador card to supply;\n");
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
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = ambassador;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.handCount[ p + 1 ] = 5;
    G.discardCount[p + 1] = 0;
    G.hand[ p + 1 ][ 0 ] = copper;
    G.hand[ p + 1 ][ 1 ] = copper;
    G.hand[ p + 1 ][ 2 ] = copper;
    G.hand[ p + 1 ][ 3 ] = copper;
    G.hand[ p + 1 ][ 4 ] = copper;

    G.supplyCount[silver] = 0;
    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;
    handPos = 0;

    // call the refactoredfunction
    returnVal = playAmbassador(0, 2, &G, handPos);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.discardCount[p] == 0,__LINE__); 
    newAssert(G.playedCardCount == 0,__LINE__); 
    newAssert(G.hand[p][0] == ambassador,__LINE__); 
    newAssert(returnVal == -1,__LINE__); 
    printf("Test completed!\n");







    return 0;
}