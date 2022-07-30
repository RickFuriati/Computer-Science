#include<stdio.h>
#include<string.h>
/*Faça um programa que leia uma string e a imprima.*/

int main (void){
    char string[200];
    printf("Digite uma string.\n");
    gets(string);
    printf("A string corresponde a:\n");
    for (int aux=0;aux<strlen(string);aux++){
        printf("%C",string[aux]);
    }
}