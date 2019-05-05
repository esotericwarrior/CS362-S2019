#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

/* Adventurer (Action): Cost = 6, Reveal cards from your deck until you reveal 2 Treasure cards. 
Put those Treasure cards into your hand and discard the other revealed cards. */
/*------------------------------ Adventurer Test ------------------------------*/
int main(int argc, char** argv) {
	int seed = 1000;
	int numPlayer = 2;	// Number of players.
	int numTests = 100;	// Number of tests to run.
	int currentPlayer = 0;	// Set current player to player 1.
	int totalPassedTest = 0; // Variable used to track number of successful tests.
	int i, r, returnedResult, actions, handPos, handSize, deckSize, deckCount, deckCounter;
	int whoseTurn;
	int temphand[MAX_HAND];	// Temporary hand for cards Adventurer reveals while being played.
	int drawntreasure = 0;	// Tracks number of treasures drawn during Adventurer's effect.
	int cardDrawn = -1; // Initialized to bogus value.
	int z = 0;	// Tracks number of cards in temporary hand.

	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;

	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };

	/* Clear the game state. */
	memset(&G, 23, sizeof(struct gameState));

	/* Initialize a new game. */
	r = initializeGame(numPlayer, k, seed, &G);

	/* Seed random number generator. */
	srand(time(NULL));		

	/* Set game state and initialize player one's turn. */
	whoseTurn = G.whoseTurn;
	G.outpostPlayed = 0;
	G.phase = 0;
	G.numActions = 1;
	G.numBuys = 1;
	G.playedCardCount = 0;
	G.whoseTurn = 0;
	G.handCount[G.whoseTurn] = 0;
	handPos = 0;

	/* Test ideas from Piazza post. */

	/* Test #1: The top two cards of the deck are treasures. */

	/* Set player one's hand. */
	G.hand[whoseTurn][0] = adventurer;
	//G.handCount[whoseTurn] = 1;	// Adventurer is in the player's hand.
	G.hand[whoseTurn][1] = estate;
	G.hand[whoseTurn][2] = estate;
	G.hand[whoseTurn][3] = estate;
	G.hand[whoseTurn][4] = estate;


	/* Set player one's deck to have two treasures on top. */
	G.deck[whoseTurn][0] = copper;
	G.deck[whoseTurn][1] = copper;
	G.deck[whoseTurn][2] = silver;
	G.deck[whoseTurn][3] = gold;
	G.deck[whoseTurn][4] = silver;

	/* Cards in hand before playing Adventurer. */
	printf("Cards in hand before playing Adventurer.\n");
	for (i = 0; i < G.deck[whoseTurn][4]; i++) {
	//for (i = 0; i < 5; i++) {
		if (G.deck[whoseTurn][i] == copper) {	// If == 4
			printf("Card #%d: Copper\n", (i + 1));	// Copper
		}
		if (G.deck[whoseTurn][i] == silver) {	// If == 5
			printf("Card #%d: Silver\n", (i + 1));	// Silver
		}
		if (G.deck[whoseTurn][i] == gold) {	// If == 6
			printf("Card #%d: Gold\n", (i + 1));	// Gold
		}
	}

	/* Get player one's hand count. */
	int hand_before = G.handCount[whoseTurn];
	printf("Hand count for player 1 prior to playing Adventurer: %d\n", hand_before);

	/* Player one's deck count before playing Adventurer. */
	int deck_before = G.deckCount[whoseTurn];
	printf("Deck count for Player 1 prior to playing Adventurer: %d\n", deck_before);

	/* Discard pile before playing Smithy. */
	int discard_pile_before = G.playedCardCount;
	printf("Player 1's discard pile prior to playing Adventurer: %d\n", discard_pile_before);

	/* Play Adventurer. */
	printf("\nPlaying Adventurer...\n\n");
	returnedResult = playAdventurer(temphand, z, drawntreasure, cardDrawn, currentPlayer, &G);
	
	/* Verify that Adventurer was played. */
	assert(returnedResult == 0);
	
	/* Discard Adventurer from hand. */
	discardCard(handPos, currentPlayer, &G, 0);

	/* Now we check everything now that Adventurer has been played. */
	/* First, get player one's hand count after playing Adventurer. */
	int hand_after = G.handCount[whoseTurn];
	printf("Hand count after playing Adventurer: %d\n", hand_after);



	/* Get player one's deck count after playing Adventurer. */
	int deck_after = G.deckCount[whoseTurn];
	printf("Deck count after playing Adventurer: %d\n", deck_after);

	/* And finally, count discarded cards after playing Adventurer. */
	int discard_pile_after = G.playedCardCount;
	printf("Player 1's discard pile after playing Adventurer: %d\n", G.playedCardCount);


	//int copperCount = 0;
	//int silverCount = 0;
	//int goldCount = 0;
	//for (i = 0; i < 4; i++) {
	//	drawCard(currentPlayer, &G);
	//	cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer] - 1];	//top card of hand is most recently drawn card.
	//	if (cardDrawn == copper) {
	//		//printf("Copper\n");
	//		copperCount++;
	//	}
	//	if (cardDrawn == silver) {
	//		//printf("Silver\n");
	//		silverCount++;
	//	}
	//	if (cardDrawn == gold) {
	//		//printf("Gold\n");
	//		goldCount++;
	//	}
	//}

	//printf("Copper count %d\n", copperCount);
	//printf("Silver count %d\n", silverCount);
	//printf("Gold count %d\n", goldCount);


	/*------------------------------ Test Results ------------------------------*/


	/*------------------------------ Report Results ------------------------------*/

	return 0;

}
