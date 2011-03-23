#include <stdlib.h>
#include "automaton.h"

// Constructor for State.
State *makestate(char name, int numberoftransitions) { 
  State *S = malloc(sizeof(State));

  S->name = name;
  S->numberoftransitions = numberoftransitions;
  S->transition = malloc(numberoftransitions * sizeof(State));

  return S;
}//makestate

// Destructor for State.
void delstate(State *S) { 
  free(S->transition); 
  free(S); 
}//delstate

// Constructor for automaton.
State *make_automaton(State *transitions(void)) { 
  State *automaton = transitions(); 

  return automaton;
}//make_automaton

// Destructor for automaton.
void del_automaton(State *S) {
   int i;

   if (S->name == '\0')
     return;
   S->name = '\0';
   for (i = 0; i < S->numberoftransitions; i++)
     del_automaton(S->transition[i]);
   delstate(S);
}//del_automaton
