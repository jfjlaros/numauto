#include <stdio.h>
#include <stdlib.h>
#include "base_fib.h"
#include "fib.h"

// Feed the automaton with number and read it's final state.
void fib_automaton(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  base_fib_expansion(result, number);
  
  for (i = IM; i; i--) 
    S = S->transition[result[i - 1]];
  printf("%c", S->name);
}//fib_automaton

// Feed the automaton with number and read it's final state.
void f2_automaton(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  for (i = 0; i < IM; i++)
    result[i] = 0;

  base_f2_exp(result, number);
//  printstring(result);
  
  for (i = IM; i; i--) 
    S = S->transition[result[i - 1]];
  printf("%c", S->name);
}//f2_automaton

void f3_automaton(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  for (i = 0; i < IM; i++)
    result[i] = 0;

  base_f3_exp(result, number);
//  printstring(result);
  
  for (i = IM; i; i--) 
    S = S->transition[result[i - 1]];
  printf("%c", S->name);
}//f2_automaton

// Feed the automaton with number and read it's final state.
void fib_automaton_reverse(State *automaton, int number) {
  State *S = automaton;
  int result[IM],
      i;
  
  base_fib_expansion(result, number);
  
  for (i = 0; i < IM; i++) 
    S = S->transition[result[i]];
  printf("%c", S->name);
}//fib_automaton_reverse
