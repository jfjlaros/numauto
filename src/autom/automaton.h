#ifndef AUTOMATON
typedef struct _State {
  char name;
  int numberoftransitions;
  struct _State **transition;
}State;//State
#define AUTOMATON
#endif

State *makestate(char, int),               // Constructor for State.
      *make_automaton(State *(void));      // Constructor for automaton.
void delstate(State *),                    // Destructor for State.
     del_automaton(State *);               // Destructor for automaton.
