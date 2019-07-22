/*
 * unittest1.c
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

#define TESTCARD "baron"

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

	// ----------- TEST 1: buy cards updated -----------------
	printf("TEST 1: Buy cards update\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\nThe number of buys pre-card %d\n", testG.numBuys);
	choice1 = 1;
	int count = testG.numBuys;
	drewBaronCard(choice1,thisPlayer,&testG);
	printf("\nThe number of buys post-card %d\n", testG.numBuys);
	//#assert the number of buys has gone up by 1
	MYASSERT(G.numBuys==count);	

// ----------- TEST 2: choice1 = 1: Discard estate/has estate card --------------
	printf("TEST 2: choice1 = 1: Discard estate/has estate card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	xtraCoins=4;
	drewBaronCard(choice1,thisPlayer,&testG);
	
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	//# assert that coins has gone up by 4
	MYASSERT(testG.coins == G.coins + xtraCoins);
	
	//# assert that player has discarded hand
	MYASSERT(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	
	//# assert that deck has increased by one
	MYASSERT(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	
	
    // ----------- TEST 3: choice1 = 1: Chooses discard estate/does not have estate card/available in supply -------------- 
	printf("TEST 3: choice1 = 1: Discard estate/does not have estate card and available in supply\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	drewBaronCard(choice1,thisPlayer,&testG);
	
	
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	
	//# assert that coins is the same
	MYASSERT(testG.coins == G.coins);
	//# assert that player has additional card
	MYASSERT(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1);
	//# assert that supply has decreased by one
	MYASSERT(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1);

	// ----------- TEST 4: choice1 = 2: Chooses discard estate/does not have estate card/not available in supply -------------- 
	printf("TEST 4: choice1 = 2:  Discard estate/does not have estate card/available in supply\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	drewBaronCard(choice1,thisPlayer,&testG);
	
	//# assert that game ends
	int over = isGameOver(&testG);
	MYASSERT(over==0);
	
	// ----------- TEST 5: choice1 = 2: Chooses pick up estate/available in supply --------------
	printf("TEST 4: choice1 = 2: Pick up estate card/available in supply\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 2;
	drewBaronCard(choice1,thisPlayer,&testG);
	
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	
	//# assert that coins is the same
	MYASSERT(testG.coins == G.coins);
	//# assert that player gains estate/supply loses estate
	MYASSERT(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1);
	MYASSERT(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1);
	
	// ----------- TEST 5: choice1 = 2: Chooses pick up estate/not available in supply --------------
	printf("TEST 5: choice1 = 2: Pick up estate card/not available in supply\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 2;
	drewBaronCard(choice1,thisPlayer,&testG);	
	
	//# assert that coins is the same
	MYASSERT(testG.coins == G.coins);
	//# assert that game ends
	over = isGameOver(&testG);
	MYASSERT(over==0);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


