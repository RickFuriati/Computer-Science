#include<stdio.h>
#include<string.h>

/*Crie um programa que compara duas strings (nao use a função strcmp). */

int main(void){
    char string1[10000];
    char string2[10000];
    int numeroString1=0;
    int numeroString2=0;
    
    printf("Digite uma palavra qualquer (string 1):\n");
    gets(string1);
    printf("Digite uma palavra qualquer (string 2):\n");
    gets(string2);
    
    for (int aux=0; string1[aux]!='\0';aux++){
        numeroString1=aux;
    }
     for (int aux=0; string2[aux]!='\0';aux++){
        numeroString2=aux;
    }

    if(numeroString1>numeroString2){
        printf("A string 1 (%i caracteres) e maior que a string 2 (%i caracteres).",numeroString1+1,numeroString2+1);
    }else if (numeroString1==numeroString2){
        printf("As duas strings possuem o mesmo tamamnho (%i caracteres).",numeroString1+1);
    }else
        printf("A string 2 (%i caracteres) e maior que a string 1 (%i caracteres).",numeroString2+1,numeroString1+1);

}