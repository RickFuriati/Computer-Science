#include<stdio.h>
#include<string.h>
/*Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max.
100 caracteres) e armazeá-la num vetor. Imprimir a frase lida trocando as vogais, isto é, trocar ’a’
pelo ’u’, ’e’ pelo ’o’, ’i’ pelo ’u’, ’o’ pelo ’a’ e o ’u’ pelo ’e’. Usar uma função void (procedimento)
para realizar a troca e uma função para realizar a impressão da frase trocada. A função deve ter
como parâmetro um ponteiro char referente ao vetor*/

void trocaVogais(char *frase){
    for (int aux=0; aux<strlen(frase);aux++){
        if (*(frase + aux)=='a'){
            *(frase+ aux)='u';
        }else if (*(frase + aux)=='e'){
             *(frase+ aux)='o';
        }else if (*(frase + aux)=='i'){
             *(frase+ aux)='u';
        }else if (*(frase + aux)=='u'){
             *(frase+ aux)='e';
        }
    }
}

void printaTrocaVogais(char *frase){
   printf("A frase alterada corresponde a: ");
    for (int aux=0;aux<strlen(frase);aux++){
        printf("%c",(*(frase+aux)));
    }
}

int main (void){
    char frase[200];
    printf("Digite uma frase:\n");
    gets(frase);
    printf("A frase normal corresponde a: %s.\n",frase);
    trocaVogais(&frase);
    printaTrocaVogais(&frase);
}