#include "../automaton/automaton.h"

#define IM 32
#define FP_MAX 1280

void expand(int[], int, int[], int),
     autoexpand(int[], int, int[], State *, int);
char autoexpand2(int *, int, int *, State *);
