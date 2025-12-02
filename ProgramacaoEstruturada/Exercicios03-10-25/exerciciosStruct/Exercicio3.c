#include <stdio.h>
#include <string.h>

struct aluno
{
  char nome[50];
  int matricula;
  char curso[50];
};

void imprimeAluno(struct aluno lista_alunos[], int tamanho);

int main()
{
  struct aluno lista_alunos[5];
  int i;

  printf("--- Cadastro de Alunos ---\n");
  for (i = 0; i < 5; i++)
  {
    printf("--- Aluno %d ---\n", i + 1);

    printf("Digite o nome: ");
    fgets(lista_alunos[i].nome, 50, stdin);

    printf("Digite a matricula: ");
    scanf("%d", &lista_alunos[i].matricula);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("Digite o curso: ");
    fgets(lista_alunos[i].curso, 50, stdin);

    printf("\n");
  }

  imprimeAluno(lista_alunos, 5);
  return 0;
}

void imprimeAluno(struct aluno lista_alunos[], int tamanho)
{
  int i;
  printf("--- Lista de Alunos Cadastrados ---\n");

  for (i = 0; i < tamanho; i++)
  {
    printf("Aluno %d:\n", i + 1);
    printf("Nome: %s", lista_alunos[i].nome);
    printf("Matricula: %d\n", lista_alunos[i].matricula);
    printf("Curso: %s\n", lista_alunos[i].curso);
    printf("\n");
  }
}