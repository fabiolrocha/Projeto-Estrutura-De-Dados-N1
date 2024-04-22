#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    char nome[64];
    char telefone[64];
    char curso[64];
    float nota1;
    float nota2;
};

int leitura(struct dados *dados);
float media(struct dados *dados);
char situacao(float media);






int leitura(struct dados *dados)
{
    FILE *dadosEstudantes;

    char *dados;

    dadosEstudantes = fopen("DadosEntrada.csv", "r");

    if (dadosEstudantes == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    system("cls");

    while (fgets(dados, sizeof(dados), dadosEstudantes) != NULL)
    {
        char *token = strtok(dados, ",");

        while (token != NULL)
        {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(dadosEstudantes);
}




















char situacao(float media)
{
    if (media >= 7)
    {
        return "APROVADO";
    }
    else
    {
        return "REPROVADO";
    }
}