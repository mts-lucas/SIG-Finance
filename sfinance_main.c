///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///    Projeto Sistema de Sistema de Controle de Finanças Domésticas        ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 2                                 ///
///////////////////////////////////////////////////////////////////////////////


//LEMBRAR DE NÃO USAR ACENTO E ESSAS COIAS Q DA B.O QUANDO COMPILA!!!!!
//Telas bunitinhas hehe


#include <stdio.h>

// Assinatura das funções

void menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void consideracoes_finais(void);

// Programa principal

int main(void) {

    menu_principal();
    tela_sobre();
    tela_equipe();
    consideracoes_finais();
    return 0;
}


/////
// Funções da tela principal

void menu_principal(void) {

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///         Projeto Sistema de Controle de Financas Domesticas              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Perfil de Moradores                                       ///\n");
    printf("///            2. Modulo de gestao de gastos a curto prazo                  ///\n");
    printf("///            3. Modulo de gestao de gatos fixos                           ///\n");
    printf("///            4. Modulo de indicacao de investimentos                      ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

//ja arrumei a descrição

void tela_sobre(void) {

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///          Projeto Sistema de Controle de Financas Domesticas             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///  O controle de financas domesticas e uma das atividades necessarias     ///\n");
    printf("///  em praticamente todas as residencias, uma vez que para conseguir       ///\n");
    printf("///  equilibrar o orcamento domestico e evitar o acumulo de dividas, se faz ///\n");
    printf("///  necessario monitorar entradas e saidas de recursos. Tal atividade pode ///\n");
    printf("///  demandar tempo e esforco, principalmente se for realizado sem a ajuda  ///\n");
    printf("///  de um software. O presente projeto tem como objetivo desenvolver um    ///\n");
    printf("///  programa de computador que realize o acompanhamento do fluxo           ///\n");
    printf("///  financeiro em uma residencia, evitando o descontrole de gastos.        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


//Add seus dados iguais os meus aqui

void tela_equipe(void) {

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacoo e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///         Projeto Sistema de Controle de Financas Domesticas              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            Este projeto exemplo foi desenvolvido por:                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Lucas Mateus da Silva                                        ///\n");
    printf("///            E-mail: lmateus1067@outlook.com                              ///\n");
    printf("///            Redes sociais: @iam.lusca                                    ///\n");
    printf("///            Github: https://github.com/W1ndeck/SIG-Finance/tree/Lucas    ///\n");
    printf("///                                                                         ///\n");
    printf("///            Tallys Aureliano Dantas dos Santos                           ///\n");
    printf("///            E-mail: tallysaureliano@outlook.com                          ///\n");
    printf("///            Redes sociais: @aureliano_tallys                             ///\n");
    printf("///            Github: https://github.com/W1ndeck/SIG-Finance/tree/tallys   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Codigo fonte do projeto disponivel em:                       ///\n");
    printf("///            https://github.com/W1ndeck/SIG-Finance                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
} 

void consideracoes_finais(void) {

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacoo e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///         Projeto Sistema de Controle de Financas Domesticas              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Ola espero que tenha gostado, segostou deixe o seu Starred, se      ///\n");
    printf("/// nao gostou em contato com a gente, voce pode nos ajudar com melhorias   ///\n");
    printf("/// no nosso sistema. O projeto esta em contante desenvolvimento e ele      ///\n");
    printf("/// contar com voce! Vamos nessa!                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///     - Lucas e Tallys                                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
} 