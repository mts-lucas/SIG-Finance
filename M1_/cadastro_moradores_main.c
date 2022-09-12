// arquivo referente ao modulo 1:

#include <stdio.h>
#include <stdlib.h>
#include "cadastro_moradores_main.h"

// declarando as variaveis globais

char nome_morador[51], cpf_morador[11], idade_morador[4], ocupacao_morador[12], renda_morador[7];

int main(void)
{

  interacao_menu_cad_morador();

  return 0;
}

char menu_cad_moradores(void)
{
  system("clear||cls");
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
  printf("///                                                                         ///\n");
  printf("///            1. Cadastro de Morador                                       ///\n");
  printf("///            2. Alterar dados de Morador                                  ///\n");
  printf("///            3. Deletar Morador                                           ///\n");
  printf("///            4. Visualizar Moradores                                      ///\n");
  printf("///            5. Sobre o modulo                                            ///\n");
  printf("///            0. Sair                                                      ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("Selecione sua opcao:");
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
      cad_morador();
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

void cad_morador(void)
{
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Cadastro de Morador      = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          Por favor informe os dados do morador:                         ///\n");
  printf("///          Informe o nome do morador:                                     ///\n");
  scanf("%[A-Z a-z]", nome_morador);
  getchar();
  printf("///          Informe o CPF do morador:                                      ///\n");
  scanf("%[0-9]", cpf_morador);
  getchar();
  printf("///          Informe a idade do morador:                                    ///\n");
  scanf("%[0-9]", idade_morador);
  getchar();
  printf("///          Informe a atual ocupacao do morador:                           ///\n");
  scanf("%[A-Z a-z]", ocupacao_morador);
  getchar();
  printf("///          Informe a renda mensal do morador:                             ///\n");
  scanf("%[0-9,.]", renda_morador);
  getchar();
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Cadastro de Morador      = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          Morador cadastrado!:                                           ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
}

void altera_morador(void)
{
  char nome_altera[51];
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          De qual Morador deseja alterar os dados?                       ///\n");
  scanf("%[A-Z a-z]", nome_altera);
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("Qual o novo nome?");
    scanf("%[A-Z a-z]", nome_morador);
    break;
  case ('2'):
    printf("Qual o novo CPF?");
    scanf("%[0-9]", cpf_morador);
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
    printf("Qual a nova renda?");
    scanf("%[0-9,.]", renda_morador);
    break;

  default:
    printf("opcao invalida");
    break;
  }
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =     Alterar dados de Morador   = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          Fim da Operacao!                                               ///\n");
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
  printf("///          Qual Morador deseja excluir da lista?                          ///\n");
  scanf("%[A-Z a-z]", nome_excluir);
  printf("///////////////////////////////////////////////////////////////////////////////\n");
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
  printf("///          Morador deletado!                                              ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
}

void visualizar_morador(void)
{
  system("clear||cls");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
  printf("///          = = = = =       Perfil de Moradores      = = = = =             ///\n");
  printf("///          = = = = =       Visualizar Moradores     = = = = =             ///\n");
  printf("///                                                                         ///\n");
  printf("///          Estes sao todos os moradores da residencia:                    ///\n");
  printf("%s\n", nome_morador);
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  getchar();
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