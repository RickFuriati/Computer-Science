#include <stdio.h>
#include <math.h>
/*Fazer um método recursivo que recebe um número inteiro n e retorna o n-ésimo termo da equação
de recorrência abaixo:
T (1) = 2
T (2) = 3
T (n) = 5 ∗n + T (n −1)n */

int T (int n){
    int resposta=1;
    if (n==1){
    return resposta=2;
    } else if (n==2){
        return resposta=3;
    }else{
        if (n>0){
        resposta=(5*n)+pow(T(n-1),n);
        return resposta;
    }
}
    return resposta;
}

int main(void){
    int n,resp=0;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    resp=T(n);
    printf("O %i termo da sequencia corresponde a: %i",n,resp);
}
