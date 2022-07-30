#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da
banda, que tipo de música ela toca, o número de integrantes e em que posição do ranking essa
banda está dentre as suas 5 bandas favoritas. Crie um looping para preencher as 5 estruturas
de bandas criadas no exemplo passado. Após criar e preencher, exiba todas as informações das
bandas/estruturas.*/

typedef struct{
    char nome[30];
    char tipo_musica[30];
    int numero_integrantes;
    int posicao;

}banda;


int main (void){
    banda vetor[5];
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
}