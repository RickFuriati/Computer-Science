#include<stdio.h>
#include<string.h>

/*Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’ (maiuscula
ou minuscula).*/

int main (void){
    char nome[200];
    printf("Digite um nome qualquer.\n");
    gets(nome);

    if ((nome[0]=='a')||(nome[0]=='A')){
        for (int aux=0;aux<strlen(nome);aux++){
            printf("%c",nome[aux]);
        }
    }else 
        printf("\nO nome nao comeca com 'a'.");
}