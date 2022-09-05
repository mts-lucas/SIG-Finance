#include <stdio.h>
#include <stdlib.h>

char menu_principal_re(void);
void gerencia_menu_principal(void);
char ler(char);
void cadastrar_re(void);
void editar_re(void);
void excluir_re(void);
void checar_re(void);
void sobre_re(void);

char ler(char x){
  scanf("%c",&x);
  getchar();
  return x;
}

int main(void) {
    
    // menu_principal_re();
    gerencia_menu_principal();

    return 0;
}

char menu_principal_re(void) {
    
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

void editar_re(void){
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

void excluir_re(void){
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

void checar_re(void){
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

void sobre_re(void){
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