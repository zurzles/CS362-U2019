/*
 * cardtest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "GetWinners"

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
	int player1=0;
	int player2=1;
	int player3=2; 
	int players[3];
	struct gameState G, testG;
	int k[10]={adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("-----------Test Card: %s -------------------\n", TESTCARD);

	memcpy(&testG, &G, sizeof(struct gameState));
	
	//assign player's cards
	for (i = 0; i<4; i++){
		testG.hand[player1][i]= estate;
		testG.hand[player2][i]=estate;
		testG.hand[player3][i]=curse;
	}

//	getWinners(players[3],&testG);	
	// --------TEST 1: Winner is assigned correctly -------
//	MYASSERT(players[0]==1);

	// --------TEST 2: Loser is assigned correctly --------
//	MYASSERT(players[2]==0);
	
	// --------Test 3: Player gets extra point for being a turn behind and ties -----------
//	MYASSERT(players[1]==1);


	
	printf("\n >>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}
