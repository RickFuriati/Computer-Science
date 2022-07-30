#include<stdio.h>

/*Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e
troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo
e, após a execução da função, A conterá o valor de B e B terá o valor de A.*/

void trocaValor (int *a, int *b){
    int aux=0;
    aux=*a;
    printf("%i\n",aux);
    *a=*b;
    printf("%i\n",a);
    *b=aux;
    printf("%i\n",b);
}


int main (void){
    int var1,var2;
    printf("Digite um numero inteiro:\n");
    scanf("%i",&var1);
    printf("Digite outro numero inteiro:\n");
    scanf("%i",&var2);

    printf("Variaveis correspondem a: variavel 1 = %i e variavel 2 = %i.\n",var1,var2);
    trocaValor(&var1,&var2);
    printf("Variaveis com valor trocado correspondem a: variavel 1 = %i e variavel 2 = %i.\n",var1,var2);
}