#include <stdlib.h>
#include "automaton.h"

// Constructor for State.
State *makestate(char name, int numberoftransitions) { 
  State *S = malloc(sizeof(State));

  printf("++ %x\n", S);
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
   int i,
       j,
       done;
   char t = S->name;

   if (S->name == '\0')
     return;
//   printf("%c %i ", S->name, S->numberoftransitions);
   S->name = '\0';
   for (i = 0; i < S->numberoftransitions; i++) {
     printf("Deleting %c[%i]\n", t, i);
     done = 0;
     for (j = 0; j < i; j++)
       if (S->transition[j] == S->transition[i])
         done = 1;
     if (!done)
       del_automaton(S->transition[i]);
   }
   printf("-- %c\n", t);
   delstate(S);
}//del_automaton
