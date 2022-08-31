#include <stdio.h>
#include <stdlib.h>

char menu_principal_gv(void);
void gerencia_menu_principal(void);
char ler(char);
void cadastrar(void);
void editar(void);
void excluir(void);
void checar(void);
void sobre(void);

char ler(char x){
  scanf("%c",&x);
  getchar();
  return x;
}

int main(void) {
    
    // menu_principal_gv();
    gerencia_menu_principal();

    return 0;
}

char menu_principal_gv(void) {
    
    char op;
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
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

void gerencia_menu_principal(void){
    char op;
    op = menu_principal_gv();
    while (op != '0') {
        
        if (op == '1') {
            cadastrar();
        }

        else if (op == '2') {
            editar();
            
        }

        else if (op == '3') {
            excluir();
            
        }

        else if (op == '4') {
            checar();
            
        }

        else if (op == '5') {
            sobre();
        }

        op = menu_principal_gv();

        }
    }

void cadastrar(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void excluir(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void sobre(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     = = = = = Sistema de Controle de Financas Domesticas = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///           = == = = Gerenciamento de Gastos Variaveis = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}