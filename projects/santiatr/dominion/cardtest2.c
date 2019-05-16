/***********************************************
* Name: Tristan Santiago
* Date: May 5, 2019
* Description: cardtest2.c tests the Smithy
* card.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

/* Smithy (Action): Cost = 4, +3 Cards */
/*------------------------------ Smithy Test ------------------------------*/
int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	int numTests = 20000;	// Number of tests to run.
	int currentPlayer = 0;	// Set current player to player 1.
	int totalPassedTest = 0; // Variable used to track number of successful tests.
	int i, r, returnedResult, actions, handPos, handSize, deckSize, deckCount, deckCounter;
	int handCount, deck_before, hand_before, deck_after, hand_after, discard_pile_before, discard_pile_after;
	int failed_hand_test = 0;
	int failed_deck_test = 0;
	int failed_discard_test = 0;
	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;

	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };

	/* Seed random number generator. */
	srand(time(NULL));

	for (i = 0; i < numTests; i++) {
		/* Begin Test. */
		printf("\nTest number %d\n\n", (i + 1));

		/* Clear the game state. */
		memset(&G, 23, sizeof(struct gameState));

		/* Initialize a new game. */
		r = initializeGame(numPlayer, k, seed, &G);
		
		/* Randomize deck size. */
		deckSize = rand() % (MAX_DECK + 1);
		printf("Randomized deck size = %d\n", deckSize);
		/* Randomize hand size. */
		handSize = rand() % (deckSize + 1);
		printf("Randomized hand size = %d\n", handSize);

		/* Calculate player one's hand size. */
		G.deckCount[0] = deckSize - handSize;

		/* Set player one's hand size. */
		G.handCount[0] = handSize;

		handPos = 0;
		/* Determine hand position of Smithy, so we discard properly. */

		/* Here, we tally everything before playing Smithy. */

		/* Get player one's hand count. */
		hand_before = G.handCount[0];
		printf("Hand count for player 1 prior to playing Smithy: %d\n", hand_before);
		/* Player one's deck count before playing Smithy. */
		deck_before = G.deckCount[0];
		printf("Deck count for Player 1 prior to playing Smithy: %d\n", deck_before);
		/* Discard pile before playing Smithy. */
		discard_pile_before = G.playedCardCount;
		printf("Player 1's discard pile prior to playing Smithy: %d\n", discard_pile_before);

		/* Since the cardEffect function returns 0 when it's successful, we assign the returned number to a variable.*/
		//returnedResult = cardEffect(smithy, choice1, choice2, choice3, &G, NULL);
		printf("Playing Smithy...\n");
		returnedResult = playSmithy(handPos, 0, &G);	// Play Smithy card.
		
		/* Verify that Smithy was successfully played. */
		//assert(returnedResult == 0);
		//printf("Returned Result %d\n", returnedResult);	// Debugging.
		
		/* Now we check everything now that Smithy has been played. */
		/* First, get player one's hand count after playing Smithy. */
		hand_after = G.handCount[0];
		printf("Hand count after playing Smithy: %d\n", hand_after);
		/* Get player one's deck count after playing Smithy. */
		deck_after = G.deckCount[0];
		printf("Deck count after playing Smithy: %d\n", deck_after);
		/* And finally, count discarded cards after playing Smithy. */
		discard_pile_after = G.playedCardCount;
		printf("Player 1's discard pile after playing Smithy: %d\n", G.playedCardCount);

		int passedTest = 1;	// Boolean variable for passing or failing a test. True by default.

		/*------------------------------ Test Results ------------------------------*/
		/* Having played Smithy, we check player one's hand before and after. */
		if (hand_after != (hand_before + 3)) {
			printf("Incorrect number of cards drawn.\n");
			/* Increment number of failed tests. */
			failed_hand_test++;
			/* Set test boolean to false. */
			passedTest = 0;
		}
		/* No "else" statement used because it can be 4 cards drawn and showing correct. */
		//else {
		//	printf("Correct number of cards drawn.\n");
		//}
		/* Check number of cards in the deck after Smithy is played. */
		if (deck_after != (deck_before - 3)) {
			printf("Incorrect number of cards in deck.\n");
			/* Increment number of failed tests. */
			failed_deck_test++;
			/* Set test boolean to false. */
			passedTest = 0;
		}

		if (discard_pile_after != (discard_pile_before + 1)) {
			printf("Incorrect number of cards in discard pile.\n");
			/* Increment number of failed tests. */
			failed_discard_test++;
			/* Set test boolean to false. */
			passedTest = 0;
		}

		/* If all tests are passed, increment number of passed tests. */
		if (passedTest == 1) {
			printf("All tests passed!\n");
			/* Increment total number of passed tests. */
			totalPassedTest++;
		}
	}

	/*------------------------------ Report Results ------------------------------*/
	printf("\nTotal number of times all tests passed: %d\n", totalPassedTest);
	printf("Total number of times cards drawn to hand failed: %d\n", failed_hand_test);
	printf("Total number of times cards placed into deck failed: %d\n", failed_deck_test);
	printf("Total number of times Smithy discarded incorrectly: %d\n", failed_discard_test);

	return 0;

}