#include<stdio.h>

/*Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de
entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável, o segundo menor
valor na variável do meio, e o maior valor na última variável. A função deve retornar o valor 1
se os três valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na
tela.*/

void ordenaValores (int *a, int *b, int *c){
    int aux=0,aux1=0;
    
    if ((*a>*b)&&(*a>*c)){

    }else if (((*b>*a)&&(*b>*c))){
        aux=*a;
        *a=*b;
        if(aux>*c){
            *b=aux;
        }else{
            aux1=*a;
            *b=*c;
            *c=aux;
        }
    }else if (((*c>*a)&&(*c>*b))){
        aux=*a;
        *a=*c;
        if(aux>*b){
            aux1=*b;
            *b=*a;
            *c=aux1;
        }else{
            *c=aux;
        }

    }
}
 

int main (void){
    int var1,var2,var3;
    printf("Digite o primeiro numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite o segundo numero inteiro:\n");
    scanf("%i",&var2);
    printf("Digite o terceiro numero inteiro:\n");
    scanf("%i",&var3);
    ordenaValores(&var1,&var2,&var3);
    printf("Os valores ordenados correspondem a: %i %i %i.",var1,var2,var3);
}