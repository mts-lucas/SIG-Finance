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
            printf("\n\t Opção invalida. digite outra...");
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
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Pesquisar por data                                        ///\n");
    printf("///            2. Pesquisar por período de tempo                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opção:");
    scanf("%c", &op);
    getchar();
    return op;
}

void entre_datas(void){

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Data inicial: 20/09/22                                              ///\n");
    printf("///     Data final: 24/09/22                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///     De 20/09/22 a 24/09/22                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///     Depósito de Talys                                                   ///\n");
    printf("///         Valor: 10,00 reais                                              ///\n");
    printf("///         Tipo: Extra                                                     ///\n");
    printf("///         Descrição: achei na rua.                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesas cadastrada por Lucas                                       ///\n");
    printf("///         Valor: 50,00 reais.                                             ///\n");
    printf("///         Tipo: Contas mensais.                                           ///\n");
    printf("///         Descrição:                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Deposito de Flavius                                                 ///\n");
    printf("///         Valor: 500,00 reais.                                            ///\n");
    printf("///         Tipo: Contribuição mensal.                                      ///\n");
    printf("///         Descrição: 1/100 do meu salário.                                ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesa cadastrada por Talys                                        ///\n");
    printf("///         Valor: 50,00 reais                                              ///\n");
    printf("///         Tipo: Emergência                                                ///\n");
    printf("///         Descrição: ventilador quebrado.                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void por_datas(void){

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Escolha a data: (hoje 27/09/22)                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          Dia 27/09/22         = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///     Deposito de Flavius                                                 ///\n");
    printf("///         Valor: 1000,00 reais.                                           ///\n");
    printf("///         Tipo: Contribuição mensal.                                      ///\n");
    printf("///         Descrição: 1/100 do meu salário.                                ///\n");
    printf("///                                                                         ///\n");
    printf("///     Despesa cadastrada por Talys                                        ///\n");
    printf("///         Valor: 110,00 reais                                             ///\n");
    printf("///         Tipo: Contas mensais                                            ///\n");
    printf("///         Descrição: Aluguel.                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}