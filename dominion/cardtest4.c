#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

int main() {
		int seed = 1000;
		int numPlayer = 2;	// Number of players.
		int numTests = 100;	// Number of tests to run.
		int currentPlayer = 0;	// Set current player to player 1.
		int totalPassedTest = 0; // Variable used to track number of successful tests.
		int i, r, returnedResult, handPos, handSize, deckSize, deckCount, deckCounter;
		int handCount, deck_before, hand_before, deck_after, hand_after, discard_pile_before, discard_pile_after;
		int actionsBefore, actionsAfter, vpBefore, vpAfter;
		int failed_hand_test = 0;
		int failed_deck_test = 0;
		int failed_discard_test = 0;
		struct gameState G;
		int choice1 = 0, choice2 = 0, choice3 = 0;
		actionsBefore = 0;
		actionsAfter = 0;
		vpBefore = 0;
		vpAfter = 0;
		handPos = 0;
		int whoseTurn = 0;

		int k[10] = { adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall };
		
		/* Clear the game state. */
		memset(&G, 23, sizeof(struct gameState));
		
		/* Initialize a new game. */
		r = initializeGame(numPlayer, k, seed, &G);

		/* Set default number of actions. */
		actionsBefore = G.numActions;
		printf("Number of actions before playing Great Hall = %d\n", G.numActions);

		printf("\nPlaying Great Hall...\n\n");
		//returnedResult = cardEffect(great_hall, choice1, choice2, choice3, &G, NULL);	// Great Hall Card cardEffect test.
		returnedResult = playGreat_Hall(handPos, whoseTurn, &G);
		
		/* Check returned value from playGreatHall function. */
		assert(returnedResult == 0);
		printf("Returned Result %d\n", returnedResult);

		//actions = G.numActions;
		printf("Number of actions after playing Great Hall = %d\n", G.numActions);
		//printf("Actions after playing Great Hall = %d\n", actions);
		/* Check number of actions after card has been played. */
		//assert(G.numActions == actions + 1);
	
		/* Check number of cards drawn. */

		/* Check Victory Points. */


	return 0;
}