#include<stdio.h>
//Fazer um método recursivo que recebe um número inteiro e retorna o seu fatorial

int fatorial (int n){
    int resultado=1;
    if (n>0){
    resultado= n* fatorial(n-1);
    return resultado;
   }
   return resultado;
}

int main(void){
    int n,resp;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    resp=fatorial(n);
    printf("O fatorial de %i corresponde a: %i",n,resp);
    }
