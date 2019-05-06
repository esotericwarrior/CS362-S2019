/***********************************************
* Name: Tristan Santiago
* Date: May 5, 2019
* Description: unittest4.c tests the getCost()
* function for 10 cards.
**********************************************/
#include <string.h> /* memset */
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "time.h"

/* Unit Test for getCost() function. */

int main() {
	/* Testing getCost() function for each card. */

	/* Adventurer */
	int adventurerCost = getCost(adventurer);
	if (adventurerCost == 6) {
		printf("Adventurer getCost() PASS!\n\n");
	}
	else {
		printf("Adventurer getCost() FAIL!\n\n");
	}

	/* Smithy */
	int smithyCost = getCost(smithy);
	if (smithyCost == 4) {
		printf("Smithy getCost() PASS!\n\n");
	}
	else {
		printf("Smithy getCost() FAIL!\n\n");
	}

	/* Council Room */
	int councilRoomCost = getCost(council_room);
	if (councilRoomCost == 5) {
		printf("Council Room getCost() PASS!\n\n");
	}
	else {
		printf("Council Room getCost() FAIL!\n\n");
	}

	/* Feast */
	int feastCost = getCost(feast);
	if (feastCost == 4) {
		printf("Feast getCost() PASS!\n\n");
	}
	else {
		printf("Feast getCost() FAIL!\n\n");
	}

	/* Gardens */
	int gardensCost = getCost(gardens);
	if (gardensCost == 4) {
		printf("Gardens getCost() PASS!\n\n");
	}
	else {
		printf("Gardens getCost() FAIL!\n\n");
	}

	/* Mine */
	int mineCost = getCost(mine);
	if (mineCost == 5) {
		printf("Mine getCost() PASS!\n\n");
	}
	else {
		printf("Mine getCost() FAIL!\n\n");
	}

	/* Remodel */
	int remodelCost = getCost(remodel);
	if (remodelCost == 4) {
		printf("Remodel getCost() PASS!\n\n");
	}
	else {
		printf("Remodel getCost() FAIL!\n\n");
	}

	/* Village */
	int villageCost = getCost(village);
	if (villageCost == 3) {
		printf("Village getCost() PASS!\n\n");
	}
	else {
		printf("Village getCost() FAIL!\n\n");
	}

	/* Baron */
	int baronCost = getCost(baron);
	if (baronCost == 4) {
		printf("Baron getCost() PASS!\n\n");
	}
	else {
		printf("Baron getCost() FAIL!\n\n");
	}

	/* Great Hall */
	int greatHallCost = getCost(great_hall);
	if (greatHallCost == 3) {
		printf("Great Hall getCost() PASS!\n\n");
	}
	else {
		printf("Great Hall getCost() FAIL!\n\n");
	}

	printf("All tests passed!\n\n");

	return 0;
}