CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS)

runcardtest1: cardtest1
	cardtest1 &> cardtest1result.out
	gcov dominion.c >> cardtest1result.out
	cat dominion.c.gcov >> cardtest1result.out

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.c rngs.c $(CFLAGS)

runcardtest2: cardtest2
	./cardtest2 &> cardtest2result.out
	gcov dominion.c >> cardtest2result.out
	cat dominion.c.gcov >> cardtest2result.out

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.c rngs.c $(CFLAGS)

runcardtest3: cardtest3
	cardtest3 &> cardtest3result.out
	gcov dominion.c >> cardtest3result.out
	cat dominion.c.gcov >> cardtest3result.out

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.c rngs.c $(CFLAGS)

runcardtest4: cardtest4
	cardtest4 &> cardtest4result.out
	gcov dominion.c >> cardtest4result.out
	cat dominion.c.gcov >> cardtest4result.out

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.c rngs.c $(CFLAGS)

rununittest1: unittest1
	unittest1 &> unittest1result.out
	gcov dominion.c >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.c rngs.c $(CFLAGS)

rununittest2: unittest2
	unittest2 &> unittest2result.out
	gcov dominion.c >> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.c rngs.c $(CFLAGS)

rununittest3: unittest3
	unittest3 &> unittest3result.out
	gcov dominion.c >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.c rngs.c $(CFLAGS)

rununittest4: unittest4
	unittest4 &> unittest4result.out
	gcov dominion.c >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out

unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS)
	gcc -o cardtest2 -g cardtest2.c dominion.c rngs.c $(CFLAGS)
	gcc -o cardtest3 -g cardtest3.c dominion.c rngs.c $(CFLAGS)
	gcc -o cardtest4 -g cardtest4.c dominion.c rngs.c $(CFLAGS)
	gcc -o unittest1 -g unittest1.c dominion.c rngs.c $(CFLAGS)
	gcc -o unittest2 -g unittest2.c dominion.c rngs.c $(CFLAGS)
	gcc -o unittest3 -g unittest3.c dominion.c rngs.c $(CFLAGS)
	gcc -o unittest4 -g unittest4.c dominion.c rngs.c $(CFLAGS)
	cardtest1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	cardtest2 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	cardtest3 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	cardtest4 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	unittest1 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	unittest2 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	unittest3 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	unittest4 &>> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer rngs.c dominion.c randomtestadventurer.c $(CFLAGS)
	randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 rngs.c dominion.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 rngs.c dominion.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 &> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
