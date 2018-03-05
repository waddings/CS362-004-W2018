#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
    int newCards = 1;
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	  struct gameState G, testG;
	  int k[11] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room, great_hall};

    printf("------------------Beginning Test for Card3: Great Hall---------------------\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    printf("Test Passed\n");

    printf("Player's deck count: %d, expected count: %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
    printf("Test Passed\n");

    printf("Player's action count: %d, expected count: %d\n", testG.numActions, G.numActions + 1);
    assert(testG.numActions == G.numActions + 1);
    printf("Test Passed\n");

    assert(testG.handCount[thisPlayer+1] == G.handCount[thisPlayer+1]);
    assert(testG.deckCount[thisPlayer+1] == G.deckCount[thisPlayer+1]);



    return 0;
}
