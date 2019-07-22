/*
 * unittest3.c
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

#define TESTCARD "minion"

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
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: num actions updated-----------------
	printf("TEST 1: Num Actions  updated\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	choice1 = 1;
	drewMinionCard(choice1,choice2,handpos,thisPlayer,&testG);

	//#assert the number of actions has gone up by 1
    	MYASSERT(testG.numActions == G.numActions + 1);
	
	// ----------- TEST 2: choice1 = 1 = +2 coins --------------
	printf("TEST 2: choice1 = 1 = +2 cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	choice1 = 1;
	drewMinionCard(choice1,choice2,handpos,thisPlayer,&testG);


	MYASSERT(testG.coins==G.coins + 2);

	// ----------- TEST 3: choice1 = 2: discard hand --------------
	printf("TEST 3: choice1 = 2: discardhand \n");
	choice1 = 2;

	testG.handCount[thisPlayer]=3;
	testG.handCount[thisPlayer+1]=3;
	testG.handCount[thisPlayer+2]=6;
	for(i=0;i<3;i++){
		for(j=0;j<testG.handCount[i];i++){
			testG.hand[i][j]=curse;
		}
	}

	drewMinionCard(choice1,choice2,handpos,thisPlayer,&testG);

	MYASSERT(testG.handCount[thisPlayer]==4);
	MYASSERT(testG.handCount[thisPlayer+1]==3);
	MYASSERT(testG.handCount[thisPlayer+2]==4);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


