#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

//int main() {
//		int seed = 1000;
//		int numPlayer = 2;	// Number of players.
//		int numTests = 12;	// Number of tests to run.
//		int currentPlayer = 0;	// Set current player to player 1.
//		int totalPassedTest = 0; // Variable used to track number of successful tests.
//		int i, r, returnedResult, handPos, handSize, deckSize, deckCount, deckCounter;
//		int handCount, deck_before, hand_before, deck_after, hand_after, discard_pile_before, discard_pile_after;
//		int actionsBefore, actionsAfter, vpBefore, vpAfter;
//		int failed_hand_test = 0;
//		int failed_deck_test = 0;
//		int failed_discard_test = 0;
//		int actions_test = 0;
//		int score_test = 0;
//		struct gameState G;
//		int choice1 = 0, choice2 = 0, choice3 = 0;
//		actionsBefore = 0;
//		actionsAfter = 0;
//		vpBefore = 0;
//		vpAfter = 0;
//		int whoseTurn = 0;
//
//		int k[10] = { adventurer, council_room, feast, gardens, mine
//			, remodel, smithy, village, baron, great_hall };
//		
//		/* Seed random number generator. */
//		srand(time(NULL));
//
//		/*------------------------------ Begin Testing ------------------------------*/
//		for (i = 0; i < numTests; i++) {
//			printf("\nTest #%d\n\n", (i + 1));			
//			
//			/* Clear the game state. */
//			memset(&G, 23, sizeof(struct gameState));
//
//			/* Initialize a new game. */
//			r = initializeGame(numPlayer, k, seed, &G);
//
//			/* Set default number of actions. */
//			actionsBefore = G.numActions;
//			printf("Number of actions before playing Great Hall = %d\n", G.numActions);
//
//			/* Reset hand position. */
//			handPos = 0;
//
//			/* Randomize deck size. */
//			deckSize = rand() % (MAX_DECK + 1);
//			printf("Randomized deck size = %d\n", deckSize);
//			/* Randomize hand size. */
//			handSize = rand() % (deckSize + 1);
//			printf("Randomized hand size = %d\n", handSize);
//
//			/* Calculate player one's hand size. */
//			G.deckCount[0] = deckSize - handSize;
//
//			/* Set player one's hand size. */
//			G.handCount[0] = handSize;
//
//
//			/* Get player one's hand count. */
//			hand_before = G.handCount[whoseTurn];
//			printf("Hand count for player 1 prior to playing Great Hall: %d\n", hand_before);
//
//			/* Player one's deck count before playing Great Hall. */
//			deck_before = G.deckCount[whoseTurn];
//			printf("Deck count for Player 1 prior to playing Great Hall: %d\n", deck_before);
//
//			/* Discard pile before playing Great Hall. */
//			discard_pile_before = G.playedCardCount;
//			printf("Player 1's discard pile prior to playing Great Hall: %d\n", discard_pile_before);
//
//			/* Set score before playing Great Hall. */
//			int score = 0;
//			printf("Score before playing Great Hall = %d\n", score);
//
//			printf("\nPlaying Great Hall...\n\n");
//			//returnedResult = cardEffect(great_hall, choice1, choice2, choice3, &G, NULL);	// Great Hall Card cardEffect test.
//			returnedResult = playGreat_Hall(handPos, whoseTurn, &G);
//
//			/* Verify Great Hall was properly played. */
//			assert(returnedResult == 0);
//			//printf("Returned Result %d\n", returnedResult);	// Debugging.
//
//			/* Now we check everything now that Great Hall has been played. */
//
//			/* First, get player one's hand count after playing Great Hall. */
//			hand_after = G.handCount[whoseTurn];
//			printf("Hand count after playing Great Hall: %d\n", hand_after);
//			/* Get player one's deck count after playing Great Hall. */
//			deck_after = G.deckCount[whoseTurn];
//			printf("Deck count after playing Great Hall: %d\n", deck_after);
//			/* And finally, count discarded cards after playing Great Hall. */
//			discard_pile_after = G.playedCardCount;
//			printf("Player 1's discard pile after playing Great Hall: %d\n", G.playedCardCount);
//
//			int passedTest = 1;	// Boolean variable for passing or failing a test. True by default.
//
//								/* Check number of actions after playing Great Hall. */
//			actionsAfter = G.numActions;
//			printf("Number of actions after playing Great Hall = %d\n", actionsAfter);
//
//			/* Check Victory Points after playing Great Hall. */
//			int scoreAfter = scoreFor(whoseTurn, &G);
//			printf("Score after Great Hall = %d\n", scoreAfter);
//
//			/* Check number of actions after card has been played. */
//			//assert(G.numActions == actions + 1);
//
//			/*------------------------------ Test Results ------------------------------*/
//			/* Having played Great Hall, we check player one's hand before and after. */
//			if (hand_after != hand_before) {
//				printf("Incorrect number of cards drawn.\n");
//				/* Increment number of failed tests. */
//				failed_hand_test++;
//				/* Set test boolean to false. */
//				passedTest = 0;
//			}
//			/* Check number of cards in the deck after Great Hall is played. */
//			if (deck_after != (deck_before - 1)) {
//				printf("Incorrect number of cards in deck.\n");
//				/* Increment number of failed tests. */
//				failed_deck_test++;
//				/* Set test boolean to false. */
//				passedTest = 0;
//			}
//
//			/* Check number of cards in the discard pile after Great Hall is played. */
//			if (discard_pile_after != (discard_pile_before + 1)) {
//				printf("Incorrect number of cards in discard pile.\n");
//				/* Increment number of failed tests. */
//				failed_discard_test++;
//				/* Set test boolean to false. */
//				passedTest = 0;
//			}
//
//			/* Check the number of actions after Great Hall is played. */
//			if (actionsAfter != (actionsBefore + 1)) {
//				printf("Incorrect number of actions given.\n");
//				/* Increment number of failed tests.*/
//				actions_test++;
//				passedTest = 0;
//			}
//
//			/* Check the score after Great Hall is played. */
//			if (scoreAfter != (score + 1)) {
//				printf("Incorrect number of Victory Points awarded.\n");
//				/* Incrememnt number of failed tests. */
//				score_test++;
//				passedTest = 0;
//			}
//
//			/* If all tests are passed, increment number of passed tests. */
//			if (passedTest == 1) {
//				printf("All tests passed!\n");
//				/* Increment total number of passed tests. */
//				totalPassedTest++;
//			}
//		}
//
//		/*------------------------------ Report Results ------------------------------*/
//		printf("\nTotal number of times all tests passed: %d\n", totalPassedTest);
//		printf("Total number of times cards drawn to hand failed: %d\n", failed_hand_test);
//		printf("Total number of times cards placed into deck failed: %d\n", failed_deck_test);
//		printf("Total number of times Great Hall discarded incorrectly: %d\n\n", failed_discard_test);
//	return 0;
//}