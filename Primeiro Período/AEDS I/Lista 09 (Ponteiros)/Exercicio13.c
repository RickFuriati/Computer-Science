#include<stdio.h>
#include <string.h>

/*Crie uma função que receba como parâmetro um array e o imprima. Não utilize índices para
percorrer o array, apenas aritmética de ponteiros.*/

void printaVetor(char *vetor){
    for (int aux=0;aux<5;aux++){
        printf("%i ",(*(vetor)+aux));
    }
}


int main (void){
    int vetor[5];
    for (int aux=0;aux<5;aux++){
        printf("Digite o valor da posicao %i:\n",aux);
        scanf("%i",&vetor[aux]);
    }
    printf("Os valores do vetor printados com ponteiros correspondem a:\n");
    printaVetor(&vetor);
     
}