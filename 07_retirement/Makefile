CFLAGS=-std=gnu99 -Wall -Wsign-compare -Wwrite-strings -Wtype-limits -Werror -pedantic

retirement: retirement.c
	gcc $(CFLAGS) -o retirement retirement.c

.PHONY: clean
clean:
	rm -f retirement *.o *.c~ *.h~
