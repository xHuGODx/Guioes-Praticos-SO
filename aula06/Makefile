CC=gcc
CFLAGS=-Wall -std=c17

LIBS=-lrt -lm

TARGETS= myCat myActions dirList sortNumbers

all: $(TARGETS)

myCat: myCat.c
	$(CC) $(CFLAGS) -o $@ $<

myActions: myActions.c
	$(CC) $(CFLAGS) -o $@ $<

dirList: dirList.c
	$(CC) $(CFLAGS) -o $@ $<

sortNumbers: sortNumbers.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

.PHONY: clean
clean:
	rm -f $(TARGETS)
