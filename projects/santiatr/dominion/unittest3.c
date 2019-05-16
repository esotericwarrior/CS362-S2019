/***********************************************
* Name: Tristan Santiago
* Date: May 5, 2019
* Description: unittest3.c tests manually adding
* copper, silver, and gold to a player's hand.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	struct gameState G;
	int k[10] = { adventurer, council_room, feast, gardens, mine
				, remodel, smithy, village, baron, great_hall };

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/* Initialize a new game. */
	int r = initializeGame(numPlayer, k, seed, &G);

	printf("Testing Adding Coins to hand.\n");

	/* Determine number of coins player's start the game with. */
	printf("\nNumber of coins before the start of the test = %d\n", G.coins);
	printf("Expected Result = %d, Returned Result = %d\n", 4, G.coins);
	if (G.coins == 4) {
		printf("TEST PASSED!\n");
	}
	else {
		printf("TEST FAILED!\n");
	}

	/* Reset coins. */
	G.coins = 0;	// Not working?
	updateCoins(0, &G, 0);	// Not working?

	printf("\nAdding 10 Copper to Player 1's hand:\n");
	G.hand[0][0] = copper;
	G.hand[0][1] = copper;
	G.hand[0][2] = copper;
	G.hand[0][3] = copper;
	G.hand[0][4] = copper;
	G.hand[0][5] = copper;
	G.hand[0][6] = copper;
	G.hand[0][7] = copper;
	G.hand[0][8] = copper;
	G.hand[0][9] = copper;
	updateCoins(0, &G, 0);
	printf("\nExpected Result = %d, Returned Result = %d\n", 10, G.coins);
	if (G.coins == 10) {
		printf("TEST PASSED!\n");
	}
	else {
		printf("TEST FAILED!\n");
	}

	printf("\nAdding 5 Silver to Player 1's hand:\n");
	G.hand[0][0] = silver;
	G.hand[0][1] = silver;
	G.hand[0][2] = silver;
	G.hand[0][3] = silver;
	G.hand[0][4] = silver;
	G.hand[0][5] = 0;	// Reset
	G.hand[0][6] = 0;	// Reset
	G.hand[0][7] = 0;	// Reset
	G.hand[0][8] = 0;	// Reset
	G.hand[0][9] = 0;	// Reset
	updateCoins(0, &G, 0);
	printf("\nExpected Result = %d, Returned Result = %d\n", 10, G.coins);
	if (G.coins == 10) {
		printf("TEST PASSED!\n");
	}
	else {
		printf("TEST FAILED!\n");
	}

	updateCoins(0, &G, 0);
	printf("\nAdding 3 Gold to Player 1's hand:\n");
	G.hand[0][0] = gold;
	G.hand[0][1] = gold;
	G.hand[0][2] = gold;
	G.hand[0][0] = 0;	// Reset
	G.hand[0][0] = 0;	// Reset
	updateCoins(0, &G, 0);
	printf("\nExpected Result = %d, Returned Result = %d\n", 9, G.coins);
	if (G.coins == 9) {
		printf("TEST PASSED!\n");
	}
	else {
		printf("TEST FAILED!\n");
	}

	/* Manually update coins with updateCoin() function. */
	//updateCoins(0, &G, 10);
	//printf("\nUpdating coins with updateCoin() function.\n\n");
	//printf("Coins after using updateCoin() function = %d\n", G.coins);


	return 0;
}