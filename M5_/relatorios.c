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
    getchar();
}

void por_datas(void){

    system("clear||cls");
    printf("Em construção");
    getchar();

}