#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "relatorios.h"
#include "../auxiliares/funcoes_auxiliares.h"
#include "../M3_/despesas_main.h"
#include "../M2_/receitas_main.h"
#include "../M1_/cadastro_moradores_main.h"

void interacao_menu_relatorios(void)
{

    char op;
    op = menu_relatorios();
    while (op != '0')
    {

        if (op == '1')
        {
            checar_dp();
        }

        else if (op == '2')
        {
            checar_re();
        }

        else if (op == '4')
        {
            buscar_receita();
        }

        else if (op == '3')
        {
            buscar_despesa();
        }

        else if (op == '5')
        {
            RelatorioValorReceita(1);
            getchar();
        }
        else if (op == '6')
        {
            RelatorioValorReceita(2);
            getchar();
        }

        else if (op == '7')
        {
            RelatorioValorDespesa(1);
            getchar();
        }
        else if (op == '8')
        {
            RelatorioValorDespesa(2);
            getchar();
        }

        else if (op == '9')
        {
            buscarUm();
        }
        else if ((op == 'A') || (op == 'a'))
        {
            MostrarReceitasPorData();
        }
        else if ((op == 'B') || (op == 'b'))
        {
            MostrarDespesasPorData();
        }
        else
        {
            printf("\n\t Opção invalida. digite outra...");
            getchar();
        }

        op = menu_relatorios();
    }
}

char menu_relatorios(void)
{
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Mostrar todas as Despesas                                 ///\n");
    printf("///            2. Mostrar todas as Receitas                                 ///\n");
    printf("///            3. Pesquisar Despesa por ID                                  ///\n");
    printf("///            4. Pesquisar Receita por ID                                  ///\n");
    printf("///            5. Pesquisar Receita em ordem de Maior valor                 ///\n");
    printf("///            6. Pesquisar Receita em ordem de Menor valor                 ///\n");
    printf("///            7. Pesquisar Despesa em ordem de Maior valor                 ///\n");
    printf("///            8. Pesquisar Despesa em ordem de Menor valor                 ///\n");
    printf("///            9. Pesquisar Morador por CPF                                 ///\n");
    printf("///            A. Mostrar Receitas em intervalo de tempo                    ///\n");
    printf("///            B. Mostrar Despesas em intervalo de tempo                    ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\tSelecione sua opção:");
    scanf("%c", &op);
    getchar();
    return op;
}

void RelatorioValorReceita(int num)
{
    FILE *fp;
    Receita *rec;
    RecDin *novo;
    RecDin *lista;

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///          = = = = =   Exib. de Receita por valor   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    if (access("cad-receita-m2.dat", F_OK) != -1)
    {
        /* code */
        fp = fopen("cad-receita-m2.dat", "rb");

        if (fp == NULL)
        {

            printf("Erro na abertura do arquivo");
            exit(1);
        }

        else
        {
            /* code */
            lista = NULL;

            rec = (Receita *)malloc(sizeof(Receita));

            while (fread(rec, sizeof(Receita), 1, fp))
            {
                /* code */
                if (rec->status == 'C')
                {
                    /* code */
                    novo = (RecDin *)malloc(sizeof(RecDin));

                    strcpy(novo->cpf, rec->cpf);
                    strcpy(novo->descricao, rec->descricao);
                    strcpy(novo->data, rec->data);
                    novo->valor = rec->valor;
                    novo->tipo = rec->tipo;
                    novo->status = rec->status;
                    novo->id = rec->id;

                    if (num == 1)
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor > lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            RecDin *anter = lista;
                            RecDin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor > novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }

                    else
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor < lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            RecDin *anter = lista;
                            RecDin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor < novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }
                }
            }

            free(rec);

            novo = lista;
            while (novo != NULL)
            {

                mostrarRecdin(novo);
                novo = novo->prox;
            }

            novo = lista;
            while (lista != NULL)
            {
                lista = lista->prox;
                // free(novo->nome);
                // free(novo->status);
                free(novo);
                novo = lista;
            }
        }

        fclose(fp);
    }
}

