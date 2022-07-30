#include<stdio.h>
#include<string.h>

/* Escreva um programa para converter uma cadeia de caracteres de letras maiusculas em letras
minusculas.*/

int main (void){
    char cadeia[200];
    printf("Digite uma cadeia de letras maiusculas:\n");
    gets(cadeia);
    printf("A cadeia transformada em letras minusculas corresponde a:\n");

    for (int aux=0;aux<strlen(cadeia);aux++){
        cadeia[aux]+=32;
        printf("%c",cadeia[aux]);
    }
}