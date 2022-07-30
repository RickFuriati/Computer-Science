#include<stdio.h>
#include<string.h>

/*Leia um vetor contendo letras de uma frase inclusive os espaços em branco. Retirar os espaços
em branco do vetor e depois escrever o vetor resultante.*/

int main (void){
    char frase[200];
    int espacos=0;
    printf("Digite uma frase:\n");
    gets(frase);
    printf("A frase sem espacos corresponde a:\n");
    for (int aux=0;aux<strlen(frase)+espacos;aux++){ //+ espaços é usado como margem para caso o numero de espaços a serem removidos seja maior que o loop 
         frase[aux-espacos]=frase[aux];
        if (frase[aux]==' '){
        espacos++;
        }/*else //So printa as posições que possuem caracteres diferentes de 0
        fraseSemEspaco[aux]=frase[aux-espacos];
        printf("%c",frase[aux]);*/
    }

    for(int aux=0;aux<strlen(frase);aux++){
    
    }
    printf("%s",frase);
}