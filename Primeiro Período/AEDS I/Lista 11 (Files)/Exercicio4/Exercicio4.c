#include <stdio.h>
#include <string.h>

/*Escreva um programa em C que solicite ao usuário a digitação do nome de um arquivo texto já
existente, e que então gere um outro arquivo, que será uma cópia do primeiro*/

int main (void){
    char nomeArquivo[20];
    char nomeCopia[20];
    char string[20];
    int aux;
    int numeroCaracteres=1;
    printf("Digite o nome do arquivo:\n");
    gets(nomeArquivo);
    printf("Difite o nome do arquivo a ser criado:\n");
    gets(nomeCopia);
    FILE *arquivo;
    arquivo=fopen(nomeArquivo,"r");
    FILE *arquivo1;
    arquivo1=fopen(nomeCopia,"w");
   

    while (aux!=EOF){
       aux=fgetc(arquivo);
       fgets(string,20,arquivo);
       while(aux!=" "){ 
        fprintf(arquivo1,"%s",string);
       }
    }
    fclose(arquivo);
    fclose(arquivo1);

}