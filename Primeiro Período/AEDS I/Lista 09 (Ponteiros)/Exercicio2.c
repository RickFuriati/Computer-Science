#include<stdio.h>

/*Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em
seguida, compare seus endereços e exiba o conteúdo do maior endereço.*/

int main (void){
    int var1,var2;
    printf("Digite um numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite outro numero inteiro:\n");
    scanf("%i",&var2);

    if (&var1>&var2){
        printf("A variavel com o maior endereco de memoria (%i) foi '%i'.",&var1,var1);
    
    }else{
        printf("A variavel com o maior endereco de memoria (%i) foi '%i'.",&var2,var2);
       
    }
}