#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesas_main.h"
#include "../auxiliares/funcoes_auxiliares.h"

char ler_dp(void)
{
    printf("\t\t\tSelecione sua opção:");
    char op;
    scanf("%c", &op);
    getchar();
    return op;
}

char menu_principal_dp(void)
{

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        = = = = =              SIG - FINANCE            = = = = =        ///\n");
    printf("///        = = = = =       Gerenciamento de Despesas       = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Despesa.                                        ///\n");
    printf("///            2. Editar Despesa.                                           ///\n");
    printf("///            3. Excluir Despesa.                                          ///\n");
    printf("///            4. Checar historico de Despesa.                              ///\n");
    printf("///            5. Pagar Despesa.                                            ///\n");
    printf("///            6. Sobre o modulo.                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char op;
    return op = ler_dp();
}

void gerencia_menu_principal_dp(void)
{
    char op;
    op = menu_principal_dp();
    while (op != '0')
    {

        if (op == '1')
        {
            preenche_despesa();
        }

        else if (op == '2')
        {
            editar_dp();
        }

        else if (op == '3')
        {
            excluir_dp();
        }

        else if (op == '4')
        {
            checar_dp();
            getchar();
        }

        else if (op == '5')
        {
            pagar_dp();
        }

        else if (op == '6')
        {
            sobre_dp();
        }

        else
        {
            printf("\n\t Opção inválida. digite outra...");
            getchar();
        }

        op = menu_principal_dp();
    }
}

void preenche_despesa(void)
{
    system("clear||cls");
    Despesa *newdespesa;
    newdespesa = (Despesa *)malloc(sizeof(Despesa));
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
    printf("\t\t\tDe qual Morador vai cadastrar a despesa?\n");
    ler_cpf(cpf);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    ler_descricaor(descricao);
    ler_valordepositado(valor);
    int tam = strlen(valor);
    newdespesa->tipo = tipos_despesa();
    ler_data(data);
    newdespesa->status = 'C';
    newdespesa->sitacao = 'D';
    newdespesa->id = idDespesa();

    newsaldo->valor_despesas = ultimaDespesa() + transform_to_float(valor, tam);
    newsaldo->valor_atual = ultimoSaldo();

    strcpy(newdespesa->data, data);
    strcpy(newdespesa->cpf, cpf);
    strcpy(newdespesa->descricao, descricao);
    // strcpy(newdespesa->valor, valor);
    newdespesa->valor = transform_to_float(valor, tam);
    mostrarDesepesa(newdespesa);
    mostrarSaldo(newsaldo);
    gravarDesepesa(newdespesa);
    gravarSaldo(newsaldo);
    free(newsaldo);
    free(newdespesa);
    printf("\n\t\t\tAperte enter para sair");
    getchar();
}

void editar_dp(void)
{
    // abrir o arquivo e tals
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Editar Despesa        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    FILE *fp;
    Despesa *des;
    int achou;
    char resp;
    int procurado;
    char cpf[15];
    char descricao[100];
    char valor[11];

    fp = fopen("cad-despesa-m3.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("\t\t\tBuscamos a Despesas pelo ID da Despesa .\n\t\t\t");
    scanf("%d", &procurado);
    getchar();
    des = (Despesa *)malloc(sizeof(Despesa));
    achou = 0;
    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp)))
    {
        if ((des->id == procurado) && (des->status == 'C'))
        {
            achou = 1;
        }
    }
    if (achou)
    {
        mostrarDesepesa(des);
        printf("\t\t\tDeseja realmente editar esta Despesa? (s/n)?\n\t\t\t");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S')
        {
            float valoraux = des->valor;
            ler_cpf(cpf);
            ler_valordepositado(valor);
            int tam = strlen(valor);
            ler_descricaor(descricao);
            des->tipo = tipos_despesa();

            strcpy(des->cpf, cpf);
            strcpy(des->descricao, descricao);
            // strcpy(des->valor, valor);
            des->valor = transform_to_float(valor, tam);
            fseek(fp, (-1) * sizeof(Despesa), SEEK_CUR);
            fwrite(des, sizeof(Despesa), 1, fp);

            Saldo *newsaldo;
            newsaldo = (Saldo *)malloc(sizeof(Saldo));
            newsaldo->valor_atual = ultimoSaldo();
            newsaldo->valor_despesas = ultimaDespesa() + transform_to_float(valor, tam) - valoraux;
            gravarSaldo(newsaldo);
            free(newsaldo);

            printf("\n\t\t\tDespesa editada com sucesso!!!\n");
        }
        else
        {
            printf("\n\t\t\tOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("\t\t\tNão ha Despesas cadastradas com esse ID %d...\n", procurado);
        printf("\n\t\t\tPressione Enter para sair");
        getchar();
    }
    free(des);
    fclose(fp);

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Editar Despesa         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\tPressione Enter para sair");
    getchar();
}

void excluir_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Excluir Despesa        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    FILE *fp;
    Despesa *des;
    int achou;
    char resp;
    int procurado;
    fp = fopen("cad-despesa-m3.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("\t\t\tLembrando que apagar despesa é diferente de pagar!!!\n");
    printf("\t\t\tBuscamos pelo ID da despesa, para apagar a despesa: \n\t\t\t");
    scanf("%d", &procurado);
    getchar();
    des = (Despesa *)malloc(sizeof(Despesa));
    achou = 0;
    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp)))
    {
        if ((des->id == procurado) && (des->status == 'C'))
        {
            achou = 1;
        }
    }

    if (achou)
    {
        mostrarDesepesa(des);
        printf("\t\t\tDeseja realmente apagar está Despesa (s/n)?\n\t\t\t");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S')
        {
            float valoraux = des->valor;
            des->status = 'A';
            fseek(fp, (-1) * sizeof(Despesa), SEEK_CUR);
            fwrite(des, sizeof(Despesa), 1, fp);

            Saldo *newsaldo;
            newsaldo = (Saldo *)malloc(sizeof(Saldo));
            newsaldo->valor_despesas = ultimaDespesa() - valoraux;
            newsaldo->valor_atual = ultimoSaldo();
            gravarSaldo(newsaldo);
            free(newsaldo);

            printf("\n\t\t\tDespesa excluída com sucesso!!!\n");
        }
        else
        {
            printf("\n\t\t\tOk, os dados não foram alterados\n");
        }
    }
    else
    {
        printf("\t\t\tA despesa do morador com esse ID %d não foi encontrada...\n", procurado);
        printf("\n\t\t\tPressione Enter para sair");
        getchar();
    }
    free(des);
    fclose(fp);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Excluir Despesa        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t Pressione Enter para sair");
    getchar();
}

