#include<stdio.h>
#include<string.h>

/*Construa um programa que leia duas strings fornecidas pelo usuario e verifique se a segunda
string lida esta contida no final da primeira, retornando o resultado da verificacão.*/

int main (void){
    char string1[200];
    char string2[200];
    int match=0;
    printf("Digite uma string:\n");
    gets(string1);
    printf("Digite outra string:\n");
    gets(string2);
    printf("%i\n",strlen(string1));
    printf("%i\n",strlen(string2));
    for (int aux=strlen(string1)-1,aux1=strlen(string2)-1;aux1>=0 ; aux--,aux1-- ){// Fiz a análise a partir da ultima posição das strings de forma decrescente até que a string2 chegue na sua posição 0
        if (string1[aux]==string2[aux1]){                                         //Foi necessário colocar "-1" no strlen tendo em vista que as strings começam da posição 0
        match++;
        }
    } 
    printf("%i\n",match);
    if (match==strlen(string2)){ // Caso o numero de correspondências (match) seja igual ao comprimento da segunda string, ela está contida na primeira
        printf("A palavra '%s' esta contida no final da palavra '%s'.\n",string2,string1);
    }else
        printf("A palavra '%s' nao esta contida no final da palavra '%s'.\n",string2,string1);
    }