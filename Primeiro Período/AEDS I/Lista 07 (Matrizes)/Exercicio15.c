#include<stdio.h>
#include<stdlib.h>

/*Criar um algoritmo que carregue uma matriz 12 x 4 com os valores das vendas de uma loja,
em que cada linha represente um mês do ano, e cada coluna, uma semana do mês. Para fins de
simplificação considere que cada mês possui somente 4 semanas. Calcule e imprima:
- Total vendido em cada mês do ano;
Total vendido no ano.
Qual a melhor semana para vender carros? 1ª, 2ª, 3ªou 4ª?*/

/*Crie duas matrizes 3x3. A primeira será digitada pelo usuário e a segunda deverá ser a primeira
rotacionada 90º. */

int random(int interval) //função para sortear numeros aleatórios em um intervalo (maior praticidade)
{
    return rand() % interval;
}
int minrand(int min, int max)
{
    return random(max - min) + min;
}

int main (void){
    srand(time(NULL));
    int vendas[12][4]; //mes corresponde ás linhas e semana ás colunas
    int vetorSemanas[4];
    int totalMes=0,totalAno=0;
    int melhorSemana=0;
    int somaSemana1=0,somaSemana2=0,somaSemana3=0,somaSemana4=0;
    printf("O vetor das vendas do ano corresponde a:\n");
    for (int mes=0;mes<12;mes++){
        for (int semana=0;semana<4;semana++){
            vendas[mes][semana]=minrand(0,10);
            printf("%i ",vendas[mes][semana]);
        }
        printf("\n");
    }
    for (int mes=0;mes<12;mes++){
        for (int semana=0;semana<4;semana++){
        totalMes+=vendas[mes][semana];
        totalAno+=totalMes;
            if(semana==3){
            printf("O total do mes %i corresponde a: %i\n",mes+1,totalMes);
            }
            if(semana==0){
                somaSemana1+=vendas[mes][0];
                vetorSemanas[0]=somaSemana1;
            }else if(semana==1){
                somaSemana2+=vendas[mes][1];
                vetorSemanas[1]=somaSemana2;
            }else if(semana==2){
                somaSemana3+=vendas[mes][2];
                vetorSemanas[2]=somaSemana3;
            }else if(semana==3){
                somaSemana4+=vendas[mes][3];
                vetorSemanas[3]=somaSemana4;
            }
        
            if (vetorSemanas[semana]>vetorSemanas[melhorSemana]){
                melhorSemana=semana;
            }
        }
        totalMes=0;
    }
    
    printf("\nO total de vendas do ano foi de: %i.\n",totalAno);
    printf("A melhor semana para se vender carros e a semana %i com um total de vendas de: %i\n",melhorSemana+1,vetorSemanas[melhorSemana]);
}