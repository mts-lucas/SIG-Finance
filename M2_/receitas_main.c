#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../auxiliares/funcoes_auxiliares.h"
#include "receitas_main.h"

char ler_re(void)
{
    printf("\t\t\tSelecione sua opção: ");
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
    Saldo *newsaldo;
    newsaldo = (Saldo *)malloc(sizeof(Saldo));
    char cpf[15];
    char descricao[100];
    char valor[11];
    char data[11];

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\tInforme de qual morador você deseja editar a receita:\n");
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
    int tam = strlen(valor);
    newreceita->tipo = tipos_rec();
    ler_data(data);
    newreceita->status = 'C';
    strcpy(newreceita->data, data);
    strcpy(newreceita->cpf, cpf);
    strcpy(newreceita->descricao, descricao);
    // strcpy(newreceita->valor, valor);
    newreceita->valor = transform_to_float(valor, tam);
    newreceita->id = idReceita();

    newsaldo->valor_atual = ultimoSaldo() + transform_to_float(valor, tam);
    newsaldo->valor_despesas =ultimaDespesa();

    mostrarReceita(newreceita);
    mostrarSaldo(newsaldo);
    gravarReceita(newreceita);
    gravarSaldo(newsaldo);
    getchar();
    free(newsaldo);
    free(newreceita);
}

void editar_re(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Editar Receita         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    FILE *fp;
    Receita *rec;
    int achou;
    char resp;
    char procurado[20];
    int aux_id;
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
    printf("\t\t\tBuscamos a receita pelo Id da receita.\n");
    // scanf("%d", &aux_id);
    ler_id(procurado);
    int tam = strlen(procurado);
    aux_id = transform_to_integer(procurado, tam);
    getchar();
    // ler_cpf(procurado);
    rec = (Receita *)malloc(sizeof(Receita));
    achou = 0;
    while ((!achou) && (fread(rec, sizeof(Receita), 1, fp)))
    {
        if ((rec->id == aux_id) && (rec->status == 'C'))
        {
            achou = 1;
        }
    }
    if (achou)
    {
        mostrarReceita(rec);
        printf("\t\t\tDeseja realmente editar esta Receita? (s/n)?\n\t\t\t");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S')
        {

            float valoraux = rec->valor;
            ler_cpf(cpf);
            ler_valordepositado(valor);
            int tam = strlen(valor);
            ler_descricaor(descricao);
            rec->tipo = tipos_rec();

            strcpy(rec->cpf, cpf);
            strcpy(rec->descricao, descricao);
            // strcpy(rec->valor, valor);
            rec->valor = transform_to_float(valor, tam);
            fseek(fp, (-1) * sizeof(Receita), SEEK_CUR);
            fwrite(rec, sizeof(Receita), 1, fp);

            Saldo *newsaldo;
            newsaldo = (Saldo *)malloc(sizeof(Saldo));
            newsaldo->valor_atual = ultimoSaldo() + transform_to_float(valor, tam) - valoraux;
            newsaldo->valor_despesas = ultimaDespesa();
            gravarSaldo(newsaldo);
            free(newsaldo);

            printf("\n\t\t\tREceita editada com sucesso!!!\n");
        }
        else
        {
            printf("\n\t\t\tOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("\t\t\tNão ha receitas cadastradas com esse CPF %d...\n", aux_id);
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
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Excluir Receita        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    FILE *fp;
    Receita *rec;
    int achou;
    char resp;
    char procuradoc[20];
    int procurado;
    fp = fopen("cad-receita-m2.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("\t\t\tBuscamos pelo ID da receita, para apagar a receita: \n");
    // scanf("%d", &procurado);
    ler_id(procuradoc);
    int tam = strlen(procuradoc);
    procurado = transform_to_integer(procuradoc, tam);
    getchar();

    rec = (Receita *)malloc(sizeof(Receita));
    achou = 0;
    while ((!achou) && (fread(rec, sizeof(Receita), 1, fp)))
    {
        if ((rec->id == procurado) && (rec->status == 'C'))
        {
            achou = 1;
        }
    }

    if (achou)
    {
        mostrarReceita(rec);
        printf("\t\t\tDeseja realmente apagar está receita (s/n)?\n\t\t\t");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S')
        {
            rec->status = 'A';
            float valoraux = rec->valor;
            fseek(fp, (-1) * sizeof(Receita), SEEK_CUR);
            fwrite(rec, sizeof(Receita), 1, fp);
            Saldo *newsaldo;
            newsaldo = (Saldo *)malloc(sizeof(Saldo));
            newsaldo->valor_atual = ultimoSaldo() - valoraux;
            newsaldo->valor_despesas = ultimaDespesa();
            gravarSaldo(newsaldo);
            free(newsaldo);
            printf("\n\t\t\tReceita excluído com sucesso!!!\n");
        }
        else
        {
            printf("\n\t\t\tOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("\t\t\tA receita do morador com esse cpf %d não foi encontrada...\n", procurado);
        getchar();
    }
    free(rec);
    fclose(fp);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Excluir Receita        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

void checar_re(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Exibir Receitas        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Exibir Receitas        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\tPressione enter pra sair");
}

void buscar_receita(void)
{

    FILE *fp;
    Receita *rec;
    int resultado;
    int aux_id;
    char procurando[20];

    fp = fopen("cad-receita-m2.dat", "rb");
    if (fp == NULL)
    {
        /* code */
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("\t\t\tBuscamos a receita pelo Id da receita.\n");
    // scanf("%d", &aux_id);
    ler_id(procurando);
    int tam = strlen(procurando);
    aux_id = transform_to_integer(procurando, tam);
    rec = (Receita *)malloc(sizeof(Receita));
    resultado = 0;
    while ((!resultado) && (fread(rec, sizeof(Receita), 1, fp)))
    {
        /* code */
        if ((rec->id == aux_id) && (rec->status == 'C'))
        {
            /* code */
            resultado = 1;
        }
    }
    fclose(fp);
    if (resultado)
    {
        /* code */
        mostrarReceita(rec);
        getchar();
    }
    else
    {
        printf("\t\t\tReceita com o ID %d não encontrada...", aux_id);
        printf("\n\t\t\tPressione enter para sair");
    }
    free(rec);
}

void mostrarReceita(Receita *newreceita)
{
    // system("clear||cls");
    printf("\n\t\t\tCPF do Morador: %s", newreceita->cpf);
    printf("\n\t\t\tDescrição: %s", newreceita->descricao);
    printf("\n\t\t\tTipo: %c", newreceita->tipo);
    printf("\n\t\t\tValor: %.2f", newreceita->valor);
    printf("\n\t\t\tId: %d", newreceita->id);
    printf("\n\t\t\tData: %s", newreceita->data);
    printf("\n");
    // getchar();
}

void mostrarRecdin(RecDin *novo)
{
    // system("clear||cls");
    printf("\n\t\t\tCPF do Morador: %s", novo->cpf);
    printf("\n\t\t\tDescrição: %s", novo->descricao);
    printf("\n\t\t\tTipo: %c", novo->tipo);
    printf("\n\t\t\tValor: %.2f", novo->valor);
    printf("\n\t\t\tId: %d", novo->id);
    printf("\n\t\t\tData: %s", novo->data);
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