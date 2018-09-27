#include <stdio.h>
#include <stdlib.h>

// Programa que armazena a idade, o peso e a altura de 2 turmas com 10 pessoas
// Após armazenados, informar quantos estão com o peso acima da média por grupo

int main() {

  struct Dados {
    int idade;
    float peso, altura;
  };
  struct Dados pessoa[2][10];

  int x, y, qtd_peso[2], c = 0;
  float media[2], soma[2];

  for (y = 0; y < 2; y++) {
    qtd_peso[y] = 0;
    media[y] = 0.0;
    soma[y] = 0.0;
  }

  for (y = 0; y < 2; y++) {
    for (x = 0; x < 10; x++) {
      printf("Informe a idade, a altura e o peso da pessoa %d do grupo %d: ", x + 1, y + 1);
      scanf_s("%d %f %f", &pessoa[y][x].idade, &pessoa[y][x].altura, &pessoa[y][x].peso);
      while ((c = getchar()) != '\n' && c != EOF) {}
      soma[y] = soma[y] + pessoa[y][x].peso;
    }
    system("cls");
  }

  for (y = 0; y < 2; y++) {
    media[y] = soma[y] / 10;
  }

  for (y = 0; y < 2; y++) {
    for (x = 0; x < 10; x++) {
      if (pessoa[y][x].peso > media[y]) {
        qtd_peso[y]++;
      }
    }
    printf("\nQuantidade de pessoas do grupo %d com o peso acima da media (%.2f): %d\n", y + 1, media[y], qtd_peso[y]);
  }

  printf("\n");
  system("pause");
  return 0;
}