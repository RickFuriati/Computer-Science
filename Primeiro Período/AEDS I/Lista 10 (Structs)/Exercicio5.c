#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*Na questão anterior crie uma função que peça o nome de uma banda ao usuário e diga se ela está
entre suas bandas favoritas ou não*/

typedef struct{
    char nome[30];
    char tipo_musica[30];
    int numero_integrantes;
    int posicao;

}banda;

bool favoritas(char *banda_usuario,banda *vetor){
    for (int aux=0;aux<5;aux++){
        if(banda_usuario==vetor[aux].nome){
            return true;
        }
    }
    return false;
}

int main (void){
    banda vetor[5];
    char banda_usuario[30];
    bool resultado;
    for (int aux=0;aux<5;aux++){
        printf("------ Banda %i ------ \n",aux+1);
        printf("Digite o nome da banda:\n");
        scanf(" %[^\n]s",&vetor[aux].nome);
        printf("Digite o tipo de musica tocada pela banda:\n");
        scanf(" %[^\n]s",vetor[aux].tipo_musica);
        printf("Digite o numero de integrantes da banda:\n");
        scanf("%i",&vetor[aux].numero_integrantes);
        printf("Digite o ranking desta banda dentre as suas 5 favoritas:\n");
        scanf("%i",&vetor[aux].posicao);
    }

    for(int aux=0;aux<5;aux++){
        printf("\n------ Banda '%s' ------ \n",vetor[aux].nome);
        printf("A banda toca %s \n",vetor[aux].tipo_musica);
        printf("A banda possui %i integrantes.\n",vetor[aux].numero_integrantes);
        printf("A banda esta no ranking %i das 5 bandas favoritas.\n",vetor[aux].posicao);  
    }

    printf("Digite o nome de uma banda:\n");
    scanf(" %[^\n]s",banda_usuario);
    resultado=favoritas(&banda_usuario,&vetor);

    if (resultado=true){
        printf("A banda %s esta entre as 5 favoritas do usuario.",banda_usuario);
    }else{
        printf("A banda %s nao esta entre as 5 favoritas do usuario.",banda_usuario);
    }
}