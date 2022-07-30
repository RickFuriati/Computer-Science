#include<stdio.h>
#include<string.h>

/*Faça um programa que conte o numero de 1’s que aparecem em um string.*/

int main (void){
    char numero[200];
    int quantidade1=0;
    printf("Digite um numero binario:\n");
    gets(numero);
    
    for (int aux=0;aux<strlen(numero);aux++){
        if (numero[aux]=='1'){
            quantidade1++;
        }
    }
    printf("A string possui %i numeros '1'.",quantidade1);
}