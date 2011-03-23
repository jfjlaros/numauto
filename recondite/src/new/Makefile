CC = gcc
CFLAGS = -Wall -ggdb

EXEC = test
MAIN = automaton.c
OBJS = 

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
