#include <stdio.h>

void MensagemADependerDaMedia(double consumoMedio);
double calculaConsumoMedio(double distanciaEmKm, double quantidadeDeLitros);
int main()
{
  printf("Digite a distancia em km: ");
  double distanciaEmKm;
  scanf("%lf", &distanciaEmKm);
  printf("Digite a quantidade de litros consumidos: ");
  double quantidadeDeLitros;
  scanf("%lf", &quantidadeDeLitros);
  double consumoMedioMain = calculaConsumoMedio(distanciaEmKm, quantidadeDeLitros);
  MensagemADependerDaMedia(consumoMedioMain);

  return 0;
}

double calculaConsumoMedio(double distanciaEmKm, double quantidadeDeLitros)
{
  double consumoMedio = distanciaEmKm / quantidadeDeLitros;
  printf("O consumo medio do veiculo e: %.2f km/l\n", consumoMedio);
  return consumoMedio;
}

void MensagemADependerDaMedia(double consumoMedio)
{
  if (consumoMedio < 8)
  {
    printf("Venda o carro!");
  }
  else if (consumoMedio >= 8 && consumoMedio <= 12)
  {
    printf("Economico!");
  }
  else
  {
    printf("Super economico!");
  }
}