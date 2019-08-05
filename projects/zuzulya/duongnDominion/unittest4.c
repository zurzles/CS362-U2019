/*
 * unittest4.c
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

#define TESTCARD "tribute"

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
	int nextPlayer=1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ---------- TEST 1: Reveals 2 actions cards-----------------
	printf("TEST 1: Reveals 2 action cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=11;
	testG.deck[thisPlayer+1][1]=17;

	tribute_helper(&testG);

	MYASSERT((testG.numActions-4)==G.numActions);

	// ---------- TEST 2: Reveals 1 action card, 1 treasure card ----
	printf("TEST 2: Reveals 1 action card, 1 treasure card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
		
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=11;
	testG.deck[thisPlayer+1][1]=4;

	tribute_helper(&testG);

	MYASSERT((testG.numActions-2)==G.numActions);
	MYASSERT((testG.coins-2)==G.coins);

	// -----------TEST 3: Reveals 1 action card, 1 victory card ----
	printf("TEST 3: Reveals 1 action card, 1 victory card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=11;
	testG.deck[thisPlayer+1][1]=2;

	tribute_helper(&testG);

	MYASSERT((testG.numActions-2)==G.numActions);
	MYASSERT((testG.handCount[thisPlayer]-2)==G.handCount[thisPlayer]);

	
	// -----------TEST 4: Reveals 2 treasure cards -----
	printf("TEST 4: Reveals 2 treasure cards \n");
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=4;
	testG.deck[thisPlayer+1][1]=5;

	tribute_helper(&testG);

	MYASSERT((testG.coins-4)==G.coins);

	
	// -----------TEST 5: Reveals 1 treasure card, 1 victory card ---
	printf("TEST 5: Reveals 1 treasure card and 1 victory card\n");
	memcpy(&testG, &G, sizeof(struct gameState));
		
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=4;
	testG.deck[thisPlayer+1][1]=1;

	tribute_helper(&testG);

	MYASSERT((testG.coins-2)==G.coins);
	MYASSERT((testG.handCount[thisPlayer]-2)==G.handCount[thisPlayer]);
	

	// -----------TEST 6: Reveals 2 vicotory cards ------
	printf("TEST 6: Reveals 2 victory cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.deckCount[thisPlayer+1]=2;
	testG.deck[thisPlayer+1][0]=1;
	testG.deck[thisPlayer+1][1]=2;

	tribute_helper(&testG);

	MYASSERT((testG.handCount[thisPlayer]-4)==G.handCount[thisPlayer]);



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


