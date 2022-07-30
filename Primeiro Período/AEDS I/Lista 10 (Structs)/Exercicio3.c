#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*Crie uma struct chamada ponto2d que tenha como atributos os pontos x,y e z. Crie duas estru-
turas do tipo ponto2d chamadas ponto_inicial e ponto_final. Faça um menu com as seguintes
opções e implemente-as:
1 Digitar o valor do primeiro ponto
2 Digitar os valores do segundo ponto
3 Mostrar a distância entre os pontos
4 Sair*/

typedef struct{
    float X;
    float Y
}ponto2d;

typedef struct{
    ponto2d;
}ponto_inicial;

typedef struct{
    ponto2d;
}ponto_final;

int main (void){
    ponto_inicial vetor[1];
    ponto_final vetor1[1];
    float distancia=0;
    printf("-------- Ponto Inicial -------- \n");
    printf("Digite a coordenada X do primeiro ponto:\n");
    scanf("%f",&vetor[1].X);
    printf("Digite a coordenada Y do primeiro ponto:\n");
    scanf("%f",&vetor[1].Y);

    printf("-------- Ponto Final -------- \n");
    printf("Digite a coordenada X do segundo ponto:\n");
    scanf("%f",&vetor1[1].X);
    printf("Digite a coordenada Y do segundo ponto:\n");
    scanf("%f",&vetor1[1].Y);

    distancia=sqrt(pow((vetor[1].X-vetor1[1].X),2)+(pow((vetor[1].Y-vetor1[1].Y),2)));
    printf("A distancia entre os dois pontos corresponde a: %.3f ",distancia);
}