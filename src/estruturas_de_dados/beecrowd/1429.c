#include <stdio.h>

int factorial(int);
int acmToDec(char *);

int main() {

  /**
   * Escreva a sua solução aqui
   * Code your solution here
   * Escriba su solución aquí
   */
  int x = 5;
  int y = factorial(x);
  printf("%d", y);
  acmToDec("719");

  printf("\n");
  return 0;
}

int factorial(int n) {
  if (n <= 1) {
    return n * factorial(n - 1);
  }
  return 1;
}

int acmToDec(char *n) {}
