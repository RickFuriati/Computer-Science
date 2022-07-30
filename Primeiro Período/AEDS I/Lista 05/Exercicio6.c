#include <stdio.h>
//Fazer um método recursivo que calcule o MDC (máximo divisor comum) de dois inteiros positivos 'm' e 'n'

int MDC (int m,int n){
    if (n!=0){
        return MDC(n,m%n);
    }else{
        return m;
    }
}

int main (void){
    int m,n,resposta;
    printf("Digite o valor do primeiro numero ('m').\n");
    scanf("%i",&m);
    printf("Digite o valor do segundo numero ('n').\n");
    scanf("%i",&n);

    resposta=MDC(m,n);
    printf("O maximo divisor comum entre '%i' e '%i' corresponde a: %i ",m,n,resposta);
}