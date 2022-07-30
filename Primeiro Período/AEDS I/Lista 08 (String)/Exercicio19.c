#include<stdio.h>
#include<string.h>

/*Escreva um programa que leia a idade e o primeiro nome de 10 pessoas. Ao terminar, seu
programa deve escrever o nome e a idade da pessoa mais jovem e mais velha.*/

int main (void){
    char nome[200];
    int idade=0,maiorIdade=0,menorIdade=200; //menor idade começa com valor alto pra que a idade no primeiro loop já seja comparada 
    char nomeMenorIdade[200];
    char nomeMaiorIdade[200];

    for (int aux=0;aux<10;aux++){
        printf("Digite o nome da pessoa %i:\n",aux+1);
        scanf(" %[^\n]s",&nome);
        printf("Digite a idade da pessoa %i:\n",aux+1);
        scanf("%i",&idade);
    
        if (idade>maiorIdade){
            maiorIdade=idade;
            strcpy(nomeMaiorIdade,nome);
        }else if(idade<menorIdade){
            menorIdade=idade;
            strcpy(nomeMenorIdade,nome);
        }
    }
    printf("%s\n",nome);
    printf("A pessoa com a menor idade foi o(a) %s com %i anos.\n",nomeMenorIdade,menorIdade);
    printf("A pessoa com a maior idade foi o(a) %s com %i anos.\n",nomeMaiorIdade,maiorIdade);


}