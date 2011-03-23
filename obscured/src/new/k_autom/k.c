#include <stdio.h>
#include <stdlib.h>
#include "../autom/base.h"
#include "k.h"

// Feed the automaton with number and read it's final state.
void k_automaton(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  base_k_expansion(result, number, S->numberoftransitions);
  
  for (i = IM; i; i--) 
    S = S->transition[result[i - 1]];
  printf("%c", S->name);
}//k_automaton

// Feed the automaton with number and read it's final state.
void k_automaton_reverse(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  base_k_expansion(result, number, S->numberoftransitions);
  
  for (i = 0; i < IM; i++) 
    S = S->transition[result[i]];
  printf("%c", S->name);
}//k_automaton_reverse
