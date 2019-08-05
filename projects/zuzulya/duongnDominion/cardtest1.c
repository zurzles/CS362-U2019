/*
 * cardtest1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "myassert.h"

#define TESTCARD "InitializeGame"

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

	// --------TEST 1: Invalid number of players - too low-------
	printf("TEST 1: Invalid number of players - too low\n");	
	numPlayers=0;
	MYASSERT(initializeGame(numPlayers, k, seed, &G)!=0);


	// --------TEST 2: Invalid number of players - too high------
	printf("TEST 2: Invalid number of players - too high\n");	
	numPlayers=100;

	MYASSERT(initializeGame(numPlayers, k, seed, &G)!=0);

	
	// --------TEST 3: Kingdom cards are the same ------
	printf("TEST 3: Kingdom cards are the same\n");	
	numPlayers=2;
	
	int k2[10]={adventurer, adventurer, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


	MYASSERT(initializeGame(numPlayers, k2, seed, &G)!=0);

	// --------TEST 4: Kingdom cards are different ------
	printf("TEST 4: kingdom cards are different\n");	

	MYASSERT(initializeGame(numPlayers, k, seed, &G)==0);

	// --------TEST 5: 2players card assignment ------
	printf("TEST 5: 2 players deck assignment\n");	
	numPlayers=2;
  	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG,&G,sizeof(struct gameState));

	//assert curse 0
	MYASSERT(testG.supplyCount[0]==10);
	//assert estate 1
	MYASSERT(testG.supplyCount[1]==8);
	//assert duchy 2
	MYASSERT(testG.supplyCount[2]==8);
	//assert province 3
	MYASSERT(testG.supplyCount[3]==8);
	//assert copper 4
	MYASSERT(testG.supplyCount[4]==46);
	//assert silver 5
	MYASSERT(testG.supplyCount[5]==40);
	//assert gold 6
	MYASSERT(testG.supplyCount[6]==30);

	
	// --------TEST 6: 3players card assigment ------  
	printf("TEST 6: 3 players deck assignment\n");	

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG,&G,sizeof(struct gameState));

	//assert curse 0
	MYASSERT(testG.supplyCount[0]==20);
	//assert estate 1
	MYASSERT(testG.supplyCount[1]==12);
	//assert duchy 2
	MYASSERT(testG.supplyCount[2]==12);
	//assert province 3
	MYASSERT(testG.supplyCount[3]==12);
	//assert copper 4
	MYASSERT(testG.supplyCount[4]==39);
	//assert silver 5
	MYASSERT(testG.supplyCount[5]==40);
	//assert gold 6
	MYASSERT(testG.supplyCount[6]==30);



	
	// --------TEST 7: 4players card assignment ------
	printf("TEST 7: 4 players deck assignment\n");	

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG,&G,sizeof(struct gameState));


	//assert curse 0
	MYASSERT(testG.supplyCount[0]==30);
	//assert estate 1
	MYASSERT(testG.supplyCount[1]==12);
	//assert duchy 2
	MYASSERT(testG.supplyCount[2]==12);
	//assert province 3
	MYASSERT(testG.supplyCount[3]==12);
	//assert copper 4
	MYASSERT(testG.supplyCount[4]==32);
	//assert silver 5
	MYASSERT(testG.supplyCount[5]==40);
	//assert gold 6
	MYASSERT(testG.supplyCount[6]==30);

 

		
	// --------TEST 8: Players draw 5 cards -------
	printf("TEST 8: Players draw 5 cards\n");	
	for(i=0; i<numPlayers;i++){
		MYASSERT(testG.handCount[i]==5);
	}
	
	// --------TEST 9: State variables are set ------
	printf("TEST 9: State variables are set\n");	
	
	for(i=0; i<=treasure_map; i++){
		MYASSERT(testG.embargoTokens[i]==0);
	}

	MYASSERT(testG.outpostPlayed==0);
	MYASSERT(testG.phase==0);
	MYASSERT(testG.numActions==1);
	MYASSERT(testG.numBuys==1);
	MYASSERT(testG.playedCardCount==0);
	MYASSERT(testG.whoseTurn==0);
	MYASSERT(testG.handCount[testG.whoseTurn]==0);
	MYASSERT(testG.coins==0);
	
	printf("\n >>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}
