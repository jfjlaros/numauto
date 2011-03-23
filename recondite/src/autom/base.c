#include <stdio.h>
#include "base.h"

// Makes a string of the number in base k.
// Make sure 1 < base.
void base_k_expansion(int result[IM], int number, int base) {
  int i;

  for (i = 0; i < IM; i++) { // Calculate the base_k expantion of number.
    result[i] = number % base;
    number /= base;
  }//while
}//base_k_expansion

// Print a number in base k.
// Make sure base < 37.
void printstring(int result[IM]) {
  int i = IM - 1;

  while ((!result[i]) && i) // Strip the leading zeros.
    i--;
  while (i + 1) {
    if (result[i] > 9)      // Use the alphabet for numbers > 9.
      printf("%c", (char)(result[i] + 55));
    else
      printf("%i", result[i]);
    i--;
  }//while
  printf("\n");
}//printstring
