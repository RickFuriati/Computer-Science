#include<stdio.h>
#include<string.h>

/*Ler o nome e o valor de uma determinada mercadoria de uma loja. Sabendo que o desconto para
pagamento a vista ‘ e de 10% sobre o valor total, calcular o valor a será pago a vista. Escrever
o nome da mercadoria, o valor total, o valor do desconto e o valor a ser pago a vista.*/

int main (void){
    char mercadoria[200];
    float valor=0;

    printf("Digite o nome da marcadoria:\n");
    gets(mercadoria);
    printf("Digite o valor da mercadoria:\n");
    scanf("%f",&valor);

    printf("--------- %s --------- \n ",mercadoria);
    printf("O valor total da mercadoria corresponde a: RS %.2f\n",valor);
    printf("O valor a vista corresponde a: RS %.2f.\n",valor*0.9);
    printf("O valor do desconto corresponde a: RS %.2f\n",valor*0.1);
}