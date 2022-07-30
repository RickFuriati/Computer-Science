#include<stdio.h>
#include<stdlib.h>

/*Preencha um vetor de 12 posições e em seguida ler também dois valores X e Y quaisquer corres-
pondentes a duas posições no vetor ou seja, os valores de X e Y devem estar entre 0 e 11. Ao
final seu programa deverá escrever a soma dos valores encontrados nas respectivas posições X e
Y.*/

int random(int interval) //função para sortear numeros aleatórios em um intervalo (maior praticidade)
{
    return rand() % interval;
}
int minrand(int min, int max)
{
    return random(max - min) + min;
}

int main (void){
    srand(time(NULL));
    int vetor[12];
    int X,Y;
    printf("O vetor sorteado corresponde a:\n");
    for(int aux=0;aux<12;aux++){
        vetor[aux]=minrand(0,10);
        printf("%i ",vetor[aux]);
    }
    do{
    printf("\nDigite um valor X.\n");
    scanf("%i",&X);
    }while(X>11);
    
    do{
    printf("Digite um valor Y.\n");
    scanf("%i",&Y);
    }while(Y>11);
    
    printf("O elemento no vetor correspondente na posicao %i corresponde a: %i.\n",X,vetor[X]);
    printf("O elemento no vetor correspondente na posicao %i corresponde a: %i.\n",Y,vetor[Y]);
}