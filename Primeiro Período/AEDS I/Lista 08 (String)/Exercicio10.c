#include<stdio.h>
#include<string.h>

/*Faça um programa que receba uma palavra e a imprima de tras-para-frente. */

int main (void){
    char palavra[200];
    printf("Digite uma palavra qualquer:\n");
    gets(palavra);

    printf("A palavra ao contrario corresponde a:\n");
    for (int aux=strlen(palavra);aux>=0;aux--){
        printf("%c",palavra[aux]);
    }
}
