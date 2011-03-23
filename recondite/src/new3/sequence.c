#include <stdio.h>
#include <stdlib.h>
#include "input/input.h"
#include "expansion/expansion.h"

extern int max_subst_length,
           numberofsubsts;

void printseq(int *seq, int i, int t) {
  int j;

  for (j = 0; seq[j] < i && j < t; j++)
    printf("%i ", seq[j]);
  printf("\n");
}//printseq

void limseq(int *seq, int i, int t) {
  int j;

  for (j = 1; seq[j] < i && j < t; j++)
    printf("%f ", (float)seq[j] / seq[j - 1]);
  printf("\n");
}//limseq

char general_automaton(State *automaton, int number, int *sequence) {
  int result[FP_MAX];
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
  if (!sigma)
    return 1;
  char *fixedpoint = dosubst(sigma, FP_MAX),
       temp;
  int **matrix = analize(sigma),
      *sequence = genseq(matrix, FP_MAX);
  State **a = build_automaton(sigma);

  printf("\nThe matrix:\n");
  printmatrix(matrix);
  printf("\nk = %i\n\nThe fixed point:", max_subst_length);
//  if (sequence[19] == 20)
//    fp_max = 21;
  for (i = 0; i < FP_MAX; i++) {
    if (!(i % 80))
      printf("\n");
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
//  if (fp_max == 21)
//    printf("... (periodic).");
  printf("\n");
  ddd_autom(a);
  delmatrix(matrix);
  destroy(sigma);

  printf("\nThe numeration system:\n");
  printseq(sequence, FP_MAX, 18);
  //limseq(sequence, FP_MAX, 18);
  free(sequence);
  if (error)
    printf("\nOne or more errors occured.\n"
           " x means that the expansion was invalid.\n"
           " X means that the fixed points did not match.\n");
  return 0;
}
