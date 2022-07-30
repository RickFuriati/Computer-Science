#include<stdio.h>
#include<string.h>

/*Faça um programa que leia um nome e imprima as 4 primeiras letras do nome.*/

int main (void){
    char nome[200];
    printf("Digite um nome qualquer.\n");
    gets(nome);
    printf("As 4 primeiras letras do nome sao:\n");
    for(int aux=0;aux<4;aux++){
        printf("%c", nome[aux]);
    }
}