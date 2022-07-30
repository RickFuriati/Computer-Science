#include<stdio.h>
#include<stdlib.h>

/*Criar um algoritmo que leia os elementos de uma matriz inteira 10 x 10 e imprima a soma dos
elementos que estão acima da diagonal principal:*/

int random(int interval) //função para sortear numeros aleatórios em um intervalo (maior praticidade)
{
    return rand() % interval;
}
int minrand(int min, int max)
{
    return random(max - min) + min;
}

int main (void){
    srand(time(NULL));
    int matriz[10][10];
    int soma=0;
    printf("A matriz corresponde a:\n\n");
    for (int linha=0;linha<10;linha++){
        for(int coluna=0;coluna<10;coluna++){
        matriz[linha][coluna]=minrand(0,10);
        printf("%i ",matriz[linha][coluna]);
        }
    printf("\n");
    }
    printf("A matriz apenas com os numeros acima da diagonal principal corresponde a:\n\n");
    for (int linha=0;linha<10;linha++){
        for(int coluna=0;coluna<10;coluna++){
            if(linha<coluna){
                printf("%i ",matriz[linha][coluna]);
                soma+=matriz[linha][coluna];
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("A soma dos elementos acima da diagonal principal corresponde a: %i.\n",soma);
}