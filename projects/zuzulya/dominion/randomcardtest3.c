//randomtestcard1.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"
#define NUM_RUNS 20 

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
	int n=0;
	int MAX_CARDS=10;
	int LAST_CARD_INDEX=10;
	int ESTATE_INDEX=1;
	int TREAUSRE_INDEX_ONE=4;
	int KINGDOM_INDEX_ONE=7;
	int CARD_INDEX_LAST=26;

	printf("\t----------------- Random Testing Card: %s ----------------\n", TESTCARD);
	
	for(m=0;m<NUM_RUNS;m++){
		
		for(i=0;i<10;i++){
			printf("i: %d\n",i);			
			int repeat=0;
			do{
				repeat=0;
				if(i>0){
					k[i]=(rand()%CARD_INDEX_LAST)+KINGDOM_INDEX_ONE;
				}else {
					k[0]=tribute;
				}
				printf("m=%d, k[i]=%d; i=%d\n",m,k[i],i);
				for(j=1;j<i;j++){
				
					if(k[i]==k[j]){
						repeat=1;
						printf("Hit repeat1 on j=%d,i=%d\n",j,i);
					}
				}
				if(i>0){
					if(k[i]==tribute){
						repeat=1;
						printf("Hit repeat2\n");
					}
				}
			} while(repeat==1);
		}
		
		
		printf("Init\n");
		initializeGame(numPlayers, k, seed, &G);
		
		printf("Copying test\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		
		printf("Set number of cards\n");

		for(n=0;n<2;n++){
			testG.handCount[n] =rand() % MAX_CARDS + 1 ;
			testG.discardCount[n] = rand() % MAX_CARDS  + 1;
			testG.supplyCount[n]=rand()%MAX_CARDS+1;		
			printf("Assign cards\n");
			for(i=1;i<testG.handCount[n];i++){
				testG.hand[n][i]=rand()%CARD_INDEX_LAST;
			}
		
			for(i=0;i<testG.deckCount[n];i++){
				testG.deck[n][i]=rand()%CARD_INDEX_LAST;
			}
		
			for(i=0;i<testG.discardCount[n];i++){
				testG.discard[n][i]=rand()%CARD_INDEX_LAST;
			}
		}		
		for(i=0;i<treasure_map+1;i++){
			testG.supplyCount[i]=(rand()% MAX_CARDS);
		}
	
		for(i=0; i<rand()% MAX_DECK;i++){
			testG.playedCardCount++;
		}
		

		printf("Draw tribute  card\n");		
		testG.playedCardCount=0;
		drewTributeCard(0,1,&testG);
		printf("Made it\n");
	}
	printf("Finished testing\n");

	return 0;
}
