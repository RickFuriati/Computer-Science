#include<stdio.h>
/* Fazer uma função que recebe um número inteiro n e retorna o maior elemento da sequência de
Fibonacci que seja menor que n. Além disso, você deve fazer um procedimento exercicio14()
para chamar a função desenvolvido nesta questão.*/

int fibonacciMenorqueN (int N){
    int numero,aux1,aux2;
    aux1=0;
    aux2=1;
    numero=0;

    for (int i=1;numero<N;i++){
        numero=aux1+aux2;
        aux1=aux2;
        aux2=numero;
    }
    return aux1; //Retorna aux1 por ser a ultima variável que possui um valor da sequencia menor que o valor desejado 
                //Isso ocorre por que a variável 'numero' é atualizada no começo da estrutura de repetição
}


void exercicio14(){
    int N,resultado;
    printf("Digite o numero desejado:\n");
    scanf("%i",&N);
    resultado=fibonacciMenorqueN(N);
    printf("O maior elemento da serie de Fibonacci menor que %i corresponde a: %i\n",N,resultado);
}   

int main (void){
    exercicio14();
}