#include <stdio.h>
/* Fazer uma função que recebe um número inteiro n e retorna o seu fatorial1. Além disso, você deve 
fazer um procedimento exercicio08() para ler o valor de n e chamar a função desenvolvido nesta questão.*/

double fatorial (int n){
    float fatorial=1,auxiliar;
    auxiliar=n;
    for (int aux1=1;aux1<=n;aux1++){
        fatorial=fatorial*auxiliar;
        auxiliar--;
    } 
    return fatorial;
}

void exercicio08(){
    int n;
    float resultado;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    resultado=fatorial(n);
    printf("O fatorial do numero %i corresponde a: %.2f",n,resultado);
}

int main (void){
    exercicio08();
}
