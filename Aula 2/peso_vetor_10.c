#include <stdio.h>
#include <stdlib.h>

// Programa que armazena a idade, o peso e a altura de 10 pessoas
// Após armazenados, informar quantos estão com o peso acima da média neste grupo

int main() {

  struct Dados {
    int idade;
    float peso, altura;
  };
  struct Dados pessoa[10];

  int x, qtd_peso = 0, c = 0;
  float media = 0.0, soma = 0.0;

  for (x = 0; x < 10; x++) {
    printf("Informe a idade, a altura e o peso da pessoa %d: ", x + 1);
    scanf_s("%d %f %f", &pessoa[x].idade, &pessoa[x].altura, &pessoa[x].peso);
    while ((c = getchar()) != '\n' && c != EOF) {}
    soma = soma + pessoa[x].peso;
  }

  media = soma / 10;

  for (x = 0; x < 10; x++) {
    if (pessoa[x].peso > media) {
      qtd_peso++;
    }
  }

  printf("\nQuantidade de pessoas com o peso acima da media (%.2f): %d\n\n", media, qtd_peso);
  system("pause");
  return 0;
}