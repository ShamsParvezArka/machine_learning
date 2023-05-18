CC = gcc
CFLAGS = -Wall -Wextra  -std=c11
CLIBS = -lm

output: main.c
	$(CC) -o a.out main.c $(CFLAGS) $(CLIBS)
