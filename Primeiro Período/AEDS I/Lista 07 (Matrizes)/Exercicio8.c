#include<stdio.h>
#include<stdlib.h>

/*Declare um vetor de 10 posições e o preencha com os 10 primeiros números impares e os escreva.*/

int main(void){
    int vetor[10];
    int aux1=1;
    printf("O vetor de 10 posicoes com os 10 primeiros numeros impares corresponde a:\n");
    for(int aux=0;aux<10;aux++){
        vetor[aux]=aux1;
        aux1+=2;
        printf("%i ", vetor[aux]);
    }
}
