/***********************************************
* Name: Tristan Santiago
* Date: May 5, 2019
* Description: unittest1.c tests the gameOver()
* function.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

int main() {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	int i, r;
	struct gameState G;
	struct gameState testGameState;
	int k[10] = { adventurer, council_room, feast, gardens, mine
				, remodel, smithy, village, baron, great_hall };

	/*------------------------------ Begin Testing ------------------------------*/
	printf("Begin testing isGameOver() function\n\n");

	/* TEST #1: Game is over when Province is empty. */

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));
	
	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);
	G.supplyCount[province] = 0;
	int result = isGameOver(&G);

	/*Test to see if supply pile is empty. */
	printf("Test #1: Is game over when Province is empty?\n");
	if (result == 1) {
		printf("PASS. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}
	else {
		printf("FAIL. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}

	/* TEST #2: Game is over when three supply piles are depleted.*/

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Deplete three supply piles. */
	G.supplyCount[6] = 0;
	G.supplyCount[2] = 0;
	G.supplyCount[1] = 0;
	result = isGameOver(&G);

	printf("Test #2: Is game over with three depleted supply piles?\n");
	if (result == 1) {
		printf("PASS. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}
	else {
		printf("FAIL. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}

	/* TEST #3: Deplete two supply piles. */

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Deplete two supply piles. */
	G.supplyCount[4] = 0;
	G.supplyCount[7] = 0;
	result = isGameOver(&G);

	printf("Test #3: Is game over with two depleted supply piles?\n");
	if (result == 0) {
		printf("PASS. Expected result = %d, Returned Result = %d\n\n", 0, result);
	}
	else {
		printf("FAIL. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}

	/* TEST #4: Deplete one supply pile. */

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Deplete one supply piles. */
	G.supplyCount[1] = 0;
	result = isGameOver(&G);

	printf("Test #4: Is game over with one depleted supply pile?\n");
	if (result == 0) {
		printf("PASS. Expected result = %d, Returned Result = %d\n\n", 0, result);
	}
	else {
		printf("FAIL. Expected result = %d, Returned Result = %d\n\n", 1, result);
	}

	return 0;
}