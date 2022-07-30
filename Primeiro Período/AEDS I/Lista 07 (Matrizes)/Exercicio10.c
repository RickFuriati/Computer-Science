#include<stdio.h>
#include<stdlib.h>

/*Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu programa devera fazer uma
busca do valor de X no vetor lido e informar as posições em que foi encontrado ou se não foi
encontrado.*/

int random(int interval) //função para sortear numeros aleatórios em um intervalo (maior praticidade)
{
    return rand() % interval;
}
int minrand(int min, int max)
{
    return random(max - min) + min;
}

int main(void){
    srand(time(NULL));
    int vetor[20];
    int X,posicao=0;
    printf("O vetor sorteado de 20 posicoes corresponde a:\n");
    for (int aux=0;aux<20;aux++){
        vetor[aux]=minrand(0,100);
        printf("%i ",vetor[aux]);
    }
    printf("\nDigite um valor X qualquer. (entre 0-100)\n");
    scanf("%i",&X);
    for(int aux=0;aux<20;aux++){
        if(vetor[aux]==X){
        printf("O numero %i foi encontrado na posicao %i.\n",X,aux+1);
        posicao++;
        }
    }
    if (posicao==0){
    printf("O numero %i nao foi encontrado no vetor.\n",X);
    }
}