#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 94
#define MAX_COLS 100

int main()
{
    FILE *DadosEntrada;

    DadosEntrada = fopen("C:\\Users\\fabio\\Desktop\\Projeto Marcelo Eustaquio\\DadosEntrada.csv", "r");

    if (DadosEntrada == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(0);
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