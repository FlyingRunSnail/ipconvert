target = test

all:test.o
	gcc -o $(target) test.c -Wall -Werror -g

.PHONY:clean

clean:
	rm -f test
	rm -f *.o
