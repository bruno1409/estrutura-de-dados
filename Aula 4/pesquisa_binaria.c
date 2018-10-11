#include <stdio.h>
#include <stdlib.h>

// Programa que realiza uma pesquisa binária, utilizando recursividade

int pesquisa_binaria(int vet[], int inicio, int fim, int numero) {
  int pivo;
  if (inicio > fim) {
    return -1;
  }
  pivo = ((fim - inicio) / 2) + inicio;
  if (numero > vet[pivo]) {
    return (pesquisa_binaria(vet, pivo + 1, fim, numero));
  }
  if (numero < vet[pivo]) {
    return (pesquisa_binaria(vet, inicio, pivo - 1, numero));
  }
  return(pivo);
}

int main() {
  int vetor[20] = {3, 7, 8, 10, 13, 15, 18, 22, 26, 27, 32, 35, 43, 47, 53, 57, 62, 63, 72, 84};
  int num, pos;
  printf("Valores no vetor: ");
  for (int x = 0; x < 20; x++) {
    printf("%d ", vetor[x]);
  }
  printf("\n\nInforme um valor para ser localizado no vetor: ");
  scanf_s("%d", &num);
  pos = pesquisa_binaria(vetor, 0, 19, num);
  system("cls");
  if (pos == -1) {
    printf("O valor nao esta no vetor.");
  } else {
    printf("O valor esta na posicao %d do vetor.", pos);
  }
  printf("\n\n");
  system("pause");
  return 0;
}