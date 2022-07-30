#include<stdio.h>

/*Implemente uma função que receba como parâmetro um array de números reais de tamanho N
e retorne quantos numeros negativos há nesse array. Essa função deve obedecer ao prototipo:
int negativos(float *vet, int N)*/
int contaNegativos (float *vet, int N){
   int numerosNegativos=0;
    for (int aux=0;aux<N;aux++){
        if(*(vet+aux)<0){
            numerosNegativos++;
        }
    }
    return numerosNegativos;
}


int main (void){
    int N,resultado=0;
    printf("Digite o tamamnho do vetor:\n");
    scanf("%i",&N);

    float vetor[N];
    
    for (int aux=0;aux<N;aux++){
        printf("Digite o valor da posicao %i.\n",aux);
        scanf("%f",&vetor[aux]);
    }
    resultado=contaNegativos(&vetor,N);
    printf("O vetor possui %i numeros negativos.\n",resultado);
}