void RelatorioValorDespesa(int num)
{
    FILE *fp;
    Despesa *des;
    Desdin *novo;
    Desdin *lista;

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///          = = = = =   Exib. de Despesa por valor   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    if (access("cad-despesa-m3.dat", F_OK) != -1)
    {
        /* code */
        fp = fopen("cad-despesa-m3.dat", "rb");

        if (fp == NULL)
        {

            printf("Erro na abertura do arquivo");
            exit(1);
        }

        else
        {
            /* code */
            lista = NULL;

            des = (Despesa *)malloc(sizeof(Despesa));

            while (fread(des, sizeof(Despesa), 1, fp))
            {
                /* code */
                if (des->status == 'C')
                {
                    /* code */
                    novo = (Desdin *)malloc(sizeof(Desdin));

                    strcpy(novo->cpf, des->cpf);
                    strcpy(novo->descricao, des->descricao);
                    strcpy(novo->data, des->data);
                    novo->valor = des->valor;
                    novo->tipo = des->tipo;
                    novo->status = des->status;
                    novo->sitacao = des->sitacao;
                    novo->id = des->id;

                    if (num == 1)
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor > lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            Desdin *anter = lista;
                            Desdin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor > novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }

                    else
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor < lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            Desdin *anter = lista;
                            Desdin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor < novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }
                }
            }

            free(des);

            novo = lista;
            while (novo != NULL)
            {

                mostrarDesDin(novo);
                novo = novo->prox;
            }

            novo = lista;
            while (lista != NULL)
            {
                lista = lista->prox;
                // free(novo->nome);
                // free(novo->status);
                free(novo);
                novo = lista;
            }
        }

        fclose(fp);
    }
}

void MostrarReceitasPorData(void)
{

    FILE *fp;
    Receita *rec;
    char datainicial[11];
    char datafinal[11];
    int achou;

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///          = = = = =  Exib. de Receita entre datas  = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    fp = fopen("cad-receita-m2.dat", "rb");
    if (fp == NULL)
    {
        /* code */
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("\t\t\tPor favor informe a data inicial do intervalo.\n");
    ler_data(datainicial);
    printf("\t\t\tPor favor informe a data final do intervalo.\n");
    ler_data(datafinal);
    rec = (Receita *)malloc(sizeof(Receita));
    while ((fread(rec, sizeof(Receita), 1, fp)))
    {
        if ((compararDatas(datainicial, datafinal, rec->data)) && (rec->status == 'C'))
        {
            mostrarReceita(rec);
            achou += 1;
        }
    }
    if (achou > 0)
    {

        getchar();
    }
    else
    {
        printf("\t\t\tNenhuma Receita encontrada nesse intervalo de tempo");
        printf("\t\t\tPressione enter para sair");
        getchar();
    }
    fclose(fp);
    free(rec);
}

void MostrarDespesasPorData(void)
{

    FILE *fp;
    Despesa *dep;
    char datainicial[11];
    char datafinal[11];
    int achou;

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///          = = = = =  Exib. de Despesas entre datas  = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    fp = fopen("cad-despesa-m3.dat", "rb");
    if (fp == NULL)
    {
        /* code */
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("\t\t\tPor favor informe a data inicial do intervalo.\n");
    ler_data(datainicial);
    printf("\t\t\tPor favor informe a data final do intervalo.\n");
    ler_data(datainicial);
    dep = (Despesa *)malloc(sizeof(Despesa));
    while ((fread(dep, sizeof(Despesa), 1, fp)))
    {
        if ((compararDatas(datainicial, datafinal, dep->data)) && (dep->status == 'C'))
        {
            mostrarDesepesa(dep);
            achou += 1;
        }
    }
    if (achou > 0)
    {

        getchar();
    }
    else
    {
        printf("\t\t\tNenhuma Despesa encontrada nesse intervalo de tempo");
        printf("\t\t\tPressione enter para sair");
        getchar();
    }
    fclose(fp);
    free(dep);
}
