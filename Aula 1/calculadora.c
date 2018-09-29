#include <stdio.h>
#include <stdlib.h>

// Programa que mostra o resultado do cálculo de dois números
// Recebe o primeiro número, depois o operador e por último o segundo número

int main() {
  int c = 0;
  float num1, num2;
  char op, continuar;
  do {
    system("cls");
    printf("Informe o primeiro numero: ");
    scanf_s("%f", &num1);
    while ((c = getchar()) != '\n' && c != EOF) {}
    system("cls");
    printf("Informe o operador: ");
    scanf_s("%c", &op, sizeof(op));
    while ((c = getchar()) != '\n' && c != EOF) {}
    system("cls");
    printf("Informe o segundo numero: ");
    scanf_s("%f", &num2);
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("\n");
    system("cls");

    switch (op) {
    case '+':
      printf("Resultado: %.2f", num1 + num2);
      break;
    case '-':
      printf("Resultado: %.2f", num1 - num2);
      break;
    case '*':
      printf("Resultado: %.2f", num1 * num2);
      break;
    case '/':
      printf("Resultado: %.2f", num1 / num2);
      break;
    }

    printf("\n\nDigite S para fazer outra operacao ou qualquer outro valor para encerrar: ");
    scanf_s("%c", &continuar, sizeof(continuar));
    while ((c = getchar()) != '\n' && c != EOF) {}
  } while (continuar == 'S' || continuar == 's');

  return 0;
}