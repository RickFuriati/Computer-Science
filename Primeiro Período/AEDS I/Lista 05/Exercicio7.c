#include <stdio.h>
//Fazer um método recursivo que conte os dígitos de um determinado número.

int contadorDigitos(int n){
    int numDigitos=0;
    if (n>0){
        if (n/10==0){
            return numDigitos=1;
        }
    numDigitos= 1 + contadorDigitos(n/10);
    return numDigitos;
        }
        
}


int main(void){
    int n,resposta=0;
    printf("Digite um numero qualquer.\n");
    scanf("%i",&n);
    resposta=contadorDigitos(n);
    printf("O numero '%i' possui %i digitos.",n,resposta);
}