void pagar_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Pagar Despesa         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    FILE *fp;
    Despesa *des;
    int achou;
    char resp;
    int procurado;
    fp = fopen("cad-despesa-m3.dat", "r+b");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("\t\t\tBuscamos pelo ID da despesa, para pagar despesa: \n");
    scanf("%d", &procurado);
    getchar();
    des = (Despesa *)malloc(sizeof(Despesa));
    achou = 0;
    while ((!achou) && (fread(des, sizeof(Despesa), 1, fp)))
    {
        if ((des->id == procurado) && (des->status == 'C') && (des->sitacao == 'D'))
        {
            achou = 1;
        }
    }

    if (achou)
    {
        mostrarDesepesa(des);
        printf("\t\t\tDeseja realmente pagar está Despesa (s/n)? Esse pagamento será descontado no saldo\n\t\t\t");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S')
        {
            float valoraux = des->valor;
            des->sitacao = 'Q';
            fseek(fp, (-1) * sizeof(Despesa), SEEK_CUR);
            fwrite(des, sizeof(Despesa), 1, fp);

            Saldo *newsaldo;
            newsaldo = (Saldo *)malloc(sizeof(Saldo));
            newsaldo->valor_despesas = ultimaDespesa() - valoraux;
            newsaldo->valor_atual = ultimoSaldo() - valoraux;
            gravarSaldo(newsaldo);
            mostrarSaldo(newsaldo);
            free(newsaldo);

            printf("\n\t\t\tDespesa quitada com sucesso!!!\n");
            printf("\n\t\t\tPressione Enter");
            getchar();
        }
        else
        {
            printf("\n\t\t\tOk, a despesa não foi paga\n");
        }
    }
    else
    {
        printf("\t\t\tA despesa do morador com esse ID %d não foi encontrada... Ou já foi paga\n", procurado);
        printf("\n\t\t\tPressione Enter para sair");
        getchar();
    }
    free(des);
    fclose(fp);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =          Pagar Despesa         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Exibir Despesas        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    FILE *fp2;
    Despesa *dp;
    fp2 = fopen("cad-despesa-m3.dat", "rb");
    if (fp2 == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    dp = (Despesa *)malloc(sizeof(Despesa));
    while (fread(dp, sizeof(Despesa), 1, fp2))
    {
        if (dp->status == 'C')
        {
            mostrarDesepesa(dp);
        }
    }
    fclose(fp2);
    getchar();
    free(dp);
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =         Exibir Despesas        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Fim da Operação!                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\tPressione Enter para sair");
}

