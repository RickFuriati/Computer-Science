#include<stdio.h>

/*Crie um programa que contenha uma função que permita passar por parâmetro dois numeros
inteiros A e B. A função deverá calcular a soma entre estes dois números e armazenar o resultado
na variável A. Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro
parâmetro. Imprima os valores de A e B na função principal.*/

void somaReferencia (int *a, int *b){
    int soma=0;
    soma=*a+*b;
    *a=soma;
}


int main (void){
    int var1,var2,resultado;
    printf("Digite um numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite outro numero inteiro:\n");
    scanf("%i",&var2);
    somaReferencia(&var1,&var2);
    printf("a soma das variaveis corresponde a: %i.",var1);
}