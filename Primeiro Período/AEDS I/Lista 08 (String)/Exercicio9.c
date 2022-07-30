#include<stdio.h>
#include<string.h>

/*Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string pelo carac-
tere ‘1’.*/

int main (void){
    char numero[200];
    printf("Digite um numero binario:\n");
    gets(numero);
    
    for (int aux=0;aux<strlen(numero);aux++){
        if (numero[aux]=='0'){
            numero[aux]='1';
        }
    }
    printf("A string com o numero '0' substituido por '1' corresponde a:");
    for (int aux=0;aux<strlen(numero);aux++){
        printf("%c",numero[aux]);
    }
}