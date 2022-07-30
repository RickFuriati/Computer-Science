#include<stdio.h>
#include<string.h>

/*Faça um programa que leia uma palavra (maximo de 50 letras) e some 1 no valor ASCII de cada
caractere da palavra. Imprima a string resultante.*/

int main (void){
    char palavra[50];

    printf("Digite uma palavra (maximo de 50 caracteres).\n");
    gets(palavra);
    printf("A palavra com os caracteres com +1 na tabela ASCII corresponde a:\n");
    for (int aux=0;aux<strlen(palavra);aux++){
        palavra[aux]=palavra[aux]+1;
        printf("%c",palavra[aux]);
    }

}