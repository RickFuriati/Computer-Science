#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
/*Considere um arquivo texto que armazene números em ponto flutuante em cada uma de suas
linhas. Escreva um programa em C que determine o valor máximo, o valor mínimo e a média
desses valores armazenados no arquivo. Imprima esses valores na tela.*/

int main (void){
    FILE *arquivo;
    arquivo=fopen("arquivofloat.txt","r");
    char linha[20];
    float soma=0,menorValor=INFINITE,maiorValor=0;
    int numLinhas=0;
    float valor;
    while (fgets(linha,20,arquivo)!=NULL){
        valor=atof(linha);
        
        soma+=valor;
        
        if(valor>maiorValor){
            maiorValor=valor;
        }
        if(valor<menorValor){
            menorValor=valor;
        }
        numLinhas++;
        
    }
    fclose(arquivo);

    printf("Menor Valor: %.2f\n",menorValor);
    printf("Maior Valor: %.2f\n",maiorValor);
    printf("Media Valor: %.2f\n",soma/(float)numLinhas);
}