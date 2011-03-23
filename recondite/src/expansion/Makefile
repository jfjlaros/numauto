CC = gcc
CFLAGS = -Wall -ggdb

EXEC = expansion
MAIN = expansion.c
OBJS = ../autom/base.o

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
