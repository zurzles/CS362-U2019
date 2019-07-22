/*
 * cardtest3.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "EndTurn"

int main(){
	int newCards = 0;
	int discarded = 1;
	int xrtaCoins=0;
	int shuffledCards=0;
	
	int i=0;
	int j = 0;
	int m = 0;
	int handpos=0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3=0;
	int bonus=0;
	int remove1;
	int remove2;
	int seed = 1000;
	int numPlayers=3;
	int thisPlayer=2;
	struct gameState G, testG;
	int k[10]={adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("-----------Test Card: %s -------------------\n", TESTCARD);

	// --------TEST 1: Card is discarded-------
	printf("TEST 1: Card is discarded\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	
	endTurn(&testG);

	//assert that discard count goes up by 1
	MYASSERT((testG.discardCount[thisPlayer]-1)==G.discardCount[thisPlayer]);

	//assert that hand count goes down by 1
	MYASSERT((testG.handCount[thisPlayer]+1)==G.handCount[thisPlayer]);		
	// --------TEST 2: Next player is correctly determined/not at max player-------
	printf("TEST 2: Next player is correctly determined/not at max player\n");
	MYASSERT(testG.whoseTurn==(thisPlayer+1));

	// --------TEST 3: Next player is correctly determined/ at max player--------
	printf("TEST 3: Next player is correctly determined/at max player\n");

	testG.whoseTurn=thisPlayer+1;
	endTurn(&testG);
	MYASSERT(testG.whoseTurn==0);

	// --------TEST 4: State variables are reset
	printf("TEST 4: State variables are reset\n");

	MYASSERT(testG.outpostPlayed==0);
	MYASSERT(testG.phase==0);
	MYASSERT(testG.numActions==1);
	MYASSERT(testG.coins==0);
	MYASSERT(testG.numBuys==1);
	MYASSERT(testG.playedCardCount==0);
	MYASSERT(testG.handCount[testG.whoseTurn]==0);

									
	// --------TEST 5: Next player draws card 
	printf("TEST 5: Next player draws card \n");
	MYASSERT((testG.handCount[0]-1)==G.handCount[0]);

	printf("\n >>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<\n\n", TESTCARD);

	return 0;
}
