#include <stdio.h>
#include <stdlib.h>

// Exemplo de fila de impressão

int main() {

  struct Info {
    char dados[30];
    struct Info *prox;
  };

  struct Info *ptr, *ultimo = NULL;

  ptr = (struct Info *) malloc(sizeof(struct Info));

  ptr->prox = NULL;

  printf("Informar arquivo: ");
  gets_s(ptr->dados);

  if (ultimo == NULL) {
    ultimo = ptr;
  } else {
    ultimo->prox = ptr;
    ultimo = ptr;
  }

  return 0;
}