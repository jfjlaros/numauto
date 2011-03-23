CC = gcc
CFLAGS = -Wall -ggdb

EXEC = fib_autom
MAIN = fib_autom.c
OBJS = base_fib.o fib.o ../autom/automaton.o ../autom/base.o

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
