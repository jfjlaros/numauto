#include "../automaton/automaton.h"

typedef struct _map {
  char name;
  int number,
      *image;
}map;//map

State **build_automaton(map *);
map *build(void);
int **analize(map *),
    *genseq(int **, int);
void destroy(map *),
     print_n(map *),
     print_s(map *),
     delmatrix(int **),
     printmatrix_s(map *, int **),
     printmatrix(int **),
     ddd_autom(State **),
     iterate(int **, int, void (int *));
