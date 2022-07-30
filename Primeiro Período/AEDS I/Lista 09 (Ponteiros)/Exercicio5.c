#include<stdio.h>

/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função que
retorne a soma do dobro dos dois numeros lidos. A função deverá armazenar o dobro de A na
propria variável A e o dobro de B na própria variável B.*/

int somaDobro (int *a, int *b){
    *a=*a*2;
    *b=*b*2;
    return *a+*b;
}


int main (void){
    int var1,var2,resultado;
    printf("Digite um numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite outro numero inteiro:\n");
    scanf("%i",&var2);

    resultado=somaDobro(&var1,&var2);
    printf("a soma do dobro das variaveis corresponde a: %i.",resultado);
}