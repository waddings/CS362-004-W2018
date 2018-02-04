#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main(){

    int newCards = 3;
    int discarded = 1;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

      printf("------------------Beginning Unit Test for: numHandCards()---------------------\n");

      initializeGame(numPlayers, k, seed, &G);
      memcpy(&testG, &G, sizeof(struct gameState));

      printf("Player's hand count: %d, expected count: %d\n", numHandCards(&testG), numHandCards(&G));
      assert(numHandCards(&testG) == numHandCards(&G));
      printf("Test Passed\n");

      printf("(Compared to G.handCount) Player's hand count: %d, expected count: %d\n", numHandCards(&testG), testG.handCount[thisPlayer]);
      assert(numHandCards(&testG) == testG.handCount[thisPlayer]);
      printf("Test Passed\n");

      testG.whoseTurn = 1; G.whoseTurn = 1;
      printf("Other player's hand count: %d, expected count: %d\n", numHandCards(&testG), numHandCards(&G));
      assert(numHandCards(&testG) == numHandCards(&G));
      printf("Test Passed\n");

      testG.whoseTurn = 0; G.whoseTurn = 0;
      cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

      printf("Player's hand count: %d, expected count: %d\n", numHandCards(&testG), numHandCards(&G) + newCards - discarded);
      assert(numHandCards(&testG) == numHandCards(&G) + newCards - discarded);
      printf("Test Passed\n");

      printf("(Compared to G.handCount) Player's hand count: %d, expected count: %d\n", numHandCards(&testG), testG.handCount[thisPlayer]);
      assert(numHandCards(&testG) == testG.handCount[thisPlayer]);
      printf("Test Passed\n");


      return 0;
}
