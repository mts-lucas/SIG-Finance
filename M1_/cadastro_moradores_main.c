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

  char nome[51];
  char cpf[12];
  char idade[4];
  char ocupacao[20];
  char renda[11];
  // float rendaf;

  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Cadastro de Morador      = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("            Insira os dados do novo morador:\n");
  ler_nome(nome);
  ler_cpf_cad(cpf);
  ler_idade(idade);
  ler_ocupacao(ocupacao);
  ler_renda(renda);
  int tam = strlen(renda);

  strcpy(mor->nome, nome);
  strcpy(mor->cpf, cpf);
  strcpy(mor->idade, idade);
  strcpy(mor->ocupacao, ocupacao);
  mor->renda = transform_to_float(renda, tam);
  // strcpy(mor->renda, renda);
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

  // modifiquei para buscar por cpf

  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  FILE *fp;
  Morador *mor;
  int achou;
  char resp;
  char procurado[15];

  char nome[51];
  char cpf[15];
  char idade[4];
  char ocupacao[20];
  char renda[11];

  fp = fopen("cadastro-m1.dat", "r+b");
  if (fp == NULL)
  {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("Informe o CPF do morador a ser alterado: ");
  ler_cpf(procurado);
  mor = (Morador *)malloc(sizeof(Morador));
  achou = 0;
  while ((!achou) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    if ((strcmp(mor->cpf, procurado) == 0) && (mor->status == 'C'))
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
    getchar();
    if (resp == 's' || resp == 'S')
    {

      ler_nome(nome);
      ler_cpf(cpf);
      ler_idade(idade);
      ler_ocupacao(ocupacao);
      ler_renda(renda);
      int tam = strlen(renda);

      strcpy(mor->nome, nome);
      strcpy(mor->cpf, cpf);
      strcpy(mor->idade, idade);
      strcpy(mor->ocupacao, ocupacao);
      // strcpy(mor->renda, renda);
      mor->renda = transform_to_float(renda, tam);
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

  system("clear||cls");
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

  // mudei a busca por CPF

  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Deletar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");

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
  printf("Informe o CPF do morador a ser apagado: ");
  ler_cpf(procurado);
  mor = (Morador *)malloc(sizeof(Morador));
  achou = 0;
  while ((!achou) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    if ((strcmp(mor->cpf, procurado) == 0) && (mor->status == 'C'))
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
    getchar();
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
    printf("...Pressione Enter para sair");
    getchar();
  }
  free(mor);
  fclose(fp);

  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Deletar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///                            Fim da Operação!                             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
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
  getchar();
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =         Exibir Moradores       = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///                            Fim da Operação!                             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
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
  printf("\nRenda do morador: %.2f", mor->renda);
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

void buscarUm(void)
{

  FILE *fp;
  Morador *mor;
  int resultado;
  char cpfbusca[12];
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
  ler_cpf(cpfbusca);
  mor = (Morador *)malloc(sizeof(Morador));
  resultado = 0;
  while ((!resultado) && (fread(mor, sizeof(Morador), 1, fp)))
  {
    /* code */
    if ((strcmp(mor->cpf, cpfbusca) == 0) && (mor->status == 'C'))
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
    printf("Morador %s não encontrado...", cpfbusca);
    printf("...Pressione enter para sair");
  }
  free(mor);
}

