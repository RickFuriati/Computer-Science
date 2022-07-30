#include<stdio.h>

/*Desenvolva um algoritmo que leia 20 valores inteiros e que armazene os dez primeiros valores no
vetor X e o restante no vetor Y. A seguir, crie e imprima um vetor que é a união entre e X e Y.*/

int main(void){
    int vetorX[10];
    int vetorY[10];
    int vetorUniao[20];
    int aux2=11;
    for (int aux1=0;aux1<10;aux1++){
        printf("Digite o %i valor \n",aux1+1);
        scanf("%i",&vetorX[aux1]);
        vetorUniao[aux1]=vetorX[aux1];
    }

    for (int aux1=0;aux1<10;aux1++){
        printf("Digite o %i valor \n",aux2);
        scanf("%i",&vetorY[aux1]);
        vetorUniao[aux2-1]=vetorY[aux1];
        aux2++;
    }

    printf("O vetor resultante da combinacao dos vetores X e Y corresponde a:\n ");
    for (int aux1=0;aux1<20;aux1++){
        printf("%i - ",vetorUniao[aux1]);
    }
}