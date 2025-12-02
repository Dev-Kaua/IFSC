#include <stdio.h>

double solicitaMedida(char texto[])
{
  double medida;
  printf("%s", texto);
  scanf("%lf", &medida);
  return medida;
}

double calcularArea(int opcao)
{
  double area = 0;
  switch (opcao)
  {
  case 1:
  {
    double base = solicitaMedida("Informe o tamanho da base: ");
    double altura = solicitaMedida("Informe o tamanho da altura: ");
    area = (base * altura) / 2;
    break;
  }
  case 2:
  {
    double comprimento = solicitaMedida("Informe o tamanho do comprimento: ");
    double largura = solicitaMedida("Informe o tamanho da largura: ");
    area = comprimento * largura;
    break;
  }
  case 3:
  {
    double raio = solicitaMedida("Informe o tamanho do raio: ");
    area = 3.14159 * raio * raio;
    break;
  }
  default:
    printf("Opcao invalida!\n");
    break;
  }
  return area;
}

void exibirResultado(char texto[], double area)
{
  printf("%s %.2f\n", texto, area);
}

int main()
{
  int opcao;
  printf("Calculo das figuras geometricas:\n");

  while (1)
  {
    printf("Escolha uma opcao:\n");
    printf("1 - Triangulo\n");
    printf("2 - Retangulo\n");
    printf("3 - Circulo\n");
    printf("4 - Sair\n");
    scanf("%d", &opcao);

    if (opcao == 4)
    {
      break;
    }

    double area = calcularArea(opcao);
    if (area > 0)
    {
      exibirResultado("A area é:", area);
    }
  }

  return 0;
}
