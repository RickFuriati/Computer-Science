#include<stdio.h>
#include<string.h>

/*Crie um programa que calcula o comprimento de uma string (nao use a função strlen)*/

int main(void){
    char string[10000];
    int numero=0;
    printf("Digite uma palavra qualquer:\n");
    gets(string);

    for (int aux=0; string[aux]!='\0';aux++){
        numero=aux;

    }
    printf("A palavra possui %i caracteres.\n",numero+1);
}