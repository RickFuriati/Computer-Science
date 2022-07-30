#include<stdio.h>
#include<string.h>

/*Ler uma frase e contar quantos caracteres sao espaços em brancos. Lembre-se que uma frase e
um conjunto de caracteres (vetor).*/

int main (void){
    char frase[2000];
    int espacos=0;
    printf("Digite uma frase:\n");
    gets(frase);

    for (int aux=0;aux<strlen(frase);aux++){
        if (frase[aux]==' '){
        espacos++;
        }
    }
    printf("A frase possui %i espacos em branco.",espacos);
}