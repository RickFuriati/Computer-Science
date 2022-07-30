#include<stdio.h>
#include<string.h>
/*Escreva um programa em C para contar a quantidade de palavras de um arquivo texto.*/

int main (void){
    FILE *arquivo;
    int aux;
    int numero_palavras=1;

    arquivo=fopen("texto.txt","r");
    
    while ((aux=fgetc(arquivo))!=EOF){
        if (aux== ' '){
            numero_palavras++;
        }
    }
    
    fclose(arquivo);
    printf("O arquivo possui %i palavras.\n",numero_palavras);
}