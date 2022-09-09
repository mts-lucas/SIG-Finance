#include <stdio.h>
#include <stdlib.h>

char menu_principal_dp(void);
void gerencia_menu_principal_dp(void);
char ler(void);
void cadastrar_dp(void);
void editar_dp(void);
void excluir_dp(void);
void checar_dp(void);
void sobre_dp(void);
void pagar_dp(void);

char ler(void){
  printf("Selecione sua opção:");
  char op;
  scanf("%c" , &op);
  getchar();
  return op;
}

/*char ler() {
     char op;
     scanf("%c", &op);
     getchar();
     
     return op;
}*/

int main(void) {
    
    gerencia_menu_principal_dp();

    return 0;
}

char menu_principal_dp(void) {
    
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
    printf("///            4. Checar historico de despesa.                              ///\n");
    printf("///            5. Pagar Despesa.                                            ///\n");
    printf("///            6. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char op;
    return op = ler();
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
            printf("\n\t Opcao invalida. digite outra...");
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
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          De qual Morador cadastrar despesa?                            ///\n");
    char morador[50];
    scanf("%s" , morador);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Adicionar receita em qual morador?                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///     Descricao:                                                          ///\n");
    char descricao[50];
    scanf("%s" , descricao);
    printf("///     Valor:                                                              ///\n");
    char valor[50];
    scanf("%s" , valor);
    printf("///     tipo:                                                               ///\n");
    char tipo[50];
    scanf("%s" , tipo);
    printf("///                                                                         ///\n");
    printf("///     (obs: a meta é fazer um for para gerar essa serie de perguntas      ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didatico           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
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
    printf("///          1. Lucas                                                       ///\n");
    printf("///          2. Tallys                                                      ///\n");
    printf("///          3. Flavius                                                     ///\n");
    printf("///                                                                         ///\n");
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

void excluir_dp(void){
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          De qual Morador vai excluir a despesa? (Atencao, excluir       ///\n");
    printf("///                                             é diferente de pagar...)    ///\n");
    printf("///          1. Lucas                                                       ///\n");
    printf("///          2. Tallys                                                      ///\n");
    printf("///          3. Flavius                                                     ///\n");
    printf("///                                                                        ///\n");
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
    printf("///     (obs: a meta é fazer um 'for' para gerar essa serie de despesas     ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didatico           ///\n");
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
    printf("///          De qual Morador vai pagar a despesa?                           ///\n");
    printf("///                                                                         ///\n");
    printf("///          1. Lucas                                                       ///\n");
    printf("///          2. Tallys                                                      ///\n");
    printf("///          3. Flavius                                                     ///\n");
    printf("///                                                                         ///\n");
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
    printf("///  mas por enquanto vamos deixar assim para ficar mais didatico           ///\n");
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
    printf("///  mas por enquanto vamos deixar assim para ficar mais didatico           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar(); 
}

void sobre_dp(void){
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Modulo encarregado para gerenciamento das despesas, aqui fica       ///\n");
    printf("///  a parte onde vamos cuidar das despesas, que vai influenciar            ///\n");
    printf("///  diretamente no saldo.                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar(); 
}