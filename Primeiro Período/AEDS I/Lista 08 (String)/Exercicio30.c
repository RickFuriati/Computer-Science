#include<stdio.h>
#include<string.h>

/*Crie um programa que receba uma frase do usuário e mostre os caracteres contidos nas posições
da série de fibonacci.*/

int main (void){
    char frase[200];
    char fraseFibonacci[200];
    int aux=0,aux1=1,atual=0;

    printf("Digite uma frase:\n");
    gets(frase);
    printf("A frase com os caracteres nas posicoes da sequencia de fibonacci corresponde a:\n");
    for (int auxiliar=0;auxiliar<strlen(frase)-2;auxiliar++){
        atual=aux+aux1;
        aux=aux1;
        aux1=atual;
        fraseFibonacci[auxiliar]=frase[atual];
    }
    printf("%s",fraseFibonacci);
}