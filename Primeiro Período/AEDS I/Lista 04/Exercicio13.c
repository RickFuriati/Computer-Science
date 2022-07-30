#include<stdio.h>
/*Fazer uma função que recebe um número inteiro n e retorna o n-ésimo termo da sequência de
Fibonacci. Além disso, você deve fazer um procedimento exercicio13() para chamar a função
desenvolvido nesta questão. */

int termoNFibonacci(int N){
    int numero,aux1,aux2;
    aux1=0;
    aux2=1;
    for (int i=2;i<=N;i++){ //'i' começa com valor 2 tendo uma vez que os 2 primeiros termos da sequencia ja foram definidos (0,1)
    numero=aux1+aux2;
    aux1=aux2;
    aux2=numero;
    }
  return numero;
}

void exercicio13(){
    int N,resultado=0;
printf("Digite o numero do termo desejado:\n");
scanf("%i",&N);
resultado=termoNFibonacci(N);
printf("O %i termo da sequencia de fibonacci corresponde a: %i\n",N,resultado);
}

int main (void){
    exercicio13();
}