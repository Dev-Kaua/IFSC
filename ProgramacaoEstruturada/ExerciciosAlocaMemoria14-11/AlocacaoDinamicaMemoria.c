#include <stdio.h>
#include <stdlib.h>

int main()
{
  int tamanho;
  int *memoria;
  int total_posicoes;

  printf("----- Alocacao Dinamica de Memoria ------\n");
  printf("Insira o tamanho da memória a ser alocada (em bytes): ");

  scanf("%d", &tamanho);

  if (tamanho <= 0 || tamanho % sizeof(int) != 0)
  {
    printf("Erro: O tamanho deve ser positivo e múltiplo de %zu bytes.\n", sizeof(int));
    return 1;
  }

  total_posicoes = tamanho / sizeof(int);
  printf("Memória de %d bytes alocada. Total de posições (int): %d\n", tamanho, total_posicoes);

  memoria = (int *)calloc(total_posicoes, sizeof(int));

  if (memoria == NULL)
  {
    printf("Falha na alocação de memória!\n");
    return 1;
  }

  int opcao;
  int posicao, valor;

  do
  {
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir um valor em uma determinada posição\n");
    printf("2 - Consultar o valor contido em uma determinada posição\n");
    printf("3 - Mostrar na tela o conteúdo de todas as posições da memória\n");
    printf("4 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      printf("Insira a posição (0 a %d) onde deseja armazenar: ", total_posicoes - 1);
      scanf("%d", &posicao);

      if (posicao < 0 || posicao >= total_posicoes)
      {
        printf("Posição inválida!\n");
      }
      else
      {
        printf("Insira o valor a ser armazenado na posicao %d: ", posicao);
        scanf("%d", &valor);

        memoria[posicao] = valor;
        printf("Valor %d armazenado.\n", valor);
      }

      break;
    }
    case 2:
    {
      printf("Insira a posição (0 a %d) que deseja consultar: ", total_posicoes - 1);
      scanf("%d", &posicao);

      if (posicao < 0 || posicao >= total_posicoes)
      {
        printf("Posição inválida!\n");
      }
      else
      {
        valor = memoria[posicao];
        printf("Valor na posição %d é %d\n", posicao, valor);
      }

      break;
    }
    case 3:
    {
      printf("\nConteúdo da memória (Total %d posições):\n", total_posicoes);

      for (int i = 0; i < total_posicoes; i++)
      {
        printf("Posição [%d]: %d\n", i, memoria[i]);
      }
      break;
    }
    case 4:
      printf("Saindo do programa.\n");
      break;

    default:
      printf("Opção inválida!\n");
      break;
    }
  } while (opcao != 4);

  printf("Liberando memória...\n");
  free(memoria);

  return 0;
}