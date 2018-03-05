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

    printf("------------------Beginning Unit Test for: handCard()---------------------\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
    printf("Test Passed\n");

    int tempCard = testG.hand[thisPlayer][4];

    printf("Player's last card: %d, expected value: %d\n", handCard(4, &testG), tempCard);
    assert(handCard(4, &testG) == tempCard);
    printf("Test Passed\n");

    tempCard = testG.hand[thisPlayer][0];

    printf("Player's first card: %d, expected value: %d\n", handCard(0, &testG), tempCard);
    assert(handCard(0, &testG) == tempCard);
    printf("Test Passed\n");

    testG.handCount[thisPlayer] = 1;
    discardCard(0, thisPlayer, &testG, 0);

    printf("Player's first card(empty hand): %d, expected value: %d\n", handCard(0, &testG), -1);
    assert(handCard(0, &testG) == -1);
    printf("Test Passed\n");

    return 0;
}
