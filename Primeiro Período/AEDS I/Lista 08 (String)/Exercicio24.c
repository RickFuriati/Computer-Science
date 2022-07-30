#include<stdio.h>
#include<string.h>

/*Escreva um programa que recebe do usuario uma string S, um caractere C, e uma posição I e
devolve o índice da primeira posição da string onde foi encontrado o caractere ~ C. A procura
deve começar a partir da posição I. ~*/

int main (void){
    char string[200];
    char C;
    int I=0;
    int posicao=0;

    printf("Digite uma string:\n");
    gets(string);

    printf("Digite uma posicao para a string:\n");
    scanf("%i",&I);

    printf("Digite um caracter qualquer:\n");
    scanf(" %c",&C);

    for(int aux=I;aux<strlen(string);aux++){
        if (string[aux]==C){
            posicao=aux;
            break;
        }
    }
    printf("A primeira posicao da string onde foi encontrado o caractere '%c' corresponde a %i posicao.\n",C,posicao);
}