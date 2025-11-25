/*
 * Classic algorithm showcasing dynamic programming converting a naive exponential into linear behavior (with linear extra memory)
 */

#include <stdio.h>

#define SIZE 42

int naive_fib(int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  return naive_fib(n-2) + naive_fib(n-1);
}

int fib(int n) {
  int buff[n+1];
  
  buff[0] = 0;
  buff[1] = 1;
  // Linear time in n
  for (int i = 2; i < n+1; ++i) {
    buff[i] = buff[i-2]+buff[i-1];
  }
  return buff[n]; 
}

int main() {
  
  printf("Naive version\n");
  for (int i = 0; i < SIZE; ++i) {
    printf("%d\n", naive_fib(i));
  }
  printf("Optimized version\n");
  for (int i = 0; i < SIZE; ++i) {
    printf("%d\n", fib(i));
  }

  return 0;
}
