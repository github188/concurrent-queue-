CC = gcc
# CFLAGS = -m32 -Wa -g


test: test.c
	$(CC)  -o -D twolock test $(CFLAGS) test.c twolock.c -lpthread

test.s: test.c
	$(CC) -S -fverbose-asm $(CFLAGS) test.c

clean:
	rm test
