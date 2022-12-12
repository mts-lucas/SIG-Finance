#include <stdio.h>
#include "funcoes_auxiliares.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../M2_/receitas_main.h"
#include "../M3_/despesas_main.h"
#include "../M1_/cadastro_moradores_main.h"

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

int validar_formato_data(char data[11], int tam)
{

    if (tam == 10)
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
    else
    {
        return 0;
    }
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
    } while ((!(verificarcpf(cpf, tam))) || ((checarCPF(cpf))));
}

void ler_cpf_cad(char *cpf)
{

    int tam;
    do
    {
        printf("             Informe o CPF do morador:\n");
        scanf("%s", cpf);
        getchar();
        tam = strlen(cpf);

    } while (!((verificarcpf(cpf, tam)) && (checarCPFCad(cpf))));
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
    printf("            1-Contribuição Mensal\t2-Extra\n");
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

void ler_id(char *id)
{

    int tam;
    do
    {
        printf("             Informe ID:\n");
        scanf("%s", id);
        getchar();
        tam = strlen(id);
    } while (!(validar_id(id, tam)));
}

int transform_to_integer(char *vetorchar, int tam)
{

    int vetor_retorno = 0;
    int aux = 1;
    for (int i = (tam - 1); i >= 0; i--)
    {

        vetor_retorno += (vetorchar[i] - '0') * aux;
        aux *= 10;
    }

    return vetor_retorno;
}

float transform_to_float(char *vetorchar, int tam)
{

    float vetor_retorno = 0.0;
    float auxq = 0.01;
    float aux = 1.0;

    for (int i = (tam - 4); i >= 0; i--)
    {

        vetor_retorno += (vetorchar[i] - '0') * aux;
        aux *= 10;
    }

    for (int j = (tam - 1); j >= (tam - 2); j--)
    {

        vetor_retorno += (vetorchar[j] - '0') * auxq;
        auxq *= 10;
    }

    return vetor_retorno;
}

int checarCPF(char *cpfbusca)
{
    FILE *fp;
    Morador *mor;
    int resultado;
    fp = fopen("cadastro-m1.dat", "rb");
    if (fp == NULL)
    {

        printf("Nenhum morador cadastrado\n");
        printf("Voce sera redirecionado para pagina de cadastro do morador após apertar qualquer tecla\t");
        getchar();
        system("cls || clear");
        preenche_morador();
        system("cls || clear");
        printf("Agora tente novamente, pressione qualquer teclar para prosseguir\t");
        getchar();
        system("cls || clear");
        return 1;
    }

    mor = (Morador *)malloc(sizeof(Morador));
    resultado = 0;
    while ((!resultado) && (fread(mor, sizeof(Morador), 1, fp)))
    {

        if ((strcmp(mor->cpf, cpfbusca) == 0) && (mor->status == 'C'))
        {

            printf("\n\tCPF já cadastrado\n");
            resultado = 1;
        }
    }
    fclose(fp);
    if (resultado)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    free(mor);
}

int checarCPFCad(char *cpfbusca)
{

    FILE *fp;
    Morador *mor;
    int resultado;
    fp = fopen("cadastro-m1.dat", "rb");
    if (fp == NULL)
    {
        return 1;
    }

    mor = (Morador *)malloc(sizeof(Morador));
    resultado = 0;
    while ((!resultado) && (fread(mor, sizeof(Morador), 1, fp)))
    {

        if ((strcmp(mor->cpf, cpfbusca) == 0) && (mor->status == 'C'))
        {

            printf("\n\tCPF já cadastrado\n");
            resultado = 1;
        }
    }
    fclose(fp);
    if (resultado)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    free(mor);
}

void ler_data(char *data)
{

    int tam;
    do
    {
        printf("             Informe a data da operação:\n");
        scanf("%s", data);
        getchar();
        tam = strlen(data);
    } while (!(validar_formato_data(data, tam)));
}

void gravarSaldo(Saldo *newsaldo)
{
    FILE *fp;
    fp = fopen("saldo-casa.dat", "ab");
    if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(newsaldo, sizeof(Saldo), 1, fp);
    fclose(fp);
}

float ultimoSaldo(void)
{

    FILE *fp;
    Saldo *ult_saldo;
    ult_saldo = (Saldo *)malloc(sizeof(Saldo));
    fp = fopen("saldo-casa.dat", "rb");
    if (fp == NULL)
    {
        return 0.0;
    }

    else
    {
        fseek(fp, -1 * sizeof(Saldo), SEEK_END);
        fread(ult_saldo, sizeof(Saldo), 1, fp);
        float ultimo_valor = ult_saldo->valor_atual;
        fclose(fp);
        free(ult_saldo);
        return ultimo_valor;
    }
}

void mostrarSaldo(Saldo *newsaldo)
{
    // system("clear||cls");
    printf("\n          Saldo: %.2f", newsaldo->valor_atual);
    printf("\n          Valor das despesas: %.2f", newsaldo->valor_despesas);
    printf("\n");
    // getchar();
}

float ultimaDespesa(void)
{

    FILE *fp;
    Saldo *ult_saldo;
    ult_saldo = (Saldo *)malloc(sizeof(Saldo));
    fp = fopen("saldo-casa.dat", "rb");
    if (fp == NULL)
    {
        return 0.0;
    }

    else
    {
        fseek(fp, -1 * sizeof(Saldo), SEEK_END);
        fread(ult_saldo, sizeof(Saldo), 1, fp);
        float ultimo_valor = ult_saldo->valor_despesas;
        fclose(fp);
        free(ult_saldo);
        return ultimo_valor;
    }
}

int convertDataToInt(char *data, int func)
{

    // func = 1 = dia
    // func = 2 = mes
    // func = 3 = ano

    if (func == 1)
    {

        int dia = 0;
        int aux = 1;
        for (int i = 1; i >= 0; i--)
        {

            dia += (data[i] - '0') * aux;
            aux *= 10;
        }
        return dia;
    }
    else if (func == 2)
    {

        int mes = 0;
        int aux = 1;
        for (int i = 4; i >= 3; i--)
        {

            mes += (data[i] - '0') * aux;
            aux *= 10;
        }
        return mes;
    }
    else if (func == 3)
    {

        int ano = 0;
        int aux = 1;
        for (int i = 9; i >= 6; i--)
        {

            ano += (data[i] - '0') * aux;
            aux *= 10;
        }
        return ano;
    }
}

int compararDatas(char *datainicial, char *datafinal, char *dataarch)
{

    int diaincial, mesinicial, anoinicial, diafinal, mesfinal, anofinal, diaarch, mesarch, anoarch;
    diaincial = convertDataToInt(datainicial, 1);
    mesinicial = convertDataToInt(datainicial, 2);
    anoinicial = convertDataToInt(datainicial, 3);

    diafinal = convertDataToInt(datafinal, 1);
    mesfinal = convertDataToInt(datafinal, 2);
    anofinal = convertDataToInt(datafinal, 3);

    diaarch = convertDataToInt(dataarch, 1);
    mesarch = convertDataToInt(dataarch, 2);
    anoarch = convertDataToInt(dataarch, 3);

    if ((anoarch <= anofinal) && (anoarch >= anoinicial) && (anoinicial < anofinal))
    {
        if ((anoarch == anofinal) && (mesarch == mesfinal) && (diaarch <= diafinal))
        {
            return 1;
        }
        else if ((anoarch == anofinal) && (mesarch < mesfinal))
        {

            return 1;
        }
        else if ((anoarch == anoinicial) && (mesarch == mesinicial) && (diaarch >= diaincial))
        {

            return 1;
        }
        else if ((anoarch == anoinicial) && (mesarch > mesinicial))
        {

            return 1;
        }
        else if (((anofinal - anoinicial) > 1) && (anoarch < anofinal) && (anoarch > anoinicial))
        {

            return 1;
        }
        else
        {

            return 0;
        }
    }
    else if ((anoinicial == anofinal) && (anoarch == anoinicial))
    {

        if ((mesinicial == mesfinal) && (mesinicial == mesarch) && (diaarch >= diaincial) && (diaarch <= diafinal))
        {

            return 1;
        }
        else if ((mesarch > mesinicial) && (mesarch == mesfinal) && (diaarch <= diafinal))
        {

            return 1;
        }
        else if ((mesarch < mesfinal) && (mesarch == mesinicial) && (diaarch >= diaincial))
        {

            return 1;
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}