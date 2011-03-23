#include <stdlib.h>

typedef struct _State {
  int nt; // Number of transitions.
  char name;
  struct _State **trans;
}State;

typedef struct _Automaton {
  int mt; // Maximum number of transitions.
  State **state;
}Automaton;

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

int main(void) {
  State *init = makeState('a'),
        *b = makeState('b');
  /*addtrans(init, b);
  addtrans(init, b);
  addtrans(b, init);*/
  delState(b);
  delState(init);
  return 0;
}
