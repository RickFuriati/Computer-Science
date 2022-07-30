#include<stdio.h>

/*Escreva uma função que receba um array de inteiros V e os endereços de duas variáveis inteiras,
min e max, e armazene nessas variáveis o valor mínimo e máximo do array. Escreva também
uma função main que use essa função.*/

void minMaxVetor (int *vetor, int *minimo, int *maximo, int tamanho){
    int min=0,max=0;
    for (int aux=0;aux<tamanho;aux++){
        if (*(vetor+aux)<vetor[min]){
            min=aux;
        }
        if (*(vetor+aux)>vetor[max]){
            max=aux;
        } 
    }
    *minimo=vetor[min];
    *maximo=vetor[max];
    //printf("%i %i\n",vetor[min],vetor[max]);

}




int main (void){
    int N,resultado=0;
    int minimo,maximo;
    printf("Digite o tamamnho do vetor:\n");
    scanf("%i",&N);

    int vetor[N];
    
    for (int aux=0;aux<N;aux++){
        printf("Digite o valor da posicao %i.\n",aux);
        scanf("%i",&vetor[aux]);
    }
    minMaxVetor(&vetor,&minimo,&maximo,N);
    printf("\nO menor valor foi %i e o maior valor foi %i.\n",minimo,maximo);
}