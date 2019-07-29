CFLAGS= -Wall -fpic -coverage -lm -std=c99

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

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomcardtest1: randomcardtest1.c dominion.o rngs.o
	gcc -o randomcardtest1 -g randomcardtest1.c dominion.o rngs.o $(CFLAGS)

randomcardtest2: randomcardtest2.c dominion.o rngs.o
	gcc -o randomcardtest2 -g randomcardtest2.c dominion.o rngs.o $(CFLAGS)

randomcardtest3: randomcardtest3.c dominion.o rngs.o
	gcc -o randomcardtest3 -g randomcardtest3.c dominion.o rngs.o $(CFLAGS)

randomcardresults:
	./randomcardtest1 3 &> randomcardresult.out
	gcov -b randomcardtest1.c >> randomcardresult.out
	./randomcardtest2 &> randomcardresult.out
	gcov -b randomcardtest2.c >> randcomcardresult.out
	./randomcardtest3 &> randomcardresult.out
	gcov -b randomcardtest3.c >> randomcardresult.out
	gcov -b dominion.c >> randomcardresult.out
	cat dominion.c.gcov >> randomcardresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe randomcardtest1  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
