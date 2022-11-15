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
            system("clear||cls");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                         ///\n");
            printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
            printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("            Informe de qual morador você deseja editar a receita:\n");
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
    FILE *fp;
    Receita *rec;
    int achou;
    char resp;
    char procurado[15];
    char cpf[15];
    char descricao[100];
    char valor[11];

    fp = fopen("cad-receita-m2.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("Buscamos a receita pelo CPF do morador.\n");
    ler_cpf(procurado);
    rec = (Receita *)malloc(sizeof(Receita));
    achou = 0;
    while ((!achou) && (fread(rec, sizeof(Receita), 1, fp)))
    {
        if ((strcmp(rec->cpf, procurado) == 0) && (rec->status == 'C'))
        {
            achou = 1;
        }
    }
    if (achou)
    {
        mostrarReceita(rec);
        printf("Deseja realmente editar esta Receita? (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S')
        {

            ler_cpf(cpf);
            ler_valordepositado(valor);
            ler_descricaor(descricao);
            rec->tipo = tipos_rec();

            strcpy(rec->cpf, cpf);
            strcpy(rec->descricao, descricao);
            strcpy(rec->valor, valor);
            fseek(fp, (-1) * sizeof(Receita), SEEK_CUR);
            fwrite(rec, sizeof(Receita), 1, fp);
            printf("\nREceita editada com sucesso!!!\n");
        }
        else
        {
            printf("\nOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("Não ha receitas cadastradas com esse CPF %s...\n", procurado);
        getchar();
    }
    free(rec);
    fclose(fp);

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Editar Receita         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    // antes de implementar a busca no arquivo, usar mesma coisa q no preencher com strcpy
    getchar();
}

void excluir_re(void)
{
    // system("clear||cls");
    // char cpf[15]; // sempre buscar pelo cpf
    // printf("///////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                         ///\n");
    // printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    // printf("///          = = = = =    Gerenciamento de Receita    = = = = =             ///\n");
    // printf("///                                                                         ///\n");
    // printf("///////////////////////////////////////////////////////////////////////////////\n");
    // printf("            Informe de qual morador você deseja excluir receita:\n");
    // ler_cpf(cpf);

    // fazer a exclusão logica a partir daqui

    FILE *fp;
    Receita *rec;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("cad-receita-m2.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("Buscamos pelo CPF do morador, para apagar receita: \n");
    ler_cpf(procurado);
    rec = (Receita *)malloc(sizeof(Receita));
    achou = 0;
    while ((!achou) && (fread(rec, sizeof(Receita), 1, fp)))
    {
        if ((strcmp(rec->cpf, procurado) == 0) && (rec->status == 'C'))
        {
            achou = 1;
        }
    }

    if (achou)
    {
        mostrarReceita(rec);
        printf("Deseja realmente apagar está receita (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S')
        {
            rec->status = 'A';
            fseek(fp, (-1) * sizeof(Receita), SEEK_CUR);
            fwrite(rec, sizeof(Receita), 1, fp);
            printf("\nReceita excluído com sucesso!!!\n");
        }
        else
        {
            printf("\nOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("A receita do morador com esse cpf %s não foi encontrada...\n", procurado);
        getchar();
    }
    free(rec);
    fclose(fp);
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
    // system("clear||cls");
    printf("\n          CPF do Morador: %s", newreceita->cpf);
    printf("\n          Descrição: %s", newreceita->descricao);
    printf("\n          Tipo: %c", newreceita->tipo);
    printf("\n          Valor: %s", newreceita->valor);
    printf("\n");
    // getchar();
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