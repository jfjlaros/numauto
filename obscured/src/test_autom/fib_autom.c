#include <stdio.h>
#include <stdlib.h>
#include "fib.h"

State *f(void) {
  State *s1 = makestate('a', 2),
        *s2 = makestate('b', 2),
        *s3 = makestate('f', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s1; // b -> a

  s2->transition[1] = s3; // garbage
  s3->transition[0] = s3; // garbage
  s3->transition[1] = s3; // garbage

  return s1;
}//f

State *f2(void) {
  State *s1 = makestate('a', 2),
        *s2 = makestate('b', 2),
        *s3 = makestate('c', 2),
        *s4 = makestate('f', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s1; // b -> ac
  s2->transition[1] = s3;
  s3->transition[0] = s2; // c -> b (c -> a is also allowed)

  s3->transition[1] = s4; // garbage
  s4->transition[0] = s4; // garbage
  s4->transition[1] = s4; // garbage

  return s1;
}//f

State *f3(void) {
  State *s1 = makestate('a', 2),
        *s2 = makestate('b', 2),
        *s3 = makestate('c', 2),
        *s4 = makestate('d', 2),
        *s5 = makestate('f', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s1; // b -> ac
  s2->transition[1] = s3;
  s3->transition[0] = s2; // c -> bd
  s3->transition[1] = s4;
  s4->transition[1] = s3; // d -> c

  s4->transition[0] = s5; // garbage
  s5->transition[0] = s5; // garbage
  s5->transition[1] = s5; // garbage

  return s1;
}//f

State *f_reverse(void) {
  State *s0 = makestate('i', 2),
        *s1 = makestate('a', 2),
        *s2 = makestate('a', 2),
        *s3 = makestate('b', 2),
        *s4 = makestate('b', 2),
        *s5 = makestate('b', 2),
        *s6 = makestate('f', 2);
  s0->transition[0] = s1;
  s0->transition[1] = s3;
  s1->transition[0] = s1;
  s1->transition[1] = s2;
  s2->transition[0] = s1;
  s2->transition[1] = s6; // garbage
  
  s3->transition[0] = s4;
  s3->transition[1] = s6; // garbage
  s4->transition[0] = s4;
  s4->transition[1] = s4;
  s5->transition[0] = s4;
  s5->transition[1] = s6; // garbage
  s6->transition[0] = s6; // garbage
  s6->transition[1] = s6; // garbage

  return s0;
}//f_reverse

void test_automaton(State *transitions(void), int test) {
  State *automaton = make_automaton(transitions);
  int i;

  for (i = 0; i < test; i++) 
    f3_automaton(automaton, i);
  printf("\n");
  del_automaton(automaton);
}//test_automaton

void test_automaton_reverse(State *transitions(void), int test) {
  State *automaton = make_automaton(transitions);
  int i;

  for (i = 0; i < test; i++)
    fib_automaton_reverse(automaton, i);
  printf("\n");
  del_automaton(automaton);
}//test_automaton

int main(void) {
  //printf("Fibonacci:\n");
  test_automaton(f3, 100);
  //printf("\nFibonacci (reverse):\n");
  //test_automaton_reverse(f_reverse, 70);

  return 0;
}//main
