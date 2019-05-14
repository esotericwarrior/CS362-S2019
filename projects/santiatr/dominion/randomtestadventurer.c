/***********************************************
* Name: Tristan Santiago
* Date: May 13, 2019
* Description: randomtestadventurer.c tests the Smithy
* card.
**********************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>

int main(int argc, char** argv) {
	int seed = 1000;
	//int numPlayers = 2;	// Number of players.
	int numTests = 1;	// Number of tests to run.
	int currentPlayer = 0;	// Set current player to player 1.
	int totalPassedTest = 0; // Variable used to track number of successful tests.
	int temphand[MAX_HAND];	// Temporary hand for cards Adventurer reveals while being played.
	int z = 0;	// Tracks number of cards in temporary hand.
	int drawnTreasure = 0; // Tracks number of treasures drawn during Adventurer's effect.
	int cardDrawn = -1;	// Initialized to a bogus value.
	int i, j, l, r, returnedResult, actions, handPos, handSize, deckSize, deckCount, deckCounter;
	int handCount, deck_before, hand_before, deck_after, hand_after, discard_pile_before, discard_pile_after;
	int coins_before, coins_after;
	int randomCard;
	int failed_hand_test = 0;
	int failed_deck_test = 0;
	int failed_discard_test = 0;
	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	//int copper_before, copper_after, silver_before, silver_after, gold_before, gold_after;
	int copperCount = 0;
	int silverCount = 0;
	int goldCount = 0;

	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };

	/* Seed random number generator. */
	srand(time(NULL));

	/* Random Testing Adventurer */
	printf("Random Testing Adventurer\n");

	for (i = 0; i < numTests; i++) {
		/* Begin Test. */
		printf("\nTest number %d\n\n", (i + 1));

		/* Clear the game state. */
		memset(&G, 23, sizeof(struct gameState));

		int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;	// Random number of players between between 2 and 4.
		printf("Number of players: %d\n", numPlayers);

		/* Initialize a new game. */
		r = initializeGame(numPlayers, k, seed, &G);

		/* Randomize deck size. */
		deckSize = rand() % (MAX_DECK + 1);
		printf("Randomized deck size = %d\n", deckSize);
		
		/* Randomize hand size. */
		handSize = rand() % (deckSize + 1);
		printf("Randomized hand size = %d\n", handSize);

		/* Calculate player one's hand size. */
		G.deckCount[0] = deckSize - handSize;
		printf("Deck count: %d\n", G.deckCount[0]);
		/* Set player one's hand size. */
		G.handCount[0] = handSize;

		//handPos = 0;
		coins_before = 0;

		for (j = 0; j < numPlayers; j++) {
			for (l = 0; l < G.deckCount[j]; l++) {
				randomCard = rand() % (3 + 1);
				if (randomCard == 1) {
					G.deck[j][l] = copper;
				}
				if (randomCard == 2) {
					G.deck[j][l] = silver;
				}
				if (randomCard == 3) {
					G.deck[j][l] = gold;
				}
			}
		}
		
		int n;
		for (n = 0; n < G.handCount[currentPlayer]; n++) {
			//if (G.hand[currentPlayer][n] == copper || G.hand[currentPlayer][n] == silver || G.hand[currentPlayer][n] == gold) {
			//	coins_before++;
			//}
			if (G.hand[currentPlayer][n] == copper) {
				copperCount++;
				coins_before++;
			}
			if (G.hand[currentPlayer][n] == silver) {
				silverCount++;
				coins_before++;
			}
			if (G.hand[currentPlayer][n] == gold) {
				goldCount++;
				coins_before++;
			}
		}
		printf("Copper count: %d\n", copperCount);
		printf("Silver count: %d\n", silverCount);
		printf("Gold count: %d\n", goldCount);
		printf("Coin count before playing Adventurer: %d\n", coins_before);

		returnedResult = playAdventurer(temphand, z, drawnTreasure, cardDrawn, currentPlayer, &G);

		/* Verify that Adventurer was played. */
		assert(returnedResult == 0);

		/* Reset variables. */
		copperCount = 0;
		silverCount = 0;
		goldCount = 0;
		coins_after = 0;

		for (n = 0; n < G.handCount[currentPlayer]; n++) {
			if (G.hand[currentPlayer][n] == copper) {
				copperCount++;
				coins_after++;
			}
			if (G.hand[currentPlayer][n] == silver) {
				silverCount++;
				coins_after++;
			}
			if (G.hand[currentPlayer][n] == gold) {
				goldCount++;
				coins_after++;
			}
		}
		printf("Coin count after playing Adventurer: %d\n", coins_after);
		printf("Copper count: %d\n", copperCount);
		printf("Silver count: %d\n", silverCount);
		printf("Gold count: %d\n", goldCount);
	}

	/*------------------------------ Report Results ------------------------------*/
	printf("\nTotal number of times all tests passed: %d\n", totalPassedTest);
	printf("Total number of times cards drawn to hand failed: %d\n", failed_hand_test);
	printf("Total number of times cards placed into deck failed: %d\n", failed_deck_test);
	printf("Total number of times Adventurer discarded incorrectly: %d\n", failed_discard_test);

	return 0;
}
