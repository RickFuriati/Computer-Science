#include<stdio.h>
#include<string.h>

/*Escreva um programa que leia duas palavras e diga qual deles vem primeiro na ordem alfabetica.
 ́Dica: ‘a’ e menor do que ‘b’.*/

int main (void){
    char palavra1[200];
    char palavra2[200];

    printf("Digite uma palavra:\n");
    gets(palavra1);
    printf("Digite outra palavra:\n");
    gets(palavra2);

    if (palavra1[0]<palavra2[0]){
        printf("Em ordem alfabetica a palavra '%s' vem antes da segunda palavra ('%s').\n",palavra1,palavra2);
    }else
        printf("Em ordem alfabetica a palavra '%s' vem antes da segunda palavra ('%s').\n",palavra2,palavra1);
}