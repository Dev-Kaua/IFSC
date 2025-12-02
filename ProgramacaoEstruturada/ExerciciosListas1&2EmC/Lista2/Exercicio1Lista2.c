#include <stdio.h>
#include <string.h>

int eBissexto(int ano)
{
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  char nome[100];
  int anoNascimento, anoAtual;
  int diasVividos = 0;

  printf("Digite seu nome: ");
  fgets(nome, sizeof(nome), stdin);

  nome[strcspn(nome, "\n")] = 0;

  printf("Digite o ano de nascimento: ");
  scanf("%d", &anoNascimento);

  printf("Digite o ano atual: ");
  scanf("%d", &anoAtual);

  if (anoNascimento > anoAtual)
  {
    printf("Ano de nascimento nao pode ser maior que o ano atual.\n");
    return 1;
  }

  for (int ano = anoNascimento; ano <= anoAtual; ano++)
  {
    if (eBissexto(ano))
    {
      diasVividos += 366;
    }
    else
    {
      diasVividos += 365;
    }
  }

  printf("%s, voce ja viveu aproximadamente %d dias. (considerando apenas anos completos)\n", nome, diasVividos);
  return 0;
}