#include<stdio.h>
#include<string.h>

/*Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da pessoa
e a palavra “ACEITA”, caso contrario imprimir “NÃO ACEITA”.*/

int main (void){
    char nome[200];
    char sexo[200];
    int idade;

    printf("Digite seu nome:\n");
    gets(nome);
    printf("Digite seu sexo:\n");
    gets(sexo);
    printf("Digite sua idade:\n");
    scanf("%i",&idade);

    if (((sexo[0]=='F') || (sexo[0]=='F')) && (idade<25)){
        printf("Seu nome corresponde a:\n");
        for (int aux=0;aux<strlen(nome);aux++){
            printf("%c",nome[aux]);
        }
        printf("\nACEITA.");
    }else 
        printf("NAO ACEITA.");
}