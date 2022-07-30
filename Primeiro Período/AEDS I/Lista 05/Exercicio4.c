#include <stdio.h>
//Fazer um método recursivo que imprima de um número natural em base binária

int binario(int n){
    int resultado;
    if (n==0){
        return resultado=0;
    }else{
        resultado=n%2 + 10*binario(n/2);
        return resultado;
    }
}

int main(void){
    int n,resposta;
    printf("Digite um numero natural");
    scanf("%i",&n);
    resposta=binario(n);
    printf("O numero '%i' na base binaria corresponde a: %i",n,resposta);
}