#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "../auxiliares/funcoes_auxiliares.h"
#include "../M3_/despesas_main.h"
#include "../M2_/receitas_main.h"
#include "../M1_/cadastro_moradores_main.h"

void interacao_menu_relatorios(void)
{

    char op;
    op = menu_relatorios();
    while (op != '0')
    {

        if (op == '1')
        {
            checar_dp();
        }

        else if (op == '2')
        {
            checar_re();
        }

        else if (op == '4')
        {
            buscar_receita();
        }

        else if (op == '3')
        {
            buscar_despesa();
        }

        else if (op == '5')
        {
            buscarUm();
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
    printf("///            1. Mostrar todas as Despesas                                 ///\n");
    printf("///            2. Mostrar todas as Recetias                                 ///\n");
    printf("///            3. Pesquisar Despesa por ID                                  ///\n");
    printf("///            4. Pesquisar Receita por ID                                  ///\n");
    printf("///            5. Pesquisar Morador por CPF                                 ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opção:");
    scanf("%c", &op);
    getchar();
    return op;
}


