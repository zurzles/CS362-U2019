/*
 * cardtest5.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "DrawCard"

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
	int numPlayers=2;
	int thisPlayer=0;
	struct gameState G, testG;
	int k[10]={adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("-----------Test Card: %s -------------------\n", TESTCARD);

	// --------TEST 1: Deck is empty -------
	printf("Test 1: Deck is empty\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	drawCard(thisPlayer,&testG);

	printf("The deck count  of pre-draw is %d\n", G.deckCount[thisPlayer]);
	printf("The deck count of post-draw is %d\n", testG.deckCount[thisPlayer]);
	//Assert Deck count is equal to previous discard count -1
	MYASSERT(testG.deckCount[thisPlayer]==(G.discardCount[thisPlayer]-1));

	//Assert discard count is now 0
	MYASSERT(testG.discardCount[thisPlayer]==0);

	//Assert Handcount has increased by 1	
	MYASSERT((testG.handCount[thisPlayer]-1)==G.handCount[thisPlayer]);	

	// --------TEST 2: Deck is not empty -------
	printf("Test 2: Deck is not empty\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	drawCard(thisPlayer,&testG);

	printf("The deck count  of pre-draw is %d\n", G.deckCount[thisPlayer]);
	printf("The deck count of post-draw is %d\n", testG.deckCount[thisPlayer]);

	//Assert deck count decreased by 1
	MYASSERT((testG.deckCount[thisPlayer]+1)==G.deckCount[thisPlayer]);

	//Assert handcount increased by 1
	MYASSERT((testG.handCount[thisPlayer]-1)==G.deckCount[thisPlayer]);

	printf("\n >>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}
