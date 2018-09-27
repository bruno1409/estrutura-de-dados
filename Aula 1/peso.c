#include <stdio.h>
#include <stdlib.h>

// Programa que recebe o peso de 30 pessoas e informa a média dos pesos, o maior peso e o menor peso

int main() {
  float peso, media = 0, soma = 0, maior = 0, menor = 1000;
  int x, c = 0;

  for (x = 1; x <= 30; x++) {
    printf("Informe o peso %d: ", x);
    scanf_s("%f", &peso);
    while ((c = getchar()) != '\n' && c != EOF) {}
    system("cls");

    soma = soma + peso;

    if (peso > maior) {
      maior = peso;
    }

    if (peso < menor) {
      menor = peso;
    }
  }

  media = soma / 30;
  system("cls");
  printf("Media: %.2f\n\n", media);
  printf("Maior peso: %.2f\n\n", maior);
  printf("Menor peso: %.2f\n\n", menor);
  system("pause");
  return 0;
}