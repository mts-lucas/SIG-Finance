#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void interacao_menu_relatorios(void)
{

    char op;
    op = menu_relatorios();
    while (op != '0')
    {

        if (op == '1')
        {
            por_datas();
        }

        else if (op == '2')
        {
            entre_datas();
        }

        else
        {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();
        }

        op = menu_relatorios();
    }
}

char menu_relatorios(void)
{
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatorios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Pesquisar por data                                        ///\n");
    printf("///            2. Pesquisar por periodo de tempo                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opcao:");
    scanf("%c", &op);
    getchar();
    return op;
}

void entre_datas(void){

    system("clear||cls");
    printf("Em construção");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatorios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     De 20/09/22 a 24/09/22                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///     Deposito de Talys                                                   ///\n");
    printf("///         Valor: 10,00 reais                                              ///\n");
    printf("///         Tipo: extra                                                     ///\n");
    printf("///         Descrição: achei na rua.                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesas cadastrada por Lucas                                       ///\n");
    printf("///         Valor: 50,00 reais.                                             ///\n");
    printf("///         Tipo: Contas mensais.                                           ///\n");
    printf("///         Descrição:                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Deposito de Flavius                                                 ///\n");
    printf("///         Valor: 500,00 reais.                                            ///\n");
    printf("///         Tipo: Contribuicao mensal.                                      ///\n");
    printf("///         Descrição: 1/100 do meu salario.                                ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesa cadastrada por Talys                                        ///\n");
    printf("///         Valor: 50,00 reais                                              ///\n");
    printf("///         Tipo: Emergencia                                                ///\n");
    printf("///         Descrição: ventilador quebrado.                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void por_datas(void){

    char op[50];
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatorios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe a data:");
    scanf("%s", op);
    getchar();
    printf("///          = = = = =          Dia 27/09/22         = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///     Deposito de Flavius                                                 ///\n");
    printf("///         Valor: 500,00 reais.                                            ///\n");
    printf("///         Tipo: Contribuicao mensal.                                      ///\n");
    printf("///         Descrição: 1/100 do meu salario.                                ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesa cadastrada por Talys                                        ///\n");
    printf("///         Valor: 50,00 reais                                              ///\n");
    printf("///         Tipo: Emergencia                                                ///\n");
    printf("///         Descrição: ventilador quebrado.                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}