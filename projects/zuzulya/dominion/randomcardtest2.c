//randomtestcard1.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"
#define NUM_RUNS 10 

int main(){

	int numPlayers=2;
	int handpos=0;
	int choice1=0;
	int seed=1000;
	int thisPlayer=0;
	struct gameState G, testG;
	int i=0;
	int j=0;
	int k[10];
	int m=0;
	int MAX_CARDS=10;
	int LAST_CARD_INDEX=10;
	int ESTATE_INDEX=1;
	int TREAUSRE_INDEX_ONE=4;
	int KINGDOM_INDEX_ONE=7;
	int CARD_INDEX_LAST=26;

	printf("\t----------------- Random Testing Card: %s ----------------\n", TESTCARD);
	
	for(m=0;m<NUM_RUNS;m++){
		
		for(i=0;i<10;i++){
			int repeat=0;
			do{
				repeat=0;
				if(i>0){
					k[i]=(rand()%CARD_INDEX_LAST)+KINGDOM_INDEX_ONE;
				}else {
					k[0]=minion;
				}
				for(j=1;j<i;j++){
				
					if(k[i]==k[j]){
						repeat=1;
					}
				}
				if(i>0){
					if(k[i]==minion){
						repeat=1;
					}
				}
			} while(repeat==1);
		}
		
		
		printf("Init\n");
		initializeGame(numPlayers, k, seed, &G);
		
		printf("Copying test\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		
		printf("Set number of cards\n");
		testG.handCount[thisPlayer] =rand() % MAX_CARDS +1;
		testG.deckCount[thisPlayer] = rand() % MAX_CARDS +1;
		testG.discardCount[thisPlayer] = rand() % MAX_CARDS +1;
		testG.supplyCount[thisPlayer]=rand()%MAX_CARDS+1;		

		printf("Assign cards\n");
		for(i=1;i<testG.handCount[thisPlayer];i++){
			testG.hand[thisPlayer][i]=rand()%LAST_CARD_INDEX;
		}
		
		for(i=0;i<testG.deckCount[thisPlayer];i++){
			testG.deck[thisPlayer][i]=rand()%LAST_CARD_INDEX;
		}
		
		for(i=0;i<testG.discardCount[thisPlayer];i++){
			testG.discard[thisPlayer][i]=rand()%LAST_CARD_INDEX;
		}
		
		for(i=0;i<treasure_map+1;i++){
			testG.supplyCount[i]=rand()% MAX_CARDS;
		}
		for(i=0; i<rand()% MAX_DECK;i++){
			testG.playedCardCount++;
		}
		
		printf("Draw minion card\n");		
		drewMinionCard(rand()%2+1,rand()%3,thisPlayer,&testG);

	}
	printf("Finished testing\n");

	return 0;
}
