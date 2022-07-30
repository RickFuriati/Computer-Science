#include<stdio.h>
#include<string.h>

/*Faça um programa que, dada uma string, diga se ela e um palíndromo ou nao. Lembrando que
um palíndromo é uma palavra que tenha a propriedade de poder ser lida tanto da direita para a
esquerda como da esquerda para a direita. Exemplo: ovo arara Socorram-me, subi no onibus em
Marrocos. Anotaram a data da maratona*/

int main (void){
    char palavra[200];
    char palavraInvertida[200];

    printf("Digite uma palavra:\n");
    gets(palavra);

    for(int aux=0, aux1=strlen(palavra);aux<strlen(palavra);aux++,aux1--){
        palavraInvertida[aux]=palavra[aux1];
    }

    if (strcmp(palavra,palavraInvertida)==0){
        printf("A palavra '%s' nao e um palindromo.\n",palavra);
    }else
        printf("A palavra '%s' e um palindromo.\n",palavra);
}