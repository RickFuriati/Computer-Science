#include<stdio.h>
#include<string.h>

/*Faça um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui essa
palavra. Entre com um caractere (vogal ou consoante) e substitua todas as vogais da palavra
dada por esse caractere.*/

int main (void){
    char string[200];
    int vogais=0;
    char caracter;

    printf("Digite uma palavra qualquer:\n");
    gets(string);
    printf("Digite um caracter para substituir as vogais:\n");
    scanf("%c",&caracter);
   
    for(int aux=0;aux<=strlen(string);aux++){
        if ((string[aux]==97)|(string[aux]==101)|(string[aux]==105)|(string[aux]==111)|(string[aux]==117)){
            vogais++;
            string[aux]=caracter;  
        }
    }
    printf("A pavra com as vogais substituidas por '%c' corresponde a:\n",caracter);
    for (int aux=0;aux<strlen(string);aux++){
        printf("%c",string[aux]);
    }
}