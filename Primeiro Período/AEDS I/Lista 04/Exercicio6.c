#include<stdio.h>
#include <math.h>
/* Fazer a função que recebe um número inteiro n, um número real x e retorna o n-ésimo termo
da sequência abaixo. Utilize a função desenvolvido na letra a da questão anterior. Além disso,
você deve fazer um procedimento exercicio06() para ler os valores de n e de x, e chamar a função
desenvolvido nesta questão.
2x/3 ,4x^2/5 ,6x^3/7,8x^4/9 ,10x^5/11 ...*/

int par(int n){ //Desenvolvida na questão 1
int termoN=0;
  for (int aux1=1;aux1<=n;aux1++){
    termoN+=2;
  }
  return termoN;
}
double parSobreImpar(int n){ 
    float numerador, denominador, resultado;
    numerador=par(n);
    denominador=numerador+1;
    resultado=numerador/denominador;
    return resultado;
}

double FuncaoExercicio06 (int n, int x){
    float resultado=0;
    resultado=parSobreImpar(n)*pow(x,n);
    return resultado;
}

void exercicio06(){
    int n,x;
    float resultadoFinal;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    printf("Digite o valor de X\n");
    scanf("%i",&x);
    resultadoFinal= FuncaoExercicio06(n,x);
    printf("O %i termo da sequencia corresponde a:%.3f",n,resultadoFinal);
}

int main (void){
    exercicio06();
}
