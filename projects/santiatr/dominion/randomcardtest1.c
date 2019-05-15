///***********************************************
//* Name: Tristan Santiago
//* Date: May 14, 2019
//* Description: randomcardtest1.c tests the Village
//* card.
//**********************************************/
//#include <stdlib.h>
//#include <stdio.h>
//#include "dominion.h"
//#include "rngs.h"
//#include "assert.h"
//#include <string.h> /* memset */
//
///* Village (Action): Cost = 3, +1 Card, +2 Actions */
//
//int main(int argc, char** argv) {
//	int seed = 1000;
//	int numPlayer = 2;
//	int numTests = 1;
//	int i, j, l, r, returnedResult, actions;
//	struct gameState G;
//	int choice1 = 0, choice2 = 0, choice3 = 0;
//
//	int k[10] = { adventurer, council_room, feast, gardens, mine
//		, remodel, smithy, village, baron, great_hall };
//
//	for (i = 0; i < numTests; i++) {
//		/* Clear the game state. */
//		memset(&G, 23, sizeof(struct gameState));
//
//		int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;	// Random number of players between between 2 and 4.
//		int currentPlayer = rand() % numPlayers + 1;
//
//		/*Initialize a new game. */
//		r = initializeGame(numPlayers, k, seed, &G);
//
//		/* Set default number of actions. */
//		actions = G.numActions;
//
//		/* Randomize deck size. */
//		int deckSize = rand() % (MAX_DECK + 1);
//		printf("Randomized deck size = %d\n", deckSize);
//				
//		/* Randomize hand size. */
//		int handSize = rand() % (deckSize + 1);
//		printf("Randomized hand size = %d\n", handSize);
//		
//		/* Calculate player one's hand size. */
//		G.deckCount[currentPlayer] = deckSize - handSize;
//		//printf("Deck count: %d\n", G.deckCount[currentPlayer]);
//		
//		/* Set player one's hand size. */
//		G.handCount[currentPlayer] = handSize;
//		
//		/* Randomize discard pile count. */
//		//G.discardCount[currentPlayer] = rand() % deckSize;
//		G.discardCount[currentPlayer] = 0;
//
//		for (j = 0; j < numPlayers; j++) {
//			for (l = 0; l < G.deckCount[j]; l++) {
//				int randomCard = rand() % (50 + 1);
//				int randomCard2 = rand() % (10);
//				if (randomCard == 1) {
//					G.deck[j][l] = copper;
//				}
//				else if (randomCard == 2) {
//					G.deck[j][l] = silver;
//				}
//				else if (randomCard == 3) {
//					G.deck[j][l] = gold;
//				}
//				else {
//					G.deck[j][l] = k[randomCard2];
//				}
//			}
//		}
//
//		int playedBefore = G.playedCardCount;
//		printf("Played card count before: %d\n", playedBefore);
//
//		int deckBefore = G.deckCount[currentPlayer];
//		printf("Deck before: %d\n", deckBefore);
//
//		//int discardBefore = G.discardCount[currentPlayer];
//		//printf("Discard pile before: %d\n", discardBefore);
//
//		int handBefore = G.handCount[currentPlayer];
//		printf("Hand before: %d\n", handBefore);
//		
//		/* Since the cardEffect function returns 0 when it's successful, we assign
//		the returned number to a variable.*/
//		int handPos = 0;
//		returnedResult = playVillage(handPos, currentPlayer, &G);	// Refactored Village card test.
//		//returnedResult = cardEffect(village, 1, 1, 1, &G, handPos);
//		//printf("Returned Result %d\n", returnedResult);	// Debugging.
//		
//		/* Discard the card. */
//		discardCard(handPos, currentPlayer, &G, 0);
//
//		int playedAfter = G.playedCardCount;
//		printf("Played card count after: %d\n", playedAfter);
//		
//		int deckAfter = G.deckCount[currentPlayer];
//		printf("Deck after: %d\n", deckAfter);
//
//		//int discardAfter = G.discardCount[currentPlayer];
//		//printf("Discard pile after: %d\n", discardAfter);
//
//		int handAfter = G.handCount[currentPlayer];
//		printf("Hand after: %d\n", handAfter);
//
//		/* Check number of actions after card has been played. */
//		assert(G.numActions == actions + 2);
//
//		/* Check returned value from cardEffect function. */
//		assert(returnedResult == 0);
//	}
//
//	printf("All tests passed!\n");
//	return 0;
//
//}