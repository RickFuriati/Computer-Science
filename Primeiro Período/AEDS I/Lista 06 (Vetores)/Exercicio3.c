#include<stdio.h>
/*Crie um programa que receba o tempo de 5 corredores em 3 etapas, depois some as 3 etapas em
um quarto vetor e diga quem foi o campeão geral das 3 etapas.*/

int main (void){
    float etapa1[5];
    float etapa2[5];
    float etapa3[5];
    float resultado[5];
    int menorTempo=0;
    printf("------------ETAPA 1------------\n");
    for(int aux1=0;aux1<5;aux1++){
        printf("Digite o tempo do corredor %i:\n",aux1+1);
        scanf("%f",&etapa1[aux1]);
        resultado[aux1]=etapa1[aux1];
        
        if (resultado[aux1]<resultado[menorTempo]){
            menorTempo=aux1;
        }
    }
    printf("O vencedor da etapa foi o corredor %i com um tempo de: %.2f\n",menorTempo+1,resultado[menorTempo]);
    printf("------------ETAPA 2------------\n");
    for(int aux1=0;aux1<5;aux1++){
        printf("Digite o tempo do corredor %i:\n",aux1+1);
        scanf("%f",&etapa2[aux1]);
        resultado[aux1]+=etapa2[aux1];
    
        if (resultado[aux1]<resultado[menorTempo]){
            menorTempo=aux1;
        }
    
    }
    printf("O vencedor da etapa foi o corredor %i com um tempo de: %.2f\n",menorTempo+1,resultado[menorTempo]);
    printf("------------ETAPA 3------------\n");
    for(int aux1=0;aux1<5;aux1++){
        printf("Digite o tempo do corredor %i:\n",aux1+1);
        scanf("%f",&etapa3[aux1]);
        resultado[aux1]+=etapa3[aux1];
    
     if (resultado[aux1]<resultado[menorTempo]){
            menorTempo=aux1;
        }
    }
        
        
    printf("O vencedor foi o corredor %i com um tempo de: %.2f",menorTempo+1,resultado[menorTempo]);
}