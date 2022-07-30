#include<stdio.h>
/*Elabore um algoritmo que leia dois vetores de dez posições e faça a multiplicação dos elementos
de mesmo índice, colocando o resultado em um terceiro vetor, que deve ser mostrado como saída. */

int main (void){
    int vetor1[10];
    int vetor2[10];
    int vetorResultado[10];

    for (int aux=1;aux<10;aux++){
        printf("Digite o valor da posicao %i do vetor 1.\n",aux);
        scanf("%i",&vetor1[aux]);
    }

    for(int aux=1;aux<10;aux++){
        printf("Digite o valor da posicao %i do vetor 2.\n",aux);
        scanf("%i",&vetor2[aux]);
        vetorResultado[aux]=vetor1[aux]*vetor2[aux];
    }
    printf("A multiplicacao de elementos do mesmo indice corresponde a: ");
    for (int aux=1;aux<10;aux++){
     printf("%i ",vetorResultado[aux]);
}
}