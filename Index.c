#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    FILE *DadosEntrada;

    DadosEntrada = fopen("DadosEntrada.csv", "r");

    if (DadosEntrada == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    char Linha[1024];

    system("cls");

    while (fgets(Linha, 1024, DadosEntrada) != NULL)
    {
        DadosEntrada = strtok(Linha, ",");

        while (DadosEntrada != NULL)
        {

            printf("%s - ", DadosEntrada);
            DadosEntrada = strtok(NULL, ",");
        }
    }

    fclose(DadosEntrada);
}