CFLAGS = -Wall -fpic -coverage -lm -std=c99


testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

runtest: testme
	- ./testme &> randomtest.out
	gcov testme.c >> randomtest.out
	cat testme.c.gcov >> randomtest.out

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out 
