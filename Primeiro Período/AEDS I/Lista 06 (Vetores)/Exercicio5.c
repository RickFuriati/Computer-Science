#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/* Faça um algoritmo que preencha um vetor como nove números inteiros e mostre quais são primos
e suas respectivas posições.*/

bool verificaPrimo(int numero){
    bool primo = true;
    if (numero<2){
        primo=false;
    }else if (numero>2){
        for(int base=2;base<=(numero/2);base++){
            if (numero%base==0){
                primo=false;
                break;
            }
        }
    }
    return primo;
}

int main (void){
    srand(time(NULL));
    int vetorPrimos [9];
    for (int aux1=0;aux1<9;aux1++){
        vetorPrimos[aux1]=rand()%1000;
        printf("%i \n",vetorPrimos[aux1]);
    }
    for (int aux1=0;aux1<9;aux1++){
        if (verificaPrimo(vetorPrimos[aux1])){
            printf("O numero %i da posicao %i eh um numero primo.\n",vetorPrimos[aux1],aux1);
        }
    }
}