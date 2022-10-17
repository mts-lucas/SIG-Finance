#include <stdio.h>
#include "funcoes_auxiliares.h"
#include <string.h>

int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char decimais[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// depois add func q troca valores de data[2] e data[5] por /

// DataValida, bissexto, dia_do_ano by Flavius Gorgonio

int bissexto(int aa) //by Flavius Gorgonio
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

int dataValida(int dd, int mm, int aa) //by Flavius Gorgonio
{
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
    return 1;
}

int dia_do_ano(int dd, int mm, int aa) //by Flavius Gorgonio
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

// Calcular a quantos dias foi um evento

int quantos_dias(int dd, int mm, int aa)
{

    printf("Precisa usar struct. ESTUDAR");

    return 0;
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

    if ((dinheiro[tam - 3] != ',') && (dinheiro[tam - 3] != '.'))
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
    for (int i = 0; i < tam; i++)
    {
        if (tam < 11)
        {
            return 0;
        }
        else if ((cpf[i] < '-' || cpf[i] > '9') || cpf[i] == '/')
        {
            if (cpf[i] == 46 && (i != 3 || i != 7))
            {
                return 0;
            }

            return 0;
        }

        /* code */
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
            dv1 = calc % 11;
        }
        mult = 11;
        calc = 0;
        for (int i = 0; i < 10; i++)
        {
            calc = calc + ((cpf[i] - 48) * mult);
            mult = mult - 1;
            dv2 = calc % 11;
        }
        char dc1, dc2;
        dc1 = (11 - dv1) + 48;
        dc2 = (11 - dv2) + 48;

        if ((dv1 < 2 && cpf[tam - 2] != '0') || (dv2 < 2 && cpf[tam - 2] != '0'))
        {
            return 0;
        }
        else if ((dv1 >= 2 && cpf[tam - 2] == '0') || (dv2 >= 2 && cpf[tam - 2] == '0'))
        {
            return 0;
        }
        else if ((dv1 >= 2 && cpf[tam - 2] != dc1) || (dv2 >= 2 && cpf[tam - 1] != dc2))
        {
            return 0;
        }
    }

    else if (tam > 11)
    {
        int calc = 0;
        calc = (cpf[0] - 48) * 10 + (cpf[1] - 48) * 9 + (cpf[2] - 48) * 8 + (cpf[4] - 48) * 7 + (cpf[5] - 48) * 6 + (cpf[6] - 48) * 5 + (cpf[8] - 48) * 4 + (cpf[9] - 48) * 3 + (cpf[10] - 48) * 2;
        int dv1 = calc % 11;
        int dv2 = ((cpf[0] - 48) * 11 + (cpf[1] - 48) * 10 + (cpf[2] - 48) * 9 + (cpf[4] - 48) * 8 + (cpf[5] - 48) * 7 + (cpf[6] - 48) * 6 + (cpf[8] - 48) * 5 + (cpf[9] - 48) * 4 + (cpf[10] - 48) * 3 + (cpf[12] - 48) * 2) % 11;
        char dc1, dc2;
        dc1 = (11 - dv1) + 48;
        dc2 = (11 - dv2) + 48;
        if ((dv1 < 2 && cpf[12] != '0') || (dv2 < 2 && cpf[13] != '0'))
        {
            return 0;
        }
        else if ((dv1 >= 2 && cpf[12] == '0') || (dv2 >= 2 && cpf[13] == '0'))
        {
            return 0;
        }

        else if ((dv1 >= 2 && cpf[12] != dc1) || (dv2 >= 2 && cpf[13] != dc2))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int cont = 0;
    
    for (int i = 0; i < tam; i++)
    {
        if (i>0 && cpf[i] == cpf[i-1])
        {
            cont = cont + 1;
            
            if (cont == tam -1)
            {
                return 0;
            }
            
        }
        
    }
    
    return 1;
}