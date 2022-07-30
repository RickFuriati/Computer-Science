#include<stdio.h>
/*A CEF concederá um crédito especial com juros de 2% aos seus clientes de acordo com o saldo médio no último ano. 
Fazer um algoritmo em que leia o saldo médio de um cliente e calcule o valor do crédito de acordo com a tabela a seguir.
 Imprimir uma mensagem informando o saldo médio e o valor de crédito.*/

 int main (void){
    float saldoMedio=0,valorCredito=0,juros=0;
    printf("Digite o seu saldo medio no ultimo ano.\n");
    scanf("%f",&saldoMedio);

    if ((saldoMedio<=500)&&(saldoMedio>0)){
        printf("Saldo medio de: %.2f, a CEF nao concede credito para este saldo.\n",saldoMedio);
    
    }else if ((saldoMedio>=501)&&(saldoMedio<=1000)){
        valorCredito=0.3*saldoMedio; //calcula o valor do credito
        printf("Com o saldo medio de: %.2f a CEF concede um credito de %.2f.\n",saldoMedio,valorCredito);
        juros=(0.02*valorCredito)+valorCredito; //calcula o valor do juros de 2%
        printf("Com o juros de 2 por cento o valor do credito corresponde a: %.2f.",juros);
    
    }else if ((saldoMedio>=1001)&&(saldoMedio<=3000)){
        valorCredito=0.4*saldoMedio; //calcula o valor do credito
        printf("Com o saldo medio de: %.2f a CEF concede um credito de %.2f.\n",saldoMedio,valorCredito);
        juros=(0.02*valorCredito)+valorCredito; //calcula o valor do juros de 2%
        printf("Com o juros de 2 por cento o valor do credito corresponde a: %.2f.",juros);
   
    }else if (saldoMedio>=3001){
        valorCredito=0.5*saldoMedio; //calcula o valor do credito
        printf("Com o saldo medio de: %.2f a CEF concede um credito de %.2f.\n",saldoMedio,valorCredito);
        juros=(0.02*valorCredito)+valorCredito; //calcula o valor do juros de 2%
        printf("Com o juros de 2 por cento o valor do credito corresponde a: %.2f.",juros);
    }
   
 }