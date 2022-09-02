//arquivo referente ao modulo 1:

#include <stdio.h>
#include <stdlib.h>

//void interacao_menu_principal(void); 
char menu_cad_moradores(void);
char ler(char);
 

int main(void) {

    //interacao_menu_principal(void); 

    return 0;
}

char menu_cad_moradores(void) {


    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =       Perfil de Moradores     = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro Morador                                          ///\n");
    printf("///            2. Alterar dados de Morador                                  ///\n");
    printf("///            3. Deletar Morador                                           ///\n");
    printf("///            3. Visualizar Moradores                                      ///\n");
    printf("///            5. Sobre o modulo                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return ler(op);

}

//void interacao_menu_principal(void) {

//}


char ler(char x){
  scanf("%c",&x);
  getchar();
  return x;
}