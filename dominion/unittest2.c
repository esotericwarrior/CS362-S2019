/***********************************************
* Name: Tristan Santiago
* Date: May 5, 2019
* Description: unittest2.c tests the player's
* coin total after playing Cutpurse.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

/* Cutpurse (Action - Attack): Cost = 4, +2 coins.
Each other player discards a Copper (or reveals a hand with no Copper. */

int main() {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	int numTests = 100;	// Number of tests to run.
	int currentPlayer = 0;	// Set current player to player 1.
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int i, r, p1coinsBefore, p1coinsAfter, p2coinsBefore, p2coinsAfter;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int maxHandCount = 5;
	int handPos = 0;
	int handCount = 1;
	// Arrays of all coppers, silvers, and golds.
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];

	for (i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	/* Seed random number generator. */
	srand(time(NULL));

	/* Begin Test. */
	//printf("\nTest number %d\n\n", (i + 1));

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));
	
	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Set player 1's coins to 4. */
	updateCoins(currentPlayer, &G, 0);	// Each player starts with 4 copper.
	p1coinsBefore = G.coins;
	printf("Player 1's Coins before playing Cutpurse: %d\n", p1coinsBefore);

	/* Set player 2's hand to include 1 copper. */
	//G.hand[1][1] = copper;
	//G.hand[1][2] = estate;
	//G.hand[1][3] = estate;
	//G.hand[1][4] = estate;
	//G.handCount[1] = handCount;                 // set the number of cards on hand
	//memcpy(G.hand[1], coppers, sizeof(int) * handCount); // set all the cards to copper

	//updateCoins(1, &G, 1);	// Copper.
	//p2coinsBefore = G.coins;
	//printf("Player 2's coins before playing Cutpurse %d\n", p2coinsBefore);

	/* Play Cutpurse. */
	playCutpurse(handPos, currentPlayer, &G);
	printf("Player 1's coins after playing Cutpurse: %d\n", G.coins);

	return 0;
}