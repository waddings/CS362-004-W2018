#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main(){

    int discarded = 1;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, i = 0, count = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

    printf("------------------Beginning Unit Test for: discardCard()---------------------\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
    printf("Test Passed\n");

    printf("Player's deck count: %d, expected count: %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
    printf("Test Passed\n");

    printf("Player's discard count: %d, expected count: %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
    assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
    printf("Test Passed\n");

    discardCard(4, thisPlayer, &testG, 0);

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]-1);
    printf("Test Passed\n");

    printf("Player's deck count: %d, expected count: %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
    printf("Test Passed\n");

    printf("Player's last card: %d, expected value: %d\n", testG.hand[thisPlayer][4], -1);
    assert(testG.hand[thisPlayer][4] == -1);
    printf("Test Passed\n");

    testG.handCount[thisPlayer] = 1;

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], 1);
    assert(testG.handCount[thisPlayer] == 1);
    printf("Test Passed\n");

    int tempCard = testG.hand[thisPlayer][0];

    discardCard(1, thisPlayer, &testG, 1);

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], 0);
    assert(testG.handCount[thisPlayer] == 0);
    printf("Test Passed\n");

    printf("Player's played count: %d, expected count: %d\n", testG.playedCardCount, 1);
    assert(testG.playedCardCount == 1);
    printf("Test Passed\n");

    printf("Player's played card: %d, expected count: %d\n", testG.playedCards[0], tempCard);
    assert(testG.playedCards[0] == tempCard);
    printf("Test Passed\n");

    return 0;
}
