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
    printf("///     mas por enquanto vamos deixar assim para ficar mais didatico        ///\n");
    printf("///     o que vamos fazer)                                                  ///\n");
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
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe de qual morador voce quer alterar a receita:                ///\n");
    printf("///                                                                         ///\n");
    printf("///     1 - Lucas                                                           ///\n");
    printf("///     2 - Tallys                                                          ///\n");
    printf("///     3 - Flavius                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///     (obs: a partir dai segue o mesmo como no menu de cadastro)          ///\n");
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
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe de qual morador voce quer alterar a receita:                ///\n");
    printf("///                                                                         ///\n");
    printf("///     1 - Lucas                                                           ///\n");
    printf("///     2 - Tallys                                                          ///\n");
    printf("///     3 - Flavius                                                         ///\n");
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
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Segue a lista das receitas por ordem cronologica:                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Nome - Data - Valor - Descricao                        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Flavius - 05/09/22 - 15.000,00 - premiacao por otimo projeto        ///\n");
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
    printf("///     = = = = =        Gerenciamento de Receitas           = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///     Em desenvolvimento... Pressione qualquer tecla para voltar ao       ///\n");
    printf("/// menu principal                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}