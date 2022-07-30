#include<stdio.h>
#include<string.h>

/*Escreva um programa que recebe uma string S e inteiros nao-negativos I e J e imprima o segmento
S[I..J].*/

int main (void){
    char string [200];
    int I,J;

    printf("Digite uma string:\n");
    gets(string);
    printf("Digite um numero inteiro nao-negativo:\n");
    scanf("%i",&I);
    printf("Digite outro numero inteiro nao-negativo:\n");
    scanf("%i",&J);

    printf("O segmento %i-%i da string corresponde a:\n",I,J);
    for (int aux=I;aux<=J;aux++){
        printf("%c",string[aux]);
    }
}