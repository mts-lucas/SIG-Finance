#include <stdio.h>
#include <stdlib.h>

char menu_investimentos(void);
char ler(void);
void interacao_menu_investimeto(void);
void renda_fixa(void);
void renda_variavel(void);
void criptomoeda(void);
void sobre_investimentos(void);

int main(void)
{

    interacao_menu_investimeto();

    return 0;
}

char menu_investimentos(void)
{
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Investimentos         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Renda fixa                                                ///\n");
    printf("///            2. Renda Variavel                                            ///\n");
    printf("///            3. Criptomoedas                                              ///\n");
    printf("///            4. Sobre o modulo                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    char op;
    return op = ler();
}

char ler(void)
{
  printf("Selecione sua opção:");
  char op;
  scanf("%c" , &op);
  getchar();
  return op;
}

void renda_fixa(void)
{

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Investimentos         = = = = =             ///\n");
    printf("///          = = = = =           Renda Fixa           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            De acordo com seu ultimo saldo, e recomendado                ///\n");
    printf("///            que invista seus X RS, em Y investimento de                  ///\n");
    printf("///            renda fixa.                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void renda_variavel(void)
{
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Investimentos         = = = = =             ///\n");
    printf("///          = = = = =          Renda Variavel        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            De acordo com seu ultimo saldo, e recomendado                ///\n");
    printf("///            que invista seus X RS, em Y investimento de                  ///\n");
    printf("///            renda variavel.                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void criptomoeda(void)
{

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Investimentos         = = = = =             ///\n");
    printf("///          = = = = =          Criptomoedas          = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            De acordo com seu ultimo saldo, e recomendado                ///\n");
    printf("///            que invista seus X RS, em Y moeda                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void sobre_investimentos(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
    printf("///          = = = = =              Sobre            = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///  Este modulo e dedicado a sugerir indicacoes em diferentes areas de     ///\n");
    printf("///  investimentos, como base nos ultimos saldos da residencias.            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void interacao_menu_investimeto(void)
{

    char op;
    op = menu_investimentos();
    while (op != '0')
    {

        if (op == '1')
        {
            renda_fixa();
        }

        else if (op == '2')
        {
            renda_variavel();
        }

        else if (op == '3')
        {
            criptomoeda();
        }

        else if (op == '4')
        {
            sobre_investimentos();
        }

        else
        {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();
        }

        op = menu_investimentos();
    }
}