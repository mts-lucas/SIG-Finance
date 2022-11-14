#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../auxiliares/funcoes_auxiliares.h"
#include "receitas_main.h"

char ler_re(void)
{
    printf("Selecione sua opção:");
    char op;
    scanf("%c", &op);
    getchar();
    return op;
}

char menu_principal_re(void)
{

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        = = = = =              SIG - FINANCE            = = = = =        ///\n");
    printf("///        = = = = =        Gerenciamento de Receitas      = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Receita.                                        ///\n");
    printf("///            2. Editar Receita.                                           ///\n");
    printf("///            3. Excluir Receitas.                                         ///\n");
    printf("///            4. Checar historico de receitas.                             ///\n");
    printf("///            5. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char op;
    return op = ler_re();
}

void gerencia_menu_principal(void)
{
    char op;
    op = menu_principal_re();
    while (op != '0')
    {

        if (op == '1')
        {
            preenche_receita();
        }

        else if (op == '2')
        {
            editar_re();
        }

        else if (op == '3')
        {

            excluir_re();
        }

        else if (op == '4')
        {
            checar_re();
            getchar();
        }

        else if (op == '5')
        {
            sobre_re();
        }

        else
        {
            printf("\n\t Opcao invalida. digite outra...");
            getchar();
        }

        op = menu_principal_re();
    }
}

void preenche_receita(void)
{
    system("clear||cls");
    Receita *newreceita;
    newreceita = (Receita *)malloc(sizeof(Receita));

    char cpf[15];
    char descricao[100];
    char valor[11];

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    ler_cpf(cpf);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =       Cadastrar Receita        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    ler_descricaor(descricao);
    ler_valordepositado(valor);
    newreceita->tipo = tipos_rec();
    newreceita->status = 'C';
    strcpy(newreceita->cpf, cpf);
    strcpy(newreceita->descricao, descricao);
    strcpy(newreceita->valor, valor);
    mostrarReceita(newreceita);
    gravarReceita(newreceita);
    getchar();
    free(newreceita);
}

void editar_re(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n          De qual Morador vai adicionar receita?                             \n");
    char morador[50];
    int tam;
    do
    {
        printf("            De qual Morador vai adicionar receita?                            \n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Editar Receita         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n          Descrição:                                                      \n");
    char descricao[50];
    scanf("%s", descricao);
    getchar();
    char valor[50];
    do
    {
        printf("\n          Valor da receita?                                                       \n");
        scanf("%s", valor);
        getchar();
        tam = strlen(valor);
    } while (!(validar_dinheiro(valor, tam)));
    printf("            tipo:                                                                  \n");
    tipos();
    getchar();
}

void excluir_re(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char morador[50];
    int tam;
    do
    {
        printf("            Informe de qual morador você deseja excluir receita:                   \n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    getchar();
}

void checar_re(void)
{
    system("clear||cls");
    FILE *fp1;
    Receita *rc;
    fp1 = fopen("cad-receita-m2.dat", "rb");
    if (fp1 == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    rc = (Receita *)malloc(sizeof(Receita));
    while (fread(rc, sizeof(Receita), 1, fp1))
    {
        if (rc->status == 'C')
        {
            mostrarReceita(rc);
        }
    }
    fclose(fp1);
    free(rc);
}

void mostrarReceita(Receita *newreceita)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n          CPF do Morador: %s", newreceita->cpf);
    printf("\n          Descrição: %s", newreceita->descricao);
    printf("\n          Tipo: %c", newreceita->tipo);
    printf("\n          Valor: %s", newreceita->valor);
    printf("\n");
    getchar();
}

void sobre_re(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Esse modulo faremos a gestao de receitas onde voce vai poder        ///\n");
    printf("///  cadastrar as suas receitas.                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void gravarReceita(Receita *newreceita)
{
    FILE *fp1;
    fp1 = fopen("cad-receita-m2.dat", "ab");
    if (fp1 == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(newreceita, sizeof(Receita), 1, fp1);
    fclose(fp1);
}