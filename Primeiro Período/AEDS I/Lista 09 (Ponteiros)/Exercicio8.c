#include<stdio.h>
#include<string.h>

/*Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço
de cada posição desse array.*/

int main (void){
    float vetor[10];
    for (int aux=0;aux<10;aux++){
        printf("Digite um valor da posicao %i:\n",aux);
        scanf(" %i",&vetor[aux]);
    }
    for (int aux=0;aux<10;aux++){
        printf("O endereco da posicao %i corresponde a: %i\n",aux, &vetor[aux]);
    }
}