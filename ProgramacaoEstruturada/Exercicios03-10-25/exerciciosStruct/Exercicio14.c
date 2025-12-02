#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMPROMISSOS 5
#define TAM_DESCRICAO 61

typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct
{
  char descricao[TAM_DESCRICAO];
  Data data;
} Compromisso;

void lerCompromissos(Compromisso agenda[], int tamanho);
void mostrarCompromissosDoMes(const Compromisso agenda[], int tamanho, int mes, int ano);

int main()
{
  Compromisso agenda[MAX_COMPROMISSOS];
  int mesBusca, anoBusca;

  lerCompromissos(agenda, MAX_COMPROMISSOS);

  do
  {
    printf("\nDigite o mes e o ano para buscar os compromissos (M A): ");
    printf("\n(Digite 0 para o mes para sair)\n> ");
    scanf("%d", &mesBusca);

    if (mesBusca == 0)
    {
      break;
    }

    scanf("%d", &anoBusca);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    mostrarCompromissosDoMes(agenda, MAX_COMPROMISSOS, mesBusca, anoBusca);

  } while (mesBusca != 0);

  return 0;
}

void lerCompromissos(Compromisso agenda[], int tamanho)
{
  printf("--- Cadastro de Compromissos ---\n");
  printf("Por favor, insira os dados para %d compromissos.\n\n", tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    printf("--- Compromisso %d ---\n", i + 1);

    printf("Descricao: ");
    fgets(agenda[i].descricao, TAM_DESCRICAO, stdin);
    agenda[i].descricao[strcspn(agenda[i].descricao, "\n")] = 0;

    printf("Digite a data (dd mm aaaa): ");
    scanf("%d %d %d", &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("\n");
  }
}

void mostrarCompromissosDoMes(const Compromisso agenda[], int tamanho, int mes, int ano)
{
  int encontrou = 0;

  printf("\n------------------------------------------------------------\n");
  printf("COMPROMISSOS PARA O MES %02d DO ANO %d\n", mes, ano);
  printf("------------------------------------------------------------\n");

  for (int i = 0; i < tamanho; i++)
  {
    if (agenda[i].data.mes == mes && agenda[i].data.ano == ano)
    {
      printf("Data: %02d/%02d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
      printf("Compromisso: %s\n", agenda[i].descricao);
      printf("------------------------------------------------------------\n");
      encontrou = 1;
    }
  }

  if (!encontrou)
  {
    printf("Nenhum compromisso encontrado para esta data.\n");
    printf("------------------------------------------------------------\n");
  }
}