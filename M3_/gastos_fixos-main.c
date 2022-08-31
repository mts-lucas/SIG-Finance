#include <stdio.h>
#include <stdlib.h>

char menu_principal_gf(void);
void gerencia_menu_principal_gf(void);
char ler(char);
void cadastrar_gf(void);
void editar_gf(void);
void excluir_gf(void);
void checar_gf(void);
void sobre_gf(void);

char ler(char x){
  scanf("%c",&x);
  getchar();
  return x;
}

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
    printf("///             = = = = = Gerenciamento de Gastos Fixos = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar gasto.                                          ///\n");
    printf("///            2. Editar gasto.                                             ///\n");
    printf("///            3. Excluir gastos.                                           ///\n");
    printf("///            4. Checar gastos.                                            ///\n");
    printf("///            5. Sobre o modulo.                                           ///\n");
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
            cadastrar_gf();
        }

        else if (op == '2') {
            editar_gf();
            
        }

        else if (op == '3') {
            excluir_gf();
            
        }

        else if (op == '4') {
            checar_gf();
            
        }

        else if (op == '5') {
            sobre_gf();
        }

        op = menu_principal_gf();

        }
    }

void cadastrar_gf(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Gerenciamento de Gastos Variaveis = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar_gf(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Gerenciamento de Gastos Variaveis = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void excluir_gf(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Gerenciamento de Gastos Variaveis = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar_gf(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Gerenciamento de Gastos Variaveis = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void sobre_gf(void){
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