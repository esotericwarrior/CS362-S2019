/***********************************************
* Name: Tristan Santiago
* Date: May 14, 2019
* Description: randomcardtest2.c tests the
* Council Room card.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

/* Council Room (Action): Cost = 5, +4 Cards, +1 Buy */
/*------------------------------ Council Room Test ------------------------------*/
int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	int numTests = 1000;	// Number of tests to run.
	int currentPlayer = 0;	// Set current player to player 1.
	int totalPassedTest = 0; // Variable used to track number of successful tests.
	int i, r, returnedResult, handPos, handSize, deckSize;
	int deck_before, hand_before, deck_after, hand_after, discard_pile_before, discard_pile_after;
	int failed_hand_test = 0;
	int failed_deck_test = 0;
	int failed_discard_test = 0;
	int failed_buy_test = 0;
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
		G.deckCount[1] = deckSize - handSize;

		/* Set player one's hand size. */
		G.handCount[0] = handSize;
		G.handCount[1] = handSize;

		handPos = 0;
		/* Determine hand position of Council Room, so we discard properly. */

		/* Here, we tally everything before playing Council Room. */

		/* Get Player 1's hand count. */
		hand_before = G.handCount[0];
		printf("Hand count for player 1 prior to playing Council Room: %d\n", hand_before);
		/* Player 1's deck count before playing Council Room. */
		deck_before = G.deckCount[0];
		printf("Deck count for Player 1 prior to playing Council Room: %d\n", deck_before);
		/* Discard pile before playing Council Room. */
		discard_pile_before = G.playedCardCount;
		printf("Player 1's discard pile prior to playing Council Room: %d\n", discard_pile_before);
		/* Get Player 1's number of buys before playing Council Room. */
		int buys_before = G.numBuys;
		printf("Player 1's number of buys before playing Council Room: %d\n", buys_before);	// Should be 1 by default.

		/* Get Player 2's number of cards before playing Council Room. */
		int p2_hand_before = G.handCount[1];
		printf("Player 2's hand count prior to playing Council Room: %d\n", p2_hand_before);

		/* Get Player 2's deck count before playing Council Room. */
		int p2_deck_before = G.deckCount[1];


		/* Since the cardEffect function returns 0 when it's successful, we assign the returned number to a variable.*/
		//returnedResult = cardEffect(smithy, choice1, choice2, choice3, &G, NULL);
		printf("Playing Council Room...\n");
		returnedResult = cardEffect(council_room, 1, 1, 1, &G, handPos);	// Play Council Room card.

		int buys_after = G.numBuys;
		printf("Player 1's number of buys after playing Council Room: %d\n", buys_after);

		/* Verify that Council Room was successfully played. */
		//assert(returnedResult == 0);
		//printf("Returned Result %d\n", returnedResult);	// Debugging.
		
		/* Now we check everything now that Council Room has been played. */
		/* First, get player one's hand count after playing Council Room. */
		hand_after = G.handCount[0];
		printf("Hand count after playing Council Room: %d\n", hand_after);
		printf("HAND count after playing Council Room: %d\n", G.handCount[0]);
		printf("P2 hand count %d\n", G.handCount[1]);
		/* Get player one's deck count after playing Council Room. */
		deck_after = G.deckCount[0];
		printf("Deck count after playing Council Room: %d\n", deck_after);
		/* And finally, count discarded cards after playing Council Room. */
		discard_pile_after = G.playedCardCount;
		printf("Player 1's discard pile after playing Council Room: %d\n", G.playedCardCount);

		int passedTest = 1;	// Boolean variable for passing or failing a test. True by default.

		/*------------------------------ Test Results ------------------------------*/
		/* Having played Council Room, we check player one's hand before and after. */
		if (hand_after != (hand_before + 3)) {
			printf("Incorrect number of cards drawn.\n");
			/* Increment number of failed tests. */
			failed_hand_test++;
			/* Set test boolean to false. */
			passedTest = 0;
		}

		/* Check number of cards in the deck after Council Room is played. */
		if (deck_after != (deck_before - 4)) {
			printf("Incorrect number of cards in deck.\n");
			/* Increment number of failed tests. */
			failed_deck_test++;
			/* Set test boolean to false. */
			passedTest = 0;
		}

		if (buys_after != buys_before + 1) {
			printf("Incorrect number of buys assigned.\n");
			failed_buy_test++;
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

	return 0;

}