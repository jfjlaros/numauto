#include <stdlib.h>

int *makearray(int size) {
  int *a = malloc((size + 1) * sizeof(int));

  a[0] = size;
  return &a[1];
}//makearray

void resizearray(int *a, int size) {
  int *b = &a[-1];

  b = realloc(&a[-1], (size + 1) * sizeof(int));
  b[0] = size;
}//resizearray

void delarray(int *a) {
  free(&a[-1]);
}//delarray

int main(void) {
  int *a = makearray(2);
  a[0] = 1;
  a[1] = 2;

  printf("%i\n", a[-1]);
  printf("%i\n", a[0]);
  printf("%i\n", a[1]);
  resizearray(a, 3);
  a[2] = 3;
  printf("%i\n", a[2]);
  printf("%i\n", a[-1]);
  delarray(a);
  return 0;
}
