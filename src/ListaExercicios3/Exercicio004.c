#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} dia_t;

void incrementa_dia(dia_t *d);
void mostra_dia(dia_t d);

// Função principal
int main()
{
    dia_t d;

    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    incrementa_dia(&d);

    mostra_dia(d);

    return 0;
}

/**
 * @brief
 * @param
 */
void incrementa_dia(dia_t *d)
{
    int dias_no_mes;

    if (d->mes == 2)
    {
        if ((d->ano % 400 == 0) || (d->ano % 4 == 0 && d->ano % 100 != 0))
        {
            dias_no_mes = 29;
        }
        else
        {
            dias_no_mes = 28;
        }
    }
    else if (d->mes == 4 || d->mes == 6 || d->mes == 9 || d->mes == 11)
    {
        dias_no_mes = 30;
    }
    else
    {
        dias_no_mes = 31;
    }

    d->dia++;

    if (d->dia > dias_no_mes)
    {
        d->dia = 1;
        d->mes++;

        if (d->mes > 12)
        {
            d->mes = 1;
            d->ano++;
        }
    }
}

/**
 * @brief
 * @param 
 */
void mostra_dia(dia_t d)
{

    printf("%02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}