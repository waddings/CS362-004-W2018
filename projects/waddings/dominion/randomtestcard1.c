#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int checkGreatHall(int, struct gameState *, int*, int);

int main () {

  int i, n, p, numfails;

  numfails = 0;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing Great Hall.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.whoseTurn = p;
    G.numActions = 0;
    G.playedCardCount = 0;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    G.hand[p][G.handCount[p]-1] = great_hall;
    checkGreatHall(p, &G, &numfails, n);
  }
  if(numfails == 0)
    printf ("ALL TESTS PASSED\n");

  return 0;
}

int checkGreatHall(int p, struct gameState *post, int *numfails, int n) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r, bonus;
  int handpos = pre.handCount[p] - 1;
  bonus = 0;

  r = cardEffect(great_hall, 0, 0, 0, post, handpos, &bonus);

  if(post->numActions != pre.numActions+1){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }
  if(post->handCount[p] != pre.handCount[p]){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }
  if(post->discardCount[p] != pre.discardCount[p]){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }

  assert (r == 0);

  return 0;
}
