#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void checkAdventurerCard(int p, struct gameState *post, int *numfails, int n){
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r, bonus;
  int handpos = pre.handCount[p] - 1;
  bonus = 0;

  r = cardEffect(adventurer, 0, 0, 0, post, handpos, &bonus);

  if(post->handCount[p] != pre.handCount[p]+2){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }
  if(post->hand[p][post->handCount[p]-1] < 4 || post->hand[p][post->handCount[p]-1] > 6){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }
  if(post->hand[p][post->handCount[p]-2] < 4 || post->hand[p][post->handCount[p]-2] > 6){
    (*numfails)++;
    printf("FAILURE AT ITERATION %d\n", n);
  }
}

int main(){
  int i, n, j, p, numfails;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  numfails = 0;

  struct gameState G;

  printf ("Testing Adventurer.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.whoseTurn = p;
    G.playedCardCount = 0;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_DECK);
    for(j = 0; j < G.discardCount[p]; j++){
      int cardval = floor(Random() * 27);
      G.discard[p][j] = cardval;
    }
    for(j = 0; j < G.deckCount[p]; j++){
      int cardval = floor(Random() * 10);
      G.deck[p][j] = cardval;
    }
    G.hand[p][G.handCount[p]-1] = adventurer;
    checkAdventurerCard(p, &G, &numfails, n);
  }

  if(numfails == 0)
    printf ("ALL TESTS PASSED\n");
  return 0;
}
