#include <stdio.h>

typedef struct
{
  int hora;
  int minutos;
  int segundos;
} Horario;

typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct
{
  Horario horario;
  Data data;
  char texto[200];
} Compromisso;

int main()
{
  Compromisso novoCompromisso;

  printf("=== Cadastro de novo compromisso ====\n");
  printf("Digite a data do compromisso (dd mm aaaa)\n");
  scanf("%d %d %d", &novoCompromisso.data.dia,
        &novoCompromisso.data.mes,
        &novoCompromisso.data.ano);

  printf("Digite o horario do novo compromisso (hh mm ss)\n");
  scanf("%d %d %d", &novoCompromisso.horario.hora,
        &novoCompromisso.horario.minutos,
        &novoCompromisso.horario.segundos);

  printf("Digite a descrição do compromisso (maximo 200 caracteres)\n");
  scanf(" %[^\n]", novoCompromisso.texto);

  printf("--- COMPROMISSO CADASTRADO COM SUCESSO ---\n");
  printf("Data: %02d/%02d/%d \n", novoCompromisso.data.dia,
         novoCompromisso.data.mes, novoCompromisso.data.ano);
  printf("Horario: %02d:%02d:%02d \n", novoCompromisso.horario.hora,
         novoCompromisso.horario.minutos, novoCompromisso.horario.segundos);
  printf("Descrição: %s\n", novoCompromisso.texto);

  printf("\nDeseja alterar o compromisso? (s/n)\n");
  char binario;
  scanf("%s", &binario);
  if (binario == 's')
  {
    while (binario == 's')
    {
      printf("=== Alterando o compromisso ====\n");
      printf("Digite a nova data do compromisso (dd mm aaaa)\n");
      scanf("%d %d %d", &novoCompromisso.data.dia,
            &novoCompromisso.data.mes,
            &novoCompromisso.data.ano);

      printf("Digite o novo horario do compromisso (hh mm ss)\n");
      scanf("%d %d %d", &novoCompromisso.horario.hora,
            &novoCompromisso.horario.minutos,
            &novoCompromisso.horario.segundos);

      printf("Digite a nova descrição do compromisso (maximo 200 caracteres)\n");
      scanf(" %[^\n]", novoCompromisso.texto);

      printf("--- COMPROMISSO ATUALIZADO COM SUCESSO ---\n");
      printf("Data: %02d/%02d/%d \n", novoCompromisso.data.dia,
             novoCompromisso.data.mes, novoCompromisso.data.ano);
      printf("Horario: %02d:%02d:%02d \n", novoCompromisso.horario.hora,
             novoCompromisso.horario.minutos, novoCompromisso.horario.segundos);
      printf("Descrição: %s\n", novoCompromisso.texto);

      printf("\nDeseja alterar o compromisso novamente? (s/n)\n");
      scanf("%s", &binario);
    }
  }
  else
  {
    printf("Programa finalizado!");
    return 0;
  }

  return 0;
}