#include<stdio.h>
#include<string.h>

/*Digite um nome, calcule e retorne quantas letras minúsculas tem esse nome*/

int main (void){
    char nome[200];
    int minusculas=0;
    printf("Digite um nome qualquer:\n");
    gets(nome);

    for (int aux=0;aux<strlen(nome);aux++){
        if (nome[aux]>96){
            minusculas++;
        }
    }
    printf("\nO nome digitado possui %i letras minusculas.",minusculas);
}