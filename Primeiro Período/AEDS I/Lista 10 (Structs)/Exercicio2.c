#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Crie uma struct para controlar ações de uma bolsa de valores com as seuigntes informações:
•Nome da compania
•Área de atuação da compania
•Valor atual da ação (em reais)
•Valor anterior
•Variação da ação em porcentagem (double), ou seja, quanto a ação cresceu ou caiu desde a
abertura da bolsa no dia.*/

typedef struct{
    char nome[20];
    char atuacao[20];
    float valorAtual;
    float valorAnterior;
    double variacao;
}bolsa;

int main (void){
    bolsa vetor[2];
    for (int aux=0;aux<2;aux++){
        printf("Digite o nome da empresa:\n");
        scanf(" %[^\n]",&vetor[aux].nome);
        printf("Digite a area de atuacao da empresa:\n");
        scanf(" %[^\n]",&vetor[aux].atuacao);
        printf("Digite o valor atual da acao (em reais):\n");
        scanf("%f",&vetor[aux].valorAtual);
        printf("Digite o valor anterior da acao (em reais): \n");
        scanf("%f",&vetor[aux].valorAnterior);
        vetor[aux].variacao=((vetor[aux].valorAtual-vetor[aux].valorAnterior)/vetor[aux].valorAtual)*100;
        printf("A variacao da acao corresponde a: %.3f por cento.\n",vetor[aux].variacao);
    }
}