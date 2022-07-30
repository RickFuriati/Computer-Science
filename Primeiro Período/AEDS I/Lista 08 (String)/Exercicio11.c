#include<stdio.h>
#include<string.h>

/*Faça um programa que receba do usuario uma string. O programa imprime a string sem suas
vogais.*/

int main (void){
    char string[200];
    printf("Digite uma palavra qualquer:\n");
    gets(string);
    printf("A palavra sem vogais corresponde a:\n");
    for(int aux=0;aux<=strlen(string);aux++){
        if ((string[aux]==97)|(string[aux]==101)|(string[aux]==105)|(string[aux]==111)|(string[aux]==117)){
        }else
        printf("%c",string[aux]); //So printa as posições cujo caracter nao é uma vogal 
    }
}