#include <stdio.h>
#include <stdlib.h>
#include "k.h"

State *ab_star(void) {
  State *s1 = makestate('a', 2),
        *s2 = makestate('b', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s1; // a -> ab
  s2->transition[1] = s2;

  return s1;
}//ab_star

State *ab_star_reverse(void) {
  State *s0 = makestate('i', 2),
        *s1 = makestate('a', 2),
        *s2 = makestate('b', 2);
  s0->transition[0] = s1; // ab^N
  s0->transition[1] = s2;
  s1->transition[0] = s1; // a^N
  s1->transition[1] = s1;
  s2->transition[0] = s2; // b^N
  s2->transition[1] = s2;

  return s0;
}//ab_star_reverse

State *thue_morse(void) {
  State *s1 = makestate('a', 2),
        *s2 = makestate('b', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s2; // b -> ba
  s2->transition[1] = s1;

  return s1;
}//thue_morse

State *cantor(void) {
  State *s1 = makestate('a', 3),
        *s2 = makestate('b', 3);
  s1->transition[0] = s1; // a -> aba
  s1->transition[1] = s2;
  s1->transition[2] = s1;
  s2->transition[0] = s2; // b -> bbb
  s2->transition[1] = s2;
  s2->transition[2] = s2;

  return s1;
}//cantor

State *rudin_shapiro(void) {
  State *s1 = makestate('+', 2),
        *s2 = makestate('+', 2),
        *s3 = makestate('-', 2),
        *s4 = makestate('-', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s1; // b -> ac
  s2->transition[1] = s3;
  s3->transition[0] = s4; // c -> db
  s3->transition[1] = s2;
  s4->transition[0] = s4; // d -> dc
  s4->transition[1] = s3;

  return s1;
}//rudin_shapiro

State *baum_sweet(void) {
  State *s1 = makestate('1', 2),
        *s2 = makestate('1', 2),
        *s3 = makestate('0', 2),
        *s4 = makestate('0', 2);
  s1->transition[0] = s1; // a -> ab
  s1->transition[1] = s2;
  s2->transition[0] = s3; // b -> cb
  s2->transition[1] = s2;
  s3->transition[0] = s2; // c -> bd
  s3->transition[1] = s4;
  s4->transition[0] = s4; // d -> dd
  s4->transition[1] = s4;

  return s1;
}//baum_sweet

void test_automaton(State *transitions(void), int test) {
  State *automaton = make_automaton(transitions);
  int i;

  for (i = 0; i < test; i++) 
    k_automaton(automaton, i);
  printf("\n");
  del_automaton(automaton);
}//test_automaton

void test_automaton_reverse(State *transitions(void), int test) {
  State *automaton = make_automaton(transitions);
  int i;

  for (i = 0; i < test; i++)
    k_automaton_reverse(automaton, i);
  printf("\n");
  del_automaton(automaton);
}//test_automaton

int main(void) {
  printf("ab*:\n");
  test_automaton(ab_star, 12);
  printf("\nab* (reverse):\n");
  test_automaton_reverse(ab_star_reverse, 12);
  printf("\nThue-Morse:\n");
  test_automaton(thue_morse, 12);
  printf("\nThue-Morse (reverse):\n");
  test_automaton_reverse(thue_morse, 12);
  printf("\nCantor:\n");
  test_automaton(cantor, 12);
  printf("\nCantor (reverse):\n");
  test_automaton_reverse(cantor, 12);
  printf("\nRudin-Shapiro:\n");
  test_automaton(rudin_shapiro, 70);
  printf("\nBaum-Sweet:\n");
  test_automaton(baum_sweet, 70);

  return 0;
}//main
