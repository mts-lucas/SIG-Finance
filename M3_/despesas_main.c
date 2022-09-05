#include <stdio.h>
#include <stdlib.h>

char menu_principal_dp(void);
void gerencia_menu_principal_dp(void);
char ler(char);
void cadastrar_dp(void);
void editar_dp(void);
void excluir_dp(void);
void checar_dp(void);
void sobre_dp(void);

char ler(char x){

    char op;
    scanf("%c",&x);
    getchar();
    return x;
}

/*char ler() {
     char op;
     scanf("%c", &op);
     getchar();
     
     return op;
}*/

int main(void) {
    
    gerencia_menu_principal_gf();

    return 0;
}

char menu_principal_gf(void) {
    
    char op;
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =         Gerenciamento de Despesas          = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Despesa.                                        ///\n");
    printf("///            2. Editar Despesa.                                           ///\n");
    printf("///            3. Excluir Despesa.                                          ///\n");
    printf("///            4. Pagar Despesa.                                            ///\n");
    printf("///            5. Checar historico de despesa.                              ///\n");
    printf("///            6. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return ler(op);
}

void gerencia_menu_principal_gf(void){
    char op;
    op = menu_principal_gf();
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
        
        op = menu_principal_gf();

        }
    }

void cadastrar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Adicionar receita em qual morador?                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///     Descricao:                                                          ///\n");
    printf("///     Valor:                                                              ///\n");
    printf("///     tipo:                                                               ///\n");
    printf("///     Id de usuario:                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///     (obs: a meta é fazer um for para gerar essa serie de perguntas      ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didatico           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =         Gerenciamento de Despesas          = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void excluir_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =         Gerenciamento de Despesas          = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = =         Gerenciamento de Despesas          = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void sobre_re(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}