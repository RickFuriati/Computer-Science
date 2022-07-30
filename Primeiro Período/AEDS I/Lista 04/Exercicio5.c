#include<stdio.h>
/*(a) Uma função double parSobreImpar(int n) que recebe um número inteiro n e retorna o n-
ésimo termo da sequência 2/3,4/5,6/7,8/9,10/11,.... A sua função deve utilizar os funçãos par e
umSobreImpar desenvolvidos anteriormente.
(b) Uma função double somaParSobreImpar(int n) que recebe um número inteiro n e retorna o
valor do somatório dos n primeiros termos da sequência anterior. A sua função somaParSo-
breImpar deve utilizar a função parSobreImpar.
(c) Um procedimento exercicio05() para ler o valor de n e chamar as funções desenvolvidas
nesta questão.*/

int par(int n){ //Desenvolvida na questão 1
int termoN=0;
  for (int aux1=1;aux1<=n;aux1++){
    termoN+=2;
  }
  return termoN;
}

double parSobreImpar(int n){ //Parte (a)
    float numerador, denominador, resultado;
    numerador=par(n);
    denominador=numerador+1;
    resultado=numerador/denominador;
    return resultado;
}

double somaParSobreImpar(int n){ //Parte (b)
    float resultadoSoma=0;
    for (int aux1=1;aux1<=n;aux1++){
        resultadoSoma=resultadoSoma+parSobreImpar(aux1);
        
    }
    return resultadoSoma;
}

void exercicio05(void){   //Parte (c)
    int nn;
    float resultado=0,resultadoSoma=0;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&nn);
    resultado=parSobreImpar(nn);
    resultadoSoma=somaParSobreImpar(nn);
    printf("O %i da sequencia de par sobre impar corresponde a: %.3f\n",nn,resultado);
    printf("A soma dos termos anteriores a %i na sequencia corresponde a: %.3f",nn,resultadoSoma);
}

int main (void){
    exercicio05();
}
