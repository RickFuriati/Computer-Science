#include <stdio.h>
/*Fazer um método recursivo que recebe um número inteiro e positivo n e calcula o somatório
abaixo.
n + (n −1) + ... + 1 + 0 */

int sequenciaSoma (int n){
    int resultado=0;
    if (n>0){
        resultado=n+sequenciaSoma(n-1);
        return resultado;
    }
        return resultado;
}

int main (void){
    int n, resposta;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    resposta=sequenciaSoma(n);
    printf("A soma de %i e todos os seus antecessores corresponde a: %i",n,resposta);
}