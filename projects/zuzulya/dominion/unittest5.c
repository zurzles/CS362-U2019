/*
 * unittest5.c
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

#define TESTCARD "mine"

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

	// ----------- TEST 1: Trash a copper  for a silver--------------
	printf("TEST 1: Trash a copper\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=4;
	choice2=5;
	drewMineCard(choice1, choice2, handpos, thisPlayer, &testG);
	
	int Gsilver=0;
	int testGsilver=0;
	for(i=0; i<G.handCount[thisPlayer];i++){
		if(G.hand[thisPlayer][i]==0){
			Gsilver++;
		}
	}
	for(i=0;i<testG.handCount[thisPlayer]; i++){
		if(testG.hand[thisPlayer][i]==5){
			testGsilver++;
		}
	}
 
        MYASSERT((testGsilver-1)==Gsilver);
	// ----------TEST 2: Trash a silver for a gold -----
	printf("TEST 2: Trash a silver for a gold\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=5;
	choice2=6;

	drewMineCard(choice1, choice2, handpos, thisPlayer, &testG);
	
	int Ggold=0;
	int testGgold=0;
	for(i=0; i<G.handCount[thisPlayer];i++){
		if(G.hand[thisPlayer][i]==0){
			Ggold++;
		}
	}	
	for(i=0;i<testG.handCount[thisPlayer]; i++){
		if(testG.hand[thisPlayer][i]==5){
			testGgold++;
		}
	}
 
        MYASSERT((testGgold-1)==Ggold);
	// ----------TEST 3: Trash a copper for a gold -----
	printf("TEST 3: Trash a copper  for a gold\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=4;
	choice2=6;

	MYASSERT(drewMineCard(choice1, choice2, handpos, thisPlayer, &testG)!=0);
	
	// ----------TEST 4: invalid choice2 range----
 
	printf("TEST 4:Invalid choice2 range \n");

	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=4;
	choice2=100;

	MYASSERT(drewMineCard(choice1, choice2, handpos, thisPlayer, &testG)!=0);
	// ----------TEST 5: invalid choice1 range----
 	printf("TEST 5: Invalid choice1 range\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	choice1=0;
	choice2=6;

	MYASSERT(drewMineCard(choice1, choice2, handpos, thisPlayer, &testG)!=0);
			
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


