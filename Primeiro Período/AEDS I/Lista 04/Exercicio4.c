#include<stdio.h>
/*Fazer uma função double somaUmSobreImpar(int n) que recebe um número inteiro n e retorna o
valor do somatório dos n primeiros termos da sequência anterior. A sua função somaUmSobreIm-
par deve utilizar a função umSobreImpar desenvolvido na questão anterior. Além disso, você deve
fazer um procedimento exercicio04() para ler o valor de n e chamar a função desenvolvido nesta
questão.*/

double umSobreImpar(int n){
  float denominador,resultado;
  denominador=1;
  for (int aux1=1;aux1<=n;aux1++){
    denominador+=2;
  }
  return resultado=1/denominador;
}

double somaUmSobreImpar(int n){
    float soma;
    soma=0;
    for (int aux1=1;aux1<=n;aux1++){
        soma=soma+umSobreImpar(aux1);
    }
    return soma;
}

void exercicio04(void){
    int nn;
    float resultado=0;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&nn);
    resultado=somaUmSobreImpar(nn);
    printf("A soma dos %i elementos da sequencia de 1 sobre numeros impares corresponde a: %.5f",nn,resultado);
}


int main (void){
exercicio04();
}
