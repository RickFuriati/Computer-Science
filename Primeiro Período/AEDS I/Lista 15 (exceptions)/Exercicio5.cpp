#include <iostream>
#include <stdexcept>

/*Escreva um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C.
Em seguida, calcule e mostre a área do triângulo retângulo que tem A por base e C por altura.
Se não for possível formar um triangulo, favor levantar uma exceção.*/

using namespace std;

int main(void){
    double pontos[3];

    try{
        printf("Digite o valor do primeiro ponto (ponto A):\n");
        scanf("%lf",&pontos[0]);
        printf("Digite o valor do segundo ponto (ponto B):\n");
        scanf("%lf",&pontos[1]);
        printf("Digite o valor do terceiro ponto (ponto C):\n");
        scanf("%lf",&pontos[2]);

        if(pontos[0] + pontos[1] <= pontos[2] || pontos[0] + pontos[2] <= pontos[1] || pontos[1] + pontos[2] <= pontos[0]){
            throw invalid_argument("Os fornecidos nao podem formar um triangulo :(\n");
        }else{
             printf("\n Área do triângulo formado pelos pontos A=%.1lf B=%.1lf C=%.1lf corresponde a: %.2f\n",pontos[0],pontos[1],pontos[2],(pontos[0] * pontos[2]) / (double)2);
        } 
    }catch (invalid_argument x){
        printf("%s\n",x.what());
    }
}