#include <stdio.h>
#include "../autom/base.h"
#include "../autom/automaton.h"

void expand(int result[IM], int number, int seq[IM], int k) {
  int i = 0,
      j;

  for (j = 0; j < IM; j++)
    result[j] = 0;

  while (seq[i] * (k - 1) < number)
    i++;
  while (i + 1) {
    for (j = k - 1; j; j--)
      if (number - j * seq[i] >= 0) {
        result[i] = j;
        number -= j * seq[i];
        //break;
      }//if
    i--;
  }//while
  if (number)
    printf("SERIOUS ERROR!\n");
}//expand

void autoexpand(int result[IM], int number, int seq[IM], State *automaton, int k) {
  int i = 0,
      j;

  for (j = 0; j < IM; j++)
    result[j] = 0;

  while (seq[i] * (k - 1) < number)
    i++;
  while (i + 1) {
    for (j = k - 1; j; j--)
      if (number - j * seq[i] >= 0) {
        result[i] = j;
        number -= j * seq[i];
        //break;
      }//if
    i--;
  }//while
}//autoexpand

/*
int main(void) {
  int seq[IM] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610},
      result[IM],
      i;
  
  for (i = 0; i < 100; i++) {
    expand(result, i, seq, 2);
    printstring(result);
  }//for

  return 0;
}//main*/
