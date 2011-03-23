#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define IN_LEN 20
#define S_STR "%19s"

int numberofsubsts = 0,
    max_subst_length = 0;


map *build(void) {
  char *images = malloc(sizeof(char)),
       input[IN_LEN];
  map *sigma = malloc(sizeof(map));
  int j,
      k,
      l;

  fscanf(stdin, S_STR, input);
  while (!feof(stdin)) {
    if (input[1] != '>') {
      printf("Error in input.\n");
      free(images);
      free(sigma);
      return NULL;
    }//if
    images = realloc(images, (numberofsubsts + 1) * IN_LEN * sizeof(char));
    sigma = realloc(sigma, (numberofsubsts + 1) * sizeof(map));
    
    sigma[numberofsubsts].name = input[0];
    sigma[numberofsubsts].number = numberofsubsts;
    for (j = 0; input[j + 2] != '\0'; j++)   // Copy the images for forward
      images[numberofsubsts * IN_LEN + j] = input[j + 2]; // scanning.
    images[numberofsubsts * IN_LEN + j + 1] = '\0';
    if (j > max_subst_length)
      max_subst_length = j;

    fscanf(stdin, S_STR, input);
    numberofsubsts++;
  }//while
  if (numberofsubsts > 9) {
      printf("Substitution scheme too large.\n");
      free(images);
      free(sigma);
      return NULL;
    }//if
  for (j = 0; j < numberofsubsts; j++) { // Set the images.
    sigma[j].image = malloc(sizeof(int));
    for (k = 0; images[j * IN_LEN + k] != '\0'; k++) {
      sigma[j].image = realloc(sigma[j].image, (k + 2) * sizeof(int));
      for (l = 0; l <= numberofsubsts; l++)
        if (images[j * IN_LEN + k] == sigma[l].name)
          sigma[j].image[k] = l;
       sigma[j].image[k + 1] = -1;
    }//for
  }//for
  free(images);
  return sigma;
}//build

void destroy(map *sigma) {
  int j;

  for (j = 0; j < numberofsubsts; j++)
    free(sigma[j].image);
  free(sigma);
}//destroy

void print_n(map *sigma) {
  int j,
      k;

  for (j = 0; j < numberofsubsts; j++) { // Print the substitution scheme.
    printf("%i -> ", sigma[j].number);
    for (k = 0; sigma[j].image[k] != -1; k++) 
      printf("%i", sigma[j].image[k]);
    printf("\n");
  }//for
}//print_n

void print_s(map *sigma) {
  int j,
      k;

  for (j = 0; j < numberofsubsts; j++) { // Print the symbolic scheme.
    printf("%c -> ", sigma[j].name);
    for (k = 0; sigma[j].image[k] != -1; k++) 
      printf("%c", sigma[sigma[j].image[k]].name);
    printf("\n");
  }//for
}//print_s

int **analize(map *sigma) {
  int **matrix = malloc(numberofsubsts * sizeof(int *)),
      j,
      k,
      l,
      m;

  for (j = 0; j < numberofsubsts; j++)
    matrix[j] = malloc(numberofsubsts * sizeof(int));

  for (j = 0; j < numberofsubsts; j++) {
    for (k = 0; k < numberofsubsts; k++) {
      m = 0;
      for (l = 0; sigma[k].image[l] != -1; l++)
        if (j == sigma[k].image[l])
          m++;
      matrix[j][k] = m;
    }//for
  }//for
  return matrix;
}//analize

void delmatrix(int **matrix) {
  int j;

  for (j = 0; j < numberofsubsts; j++)
    free(matrix[j]);
  free(matrix);
}//delmatrix

void printmatrix_s(map *sigma, int **matrix) {
  int j,
      k;

  for (j = 0; j < numberofsubsts; j++) {
    printf("%c_n = ", sigma[j].name);
    for (k = 0; k < numberofsubsts; k++) {
      if (k)
        printf(" + ");
      printf("%i %c_{n - 1}", matrix[j][k], sigma[k].name);
    }//for
    printf("\n");
  }//for
}//printmatrix_s

void printmatrix(int **matrix) {
  int j,
      k;

  for (j = 0; j < numberofsubsts; j++) {
    for (k = 0; k < numberofsubsts; k++) 
      printf("%i ", matrix[j][k]);
    printf("\n");
  }//for
}//printmatrix

void resetrow(int *row) {
  int j;

  for (j = 0; j < numberofsubsts; j++)
    row[j] = 0;
}//resetrow

void printrow(int *row) {
  int j,
      k = 0;

  for (j = 0; j < numberofsubsts; j++) {
    printf("%i ", row[j]);
    k += row[j];
  }//for
  printf("-> %i\n", k);
}//printrow

void printrow_m(int *row) {
  int j,
      k = 0;

  for (j = 0; j < numberofsubsts; j++)
    k += row[j];
  printf("%i ", k);
}//printrow_m

void iterate(int **matrix, int t, void func(int *)) {
  int *a = malloc(numberofsubsts * sizeof(int)),
      *b = malloc(numberofsubsts * sizeof(int)),
      *c,
      j,
      k,
      l;

  resetrow(a);
  a[0] = 1;
  func(a);
  for (l = 0; l < t; l++) {
    resetrow(b);
    for (j = 0; j < numberofsubsts; j++)
      for (k = 0; k < numberofsubsts; k++) 
        b[j] += a[k] * matrix[j][k];
    func(b);
    c = a;
    a = b;
    b = c;
  }//for
  free(b);
  free(a);
}//iterate

int *genseq(int **matrix, int t) {
  int *a = malloc(numberofsubsts * sizeof(int)),
      *b = malloc(numberofsubsts * sizeof(int)),
      *r = malloc(sizeof(int)),
      *c,
      j,
      k,
      l;

  resetrow(a);
  a[0] = 1;
  r[0] = 1;
  for (l = 1; r[l - 1] < t; l++) {
    r = realloc(r, (l + 1) * sizeof(int));
    resetrow(b);
    for (j = 0; j < numberofsubsts; j++)
      for (k = 0; k < numberofsubsts; k++) 
        b[j] += a[k] * matrix[j][k];
    r[l] = 0;
    for (k = 0; k < numberofsubsts; k++)
      r[l] += b[k];
    c = a;
    a = b;
    b = c;
  }//for
  free(b);
  free(a);

  return r;
}//genseq

State **build_automaton(map *sigma) {
  State **a = malloc((numberofsubsts + 1) * sizeof(State *));
  int i,
      j;

  for (i = 0; i < numberofsubsts; i++)
    a[i] = makeState(sigma[i].name);
  a[numberofsubsts] = NULL;

  for (i = 0; i < numberofsubsts; i++)
    for (j = 0; sigma[i].image[j] != -1; j++)
      addtrans(a[i], a[sigma[i].image[j]]);

  return a;
}//build_automaton

void ddd_autom(State **a) {
  int i;

  for (i = 0; i < numberofsubsts; i++)
    delState(a[i]);
  if (a[numberofsubsts])
    delState(a[numberofsubsts]);
  free(a);
}//ddd_autom
