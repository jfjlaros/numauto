#include <stdio.h>
#include <stdlib.h>
#include "input/input.h"
#include "expansion/expansion.h"

extern int max_subst_length,
           numberofsubsts;

void printseq(int *seq, int i) {
  int j;

  for (j = 0; j < i; j++)
    printf("%i ", seq[j]);
  printf("\n");
}//printseq

char general_automaton(State *automaton, int number, int *sequence) {
  int result[IM];
  char c = autoexpand2(result, number, sequence, automaton);

  //printf("%c", c);
  return c;
}//general_automaton

char *dosubst(map *sigma, int size) {
  char *fixedpoint = malloc(size * sizeof(int)); 
  int i = 0,
      j = 0,
      k,
      l;

  fixedpoint[0] = sigma[0].name;
  while (j < size) 
    for (k = 0; k < numberofsubsts; k++) 
      if (fixedpoint[i] == sigma[k].name) {
        for (l = 0; sigma[k].image[l] != -1; l++) {
          fixedpoint[j] = sigma[sigma[k].image[l]].name;
          j++;
        }//for
        i++;
      }//if

  return fixedpoint;
}//dosubst

int main(void) {
  int error = 0,
      i;

  map *sigma = build();
  char *fixedpoint = dosubst(sigma, 640),
       temp;
  int **matrix = analize(sigma),
      *sequence = genseq(matrix, 20);
  State **a = build_automaton(sigma);

  printf("\nThe matrix:\n");
  printmatrix(matrix);
  printf("\nk = %i\n\nThe fixed point:\n", max_subst_length);
  for (i = 0; i < 640; i++) {
    temp = general_automaton(a[0], i, sequence);
    if (temp != fixedpoint[i]) {
      error = 1;
      if (temp != 'x')
        printf("X");
      else
        printf("x");
    }//if
    else
      printf("%c", temp);
  }//for
  printf("\n");
  ddd_autom(a);
  delmatrix(matrix);
  destroy(sigma);

  printf("\nThe numeration system:\n");
  printseq(sequence, 20);
  free(sequence);
  if (error)
    printf("\nOne or more errors occured.\n"
           " x means that the expansion was invalid.\n"
           " X means that the fixed points did not match.\n");
  return 0;
}
