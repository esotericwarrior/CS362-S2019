#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"

/* Village (Action): Cost = 3, +1 Card, +2 Actions */

int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;
	int r, returnedResult, actions;
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

	/* Since the cardEffect function returns 0 when it's successful, we assign
	the returned number to a variable.*/
	returnedResult = cardEffect(village, choice1, choice2, choice3, &G, NULL);

	/* Check number of actions after card has been played. */
	assert(G.numActions == actions + 2);
	/* Check returned value from cardEffect function. */
	assert(returnedResult == 0);

	printf("All tests passed!\n");
	return 0;

}