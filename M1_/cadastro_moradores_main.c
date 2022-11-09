// arquivo referente ao modulo 1:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_moradores_main.h"
#include "../auxiliares/funcoes_auxiliares.h"

// declarando as variaveis globais
// OLHAR TODOS OS COMENTS
char nome_morador[51], cpf_morador[11], idade_morador[4], ocupacao_morador[12], renda_morador[7];

char menu_cad_moradores(void)
{
  system("clear||cls");
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
  printf("///                                                                         ///\n");
  printf("///            1. Cadastrar de Morador                                       ///\n");
  printf("///            2. Alterar dados de Morador                                  ///\n");
  printf("///            3. Deletar Morador                                           ///\n");
  printf("///            4. Visualizar Moradores                                      ///\n");
  printf("///            5. Sobre o modulo                                            ///\n");
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
      sobre_moradores();
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
    printf("             Informe o nome do morador:                                        \n");
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
  char nome_altera[51];
  int tam;
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");

  do
  {
    printf("             De qual Morador deseja alterar os dados?                        \n");
    scanf("%s", nome_altera);
    getchar();
    tam = strlen(nome_altera);
  } while (!(validar_letras(nome_altera, tam)));
  getchar();
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          Que dado deseja alterar deste Morador?                         ///\n");
  printf("///          1. Nome                                                        ///\n");
  printf("///          2. CPF                                                         ///\n");
  printf("///          3. Idade                                                       ///\n");
  printf("///          4. Ocupacao                                                    ///\n");
  printf("///          5. Renda Mensal                                                ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  char op;
  scanf("%c", &op);
  switch (op)
  {
  case ('1'):
    do
    {
      printf("             Informe o nome do morador:                                    \n");
      scanf("%s", nome_morador);
      getchar();
      tam = strlen(nome_morador);
    } while (!(validar_letras(nome_morador, tam)));
    break;
  case ('2'):
    do
    {
      printf("             Informe o nome CPF do morador:                                \n");
      scanf("%s", cpf_morador);
      getchar();
      tam = strlen(cpf_morador);
    } while (!(verificarcpf(cpf_morador, tam)));
    break;
  case ('3'):
    printf("Qual a nova idade?");
    scanf("%[0-9]", idade_morador);
    break;
  case ('4'):
    printf("Qual a nova ocupacao");
    scanf("%[A-Z a-z]", ocupacao_morador);
    break;
  case ('5'):

    do
    {
      printf("             Informe a renda mensal do morador:                             \n");
      scanf("%s", renda_morador);
      getchar();
      tam = strlen(renda_morador);
    } while (!(validar_dinheiro(renda_morador, tam)));
    break;

  default:
    printf("\n\toçcão inválida");
    break;
  }
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
  char nome_excluir[51];
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
  printf("///          = = = = =         Deletar Morador        = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n          Qual Morador deseja excluir da lista?                              \n");
  scanf("%[A-Z a-z]", nome_excluir);
  getchar();
  remove(nome_morador);
  remove(cpf_morador);
  remove(idade_morador);
  remove(ocupacao_morador);
  remove(renda_morador);
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =         Deletar Morador        = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///                           Morador deletado!                             ///\n");
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
}

void sobre_moradores(void)
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