#include<stdio.h>
#include<string.h>

/*Leia uma cadeia de caracteres e converta todos os caracteres para maiuscula.*/

int main (void){
    char cadeia[200];
    printf("Digite uma cadeia de letras:\n");
    gets(cadeia);
    printf("A cadeia transformada em letras maiusculas corresponde a:\n");

    for (int aux=0;aux<strlen(cadeia);aux++){
        cadeia[aux]-=32;
        printf("%c",cadeia[aux]);
    }
}