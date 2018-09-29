#include <stdio.h>
#include <stdlib.h>

// Programa que recebe três lados de um triângulo e exibe o tipo correspondente deste triangulo
// Tipos: Equilatero, Escaleno ou Isosceles

int main() {
  int lado1, lado2, lado3, c = 0;
  
  printf("Digite o lado 1 do triangulo: ");
  scanf_s("%d", &lado1);
  while ((c = getchar()) != '\n' && c != EOF) {}
  printf("Digite o lado 2 do triangulo: ");
  scanf_s("%d", &lado2);
  while ((c = getchar()) != '\n' && c != EOF) {}
  printf("Digite o lado 3 do triangulo: ");
  scanf_s("%d", &lado3);
  while ((c = getchar()) != '\n' && c != EOF) {}
  system("cls");

  if ((lado1 < (lado2 + lado3)) && (lado2 < (lado1 + lado3)) && (lado3 < (lado1 + lado2))) {
    if ((lado1 == lado2) && (lado2 == lado3)) {
      printf("Triangulo Equilatero");
    }
    else {
      if ((lado1 != lado2) && (lado2 != lado3) && (lado3 != lado1)) {
        printf("Triangulo Escaleno");
      }
      else {
        printf("Triangulo Isosceles");
      }
    }
  }
  else {
    printf("Os valores informados nao correspondem a um triangulo");
  }

  printf("\n\n");
  system("pause");
  return 0;
}