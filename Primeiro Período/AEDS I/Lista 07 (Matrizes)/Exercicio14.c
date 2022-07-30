#include<stdio.h>
#include<stdlib.h>

/*Crie duas matrizes 3x3. A primeira será digitada pelo usuário e a segunda deverá ser a primeira
rotacionada 90º. */

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
    int matriz[3][3];
    int matrizRotacionada[3][3];
    printf("A matriz 3x3 sorteada corresponde a:\n");
    for(int linha=0;linha<3;linha++){
        for (int coluna=0;coluna<3;coluna++){
            matriz[linha][coluna]=minrand(0,10);
            matrizRotacionada[linha][coluna]=matriz[linha][coluna];
            printf("%i ",matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("\nA matriz rotacionada em 90 graus corresponde a:\n");
    for(int linha=0;linha<3;linha++){
        for (int coluna=0;coluna<3;coluna++){
            if (linha!=coluna){
                matrizRotacionada[linha][coluna]=matriz[coluna][linha];
            }
            printf("%i ",matrizRotacionada[linha][coluna]);
        }
        printf("\n");
    }
}