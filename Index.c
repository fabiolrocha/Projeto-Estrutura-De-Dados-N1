#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados{
        char nome[64];
        char telefone[64];
        char curso[64];
        float nota1;
        float nota2;
        float media;
    };

int leitura(struct Dados *dados, FILE *dadosEstudantes);
float calcularMedia(float nota1, float nota2);
char* determinarSituacao(float media);


int main(){
    FILE *dadosEstudantes;
    FILE *retornoDados;
    float media;
    char situacao;
    
    struct Dados dados;

    dadosEstudantes = fopen("DadosEntrada.csv", "r");
    retornoDados = fopen("RetornoDados.csv", "w");

    if (dadosEstudantes == NULL || retornoDados == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    

while (leitura(&dados, dadosEstudantes) != EOF) {

media = calcularMedia(dados.nota1, dados.nota2);

;

    fprintf(retornoDados, "Dados do Aluno:");
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Nome: %s", dados.nome);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Telefone: %s", dados.telefone);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Curso: %s", dados.curso);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Nota 1: %.2f", dados.nota1);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Nota 2: %.2f", dados.nota2);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Media: %.2f", media);
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "Situacao final: %s", determinarSituacao(media));
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "\n");
    fprintf(retornoDados, "\n");

}
    fclose(dadosEstudantes);
    fclose(retornoDados); 
}

int leitura(struct Dados *dados, FILE *dadosEstudantes)
{
        return fscanf(dadosEstudantes, "%[^,], %[^,], %[^,], %f, %f", dados->nome, dados->telefone, dados->curso, &dados->nota1, &dados->nota2);
}


float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

char* determinarSituacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}