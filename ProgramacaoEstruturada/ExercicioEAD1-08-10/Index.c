#include <stdio.h>

int calcularOperacao(int param1, int param2);

void imprimirResultado(int num1, int num2, int resultadoFinal);

int main(){

  int numero1, numero2, resultado;
  char continuar;

  printf("======================================\n");
    printf("  Calculadora Especial - Soma e Multiplica\n");
    printf("======================================\n");
    printf("Este programa soma dois números e multiplica o resultado por 10.\n\n");

  do{
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &numero1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &numero2);

    resultado = calcularOperacao(numero1, numero2);

    imprimirResultado(numero1, numero2, resultado);

    printf("\n\nDeseja realizar um novo cálculo? (S/N): ");
    scanf(" %c", &continuar);
    printf("\n");
  }while(continuar == 'S' || continuar == 's');

  printf("Programa finalizado!");

  return 0;
}

int calcularOperacao(int param1, int param2){
  int fatorFixo = 10;

  int resultadoLocal;

  resultadoLocal = (param1 + param2) * fatorFixo;

  return resultadoLocal;
}

void imprimirResultado(int num1, int num2, int resultadoFinal){
  printf("\n---------- RESULTADOS ----------\n");
  printf("Primeiro número digitado: %d\n", num1);
  printf("Segundo número digitado:  %d\n", num2);
  printf("Cálculo realizado:        (%d + %d) * 10\n", num1, num2);
  printf("Resultado final:          %d\n", resultadoFinal);
  printf("------------------------------\n");
}