#include <stdio.h>

typedef struct
{
  char rua[100];
  char cidade[50];
  char estado[50];
} Endereco;

typedef struct
{
  char nome[25];
  int idade;
  Endereco endereco;
} Estrutura;

void imprimirDados(Estrutura estrutura);

int main()
{
  Estrutura novoCadastro;

  printf("=== Cadastro ===\n");
  printf("Insira os dados a seguir\n");
  printf("Nome:\n");
  scanf("%s", novoCadastro.nome);
  printf("Idade:\n");
  scanf("%d", &novoCadastro.idade);
  printf("Insira sua rua:\n");
  scanf(" %[^\n]", novoCadastro.endereco.rua);
  printf("\nInsira sua cidade:\n");
  scanf("%s", novoCadastro.endereco.cidade);
  printf("Insira seu estado:\n");
  scanf(" %[^\n]", novoCadastro.endereco.estado);

  printf("Deseja imprimir os dados da pessoa? (s/n)\n");
  char binario;
  scanf(" %c", &binario);
  while (binario == 's' || binario == 'S')
  {
    imprimirDados(novoCadastro);

    printf("\nDeseja imprimir os dados novamente? (s/n)\n");
    scanf(" %c", &binario);
  }

  printf("Programa finalizado!!!");
  return 0;
}

void imprimirDados(Estrutura estrutura)
{
  printf("==== Pessoa cadastrada ====\n");
  printf("Nome: %s\n", estrutura.nome);
  printf("Idade: %d\n", estrutura.idade);
  printf("Endereço: \nRua: %s\nCidade: %s\nEstado: %s\n", estrutura.endereco.rua,
         estrutura.endereco.cidade, estrutura.endereco.estado);
}