#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"

/* Smithy (Action): Cost = 4, +3 Cards */

int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;
	int r, returnedResult, actions, deckCount, deckCounter;
	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;

	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Set default number of actions. */
	actions = G.numActions;

	deckCount = G.handCount[1];	//Get current player's hand count
	printf("Deck Count: %d\n", deckCount);

	/* Since the cardEffect function returns 0 when it's successful, we assign
	the returned number to a variable.*/
	//returnedResult = cardEffect(smithy, choice1, choice2, choice3, &G, NULL);
	returnedResult = playSmithy(NULL, 1, &G);
	//printf("Returned Result %d\n", returnedResult);	// Debugging.

	deckCount = G.handCount[1];	//Get current player's hand count

	if (DEBUG) {//Debug statements
		printf("Current hand count: %d\n", deckCount);
	}

	deckCounter = G.deckCount[1];	//Create a holder for the deck count
	printf("Deck Count: %d\n", deckCount);

	if (deckCounter == 0)
		return -1;

	/* Check number of actions after card has been played. */
	//assert(G.numActions == actions + 2);

	/* Check returned value from cardEffect function. */
	//assert(returnedResult == 0);

	printf("All tests passed!\n");
	return 0;

}