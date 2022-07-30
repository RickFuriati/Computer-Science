#include<stdio.h>
#include<string.h>

/*Implemente um programa que leia duas strings, str1 e str2, e um valor inteiro positivo N. Con-
catene nao mais que N caracteres da string str2 na string str1 e termine str1 com ‘barra0’*/

int main (void){
    char string1[200];
    char string2[200];
    char stringResultante[400];
    int N=0;

    printf("Digite uma string:\n");
    gets(string1);
    printf("Digite outra string:\n");
    gets(string2);
    printf("Digite um valor inteiro posivo:\n");
    scanf("%i",&N);

    for (int aux=0;string1[aux]!='\0';aux++){
       stringResultante[aux]=string1[aux];
        for (int aux1=strlen(string1), aux2=0;aux2<N;aux1++,aux2++){
            stringResultante[aux1]=string2[aux2];
        }
    }
    printf("\n%s",stringResultante);

}