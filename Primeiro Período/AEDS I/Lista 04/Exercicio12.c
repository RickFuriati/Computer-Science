#include <stdio.h>

/*Fazer uma função que recebe um número inteiro n e imprima os n primeiros múltiplos de 5. Além
disso, você deve fazer um procedimento exercicio12() para chamar a função desenvolvido nesta
questão. */

int multiplos5 (int n){
    int i,resp;
    resp=0;
    i=1;
    while (i<=n){
        resp=resp+5;
        printf("%i\n",resp);
        ++i;
  }
  return resp;
}

void exercicio12(){
    int n;
    printf("Quantos multilpos de 5 voce gostaria de ver?");
    scanf("%i",&n);
    multiplos5(n);
}

int main (void){
    exercicio12();
}