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

    printf("Begin Testing tribute(); other player has 1 victory card in deck\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 1;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = estate;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    int returnVal = playTribute(&G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 7,__LINE__); 
    newAssert(G.deckCount[p] == 0,__LINE__); 
    newAssert(G.hand[p][5] == gold,__LINE__); 
    newAssert(G.hand[p][6] == estate,__LINE__); 
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(G.coins ==0,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");




    printf("Begin Testing tribute(); other player has 1 treasure card in deck\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 1;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = silver;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G, 0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==2,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");





    printf("Begin Testing tribute(); other player has 1 action card in deck\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 1;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = adventurer;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==0,__LINE__);
    newAssert(G.numActions ==2,__LINE__);
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");






    printf("Begin Testing tribute(); other player has 1 victory card in discard\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;
    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = silver;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 0;
    G.discardCount[p + 1] = 1;
    G.discard[ p + 1 ][ 0 ] = estate;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 7,__LINE__); 
    newAssert(G.deckCount[p] == 0,__LINE__); 
    newAssert(G.hand[p][5] == gold,__LINE__); 
    newAssert(G.hand[p][6] == estate,__LINE__); 
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(G.coins ==0,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");




    printf("Begin Testing tribute(); other player has 1 treasure card in discard\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 0;
    G.discardCount[p + 1] = 1;
    G.discard[ p + 1 ][ 0 ] = silver;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==2,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");





    printf("Begin Testing tribute(); other player has 1 action card in discard\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 0;
    G.discardCount[p + 1] = 1;
    G.discard[ p + 1 ][ 0 ] = adventurer;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==0,__LINE__);
    newAssert(G.numActions ==2,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");




    printf("Begin Testing tribute(); other player has no cards in deck or discard\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 0;
    G.discardCount[p + 1] = 0;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==0,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==0,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing tribute(); other player has more than 2 distinct treasure cards in deck\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 3;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = gold;
    G.deck[ p + 1 ][ 1 ] = silver;
    G.deck[ p + 1 ][ 2 ] = copper;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==4,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.deckCount[ p + 1 ] ==1,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==2,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");





    printf("Begin Testing tribute(); other player has 2 of the same treasure card in deck\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 2;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = gold;
    G.deck[ p + 1 ][ 1 ] = gold;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==2,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==2,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");






    printf("Begin Testing tribute(); other player has 2 distinct cards in deck (victory and treasure)\n");
    //
    // set the state of your variables
    // test: other player has 2 distinct cards in deck (victory and treasure)
    //

    // set the game state
    memset(&G, 23, sizeof(struct gameState));

    // initialize a new game
    r = initializeGame(2, k, seed, &G); 

    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = mine;
    G.deck[ p ][ 1 ] = gardens;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 2;
    G.discardCount[p + 1] = 0;
    G.deck[ p + 1 ][ 0 ] = great_hall;
    G.deck[ p + 1 ][ 1 ] = gold;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 7,__LINE__); 
    newAssert(G.deckCount[p] == 0,__LINE__); 
    newAssert(G.coins ==2,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.hand[p][5] == gardens,__LINE__); 
    newAssert(G.hand[p][6] == mine,__LINE__); 
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==2,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");



    printf("Begin Testing tribute(); other player has 2 distinct cards (victory and treasure), 1 in discard and 1 in deck\n");
    //
    // set the state of your variables
    // test: other player has 2 distinct cards in deck (victory and treasure)
    //

    // set the game state
    memset(&G, 23, sizeof(struct gameState));

    // initialize a new game
    r = initializeGame(2, k, seed, &G); 

    // set any other variables
    G.handCount[p] = 5;
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = mine;
    G.deck[ p ][ 1 ] = gardens;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 1;
    G.discardCount[p + 1] = 1;
    G.deck[ p + 1 ][ 0 ] = great_hall;
    G.discard[ p + 1 ][ 0 ] = gold;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 7,__LINE__); 
    newAssert(G.deckCount[p] == 0,__LINE__); 
    newAssert(G.coins ==2,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.hand[p][5] == gardens,__LINE__); 
    newAssert(G.hand[p][6] == mine,__LINE__); 
    newAssert(G.deckCount[ p + 1 ] ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==2,__LINE__);
    newAssert(returnVal == 0,__LINE__); 

    printf("Test completed!\n");








    printf("Begin Testing tribute(); other player has 2 treasure cards in discard\n");
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
    G.deckCount[ p] = 2;
    G.deck[ p ][ 0 ] = estate;
    G.deck[ p ][ 1 ] = gold;

    G.discardCount[p] = 0;
    G.hand[ p ][ 0 ] = tribute;
    G.hand[ p ][ 1 ] = copper;
    G.hand[ p ][ 2 ] = copper;
    G.hand[ p ][ 3 ] = copper;
    G.hand[ p ][ 4 ] = copper;

    G.deckCount[ p + 1 ] = 0;
    G.discardCount[p + 1] = 2;
    G.discard[ p + 1 ][ 0 ] = silver;
    G.discard[ p + 1 ][ 1 ] = gold;

    G.playedCardCount = 0;
    G.numActions = 0;
    G.numBuys = 0;
    G.coins = 0;

    // call the refactoredfunction
    returnVal = playTribute(&G,0);

    // verify that your assertspass, for the bugs your asserts may fail
    newAssert(G.handCount[p] == 5,__LINE__); 
    newAssert(G.deckCount[p] == 2,__LINE__); 
    newAssert(G.coins ==4,__LINE__);
    newAssert(G.numActions ==0,__LINE__);
    newAssert(G.discardCount[ p + 1 ] ==1,__LINE__);
    newAssert(returnVal == 0,__LINE__); 
    printf("Test completed!\n");




    return 0;
}
