CC=gcc
CFLAGS=-Wall -std=c17

LIBS=-lrt -lm

TARGETS= readPeople writePeople testLongOpt

all: $(TARGETS)

readPeople: readPeople.c
	$(CC) $(CFLAGS) -o $@ $<

writePeople: writePeople.c
	$(CC) $(CFLAGS) -o $@ $<

testLongOpt: testLongOpt.c
	$(CC) $(CFLAGS) -o $@ $<

	
.PHONY: clean
clean:
	rm -f $(TARGETS)
