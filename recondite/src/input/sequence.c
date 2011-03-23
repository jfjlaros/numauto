#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "../expansion/expansion.h"

extern int max_subst_length;

void printseq(int *seq, int i) {
  int j;

  for (j = 0; j < i; j++)
    printf("%i ", seq[j]);
  printf("\n");
}//printseq

void general_automaton(State *automaton, int number, int *sequence, int k) {
  State *S = automaton;
  int result[IM],
  i;

  expand(result, number, sequence, k);

  for (i = IM; i; i--)
    S = S->transition[result[i - 1]];
  printf("%c", S->name);
  if (S->name == 'z') {
    printf("\n %i: ", number);
    printstring(result);
  }
}//general_automaton

int main(void) {
  int //result[IM],
      i;

  map *sigma = build();
  int **matrix = analize(sigma);
  int *sequence = genseq(matrix, 20);
  State **a = build_automaton(sigma);

  printmatrix(matrix);
  printf("%i\n", max_subst_length);
  for (i = 0; i < 640; i++) {
  //  expand(result, i, sequence, max_subst_length);
  //  printstring(result);
    general_automaton(a[0], i, sequence, max_subst_length);
  }//for
  printf("\n");
//  del_automaton(a);
  ddd_autom(a);
  delmatrix(matrix);
  destroy(sigma);

  printseq(sequence, 20);
  free(sequence);
  return 0;
}
