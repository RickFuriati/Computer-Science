#include<stdio.h>
#include<stdlib.h>

/*Leia um vetor de 40 posições. Contar e escrever quantos valores pares ele possui.*/

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
        vetor[aux]=minrand(0,100);
        printf("%i ",vetor[aux]);
    }

    for(int aux=0;aux<40;aux++){
        if(vetor[aux]%2==0){
        pares++;
        }
    }
    printf("\nO vetor possui %i numeros pares.",pares);
    }

    
