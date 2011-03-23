#include <stdio.h>
#include "base_fib.h"

//const int seq[] = {1, 2, 4, 7, 13, 23, 42, 75, 136, 244};
const int seq[] = {1, 2, 4, 7, 13, 23, 42, 75, 136, 244, 441, 793, 1431, 2576, 4645, 8366};
//const int seq2[] = {1, 2, 4, 8, 15, 29, 54, 103};
const int seq2[] = {1, 2, 4, 8, 15, 29, 54, 103, 192, 364, 680, 1285, 2405, 4536, 8501, 16014};

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

void base_f2_exp(int result[IM], int number) {
  int i = 0;

  while (seq[i] < number)
    i++;
  while (i + 1) {
    if (number - seq[i] >= 0) {
      result[i] = 1;
      number -= seq[i];
    }
    i--;
  }
}

void base_f3_exp(int result[IM], int number) {
  int i = 0;

  while (seq2[i] < number)
    i++;
  while (i + 1) {
    if (number - seq2[i] >= 0) {
      result[i] = 1;
      number -= seq2[i];
    }
    i--;
  }
}
