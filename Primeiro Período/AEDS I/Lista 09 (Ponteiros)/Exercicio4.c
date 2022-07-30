#include<stdio.h>

/*Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores
de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável.
Escreva o conteúdo das 2 variáveis na tela.*/

void ordenaValor (int *a, int *b){
    int aux=0;
    aux=*a;
    if (*a < *b){
     *a=*b;
     *b=aux;   
    }
}


int main (void){
    int var1,var2;
    printf("Digite um numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite outro numero inteiro:\n");
    scanf("%i",&var2);

    printf("Variaveis correspondem a: variavel 1 = %i e variavel 2 = %i.\n",var1,var2);
    ordenaValor(&var1,&var2);
    printf("Variaveis ordenados em ordem crescente correspondem a: variavel 1 = %i e variavel 2 = %i.\n",var1,var2);
}