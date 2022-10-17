#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesas_main.h"
#include "../aux/funcoes_auxiliares.h"


char ler_dp(void){
  printf("Selecione sua opção:");
  char op;
  scanf("%c" , &op);
  getchar();
  return op;
}


char menu_principal_dp(void) {
    
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Finanças Domésticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =         Gerenciamento de Despesas          = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Despesa.                                        ///\n");
    printf("///            2. Editar Despesa.                                           ///\n");
    printf("///            3. Excluir Despesa.                                          ///\n");
    printf("///            4. Checar historico de Despesa.                              ///\n");
    printf("///            5. Pagar Despesa.                                            ///\n");
    printf("///            6. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char op;
    return op = ler_dp();
}

void gerencia_menu_principal_dp(void){
    char op;
    op = menu_principal_dp();
    while (op != '0') {
        
        if (op == '1') {
            cadastrar_dp();
        }

        else if (op == '2') {
            editar_dp();
            
        }

        else if (op == '3') {
            excluir_dp();
            
        }

        else if (op == '4') {
            checar_dp();
            
        }

        else if (op == '5') {
            pagar_dp();
        }

        else if (op == '6') {
            sobre_dp();
        }

        else {
            printf("\n\t Opção inválida. digite outra...");
            getchar();

        }
        
        op = menu_principal_dp();

        }
    }

void cadastrar_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    int tam;
    // scanf("%s" , morador);
    // printf("///                                                                         ///\n");
    // printf("///////////////////////////////////////////////////////////////////////////////\n");
    do
    {
        printf("///          De qual Morador vai cadastrar a despesa?                       ///\n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Descrição:                                                          ///\n");
    char descricao[50];
    scanf("%s" , descricao);
    char valor[50];
    // scanf("%s" , valor);
    do
    {
        printf("///     Valor:                                                              ///\n");
        scanf("%s", valor);
        getchar();
        tam = strlen(valor);
    } while (!(validar_dinheiro(valor, tam)));
    printf("///     Tipo da despesa:                                                    ///\n");
    tipos_d();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          De qual Morador vai editar a despesa?                          ///\n");
    char morador[50];
    int tam;
    // scanf("%s" , morador);
    do
    {
        printf("///          De qual Morador vai cadastrar a despesa?                       ///\n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Editar despesa:                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///     Descrição:                                                          ///\n");
    char descricao_d[50];
    scanf("%s", descricao_d);
    char valor_d[50];
    // scanf("%s", valor_d);
    // getchar();
    do
    {
        printf("///     Valor:                                                              ///\n");
        scanf("%s", valor_d);
        getchar();
        tam = strlen(valor_d);
    } while (!(validar_dinheiro(valor_d, tam)));
    printf("///     Tipo da despesa:                                                    ///\n");
    tipos_d();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void excluir_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    int tam;
    // scanf("%s" , morador);
    // printf("///////////////////////////////////////////////////////////////////////////////\n");
    // getchar();
    do
    {
        printf("///          De qual Morador vai excluir a despesa? (Atenção, excluir       ///\n");
        printf("///                                             é diferente de pagar...)    ///\n");        
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Excluir qual despesa:                                               ///\n");
    printf("///                                                                         ///\n");
    printf("///     1 - Despesa abc                                                     ///\n");
    printf("///     2 - Despesa abc                                                     ///\n");
    printf("///     3 - Despesa abc                                                     ///\n");
    printf("///     4 - Despesa abc                                                     ///\n");
    printf("///     5 - Despesa abc                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///     (obs: a meta é fazer um 'for' para gerar essa série de despesas     ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didático           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  
}

void pagar_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    char morador[50];
    int tam;
    // scanf("%s", morador);
    do
    {
        printf("///          De qual Morador vai cadastrar a despesa?                       ///\n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Pagar qual despesa:                                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///     1 - Despesa abc                                                     ///\n");
    printf("///     2 - Despesa abc                                                     ///\n");
    printf("///     3 - Despesa abc                                                     ///\n");
    printf("///     4 - Despesa abc                                                     ///\n");
    printf("///     5 - Despesa abc                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///     (obs: a meta é fazer um 'for' para gerar essa serie de despesas     ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didático           ///\n");
    printf("///  o que vamos fazer, pagando com base na receita e/ou no saldo)          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  
}

void checar_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Lista de despesas:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///     1 - Despesa abc                                                     ///\n");
    printf("///     2 - Despesa abc                                                     ///\n");
    printf("///     3 - Despesa abc                                                     ///\n");
    printf("///     4 - Despesa abc                                                     ///\n");
    printf("///     5 - Despesa abc                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///     (obs: a meta é fazer um 'for' para gerar essa serie de despesas     ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didático           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar(); 
}

void sobre_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Modulo encarregado do gerenciamento das despesas, aqui fica         ///\n");
    printf("///  a parte onde vamos cadastrar as despesas, que vai influenciar            ///\n");
    printf("///  diretamente no saldo.                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar(); 
}

void tipos_d(void) {
    printf("1-Contribuição Mensal\t2-Extra\t3-Emergência\n");
    char tipo;
    scanf("%c",&tipo);
    getchar();
}