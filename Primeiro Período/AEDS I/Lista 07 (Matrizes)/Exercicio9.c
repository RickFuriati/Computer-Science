#include<stdio.h>
#include<stdlib.h>

/*Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e vice-e-versa.
Escreva ao final o vetor obtido.*/

int random(int interval) //função para sortear numeros aleatórios em um intervalo (maior praticidade)
{
    return rand() % interval;
}
int minrand(int min, int max)
{
    return random(max - min) + min;
}

int main(void){
    int vetor[16];
    int vetorFinal[16];
    int aux1=8;
    int aux2=0;
    srand(time(NULL));
    printf("O vetor sorteado de 16 posicoes corresponde a:\n");
    for (int aux=0;aux<16;aux++){
        vetor[aux]=minrand(0,10);
        printf("%i  ",vetor[aux]);
            vetorFinal[aux]=0;
    
    }
    printf("\nO vetor com os 8 primeiros elementos trocados pelos 8 ultimos corresponde a:\n");
    for (int aux=0;aux<16;aux++){
        if (aux<8){
            vetorFinal[aux]=vetor[aux1];
        }else if (aux>=8){
            vetorFinal[aux]=vetor[aux2];
            aux2++;
        }
        aux1++;
        printf("%i  ",vetorFinal[aux]);
    }
}