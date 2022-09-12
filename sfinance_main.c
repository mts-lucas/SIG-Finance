///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///    Projeto Sistema de Sistema de Controle de Finanças Domésticas        ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 3                                 ///
///////////////////////////////////////////////////////////////////////////////

// LEMBRAR DE NÃO USAR ACENTO E ESSAS COIAS Q DA B.O QUANDO COMPILA!!!!!
// OLHAR TODOS OS COMENTS

#include <stdio.h>
#include <stdlib.h>
#include "M1_/cadastro_moradores_main.h"
#include "M2_/receitas_main.h"
#include "M3_/despesas_main.h"


// Assinatura das funções

char menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void consideracoes_finais(void);
void interacao_menu_principal(void);
char menu_informacoes(void);
void interecao_informacoes(void);


// Programa principal

// char nome_morador[51], cpf_morador[11], idade_morador[4], ocupacao_morador[12], renda_morador[7];

int main(void)
{
    interacao_menu_principal();

    return 0;
}

// Funções da tela principal

char menu_principal(void)
{
    char op;

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
    printf("///            2. Receitas                                                  ///\n");
    printf("///            3. Despesas                                                  ///\n");
    printf("///            4. Investimentos                                             ///\n");
    printf("///            5. Informacoes sobre o Projeto                               ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opcao:");
    scanf("%c", &op);
    getchar();
    return op;
}

void tela_sobre(void)
{
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

void tela_equipe(void)
{
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

void consideracoes_finais(void)
{
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
    getchar();
}

void interacao_menu_principal(void)
{

    char op;
    op = menu_principal();
    while (op != '0')
    {

        if (op == '1')
        {
            interacao_menu_cad_morador();
        }

        else if (op == '2')
        {
            gerencia_menu_principal();
        }

        else if (op == '3')
        {
            gerencia_menu_principal_dp();
        }

        else if (op == '4')
        {
            printf("Em contrucao");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }

        else if (op == '5')
        {
            interecao_informacoes();
        }
        else
        {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();
        }

        op = menu_principal();
    }
}

char menu_informacoes(void)
{

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =  Informacoes sobre o Projeto   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Equipe                                                    ///\n");
    printf("///            2. Sobre                                                     ///\n");
    printf("///            3. Consideracoes finais                                      ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opcao:");
    char op;
    scanf("%c", &op);
    getchar();
    return op;
}

void interecao_informacoes(void)
{

    char op;
    op = menu_informacoes();
    while (op != '0')
    {

        if (op == '1')
        {
            tela_equipe();
        }

        else if (op == '2')
        {
            tela_sobre();
        }

        else if (op == '3')
        {
            consideracoes_finais();
        }

        else
        {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();
        }

        op = menu_informacoes();
    }
}