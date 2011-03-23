#include <stdio.h>
#include "expansion.h"

void expand(int result[IM], int number, int seq[IM], int k) {
  int i = 0,
      j;

  for (j = 0; j < IM; j++)
    result[j] = 0;

  while (seq[i] * (k - 1) <= number)
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
    printf("serious error!\n");
}//expand

void autoexpand(int result[IM], int number, int seq[IM], State *automaton, int k) {
  State *s = automaton;
  int i = 0,
      j;

  for (j = 0; j < IM; j++)
    result[j] = 0;

  //while (seq[i] * (s->nt - 1) <= number) // This line needs some work...
  while (seq[i] <= number) // This line needs some work...
    i++;
  while (i + 1) {
    for (j = s->nt - 1; j; j--)
      if (number - j * seq[i] >= 0) {
        result[i] = j;
        number -= j * seq[i];
        break;
      }//if
    s = s->trans[j];
    i--;
  }//while
  if (number)
    printf("X");
  else
    printf("%c", s->name);
  fflush(stdout);
}//autoexpand

char autoexpand2(int result[IM], int number, int seq[IM], State *automaton) {
  State *s = automaton;
  int i = 0,
      j;

  for (j = 0; j < IM; j++)
    result[j] = 0;

  while (seq[i] * (s->nt - 1) <= number) // This line needs some work...
    i++;
  while (i + 1) {
    for (j = s->nt - 1; j; j--)
      if (number - j * seq[i] >= 0) {
        result[i] = j;
        number -= j * seq[i];
        break;
      }//if
    s = s->trans[j];
    i--;
  }//while
  if (number)
    return 'X';
  return s->name;
}//autoexpand
