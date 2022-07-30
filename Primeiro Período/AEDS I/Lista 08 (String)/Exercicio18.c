#include<stdio.h>
#include<string.h>

/*Faça um programa em que troque todas as ocorrencias de uma letra L1 pela letra L2 em uma
string. A string e as letras L1 e L2 devem ser fornecidas pelo usuario.*/

int main (void){
    char string[200];
    char L1,L2;
    printf("Digite uma string:\n");
    gets(string);
    printf("Digite a letra a ser substituida:\n");
    scanf("%c",&L1);
    printf("Digite a letra que subsituira a letra '%c':\n",L1);
    scanf(" %c",&L2);
    printf("A string com a letra '%c' trocada por '%c' corresponde a:",L1,L2);
    for (int aux=0;aux<strlen(string);aux++){
        if (string[aux]==L1){
            string[aux]=L2;
        }
        printf("%c",string[aux]);
    }
    }