#include <stdio.h>

#define INPUT_MAX 200 // The length of the 'tape'.

char input[INPUT_MAX]; // The input/ouput 'tape'.
int tail = 0;          // The position of the 'write head' on the 'tape'.

void put(char c) {
  if (tail < INPUT_MAX) { // Only write back the first INPUT_MAX results.
    input[tail] = c;
    tail++;
  }//if
  printf("%c", c);        // But print them in any case.
}//put

// Substitution rules for the fibonacci sequence.
void fibonacci(int i) {
  if (input[i] == 'a') {
    put('a');
    put('b');
  }//if
  else {
    put('a');
  }//else
}//fibonacci

// Substitution rules for the tribonacci sequence.
void tribonacci(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('a');
      put('c');
      break;
    case 'c':
      put('b');
  }//switch
}//tribonacci

// Substitution rules for the fourbonacci sequence.
void fourbonacci(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('a');
      put('c');
      break;
    case 'c':
      put('b');
      put('d');
      break;
    case 'd':
      put('c');
  }//switch
}//fourbonacci

// Substitution rules for the fourbonacci sequence.
void fivebonacci(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('a');
      put('c');
      break;
    case 'c':
      put('b');
      put('d');
      break;
    case 'd':
      put('c');
      put('e');
      break;
    case 'e':
      put('d');
  }//switch
}//fourbonacci

// Substitution rules for the tribonacci sequence.
void testbon(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('a');
      put('b');
      break;
    case 'b':
      put('c');
      break;
    case 'c':
      put('a');
      put('a');
      put('c');
  }//switch
}//testbon

// Substitution rules for the morse sequence.
void morse(int i) {
  if (input[i] == 'a') {
    put('a');
    put('b');
  }//if
  else {
    put('b');
    put('a');
  }//else
}//morse

// Substitution rules for the cantor sequence.
void cantor(int i) {
  if (input[i] == 'a') {
    put('a');
    put('b');
    put('a');
  }//if
  else {
    put('b');
    put('b');
    put('b');
  }//else
}//cantor

// Substitution rules for the rudin-shapiro sequence.
void rudin_shapiro(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('a');
      put('c');
      break;
    case 'c':
      put('d');
      put('b');
      break;
    case 'd':
      put('d');
      put('c');
  }//switch
}//rudin_shapiro

// Substitution rules for the baum-sweet sequence.
void baum_sweet(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('c');
      put('b');
      break;
    case 'c':
      put('b');
      put('d');
      break;
    case 'd':
      put('d');
      put('d');
  }//switch
}//baum_sweet

// Substitution rules for a non-automatic sequence.
void non_automatic(int i) {
  switch (input[i]) {
    case 'a': 
      put('a');
      put('b');
      break;
    case 'b':
      put('c');
      put('b');
      break;
    case 'c':
      put('b');
  }//switch
}//non_automatic

// This function prints the first INPUT_MAX substitutions given a substitution 
// function and an initial symbol.
void generate(void subst(int), char initial) {
  int i = 0;

  input[0] = initial; // Put the initial symbol on the 'tape'.
  tail = 0;           // Set the 'read head' to the beginning of the 'tape'.

  for (i = 0; i < INPUT_MAX; i++) // Do the first INPUT_MAX substitutions.
    subst(i);
}//generate

int main(void) {
  printf("The fibonacci sequence.\n");
  generate(fibonacci, 'a');
  printf("\n\nThe tribonacci sequence.\n");
  generate(tribonacci, 'a');
  printf("\n\nThe fourbonacci sequence.\n");
  generate(fourbonacci, 'a');
  printf("\n\nThe fivebonacci sequence.\n");
  generate(fivebonacci, 'a');
  printf("\n\nThe morse sequence.\n");
  generate(morse, 'a');
  printf("\n\nThe cantor sequence.\n");
  generate(cantor, 'a');
  printf("\n\nThe rudin-shapiro sequence.\n");
  generate(rudin_shapiro, 'a');
  printf("\n\nThe baum-sweet sequence.\n");
  generate(baum_sweet, 'a');
  printf("\n\nThe testbon sequence.\n");
  generate(testbon, 'a');
  printf("\n\nA non-automatic sequence.\n");
  generate(non_automatic, 'a');
  printf("\n");

  return 0;
}//main
