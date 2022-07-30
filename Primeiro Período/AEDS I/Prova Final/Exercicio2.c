#include <stdio.h>
#include <stdbool.h>
/*Considere o arquivo gerado na questão anterior, que é um documento de texto com vários valores de 1 a 4, sendo que cada linha do
documento possui um valor. Faça um programa que apure o resultado desta votação, ou seja, quem é o ganhador
ou quem irá disputar o segundo turno.*/


int main(void){
    FILE *arquivo1;
    arquivo1=fopen("arquivo1.txt","r");
    int votos1=0,votos2=0,votos3=0,votos4=0;
    int vencedor=0;
    int segundoturno[4];
    int aux;
    int votosVencedor=0;
    bool segundoTurno;
   
    while(aux!=EOF){
        aux=fgetc(arquivo1);
        if(aux=='1'){
            votos1+=1;
        }else if(aux=='2'){
            votos2+=1;
        }else if(aux=='3'){
            votos3+=1;
        }else if(aux=='4'){
            votos4+=1;
        }
    }
    fclose(arquivo1);
    printf("-------- Resultados da Votacao --------\n");
    printf("Candidato 1 - %i Votos.\n",votos1);
    printf("Candidato 2 - %i Votos.\n",votos2);
    printf("Candidato 3 - %i Votos.\n",votos3);
    printf("Candidato 4 - %i Votos.\n",votos4);


    if((votos1>votos2)&&(votos1>votos3)&&(votos1>votos4)){
        vencedor=1;
        votosVencedor=votos1;
    }else if((votos2>votos1)&&(votos1>votos3)&&(votos1>votos4)){
        vencedor=2;
        votosVencedor=votos2;
    }else if((votos3>votos2)&&(votos3>votos1)&&(votos3>votos4)){
        vencedor=3;
        votosVencedor=votos3;
    }else if((votos4>votos2)&&(votos4>votos3)&&(votos4>votos1)){
        vencedor=4;
        votosVencedor=votos4;
    }


    if(votosVencedor==votos1){
        printf("A votacao vai a segundo turno entre os candidatos:\nCandidato %i e Candidato %i\n",vencedor,votos1);
    }else if(votosVencedor==votos2){
        printf("A votacao vai a segundo turno entre os candidatos:\nCandidato %i e Candidato %i\n",vencedor,votos2);
    }else if(votosVencedor==votos3){
        printf("A votacao vai a segundo turno entre os candidatos:\nCandidato %i e Candidato %i\n",vencedor,votos3);
    }else if(votosVencedor==votos4){
        printf("A votacao vai a segundo turno entre os candidatos:\nCandidato %i e Candidato %i\n",vencedor,votos4);
    }else{
        printf("O vencedor das eleicoes foi o Candidato %i\n",vencedor);
    }
   
}