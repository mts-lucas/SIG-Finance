#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../aux/funcoes_auxiliares.h"
#include "receitas_main.h"

char ler_re(void){
  printf("Selecione sua opção:");
  char op;
  scanf("%c" , &op);
  getchar();
  return op;
}

// char ler_res(void){
//   printf("Selecione sua opção:");
//   char st;
//   scanf("%s" , st);
//   getchar();
//   return st[];
// }

// int main(void) {
    
//     // menu_principal_re();
//     gerencia_menu_principal();

//     return 0;
// }


char menu_principal_re(void) {

    
    
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Receita.                                        ///\n");
    printf("///            2. Editar Receita.                                           ///\n");
    printf("///            3. Excluir Receitas.                                         ///\n");
    printf("///            4. Checar historico de receitas.                             ///\n");
    printf("///            5. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char op;
    return op = ler_re();
}

void gerencia_menu_principal(void){
    char op;
    op = menu_principal_re();
    while (op != '0') {
        
        if (op == '1') {
            cadastrar_re();
        }

        else if (op == '2') {
            editar_re();
        }

        else if (op == '3') {

            excluir_re();
            
        }

        else if (op == '4') {
            checar_re();

        }

        else if (op == '5') {
            sobre_re();

        }

        else {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();

        }

        op = menu_principal_re();

        }
    }

void cadastrar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          De qual Morador vai adicionar receita?                         ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    scanf("%s" , morador);
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =       Cadastrar Receita        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Adicionar receita:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///     Descrição:                                                          ///\n");
    char descricao[100];
    scanf("%s" , descricao);
    getchar();
    printf("///     Valor:                                                              ///\n");
    char valor[10];
    scanf("%s" , valor);
    getchar();
    printf("///     Tipo da receita?                                                   ///\n");
    tipos();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          De qual Morador vai adicionar receita?                         ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    scanf("%s" , morador);
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Editar Receita         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Editar   receita:                                                   ///\n");
    char descricao[50];
    scanf("%s" , descricao);
    getchar();
    printf("///     Tipo da receita?                                                    ///\n");
    char valor[50];
    scanf("%s" , valor);
    getchar();
    printf("///     tipo:                                                               ///\n");
    tipos();
    printf("///                                                                                 ///\n");
    printf("///                                                                         ///\n");
    printf("/////////////////////////////////// ////////////////////////////////////////////\n");
    getchar();

}

void excluir_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe de qual morador você deseja excluir receita:                ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    scanf("%s" , morador);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Segue a lista das receitas por ordem cronológica:                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Nome - Data - Valor - Descrição                        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Flavius - 05/09/22 - 15.000,00 - premiação por otimo projeto        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void sobre_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Esse modulo faremos a gestao de receitas onde voce vai poder        ///\n");
    printf("///  cadastrar as suas receitas.                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void tipos(void) {
    printf("1-Contribuição Mensal\n2-Extra\n3-Emergência\n");
    char tipo;
    scanf("%c",&tipo);
    getchar();
}
