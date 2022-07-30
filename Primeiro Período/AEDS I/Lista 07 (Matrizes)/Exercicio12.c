#include<stdio.h>
#include<stdlib.h>

/*Leia um vetor de 40 posições e atribua valor 0 para todos os elementos que possuírem valores
negativos.*/

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
    int vetor[40];
    int X,pares=0;
    printf("O vetor sorteado de 40 posicoes corresponde a:\n");
    for (int aux=0;aux<40;aux++){
        vetor[aux]=minrand(-20,20);
        printf("%i ",vetor[aux]);
    }
    printf("\n O vetor com numeros negativos subistituidos por 0 corresponde a:\n");
    for(int aux=0;aux<40;aux++){
        if(vetor[aux]<0){
        vetor[aux]=0;
        }
        printf("%i ",vetor[aux]);
    }
}
