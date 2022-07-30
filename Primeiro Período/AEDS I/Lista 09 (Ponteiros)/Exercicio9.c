#include<stdio.h>
#include<string.h>

/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas
aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.*/

int main (void){
    int vetorInteiros[5];
    for(int aux=0;aux<5;aux++){
        printf("Digite um inteiro para posicao %i.\n",aux);
        scanf("%i",vetorInteiros+aux);
    }
    for (int aux=0;aux<5;aux++){
        printf("O dobro do valor na posicao %i corresponde a: %i \n",aux,*(vetorInteiros+aux)*2);
    }
}