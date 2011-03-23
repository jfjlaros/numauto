#include <stdlib.h>

#ifndef AUTOMATON
#define AUTOMATON
typedef struct _State {
  int nt; // Number of transitions.
  char name;
  struct _State **trans;
}State;

typedef struct _Automaton {
  int mt; // Maximum number of transitions.
  State **state;
}Automaton;
#endif

State *makeState(char);
void delState(State *),
     addtrans(State *, State *);
