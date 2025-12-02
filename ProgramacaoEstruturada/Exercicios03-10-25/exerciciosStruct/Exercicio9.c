#include <stdio.h>
#include <string.h>

#define TOTAL_ALUNOS 5
#define MEDIA_APROVACAO 5.0

struct Aluno
{
  char nome[100];
  int matricula;
  double mediaFinal;
};

void exibirAlunos(struct Aluno alunos[], int quantidade, const char *titulo);

int main()
{

  struct Aluno todosAlunos[TOTAL_ALUNOS];

  struct Aluno alunosAprovados[TOTAL_ALUNOS];
  struct Aluno alunosReprovados[TOTAL_ALUNOS];

  int contadorAprovados = 0;
  int contadorReprovados = 0;
  int i;

  printf("=== Cadastro de Alunos ===\n\n");

  for (i = 0; i < TOTAL_ALUNOS; i++)
  {
    printf("--- Aluno %d ---\n", i + 1);

    printf("Nome: ");
    fgets(todosAlunos[i].nome, 100, stdin);

    printf("Matricula: ");
    scanf("%d", &todosAlunos[i].matricula);

    printf("Media Final: ");

    scanf("%lf", &todosAlunos[i].mediaFinal);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("\n");
  }

  for (i = 0; i < TOTAL_ALUNOS; i++)
  {

    if (todosAlunos[i].mediaFinal >= MEDIA_APROVACAO)
    {
      alunosAprovados[contadorAprovados] = todosAlunos[i];
      contadorAprovados++;
    }
    else
    {
      alunosReprovados[contadorReprovados] = todosAlunos[i];
      contadorReprovados++;
    }
  }

  exibirAlunos(alunosAprovados, contadorAprovados, "APROVADOS");
  exibirAlunos(alunosReprovados, contadorReprovados, "REPROVADOS");

  return 0;
}

void exibirAlunos(struct Aluno vetor[], int quantidade, const char *titulo)
{
  printf("\n\n===================================\n");
  printf("        LISTA DE ALUNOS %s\n", titulo);
  printf("===================================\n\n");

  if (quantidade == 0)
  {
    printf("Nenhum aluno nesta categoria.\n");
    return;
  }

  for (int i = 0; i < quantidade; i++)
  {
    printf("Aluno %d:\n", i + 1);
    printf("  Nome: %s", vetor[i].nome);
    printf("  Matricula: %d\n", vetor[i].matricula);
    printf("  Media Final: %.2f\n", vetor[i].mediaFinal);
    printf("-----------------------------------\n");
  }
}