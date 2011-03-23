CC = gcc
CFLAGS = -Wall -ggdb

EXEC = sequence
MAIN = sequence.c
OBJS = input/input.o automaton/automaton.o expansion/expansion.o 

all: $(EXEC)

.cc.o:
	$(CC) $(CFLAGS) -c $<
	
$(EXEC): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

release: $(EXEC) clean
	strip $(EXEC)

clean:
	rm -f $(OBJS) core

realclean: clean
	rm -f $(EXEC)
