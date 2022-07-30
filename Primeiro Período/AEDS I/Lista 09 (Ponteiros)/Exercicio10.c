#include<stdio.h>
#include<string.h>

/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array do
teclado e imprima o endereço das posições contendo valores pares.*/

int main (void){
    int vetor[5];

    for (int aux=0;aux<5;aux++){
        printf("Digite um valor inteiro para posicao %i:\n",aux);
        scanf("%i",&vetor[aux]);
    }

    for (int aux=0;aux<5;aux++){
        if(vetor[aux]%2==0){
            printf("A posicao %i contem um numero par que esta no endereco: %i.\n",aux,&vetor[aux]);
        }
    }
}