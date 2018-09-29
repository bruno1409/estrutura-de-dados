#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa que recebe altura e peso de alunos de 7 turmas
// Cada turma possui no máximo 50 estudantes
// Este programa informa:
// a) a média de altura e peso por turma
// b) a turma que possui maior e menor média de altura
// c) a turma que possui maior e menor média de peso
// d) o(a) aluno(a) com maior e menor altura de todas as turmas
// e) o(a) aluno(a) com maior e menor peso de todas as turmas

int main() {
  struct Aluno {
    char nome[30];
    float altura, peso;
  };
  struct Aluno dados[7][50];

  int x, y, turma1, turma2, c = 0;
  int tot_alunos[7] = {0, 0, 0, 0, 0, 0, 0};
  float med_altura[7] = {0, 0, 0, 0, 0, 0, 0};
  float med_peso[7] = {0, 0, 0, 0, 0, 0, 0};
  float aux1, aux2;
  char aluno1[30], aluno2[30];

  // Cálculo da média de altura e peso por turma

  for (x = 0; x < 7; x++) {
    system("cls");
    printf("Quantos alunos a turma %d possui? ", x + 1);
    scanf_s("%d", &tot_alunos[x]);
    while ((c = getchar()) != '\n' && c != EOF) {}
    for (y = 0; y < tot_alunos[x]; y++) {
      system("cls");
      printf("Aluno %d - Turma %d\n\n", y + 1, x + 1);
      printf("Nome: ");
      scanf_s("%s", &dados[x][y].nome, sizeof(dados[x][y].nome));
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("Altura: ");
      scanf_s("%f", &dados[x][y].altura);
      while ((c = getchar()) != '\n' && c != EOF) {}
      printf("Peso: ");
      scanf_s("%f", &dados[x][y].peso);
      while ((c = getchar()) != '\n' && c != EOF) {}
      med_altura[x] += dados[x][y].altura;
      med_peso[x] += dados[x][y].peso;
    }
    med_altura[x] = med_altura[x] / tot_alunos[x];
    med_peso[x] = med_peso[x] / tot_alunos[x];
  }
  system("cls");
  for (x = 0; x < 7; x++) {
    printf("Turma %d - Media de altura: %.2f - Media de peso: %.2f\n", x + 1, med_altura[x], med_peso[x]);
  }
  printf("\n");

  // Turma que possui maior e menor média de altura
  
  aux1 = 0;
  aux2 = 1000;

  for (x = 0; x < 7; x++) {
    if (med_peso[x] > aux1) {
      aux1 = med_peso[x];
      turma1 = x + 1;
    }
    if (med_peso[x] < aux2) {
      aux2 = med_peso[x];
      turma2 = x + 1;
    }
  }

  printf("Turma com maior media de peso: %d\n", turma1);
  printf("Turma com menor media de peso: %d\n", turma2);
  printf("\n");

  // Turma que possui maior e menor média de peso

  aux1 = 0;
  aux2 = 1000;

  for (x = 0; x < 7; x++) {
    if (med_altura[x] > aux1) {
      aux1 = med_altura[x];
      turma1 = x + 1;
    }
    if (med_altura[x] < aux2) {
      aux2 = med_altura[x];
      turma2 = x + 1;
    }
  }

  printf("Turma com maior media de altura: %d\n", turma1);
  printf("Turma com menor media de altura: %d\n", turma2);
  printf("\n");

  // Aluno(a) com maior e menor altura de todas as turmas

  aux1 = 0;
  aux2 = 1000;

  for (x = 0; x < 7; x++) {
    for (y = 0; y < tot_alunos[x]; y++) {
      if (dados[x][y].altura > aux1) {
        aux1 = dados[x][y].altura;
        turma1 = x + 1;
        strcpy_s(aluno1, dados[x][y].nome);
      }
      if (dados[x][y].altura < aux2) {
        aux2 = dados[x][y].altura;
        turma2 = x + 1;
        strcpy_s(aluno2, dados[x][y].nome);
      }
    }
  }

  printf("Aluno(a) com maior altura: %s da turma %d\n", aluno1, turma1);
  printf("Aluno(a) com menor altura: %s da turma %d\n", aluno2, turma2);
  printf("\n");

  // Aluno(a) com maior e menor peso de todas as turmas

  aux1 = 0;
  aux2 = 1000;

  for (x = 0; x < 7; x++) {
    for (y = 0; y < tot_alunos[x]; y++) {
      if (dados[x][y].peso > aux1) {
        aux1 = dados[x][y].peso;
        turma1 = x + 1;
        strcpy_s(aluno1, dados[x][y].nome);
      }
      if (dados[x][y].peso < aux2) {
        aux2 = dados[x][y].peso;
        turma2 = x + 1;
        strcpy_s(aluno2, dados[x][y].nome);
      }
    }
  }

  printf("Aluno(a) com maior peso: %s da turma %d\n", aluno1, turma1);
  printf("Aluno(a) com menor peso: %s da turma %d\n", aluno2, turma2);
  printf("\n");
  system("pause");
  return 0;
}