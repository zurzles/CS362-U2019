#include "dominion_helpers.h"
#include "dominion.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "rngs.h"

int check = 0;
/*Test AMBASSADOR*/
void printerror(int conditional, char*text) {
	if (conditional == 0) {
		printf("CHECK:  %s\n", text );
		check = 1;
	}
	return;
}
int main(int argc, char const *argv[]) {
	struct gameState *gS = malloc(sizeof(struct gameState));
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};


	int tstGame;

	//Initialize test
	tstGame=initializeGame(2, k, 69, gS);
	printf("-----Testing AMBASSADOR----- \n" );
	printerror(tstGame==0," initialize conditions FAILED ");


	gS->whoseTurn = 1;
	gS->hand[1][1] = ambassador; //Add minion card in hand.
	//int x  = gS->numActions; //dummy variable to hold numBuys
	int y = playCard(2,1,1,0,gS); //Play the first card in hand with all choices = 0
	printerror(y==0," playCard function FAILED");



	if(check==0){
		printf("ambassador_helper PASSED" );
	}

	return 0;
}
