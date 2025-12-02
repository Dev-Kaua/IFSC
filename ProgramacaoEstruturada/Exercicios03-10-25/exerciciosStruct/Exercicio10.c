#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARTAS 52
#define NAIPES 4
#define VALORES 13
#define CARTAS_POR_JOGADOR 5

typedef struct
{
  char *valor;
  char *naipe;
} Carta;

void criarBaralho(Carta baralho[]);
void embaralhar(Carta baralho[]);
void exibirMao(Carta mao[], int jogador);

int main()
{
  srand(time(NULL));

  Carta baralho[TOTAL_CARTAS];
  Carta maoJogador1[CARTAS_POR_JOGADOR];
  Carta maoJogador2[CARTAS_POR_JOGADOR];

  criarBaralho(baralho);

  printf("Embaralhando as cartas...\n");
  embaralhar(baralho);

  printf("Distribuindo as cartas para 2 jogadores.\n\n");

  int cartaAtual = 0;
  for (int i = 0; i < CARTAS_POR_JOGADOR; i++)
  {
    maoJogador1[i] = baralho[cartaAtual++];
    maoJogador2[i] = baralho[cartaAtual++];
  }

  exibirMao(maoJogador1, 1);
  exibirMao(maoJogador2, 2);

  return 0;
}

void criarBaralho(Carta baralho[])
{
  char *valores[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};
  char *naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};

  int indiceCarta = 0;
  for (int i = 0; i < NAIPES; i++)
  {
    for (int j = 0; j < VALORES; j++)
    {
      baralho[indiceCarta].naipe = naipes[i];
      baralho[indiceCarta].valor = valores[j];
      indiceCarta++;
    }
  }
}

void embaralhar(Carta baralho[])
{
  for (int i = TOTAL_CARTAS - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);

    Carta temp = baralho[i];
    baralho[i] = baralho[j];
    baralho[j] = temp;
  }
}

void exibirMao(Carta mao[], int jogador)
{
  printf("--- Cartas do Jogador %d ---\n", jogador);
  for (int i = 0; i < CARTAS_POR_JOGADOR; i++)
  {
    printf("  %d: %s de %s\n", i + 1, mao[i].valor, mao[i].naipe);
  }
  printf("\n");
}