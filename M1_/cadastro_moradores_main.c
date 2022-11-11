// arquivo referente ao modulo 1:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_moradores_main.h"
#include "../auxiliares/funcoes_auxiliares.h"

// char nome_morador[51], cpf_morador[11], idade_morador[4], ocupacao_morador[12], renda_morador[7];

char menu_cad_moradores(void)
{
  system("clear||cls");
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
  printf("///                                                                         ///\n");
  printf("///            1. Cadastrar de Morador                                      ///\n");
  printf("///            2. Alterar dados de Morador                                  ///\n");
  printf("///            3. Deletar Morador                                           ///\n");
  printf("///            4. Visualizar Moradores                                      ///\n");
  printf("///            5. Buscar Morador                                            ///\n");
  printf("///            6. Sobre o modulo                                            ///\n");
  printf("///            0. Sair                                                      ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("Selecione sua opção:");
  char op;
  return op = ler();
}

void interacao_menu_cad_morador(void)
{
  char op;
  op = menu_cad_moradores();
  while (op != '0')
  {

    if (op == '1')
    {
      preenche_morador();
    }

    else if (op == '2')
    {
      altera_morador();
    }

    else if (op == '3')
    {
      deletar_morador();
    }

    else if (op == '4')
    {
      visualizar_morador();
      getchar();
    }

    else if (op == '5')
    {
      buscarUm();
      getchar();
    }
    else if (op == '6')
    {
      sobre_m1();
    }
    else
    {
      printf("\n\t Opcao invalida. digite outra...");
      getchar();
    }

    op = menu_cad_moradores();
  }
}

char ler(void)
{

  char x;
  scanf("%c", &x);
  getchar();
  return x;
}

void preenche_morador(void)
{
  system("clear||cls");
  Morador *mor;
  mor = (Morador *)malloc(sizeof(Morador));
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Cadastro de Morador      = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n             Por favor informe os dados do morador:                          \n");

  int tam;

  do
  {
    printf("          Informe o nome do morador:                                        \n");
    scanf("%s", mor->nome);
    getchar();
    tam = strlen(mor->nome);
  } while (!(validar_letras(mor->nome, tam)));

  do
  {
    printf("             Informe o nome CPF do morador:                                   \n");
    scanf("%s", mor->cpf);
    getchar();
    tam = strlen(mor->cpf);
  } while (!(verificarcpf(mor->cpf, tam)));

  printf("             Informe a idade do morador:                                       \n");
  scanf("%s", mor->idade);
  getchar();
  printf("             Informe a atual ocupação do morador:                             \n");
  scanf("%s", mor->ocupacao);
  getchar();

  do
  {
    printf("             Informe a renda mensal do morador:                                \n");
    scanf("%s", mor->renda);
    getchar();
    tam = strlen(mor->renda);
  } while (!(validar_dinheiro(mor->renda, tam)));

  mor->status = 'C';
  mostrarMorador(mor);
  gravarMorador(mor);
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Cadastro de Morador      = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///                          Morador cadastrado!:                           ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n\t ...Enter para sair");
  getchar();
  free(mor);
}

void altera_morador(void)
{
  int tam;
  FILE *fp;
  Morador *mor;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("cadastro-m1.dat", "r+b");
  if (fp == NULL)
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  ;
  printf("Informe o nome do morador a ser alterado: ");
  scanf(" %14[^\n]", procurado);
  mor = (Morador *)malloc(sizeof(Morador));
  achou = 0;
  while ((!achou) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    if ((strcmp(mor->nome, procurado) == 0) && (mor->status == 'C'))
    {
      achou = 1;
    }
  }
  if (achou)
  {
    mostrarMorador(mor);
    getchar();
    printf("Deseja realmente editar este Morador (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S')
    {

      do
      {
        printf("          Informe o nome do morador:                                        \n");
        scanf("%s", mor->nome);
        getchar();
        tam = strlen(mor->nome);
      } while (!(validar_letras(mor->nome, tam)));

      do
      {
        printf("             Informe o nome CPF do morador:                                   \n");
        scanf("%s", mor->cpf);
        getchar();
        tam = strlen(mor->cpf);
      } while (!(verificarcpf(mor->cpf, tam)));

      printf("             Informe a idade do morador:                                       \n");
      scanf("%s", mor->idade);
      getchar();
      printf("             Informe a atual ocupação do morador:                             \n");
      scanf("%s", mor->ocupacao);
      getchar();

      do
      {
        printf("             Informe a renda mensal do morador:                                \n");
        scanf("%s", mor->renda);
        getchar();
        tam = strlen(mor->renda);
      } while (!(validar_dinheiro(mor->renda, tam)));

      mor->status = 'C';
      fseek(fp, (-1) * sizeof(Morador), SEEK_CUR);
      fwrite(mor, sizeof(Morador), 1, fp);
      printf("\nMorador editado com sucesso!!!\n");
    }
    else
    {
      printf("\nOk, os dados não foram alterados\n");
    }
  }
  else
  {
    printf("O Morador %s não foi encontrado...\n", procurado);
    getchar();
  }
  free(mor);
  fclose(fp);

  // system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///                            Fim da Operação!                             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
}

void deletar_morador(void)
{

  FILE *fp;
  Morador *mor;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("cadastro-m1.dat", "r+b");
  if (fp == NULL)
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("Informe o nome do morador a ser apagado: ");
  scanf(" %14[^\n]", procurado);
  mor = (Morador *)malloc(sizeof(Morador));
  achou = 0;
  while ((!achou) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    if ((strcmp(mor->nome, procurado) == 0) && (mor->status == 'C'))
    {
      achou = 1;
    }
  }

  if (achou)
  {
    mostrarMorador(mor);
    getchar();
    printf("Deseja realmente apagar este morador (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S')
    {
      mor->status = 'A';
      fseek(fp, (-1) * sizeof(Morador), SEEK_CUR);
      fwrite(mor, sizeof(Morador), 1, fp);
      printf("\nMorador excluído com sucesso!!!\n");
    }
    else
    {
      printf("\nOk, os dados não foram alterados\n");
    }
  }
  else
  {
    printf("O morador %s não foi encontrado...\n", procurado);
    getchar();
  }
  free(mor);
  fclose(fp);
}
// simulado:
void visualizar_morador(void)
{
  FILE *fp;
  Morador *mor;
  fp = fopen("cadastro-m1.dat", "rb");
  if (fp == NULL)
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =         Exibir Moradores       = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  mor = (Morador *)malloc(sizeof(Morador));
  while (fread(mor, sizeof(Morador), 1, fp))
  {
    if (mor->status == 'C')
    {
      mostrarMorador(mor);
    }
  }
  fclose(fp);
  free(mor);
}

void sobre_m1(void)
{
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE        = = = = =              ///\n");
  printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
  printf("///          = = = = =              Sobre            = = = = =              ///\n");
  printf("///                                                                         ///\n");
  printf("///  Este modulo e dedicado a gerencia e controle das informacoes dos       ///\n");
  printf("///  moradores da residencia.                                               ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
}

void mostrarMorador(Morador *mor)
{

  printf("\n Nome do morador: %s", mor->nome);
  printf("\nCPF do morador: %s", mor->cpf);
  printf("\nIdade do morador: %s", mor->idade);
  printf("\nOcupação do morador: %s", mor->ocupacao);
  printf("\nRenda do morador: %s", mor->renda);
  printf("\nStatus do morador: %c", mor->status);
  printf("\n");
}

void gravarMorador(Morador *mor)
{
  FILE *fp;
  fp = fopen("cadastro-m1.dat", "ab");
  if (fp == NULL)
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(mor, sizeof(Morador), 1, fp);
  fclose(fp);
}

void buscarUm(void) {

  FILE *fp;
  Morador *mor;
  int resultado;
  char nomeBusca[51];
  fp = fopen("cadastro-m1.dat", "rb");
  if (fp == NULL)
  {
    /* code */
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  system("clear");
  printf("\n informe o nome do morador que voce busca\t");
  scanf("%s", nomeBusca);
  mor = (Morador *)malloc(sizeof(Morador));
  resultado = 0;
  while ((!resultado) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    /* code */
    if ((strcmp(mor->nome, nomeBusca) == 0) && (mor->status == 'C'))
    {
      /* code */
      resultado = 1;
    }
  }
  fclose(fp);
  if (resultado)
  {
    /* code */
    mostrarMorador(mor);
    getchar();
  }
  else
  {
    printf("Bovino %s não encontrado...", nomeBusca);
    getchar();
  }
  free(mor);
}