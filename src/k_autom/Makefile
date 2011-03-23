CC = gcc
CFLAGS = -Wall -O3

EXEC = k_autom
MAIN = k_autom.c
OBJS = k.o ../autom/automaton.o ../autom/base.o

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
