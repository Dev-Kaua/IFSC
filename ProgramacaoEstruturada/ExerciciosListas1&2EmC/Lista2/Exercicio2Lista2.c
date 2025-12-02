#include <stdio.h>

int potenciacao(int base, int expoente)
{
  int resultado = 1;
  for (int i = 0; i < expoente; i++)
  {
    resultado *= base;
  }
  return resultado;
}

int main()
{
  int base, expoente, resultado;
  printf("Digite a base: ");
  scanf("%d", &base);
  printf("Digite o expoente: ");
  scanf("%d", &expoente);
  if (expoente < 0)
  {
    printf("Expoente deve ser um numero inteiro nao negativo.\n");
    return 1;
  }

  resultado = potenciacao(base, expoente);

  printf("Resultado: %d elevado a %d = %d\n", base, expoente, resultado);

  return 0;
}