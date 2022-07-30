#include<stdio.h>
#include<string.h>

/*Faça um programa que receba duas frases distintas e imprima de maneira invertida, trocando as
letras A por *. */

int main (void){
    char frase1[200];
    char frase2[200];

    printf("Digite uma frase:\n");
    gets(frase1);
    printf("Digite uma segunda frase:\n");
    gets(frase2);

    for (int aux=0;aux<strlen(frase1);aux++){
        if ((frase1[aux]=='a')|(frase1[aux]=='A')){
            frase1[aux]='*';
        }
    }
    for (int aux=0;aux<strlen(frase2);aux++){
        if ((frase2[aux]=='a')|(frase2[aux]=='A')){
            frase2[aux]='*';
        }
    }
    printf("As frases invertidas e com as letras 'a' substituidas por '*'.\n");
    printf("%s %s",frase2,frase1);
}