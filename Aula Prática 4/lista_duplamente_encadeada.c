#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa que gerencia informações de veículos em uma lista duplamente encadeada

struct Carro {
  char placa[8];
  struct Carro *ante, *prox;
};

struct Carro *prim, *ulti, *ptr, *aux;

void armazenar();
void retirar();
void limpar();
void listar();
int menu();

int main() {
  char op;
  prim = ulti = NULL;

  do {
    op = menu();
    switch (op) {
      case 1:
        armazenar();
        break;
      case 2:
        retirar();
        break;
      case 3:
        limpar();
        break;
      case 4:
        listar();
        break;
    }
  } while (op != 5);
  return 0;
}

int menu() {
  int op = 0, c = 0;
  system("cls");
  printf("--- Menu Principal ---\n\n");
  printf("[1] para adicionar um carro\n");
  printf("[2] para retirar um carro\n");
  printf("[3] para retirar todos os carros\n");
  printf("[4] para listar todos os carros\n");
  printf("[5] para encerrar\n\n");
  scanf_s("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}
  return op;
}

void listar() {
  system("cls");
  printf("--- Listar todos os carros ---\n\n");
  ptr = prim;

  if (prim == NULL || ulti == NULL) {
    printf("Nenhum carro adicionado na lista.\n\n");
    system("pause");
    return;
  } else {
    while (ptr != NULL) {
      printf("Placa: %s\n", ptr->placa);
      ptr = ptr->prox;
    }
  }

  printf("\n");
  system("pause");
}

void limpar() {
  system("cls");
  printf("--- Retirar todos os carros ---\n\n");

  if (prim == NULL || ulti == NULL) {
    printf("Nenhum carro adicionado na lista.\n\n");
    system("pause");
    return;
  } else {
    while (prim != NULL) {
      ptr = prim;
      prim = prim->prox;
      free(ptr);
    }
  }

  ulti = NULL;
  printf("Todos os carros foram removidos.\n\n");
  system("pause");
}

void pesquisar(char placa[]) {
  aux = prim;

  while (aux != NULL) {
    if (strcmp(placa, aux->placa) == 0) {
      break;
    }
    aux = aux->prox;
  }
}

void localizar(char placa[]) {

  if (strcmp(placa, prim->placa) < 0) {
    return;
  }

  aux = prim;

  while (aux != ulti) {
    if (strcmp(placa, aux->prox->placa) < 0) {
      return;
    }
    aux = aux->prox;
  }
}

void armazenar() {
  system("cls");
  printf("--- Adicionar carro ---\n\n");
  ptr = (struct Carro *) malloc(sizeof(struct Carro));
  printf("Informe a placa do carro: ");
  gets_s(ptr->placa);
  ptr->prox = ptr->ante = NULL;

  if (prim == NULL) {
    prim = ulti = ptr;
    return;
  }

  aux = NULL;
  localizar(ptr->placa);

  if (aux == NULL) {
    ptr->prox = prim;
    prim->ante = ptr;
    prim = ptr;
    return;
  }

  if (aux == ulti) {
    ptr->ante = ulti;
    ulti->prox = ptr;
    ulti = ptr;
    return;
  }

  ptr->ante = aux;
  ptr->prox = aux->prox;
  aux->prox->ante = ptr;
  aux->prox = ptr;
}

void retirar() {
  system("cls");
  printf("--- Retirar carro ---\n\n");

  if (prim == NULL || ulti == NULL) {
    printf("Nenhum carro adicionado na lista.\n\n");
    system("pause");
    return;
  } else {
    char placa[8];
    printf("Informe a placa do carro: ");
    gets_s(placa);
    pesquisar(placa);

    if (aux == NULL) {
      printf("\nPlaca nao localizada.\n\n");
      system("pause");
      return;
    }

    if (aux == prim) {
      prim = prim->prox;
      free(aux);
      if (prim == NULL) {
        ulti = NULL;
      } else {
        prim->ante = NULL;
      }
      return;
    }

    if (aux == ulti) {
      ulti = ulti->ante;
      ulti->prox = NULL;
      free(aux);
      return;
    }

    aux->prox->ante = aux->ante;
    aux->ante->prox = aux->prox;
    free(aux);
  }
}