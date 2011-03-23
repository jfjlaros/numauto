#include <stdio.h>
#include "input.h"

int main(void) {
  map *sigma = build();
  int **matrix = analize(sigma);

  printf("\nSymbolic:\n");
  print_s(sigma);
  printf("\nNormalized:\n");
  print_n(sigma);
  printf("\nRecurrent:\n");
  printmatrix_s(sigma, matrix);
  printf("\nMatrix:\n");
  printmatrix(matrix);
  printf("\nIteration:\n");
  iterate(matrix, 10, printrow);
  printf("\nSequence:\n");
  iterate(matrix, 15, printrow_m);
  printf("\n");

  delmatrix(matrix);
  destroy(sigma);

  return 0;
}//main
