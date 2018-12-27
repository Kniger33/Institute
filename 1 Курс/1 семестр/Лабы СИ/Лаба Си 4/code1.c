#include <stdio.h>

int main() {
  int num = 1;
  int *pointer_int = &num;
  printf("Before change: %x, value: %d\n", pointer_int, *pointer_int);
  pointer_int++;
  printf("After change: %x, value: %d\n", pointer_int, *pointer_int);
  
  char character = 'X';
  char *pointer_char = &character;
  printf("Before change: %x, value: %c\n", pointer_char, *pointer_char);
  pointer_char++;
  printf("After change: %x, value: %c\n", pointer_char, *pointer_char);
  
  double drob = 2.0;
  double *pointer_double = &drob;
  printf("Before change: %x, value: %.2lf\n", pointer_double, *pointer_double);
  pointer_double++;
  printf("After change: %x, value: %.2lf\n", pointer_double, *pointer_double);
  
  float vecsh = 7.5;
  float *pointer_float = &vecsh;
  printf("Before change: %x, value: %f\n", pointer_float, *pointer_float);
  pointer_float++;
  printf("After change: %x, value: %f\n", pointer_float, *pointer_float);
  
  long length = 79;
  long *pointer_long = &length;
  printf("Before change: %x, value: %l\n", pointer_long, *pointer_long);
  pointer_long++;
  printf("After change: %x, value: %l\n", pointer_long, *pointer_long);
  
  return 0;
}
