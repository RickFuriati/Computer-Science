#include <stdio.h>
/*Fazer uma função double umSobreImpar(int n) que recebe um número inteiro n e retorna o n-ésimo termo da sequência 1/3,1/5,1/7,1/9,1/11 
.... Além disso, você deve fazer um procedimento exercicio03()para ler o valor de n e chamar a função desenvolvido nesta questão.*/

double umSobreImpar(int n){
  float denominador;
  float resp;
  denominador=1;
  for (int aux1=1;aux1<=n;aux1++){
    denominador+=2;
    printf("%.2f\n",1/denominador);
  }
  return denominador;
}

void exercicio03(void){
  int n, resultado;
  resultado=0;
  printf("Digite um numero inteiro");
  scanf("%i",&n);
  resultado=umSobreImpar(n);
  printf("O %i termo da sequencia corresponde a:1/%i",n,resultado);
}

int main(void) {
  exercicio03();
  return 0;
}