#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
    int newCards = 2;
    int discarded = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("------------------Beginning Test for Card2: Adventurer---------------------\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("2nd to last card in player's hand: %d, expected: 4-6\n", testG.hand[thisPlayer][testG.handCount[thisPlayer]-2]);
    assert(testG.hand[thisPlayer][testG.handCount[thisPlayer]-2] >= 4 && testG.hand[thisPlayer][testG.handCount[thisPlayer]-2] <= 6);
    printf("Test Passed\n");

    printf("Last card in player's hand: %d, expected: 4-6\n", testG.hand[thisPlayer][testG.handCount[thisPlayer]-1]);
    assert(testG.hand[thisPlayer][testG.handCount[thisPlayer]-1] >= 4 && testG.hand[thisPlayer][testG.handCount[thisPlayer]-1] <= 6);
    printf("Test Passed\n");

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    printf("Test Passed\n");

    printf("Player's deck count: %d, expected count: %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
    printf("Test Passed\n");

    assert(testG.handCount[thisPlayer+1] == G.handCount[thisPlayer+1]);
    assert(testG.deckCount[thisPlayer+1] == G.deckCount[thisPlayer+1]);

    return 0;
}
