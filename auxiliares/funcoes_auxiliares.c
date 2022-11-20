#include <stdio.h>
#include "funcoes_auxiliares.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../M2_/receitas_main.h"
#include "../M3_/despesas_main.h"

int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char decimais[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// DataValida, bissexto, dia_do_ano by Flavius Gorgonio

int bissexto(int aa) // by Flavius Gorgonio
{
    if ((aa % 4 == 0) && (aa % 100 != 0))
    {
        return 1;
    }
    else if (aa % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dataValida(int dd, int mm, int aa) // by Flavius Gorgonio
{

    struct tm *datetime;
    time_t segundos;
    time(&segundos);
    datetime = localtime(&segundos);
    int idia = datetime->tm_mday;
    int imes = datetime->tm_mon + 1;
    int iano = datetime->tm_year + 1900;

    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12 || dd < 1)
    {
        return 0;
    }
    if (mm == 2)
    {
        if (bissexto(aa))
        {
            maiorDia = 29;
        }
        else
        {
            maiorDia = 28;
        }
    }
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
    {
        maiorDia = meses[mm - 1];
    }
    else
    {
        maiorDia = meses[mm - 1];
    }
    if (dd > maiorDia)
    {
        return 0;
    }
    if (aa > iano)
    {

        return 0;
    }
    else if ((aa == iano) && (mm > imes))
    {

        return 0;
    }
    else if ((aa == iano) && (mm == imes) && (dd > idia))
    {

        return 0;
    }
    return 1;
}

int dia_do_ano(int dd, int mm, int aa) // by Flavius Gorgonio
{

    dataValida(dd, mm, aa);
    int soma = 0;
    for (int i = 0; i < mm - 1; i++)
    {
        soma += meses[i];
    }
    soma += dd;
    if ((mm > 2) && (bissexto(aa)))
    {
        soma += 1;
    }

    return soma;
}

int validar_formato_data(char data[11])
{

    for (int i = 0; i <= 10; i++)
    {

        if ((i != 2) && (i != 5))
        {
            for (int j = 0; j <= 10; j++)
            {

                if ((j == 10) && (data[i] != decimais[j]))
                {
                    return 0;
                }
                else if (data[i] == decimais[j])
                {
                    break;
                }
            }
        }
        else if ((i == 2) && (data[i] != '/'))
        {

            return 0;
        }
        else if ((i == 5) && (data[i] != '/'))
        {

            return 0;
        }
    }

    int d1, d2, dd, m1, m2, mm, a1, a2, a3, a4, aa;
    d1 = data[0] - '0';
    d2 = data[1] - '0';
    dd = (d1 * 10) + d2;

    m1 = data[3] - '0';
    m2 = data[4] - '0';
    mm = (m1 * 10) + m2;

    a1 = data[6] - '0';
    a2 = data[7] - '0';
    a3 = data[8] - '0';
    a4 = data[9] - '0';
    aa = (a1 * 1000) + (a2 * 100) + (a3 * 10) + a4;

    return dataValida(dd, mm, aa);
}

int validar_letras(char nome[], int tam)
{

    for (int i = 0; i <= (tam - 1); i++)
    {

        if (((nome[i] <= 'z') && (nome[i] >= 'A')))
        {

            if (((nome[i] > 'Z') && (nome[i] < 'a')))
            {

                return 0;
            }
        }
        else
        {

            return 0;
        }
    }

    return 1;
}

int validar_dinheiro(char dinheiro[], int tam)

{

    if (dinheiro[tam - 3] != '.')
    {
        return 0;
    }
    else
    {

        for (int i = 0; i <= (tam - 1); i++)
        {
            for (int j = 0; j <= 10; j++)
            {

                if ((j == 10) && (dinheiro[i] != decimais[j]))
                {
                    return 0;
                }
                else if (dinheiro[i] == decimais[j])
                {
                    break;
                }
                else if (i == (tam - 3))
                {

                    break;
                }
            }
        }
    }

    return 1;
}

char verificarcpf(char *cpf, int tam)
{
    if (tam < 11)
    {
        return 0;
    }

    if (tam == 11)
    {
        int calc = 0;
        int mult = 10;
        int dv1, dv2;
        for (int i = 0; i < 9; i++)
        {
            calc = calc + ((cpf[i] - 48) * mult);
            mult = mult - 1;
            dv1 = (calc * 10) % 11;
        }
        mult = 11;
        calc = 0;
        for (int i = 0; i < 10; i++)
        {
            calc = calc + ((cpf[i] - 48) * mult);
            mult = mult - 1;
            dv2 = (calc * 10) % 11;
        }

        if ((dv1 == 10))
        {
            dv1 = 0;
        }
        if ((dv2 == 10))
        {
            dv2 = 0;
        }

        char dc1, dc2;
        dc1 = dv1 + '0';
        dc2 = dv2 + '0';

        if ((dv1 == 10 && cpf[tam - 2] != '0') || (dv2 == 10 && cpf[tam - 1] != '0'))
        {
            return 0;
        }
        else if ((cpf[tam - 2] != dc1) || (cpf[tam - 1] != dc2))
        {
            return 0;
        }
    }

    else if (tam > 11)
    {
        return 0;
    }

    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (i > 0 && cpf[i] == cpf[i - 1])
        {
            cont = cont + 1;

            if (cont == tam - 1)
            {
                return 0;
            }
        }
    }

    return 1;
}

void ler_nome(char *name)
{

    int tam;
    do
    {
        printf("          Informe o nome do morador:\n");
        scanf("%s", name);
        getchar();
        tam = strlen(name);
    } while (!(validar_letras(name, tam)));
}

void ler_cpf(char *cpf)
{

    int tam;
    do
    {
        printf("             Informe o CPF do morador:\n");
        scanf("%s", cpf);
        getchar();
        tam = strlen(cpf);
    } while (!(verificarcpf(cpf, tam)));
}

void ler_idade(char *idade)
{

    int tam;
    do
    {
        printf("             Informe a idade do morador:\n");
        scanf("%s", idade);
        getchar();
        tam = strlen(idade);
    } while (!(validar_idade(idade, tam)));
}

int validar_idade(char idade[], int tam)
{

    for (int i = 0; i <= (tam - 1); i++)
    {

        for (int j = 0; j <= 10; j++)
        {

            if ((j == 10) && (idade[i] != decimais[j]))
            {
                return 0;
            }
            else if (idade[i] == decimais[j])
            {
                break;
            }
        }
    }

    return 1;
}

void ler_ocupacao(char *ocupacao)
{
    printf("             Informe a atual ocupação do morador:\n");
    scanf("%s", ocupacao);
    getchar();
}

void ler_renda(char *renda)
{

    int tam;
    do
    {
        printf("             Informe a renda mensal do morador:\n");
        scanf("%s", renda);
        getchar();
        tam = strlen(renda);
    } while (!(validar_dinheiro(renda, tam)));
}

void ler_descricaor(char *descricaor)
{

    printf("\n          Descrição:\n");
    scanf("%50[^\n]", descricaor);
    getchar();
}

void ler_valordepositado(char *deposito)
{
    int tam;
    do
    {
        printf("            Valor:\n");
        scanf("%s", deposito);
        getchar();
        tam = strlen(deposito);
    } while (!(validar_dinheiro(deposito, tam)));
}

char tipos_rec(void)
{
    printf("            Tipo da receita?\n");
    printf("            1-Contribuição Mensal\n2-Extra\n");
    char tipo;
    scanf("%c", &tipo);
    getchar();
    return tipo;
}

char tipos_despesa(void)
{
    printf("            Tipo da despesa:\n");
    printf("1-Gasto Mensal\t2-Gasto Extra\t3-Emergência\n");
    char tipo;
    scanf("%c", &tipo);
    getchar();
    return tipo;
}

int idReceita(void)
{
    Receita *rec;
    rec = (Receita *)malloc(sizeof(Receita));
    FILE *fp;
    fp = fopen("cad-receita-m2.dat", "rb");
    if (fp == NULL)
    {
        return 1;
    }

    else
    {
        fseek(fp, (-1) * sizeof(Receita), SEEK_END);
        fread(rec, sizeof(Receita), 1, fp);
        return rec->id + 1;
    }
}

int idDespesa(void)
{
    Despesa *dep;
    dep = (Despesa *)malloc(sizeof(Despesa));
    FILE *fp;
    fp = fopen("cad-despesa-m3.dat", "rb");
    if (fp == NULL)
    {
        return 1;
    }

    else
    {
        fseek(fp, (-1) * sizeof(Despesa), SEEK_END);
        fread(dep, sizeof(Despesa), 1, fp);
        return dep->id + 1;
    }
}

int validar_id(char *id, int tam)
{

    for (int i = 0; i <= (tam - 1); i++)
    {

        for (int j = 0; j <= 10; j++)
        {

            if ((j == 10) && (id[i] != decimais[j]))
            {
                return 0;
            }
            else if (id[i] == decimais[j])
            {
                break;
            }
        }
    }

    return 1;
}
