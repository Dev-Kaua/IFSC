#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Numeros
{
  int valor;
};

struct Principal
{
  int valorInicial;
  struct Numeros *listaDeNumeros;
};

void preencherLista(struct Numeros *lista, int quantidade, int valorInicial)
{
  int i = 0;

  int regraPar = (valorInicial % 2 == 0);

  printf("Preenchendo a lista com %d números\n", quantidade);
  printf("--- Valor inicial é %d (%s), buscando números %s.\n",
         valorInicial, (regraPar ? "PAR" : "IMPAR"), (regraPar ? "PARES" : "IMPARES"));

  while (i < quantidade)
  {
    int numeroAleatorio = rand() % 100;

    if (regraPar)
    {
      if (numeroAleatorio % 2 == 0)
      {
        lista[i].valor = numeroAleatorio;
        i++;
      }
    }
    else
    {
      if (numeroAleatorio % 2 != 0)
      {
        lista[i].valor = numeroAleatorio;
        i++;
      }
    }
  }
}

int main()
{
  srand(time(NULL));

  printf("----- Alocacao Dinamica de Lista ------\n");
  printf("Insira um número inicial: ");
  struct Principal p;
  scanf("%d", &p.valorInicial);
  printf("Quantos números deseja alocar na lista? ");
  int quantidade;
  scanf("%d", &quantidade);

  p.listaDeNumeros = (struct Numeros *)malloc(quantidade * sizeof(struct Numeros));
  if (p.listaDeNumeros == NULL)
  {
    printf("Erro na alocação de memória!\n");
    return 1;
  }

  preencherLista(p.listaDeNumeros, quantidade, p.valorInicial);

  printf("----- Lista preenchida -----\n");
  for (int i = 0; i < quantidade; i++)
  {
    printf("Posicao [%d] = %d\n", i, p.listaDeNumeros[i].valor);
  }

  printf("-- Liberando memória alocada --\n");
  free(p.listaDeNumeros);
  return 0;
}
