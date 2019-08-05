/*
 * cardtest2.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "Shuffle"

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

	// --------TEST 1: Deck count is less than 0 -------
	printf("TEST 1: Deck count is less than 0\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	testG.deckCount[thisPlayer]=0;

	//assert returns invalid
	MYASSERT(shuffle(thisPlayer,&testG)!=0);	

	// --------TEST 2: Deck count is >0 -------------
	printf("TEST 2: Deck count is greater than 0\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	testG.deckCount[thisPlayer]=5;
	testG.deck[thisPlayer][0]=curse;
	testG.deck[thisPlayer][1]=duchy;
	testG.deck[thisPlayer][2]=copper;
	testG.deck[thisPlayer][3]=feast;
	testG.deck[thisPlayer][4]=mine;

	shuffle(thisPlayer,&testG);

	int wasShuffled=0;
	if(testG.deck[thisPlayer][0]!=curse){
		wasShuffled=1;
	}else if(testG.deck[thisPlayer][1]!=duchy){
		wasShuffled=1;
	} else 	if(testG.deck[thisPlayer][2]!=copper){
		wasShuffled=1;
	} else if(testG.deck[thisPlayer][3]!=feast){
		wasShuffled=1;
	}else if(testG.deck[thisPlayer][4]!=mine){
		wasShuffled=1;
	}
	MYASSERT(wasShuffled==1);
	
	printf("\n >>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}
