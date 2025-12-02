#include <stdio.h>

struct Area
{
  int comprimento;
  int largura;
  int area;
};

void trocarValores(int *parte_a, int *parte_b)
{
  int variavelTemporaria = *parte_a;
  *parte_a = *parte_b;
  *parte_b = variavelTemporaria;
}

int main()
{
  int numero1 = 20;
  int numero2 = 10;

  printf("Valores Originais:\n");
  printf("Numero 1 = %d\n", numero1);
  printf("Numero 2 = %d\n", numero2);

  trocarValores(&numero1, &numero2);

  printf("Valores trocados:\n");
  printf("Numero1 = %d\n", numero1);
  printf("Numero2 = %d\n", numero2);

  return 0;
}