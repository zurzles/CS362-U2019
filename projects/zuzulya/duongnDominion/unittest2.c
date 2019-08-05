/*
 * unittest2.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "ambassador"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i = 0;
    int j = 0;
    int	m = 0;
    int handpos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int remove1;
    int remove2;
    int seed = 1000;
    int numPlayers = 3;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Choice 2 too low-----------------
	printf("TEST 1: Choice2 too low\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2=-3;
	MYASSERT(ambassador_helper(choice1,choice2,&testG,handpos)!=0);

	
	// ----------- TEST 2: choice1 = 1 = +2 coins --------------
	printf("TEST 2: choice2 too high\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 100;
	MYASSERT(ambassador_helper(choice1,choice2,&testG,handpos)!=0);
	
	// ----------- TEST 3: choice2 in range --------------
	printf("TEST 3: choice2 in range \n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	choice2 = 2;
	testG.handCount[thisPlayer]=3;
	testG.hand[thisPlayer][0]=curse;
	testG.hand[thisPlayer][1]=curse;
	testG.hand[thisPlayer][2]=curse;
	testG.handCount[thisPlayer+1]=3;
	testG.hand[thisPlayer+1][0]=curse;
	testG.hand[thisPlayer+1][1]=curse;
	testG.hand[thisPlayer+1][2]=curse;
	testG.handCount[thisPlayer+2]=6;
	testG.hand[thisPlayer+2][0]=curse;
	testG.hand[thisPlayer+2][1]=curse;
	testG.hand[thisPlayer+2][2]=curse;
	testG.hand[thisPlayer+2][3]=curse;
	testG.hand[thisPlayer+2][4]=curse;
	testG.hand[thisPlayer+2][5]=curse;



	ambassador_helper(choice1,choice2,&testG,handpos);
	MYASSERT(testG.handCount[thisPlayer]==4);
	MYASSERT(testG.handCount[thisPlayer+1]==3);
	MYASSERT(testG.handCount[thisPlayer+2]==4);

	// ----------- TEST 4: choice1 is invalid-------------
	printf("TEST 4: choice1 is invalid/same as handpos\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=1;
	handpos=1; 
	choice2=1;

	MYASSERT(ambassador_helper(choice1,choice2,&testG,handpos)!=0);

	// ----------- TEST 5: Enough discard cards------------
	printf("Test 5: verify enough discard cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=1;
	handpos=2;

	MYASSERT(ambassador_helper(choice1,choice2,&testG,handpos));
	
	// ----------- TEST 6: Not enough discard cards------------
	printf("Test 6: verify not enough discard cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=1;
	handpos=0;

	MYASSERT(ambassador_helper(choice1,choice2,&testG,handpos)!=0);


	// ----------- TEST 7: Supply cards has increased ------------
	printf("Test 7: verify supply cards has increased\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=1;
	handpos=0;


	ambassador_helper(choice1,choice2,&testG,handpos);
	MYASSERT((testG.supplyCount[1]-1)==G.supplyCount[1]);
	
	// ----------- TEST 8: Other players cards have increased ----------
	printf("Test 8: verify others' cards increased\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=1;
	handpos=0;

	ambassador_helper(choice1,choice2,&testG,handpos);
	printf("Pre handcount %d\n", G.handCount[thisPlayer+1]);
	printf("Post handcount %d\n", testG.handCount[thisPlayer+1]);
	MYASSERT((testG.handCount[thisPlayer+1]-1)==G.handCount[thisPlayer+1]);

	// ----------- TEST 9: Current players card has discarded ----------
	printf("Test 9: verify current player discarded card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=1;
	handpos=0;


	ambassador_helper(choice1,choice2,&testG,handpos);
	MYASSERT((testG.handCount[thisPlayer]+1)==G.handCount[thisPlayer]);
		
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


