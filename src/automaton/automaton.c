#include <stdlib.h>
#include "automaton.h"

State *makeState(char name) {
  State *S = malloc(sizeof(State));

  S->nt = 0;
  S->name = name;
  S->trans = NULL;

  return S;
}//makeState

void delState(State *S) {
  free(S->trans);
  free(S);
}//delState

void addtrans(State *S1, State *S2) {
  S1->nt++;
  S1->trans = realloc(S1->trans, S1->nt * sizeof(State *));
  S1->trans[S1->nt - 1] = S2;
}//addtrans
