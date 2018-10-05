#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa que gerencia um cadastro de pessoas

#define MAXIMOPESSOAS 5

struct Pessoa {
  char nome[30], telefone[20], email[70];
};
struct Pessoa dados[MAXIMOPESSOAS];

int menu() {
  int op = 0, c = 0;
  system("cls");
  printf("--- Menu Principal ---\n\n");
  printf("[1] para cadastrar\n");
  printf("[2] para atualizar\n");
  printf("[3] para listar\n");
  printf("[4] para sair\n\n");
  scanf_s("%d", &op);
  while ((c = getchar()) != '\n' && c != EOF) {}
  return op;
}

void cadastrar(int *q) {
  int c = 0;
  system("cls");
  printf("--- Cadastro ---\n\n");

  if (*q >= MAXIMOPESSOAS) {
    printf("Limite maximo de cadastros atingido.\n\n");
    system("pause");
  } else {
    printf("Informe o nome: ");
    scanf_s("%s", dados[*q].nome, sizeof(dados[*q].nome));
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Informe o telefone: ");
    scanf_s("%s", dados[*q].telefone, sizeof(dados[*q].telefone));
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Informe o e-mail: ");
    scanf_s("%s", dados[*q].email, sizeof(dados[*q].email));
    while ((c = getchar()) != '\n' && c != EOF) {}
    (*q)++;
  }
}

void listar(int q) {
  system("cls");
  printf("--- Listagem ---\n\n");

  if (q == 0) {
    printf("Nenhum usuario cadastrado.\n\n");
  } else {
    for (int x = 0; x < q; x++) {
      printf("Nome: %s\n", dados[x].nome);
      printf("Telefone: %s\n", dados[x].telefone);
      printf("E-mail: %s\n", dados[x].email);
      printf("\n");
    }
  }

  system("pause");
}

void atualizar(int q) {
  char nome[30];
  int aux = -1, c = 0;
  system("cls");
  printf("--- Atualizar ---\n\n");

  if (q == 0) {
    printf("Nenhum usuario cadastrado.\n\n");
    system("pause");
  } else {
    printf("Informe o nome da pessoa que deseja atualizar: ");
    scanf_s("%s", &nome, sizeof(nome));
    while ((c = getchar()) != '\n' && c != EOF) {}

    for (int x = 0; x < q; x++) {
      if (strcmp(dados[x].nome, nome) == 0) {
        aux = x;
        break;
      }
    }

    if (aux == -1) {
      printf("\nNome nao localizado.\n\n");
      system("pause");
    } else {
      printf("\nInforme o nome: ");
      scanf_s("%s", dados[aux].nome, sizeof(dados[aux].nome));
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("Informe o telefone: ");
      scanf_s("%s", dados[aux].telefone, sizeof(dados[aux].telefone));
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("Informe o e-mail: ");
      scanf_s("%s", dados[aux].email, sizeof(dados[aux].email));
      while ((c = getchar()) != '\n' && c != EOF) {}
    }
  }
}

int main() {
  int op, qtd = 0;
  do {
    op = menu();
    switch (op) {
    case 1:
      cadastrar(&qtd);
      break;
    case 2:
      atualizar(qtd);
      break;
    case 3:
      listar(qtd);
      break;
    }
  } while (op != 4);
  return 0;
}