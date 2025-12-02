#include <stdio.h>
#define TAMANHO 5

int encontraIntersecao(int *vetor1, int *vetor2, int *vetor_resultado, int tam)
{
  int contador_resultado = 0;

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      if (vetor1[i] == vetor2[j])
      {
        int ja_existe = 0;
        for (int k = 0; k < contador_resultado; k++)
        {
          if (vetor_resultado[k] == vetor1[i])
          {
            ja_existe = 1;
            break;
          }
        }

        if (ja_existe == 0)
        {
          vetor_resultado[contador_resultado] = vetor1[i];
          contador_resultado++;
        }

        break;
      }
    }
  }

  return contador_resultado;
}

int main()
{
  int vetor1[TAMANHO];
  int vetor2[TAMANHO];
  int vetor3[TAMANHO];

  printf("Preencha o primeiro vetor\n");
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("Digite o %dº numero: ", i + 1);
    scanf("%d", &vetor1[i]);
  }

  printf("\nPreencha o segundo vetor\n");
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("Digite o %dº numero: ", i + 1);
    scanf("%d", &vetor2[i]);
  }
  int quantidade_em_comum = encontraIntersecao(vetor1, vetor2, vetor3, TAMANHO);

  printf("\nVetor 3 (Numeros em comum)\n");

  if (quantidade_em_comum == 0)
  {
    printf("Nenhum numero em comum foi encontrado.\n");
  }
  else
  {
    for (int i = 0; i < quantidade_em_comum; i++)
    {
      printf("%d ", vetor3[i]);
    }
    printf("\n");
  }

  return 0;
}