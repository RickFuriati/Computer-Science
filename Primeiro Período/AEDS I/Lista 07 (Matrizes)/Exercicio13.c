#include<stdio.h>
#include<stdlib.h>

/*Leia dois vetores de 20 posições e calcule um outro vetor contendo, nas posições pares os valores
do primeiro e nas posições impares os valores do segundo.*/

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
    int vetor1[20];
    int vetor2[20];
    int vetorResultado[20];
    printf("O primeiro vetor de 20 posicoes corresponde a:\n");
    for (int aux=0;aux<20;aux++){
        vetor1[aux]=minrand(0,10);
        if (aux%2==0){
            vetorResultado[aux]=vetor1[aux];
        }
        printf("%i ",vetor1[aux]);
    }
    printf("\nO segundo vetor de 20 posicoes corresponde a:\n");
    for (int aux=0;aux<20;aux++){
        vetor2[aux]=minrand(-10,0);
        if (aux%2!=0){
            vetorResultado[aux]=vetor2[aux];
        }
        printf("%i ",vetor2[aux]);
    }
    printf("\nO vetor resultante corresponde a:\n");
    for (int aux=0;aux<20;aux++){
        printf("%i ",vetorResultado[aux]);
    }
}