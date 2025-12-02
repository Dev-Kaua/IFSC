#include <stdio.h>

void DesenhaLinha(int quantidade);
void Intervalo(int n1, int n2);

int main()
{
    int numero, soma = 0;

    printf("Digite a quantidade de = a serem desenhados: ");
    scanf("%d", &numero);

    DesenhaLinha(numero);

    int numero1, numero2;
    printf("\nDigite o intervalo inicial: ");
    scanf("%d", &numero1);
    printf("Digite o intervalo final: ");
    scanf("%d", &numero2);

    Intervalo(numero1, numero2);
    DesenhaLinha(soma);

    int numeroInicial = numero1, numeroFinal = numero2;

    while (numeroInicial != 0 && numeroFinal != 0)
    {
        printf("\n\nDigite 0 para sair ou dois numeros para definir um novo intervalo: ");
        scanf("%d %d", &numeroInicial, &numeroFinal);

        if (numeroInicial == 0 && numeroFinal == 0)
            break;

        soma = 0;
        Intervalo(numeroInicial, numeroFinal);
    }

    return 0;
}

void DesenhaLinha(int quantidade)
{
    printf("\n--------------------\n");
    for (int x = 1; x <= quantidade; x++)
    {
        printf("=");
    }
    printf("\n");
}

void Intervalo(int n1, int n2)
{
    int soma = 0;
    for (int x = n1; x <= n2; x++)
    {
        soma += x;
        printf("%d ", x);
    }
    printf("\nsoma: %d", soma);
}
