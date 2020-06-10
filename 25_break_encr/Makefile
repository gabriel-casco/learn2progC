CC=gcc
CFLAGS=-Wall -Werror -pedantic -std=gnu99 -Wsign-compare -Wwrite-strings -Wtype-limits -fsanitize=address

breaker: breaker.c
	$(CC) -o breaker $(CFLAGS) breaker.c

.PHONY: clean
clean:
	rm -f breaker *.o *.c~ Makefile~
