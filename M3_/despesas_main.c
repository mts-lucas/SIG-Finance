#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesas_main.h"
#include "../auxiliares/funcoes_auxiliares.h"

char ler_dp(void)
{
    printf("Selecione sua opção:");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    int tam;
    do
    {
        printf("             De qual Morador vai cadastrar a despesa?                       \n");
        scanf("%s", newdespesa->morador);
        getchar();
        tam = strlen(newdespesa->morador);
    } while (!(validar_letras(newdespesa->morador, tam)));
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("        Descrição:                                                             \n");
    scanf("%s", newdespesa->descricao);
    do
    {
        printf("        Valor:                                                                \n");
        scanf("%s", newdespesa->valor);
        getchar();
        tam = strlen(newdespesa->valor);
    } while (!(validar_dinheiro(newdespesa->valor, tam)));
    printf("        Tipo da despesa:                                                       \n");
    newdespesa->tipo = tipos_d();
    newdespesa->status = 'C';
    mostrarDesepesa(newdespesa);
    gravarDesepesa(newdespesa);
    free(newdespesa);
    getchar();
}

void editar_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n           De qual Morador vai editar a despesa?                             \n");
    char morador[50];
    int tam;
    do
    {
        printf("            De qual Morador vai cadastrar a despesa?                       \n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n       Editar despesa:                                                       \n");
    printf("         Descrição:                                                            \n");
    char descricao_d[50];
    scanf("%s", descricao_d);
    char valor_d[50];
    do
    {
        printf("         Valor:                                                              \n");
        scanf("%s", valor_d);
        getchar();
        tam = strlen(valor_d);
    } while (!(validar_dinheiro(valor_d, tam)));
    printf("         Tipo da despesa:                                                    ///\n");
    tipos_d();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void excluir_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char morador[50];
    int tam;
    do
    {
        printf("        De qual Morador vai excluir a despesa? (Atenção, excluir          \n");
        printf("                                         é diferente de pagar...)         \n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
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
    printf("///     (obs: a meta é fazer um 'for' para gerar essa série de despesas     ///\n");
    printf("///  mas por enquanto vamos deixar assim para ficar mais didático           ///\n");
    printf("///  o que vamos fazer)                                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void pagar_dp(void)
{
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =        Login do morador        = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char morador[50];
    int tam;
    do
    {
        printf("\n             De qual Morador vai cadastrar a despesa?                          \n");
        scanf("%s", morador);
        getchar();
        tam = strlen(morador);
    } while (!(validar_letras(morador, tam)));
    getchar();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
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
    printf("///  mas por enquanto vamos deixar assim para ficar mais didático           ///\n");
    printf("///  o que vamos fazer, pagando com base na receita e/ou no saldo)          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void checar_dp(void)
{
    system("clear||cls");
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
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Despesas   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    dp = (Despesa *)malloc(sizeof(Despesa));
    while (fread(dp, sizeof(Despesa), 1, fp2))
    {
        if (dp->status == 'C')
        {
            mostrarDesepesa(dp);
        }
    }
    fclose(fp2);
    free(dp);
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

char tipos_d(void)
{
    printf("1-Contribuição Mensal\t2-Extra\t3-Emergência\n");
    char tipo;
    scanf("%c", &tipo);
    getchar();
    return tipo;
}

void mostrarDesepesa(Despesa *newdespesa)
{

    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///          = = = = =    Gerenciamento de Desepesa   = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\nMorador: %s", newdespesa->morador);
    printf("\nDescrição: %s", newdespesa->descricao);
    printf("\nTipo: %c", newdespesa->tipo);
    printf("\nValor: %s", newdespesa->valor);
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