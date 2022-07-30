#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter
a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira
prova.
•(a) Permita ao usuário entrar com os dados de 5 alunos.
•(b) Encontre o aluno com maior nota da primeira prova.
•(c) Encontre o aluno com maior média geral.
•(d) Encontre o aluno com menor média geral
•(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovação.*/

typedef struct{
    float nota1;
    float nota2;
    float nota3;
}notas;

typedef struct{
    char nome[30];
    int matricula;
    float media;
    notas;
}alunos;



int main (void){
    alunos vetor[5];
    int posicaoMaiorNota1=0;
    int posicaoMaiorMedia=0;
    int posicaoMenorMedia=0;
    for (int aux=0;aux<5;aux++){
        printf("-------- Aluno %i -------- \n",aux+1);
        printf("Digite o nome do aluno:\n");
        scanf(" %[^\n]s",vetor[aux].nome);
        printf("Digite a matricula do aluno:\n");
        scanf("%i",&vetor[aux].matricula);
        printf("Digite a nota da prova 1:\n");
        scanf("%f",&vetor[aux].nota1);
        printf("Digite a nota da prova 2:\n");
        scanf("%f",&vetor[aux].nota2);
        printf("Digite a nota da prova 3:\n");
        scanf("%f",&vetor[aux].nota3);
        vetor[aux].media=((vetor[aux].nota1+vetor[aux].nota2+vetor[aux].nota3)/3);

        if (vetor[aux].media>=6){
            printf("O aluno %s esta aprovado.\n",vetor[aux].nome);
        }else{
            printf("O aluno %s esta reprovado.\n",vetor[aux].nome);
        }

        if(vetor[aux].nota1>vetor[posicaoMaiorNota1].nota1){
            posicaoMaiorNota1=aux;
        }
        if(vetor[aux].media>vetor[posicaoMaiorMedia].media){
            posicaoMaiorMedia=aux;
        }
        if(vetor[aux].media<vetor[posicaoMenorMedia].media){
            posicaoMenorMedia=aux;
        }

    }

    printf("------- Dados --------\n");
    printf("O aluno com maior nota na prova 1 foi o(a) '%s' com %.2f pontos.\n",vetor[posicaoMaiorNota1].nome,vetor[posicaoMaiorNota1].nota1);
    printf("O aluno com maior media geral foi o(a) '%s' com uma media de %.2f pontos.\n",vetor[posicaoMaiorMedia].nome,vetor[posicaoMaiorMedia].media);
    printf("O aluno com menor media geral foi o(a) '%s' com uma media de %.2f pontos.\n",vetor[posicaoMenorMedia].nome,vetor[posicaoMenorMedia].media);
}