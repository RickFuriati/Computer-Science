#include <stdio.h>
#include <string.h>

/*Escreva um programa em C que abra um arquivo texto e que conte a quantidade de caracteres
armazenados nele. Imprima o número na tela. O programa deve solicitar ao usuário que digite
o nome do arquivo.*/

int main (void){
    char nomeArquivo[20];
    int aux;
    int numeroCaracteres=1;
    printf("Digite o nome do arquivo:\n");
    gets(nomeArquivo);

    FILE *arquivo;
    arquivo=fopen(nomeArquivo,"r");
     
    while (aux=fgetc(arquivo)!=EOF){
        aux=fgetc(arquivo); 
        numeroCaracteres++;
    }
    fclose(arquivo);
    printf("O arquivo '%s' possui %i caracteres.\n",nomeArquivo,numeroCaracteres);
}