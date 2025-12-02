#include <stdio.h>

struct Area
{
  int comprimento;
  int largura;
  int area;
};

void carregarDadosEcalcularArea(struct Area *ptr_estrutura, int indice)
{

  ptr_estrutura->comprimento = indice + 5;
  ptr_estrutura->largura = indice + 10;

  ptr_estrutura->area = ptr_estrutura->comprimento * ptr_estrutura->largura;
}

int main()
{
  struct Area vetorDeAreas[10];
  int somaTotalDasAreas = 0;

  for (int i = 0; i < 10; i++)
  {
    carregarDadosEcalcularArea(&vetorDeAreas[i], i);
  }

  printf("--- Dados Carregados em Cada Estrutura ---\n");

  for (int i = 0; i < 10; i++)
  {
    printf("Posicao %d: Comprimento = %d, Largura = %d, Area = %d\n",
           i,
           vetorDeAreas[i].comprimento,
           vetorDeAreas[i].largura,
           vetorDeAreas[i].area);

    somaTotalDasAreas = somaTotalDasAreas + vetorDeAreas[i].area;
  }

  printf("\n--> O valor total de todas as areas somadas é: %d\n", somaTotalDasAreas);

  return 0;
}