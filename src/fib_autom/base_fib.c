#include <stdio.h>
#include "base_fib.h"

// Print the base fibonacci of number.
void fib(int *number, int i, int j, int result[IM], int k) {
  if (i > *number)
    return;
  fib(number, j, i + j, result, k + 1);
  if (*number - i >= 0) {
    result[k] = 1; 
    *number -= i;
  }//if
  else 
    result[k] = 0; 
}//fib

void base_fib_expansion(int result[IM], int number) {
  int i;

  for (i = 0; i < IM; i++)
    result[i] = 0;
  fib(&number, 1, 2, result, 0);
}//testfib
