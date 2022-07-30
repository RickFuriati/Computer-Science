#include<stdlib.h>

/*Escreva um algoritmo que leia um vetor de 20 posições e mostre-o. Em seguida, troque o primeiro
elemento pelo o último, o segundo com o penúltimo, o terceiro com o antepenúltimo e, assim,
sucessivamente. Mostre o novo vetor após todas as trocas. */

int main (void){
    int vetor[20];
    int vetorInvertido[20];
    int aux1=19;
    for (int aux=0;aux<20;aux++){
        printf("Digite o valor da posicao %i do vetor.\n",aux);
        scanf("%i",&vetor[aux]);
        vetorInvertido[aux1]=vetor[aux];
        aux1--;
    }
    printf("O vetor invertido corresponde a:\n");
    for (int aux1=0;aux1<20;aux1++){
        printf("%i - ",vetorInvertido[aux1]);
    }
}