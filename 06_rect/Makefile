CFLAGS=-std=gnu99 -Wall -Wsign-compare -Wwrite-strings -Wtype-limits -Werror -pedantic

rectangle: rectangle.c
	gcc $(CFLAGS) -o rectangle rectangle.c

.PHONY: clean
clean:
	rm -f rectangle *.o *.c~ *.h~
