#include <stdio.h>
#include <stdlib.h>

// Programa que armazena temporariamente informações digitadas pelo usuário em uma fila

struct Pessoa {
  char nome[30];
  char cpf[15];
  struct Pessoa *prox;
};

struct Pessoa *ini, *fin, *ptr;

void enfileirar() {
  system("cls");
  printf("--- Adicionar novo valor na fila ---\n\n");

  ptr = (struct Pessoa *) malloc(sizeof(struct Pessoa));
  printf("Digite o nome: ");
  gets_s(ptr->nome);
  printf("Digite o CPF: ");
  gets_s(ptr->cpf);
  ptr->prox = NULL;

  if (ini == NULL) {
    ini = fin = ptr;
  } else {
    fin->prox = ptr;
    fin = ptr;
  }
}

void retirar() {
  system("cls");
  printf("--- Valores adicionados na fila ---\n\n");

  if (ini == NULL) {
    printf("Nenhum valor adicionado. A fila esta vazia.\n\n");
  } else {
    printf("Primeiro endereco da fila: %p\n\n", ini);
    while (ini != NULL) {
      ptr = ini;
      printf("Endereco: %p | Nome: %s | CPF: %s | Proximo endereco: %p\n", ptr, ini->nome, ini->cpf, ini->prox);
      ini = ini->prox;
      free(ptr);
    }
    printf("\nUltimo endereco da fila: %p\n\n", fin);
    fin = NULL;
    printf("Todos os valores acima foram retirados da fila\n\n");
  }
  system("pause");
}

int menu() {
  int op = 0, c = 0;
  system("cls");
  printf("--- Menu Principal ---\n\n");
  printf("[1] para adicionar dados na fila\n");
  printf("[2] para exibir e retirar dados da fila\n");
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
      enfileirar();
      break;
    case 2:
      retirar();
      break;
    }

  } while (op != 3);
  return 0;
}