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

      printf("------------------Beginning Test for Card1: Smithy---------------------\n");

      initializeGame(numPlayers, k, seed, &G);
      memcpy(&testG, &G, sizeof(struct gameState));

      cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

      //test that player's hand has increased by the correct number of cards -- +3 from smithy and -1 rom discard
      printf("Player's hand count: %d, expected count: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
      assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
      printf("Test Passed\n");
      //test that player's deck has decreased by 3 cards
      printf("Player's deck count: %d, expected count: %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
      assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
      printf("Test Passed\n");

      //test that there are no changes to other player's hand and deck
      assert(testG.handCount[thisPlayer+1] == G.handCount[thisPlayer+1]);
      assert(testG.deckCount[thisPlayer+1] == G.deckCount[thisPlayer+1]);


      return 0;
}
