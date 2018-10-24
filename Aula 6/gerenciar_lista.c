#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa que gerencia os dados em uma lista

struct Pessoa {
  char nome[30];
  struct Pessoa *ante, *prox;
};

struct Pessoa *ini, *fin, *ptr;

void armazenar() {
  system("cls");
  printf("--- Adicionar novo valor na lista ---\n\n");

  ptr = (struct Pessoa *) malloc(sizeof(struct Pessoa));
  printf("Digite o nome: ");
  gets_s(ptr->nome);
  ptr->prox = ptr->ante = NULL;

  if (ini == NULL) {
    ini = fin = ptr;
  } else {
    ptr->ante = fin;
    fin->prox = ptr;
    fin = ptr;
  }
}

void listar() {
  system("cls");
  printf("--- Valores adicionados na lista ---\n\n");

  if (ini == NULL) {
    printf("Nenhum valor adicionado. A lista esta vazia.\n\n");
  } else {
    ptr = ini;
    printf("Primeiro endereco da lista: %p\n\n", ini);
    while (ini != NULL) {
      ptr = ini;
      printf("Endereco: %p | Nome: %s | Anterior: %p | Proximo: %p\n", ptr, ptr->nome, ptr->ante, ptr->prox);
      ini = ini->prox;
      free(ptr);
    }
    printf("\nUltimo endereco da lista: %p\n\n", fin);
    fin = NULL;
    printf("Todos os valores acima foram retirados da lista\n\n");
  }
  system("pause");
}

int menu() {
  int op = 0, c = 0;
  system("cls");
  printf("--- Menu Principal ---\n\n");
  printf("[1] para adicionar dados na lista\n");
  printf("[2] para exibir e retirar dados da lista\n");
  printf("[3] para encerrar\n\n");
  scanf_s("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}
  return op;
}

int main() {
  char op;
  ini = fin = NULL;

  do {
    op = menu();

    switch (op) {
    case 1:
      armazenar();
      break;
    case 2:
      listar();
      break;
    }

  } while (op != 3);
  return 0;
}