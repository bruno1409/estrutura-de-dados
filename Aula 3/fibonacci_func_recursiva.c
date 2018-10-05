#include <stdio.h>
#include <stdlib.h>

// Programa que exibe a sequência de Fibonacci com um limite de termos informado pelo usuário
// Utilização de função recursiva

int fibonacci(int n1, int n2, int q, int max) {
  printf("%d ", n2);
  if (q == max) {
    return 0;
  } else {
    q++;
    fibonacci(n2, (n1 + n2), q, max);
    return 0;
  }
}

int main() {
  int num;
  printf("Informe o numero maximo de termos da sequencia de Fibonacci que serao exibidos: ");
  scanf_s("%d", &num);
  printf("\n");
  fibonacci(0, 1, 1, num);
  printf("\n\n");
  system("pause");
  return 0;
}