void buscar_despesa(void)
{

    FILE *fp;
    Despesa *dep;
    int resultado;
    int aux_id;
    char procurando[20];

    fp = fopen("cad-despesa-m3.dat", "rb");
    if (fp == NULL)
    {
        /* code */
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("\t\t\tBuscamos a Despesa pelo Id da Despesa.\n");
    // scanf("%d", &aux_id);
    ler_id(procurando);
    int tam = strlen(procurando);
    aux_id = transform_to_integer(procurando, tam);
    dep = (Despesa *)malloc(sizeof(Despesa));
    resultado = 0;
    while ((!resultado) && (fread(dep, sizeof(Despesa), 1, fp)))
    {
        /* code */
        if ((dep->id == aux_id) && (dep->status == 'C'))
        {
            /* code */
            resultado = 1;
        }
    }
    fclose(fp);
    if (resultado)
    {
        /* code */
        mostrarDesepesa(dep);
        getchar();
    }
    else
    {
        printf("\t\t\tDespesa com o ID %d não encontrada...", aux_id);
        printf("\t\t\tPressione enter para sair");
    }
    free(dep);
}

void sobre_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Modulo encarregado do gerenciamento das despesas, aqui fica         ///\n");
    printf("///  a parte onde vamos cadastrar as despesas, que vai influenciar          ///\n");
    printf("///  diretamente no saldo.                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void mostrarDesepesa(Despesa *newdespesa)
{
    printf("\n\t\t\tCPF do morador: %s", newdespesa->cpf);
    printf("\n\t\t\tDescrição: %s", newdespesa->descricao);
    printf("\n\t\t\tTipo: %c", newdespesa->tipo);
    printf("\n\t\t\tValor: %.2f", newdespesa->valor);
    printf("\n\t\t\tSituação: %c", newdespesa->sitacao);
    printf("\n\t\t\tId: %d", newdespesa->id);
    printf("\n\t\t\tData: %s", newdespesa->data);
    printf("\n");
}

void mostrarDesDin(Desdin *novo) {

    printf("\n\t\t\tCPF do morador: %s", novo->cpf);
    printf("\n\t\t\tDescrição: %s", novo->descricao);
    printf("\n\t\t\tTipo: %c", novo->tipo);
    printf("\n\t\t\tValor: %.2f", novo->valor);
    printf("\n\t\t\tSituação: %c", novo->sitacao);
    printf("\n\t\t\tId: %d", novo->id);
    printf("\n\t\t\tData: %s", novo->data);
    printf("\n");
}

void gravarDesepesa(Despesa *newdespesa)
{
    FILE *fp2;
    fp2 = fopen("cad-despesa-m3.dat", "ab");
    if (fp2 == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(newdespesa, sizeof(Despesa), 1, fp2);
    fclose(fp2);
}