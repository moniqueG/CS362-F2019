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

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittest-bug1 unittest-bug2 unittest-bug7 unittest-bug9

unittest-bug1: dominion.o unittest-bug1.c
	gcc -o unittest-bug1 unittest-bug1.c -g dominion.o rngs.o $(CFLAGS)

unittest-bug2: dominion.o unittest-bug2.c
	gcc -o unittest-bug2 unittest-bug2.c -g dominion.o rngs.o $(CFLAGS)

unittest-bug7: dominion.o unittest-bug7.c
	gcc -o unittest-bug7 unittest-bug7.c -g dominion.o rngs.o $(CFLAGS)

unittest-bug9: dominion.o unittest-bug9.c
	gcc -o unittest-bug9 unittest-bug9.c -g dominion.o rngs.o $(CFLAGS)

unittestresults: unittest-bug7
	./unittest-bug7 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
