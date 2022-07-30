#include<stdio.h>
#include<math.h>
/*Fazer uma função que recebe um número inteiro n, um real x e retorna o produto dos n primeiros
termos da sequência acima. Utilize a função desenvolvida na questão acima. Além disso, você
deve fazer um procedimento exercicio07() para ler os valores de n e de x, e chamar a função
desenvolvida nesta questão. */

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

double FuncaoExercicio06 (int n, int x){ //Desenvolvida na questão 6
    float resultado=0;
    resultado=parSobreImpar(n)*pow(x,n);
    return resultado;
}

double FuncaoExercicio07 (int n, int x){
    float resultadoMulti=1;
    for (int aux1=1;aux1<=n;aux1++){
        resultadoMulti=resultadoMulti*FuncaoExercicio06(aux1,x);
    }
    return resultadoMulti;
}

void exercicio07 (){
    int n,x;
    float resultadoFinal;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    printf("Digite o valor de X.\n");
    scanf("%i",&x);
    resultadoFinal=FuncaoExercicio07(n,x);
    printf("O produto dos %i termos da sequencia corresponde a: %.3f",n,resultadoFinal);
}

int main(void){
    exercicio07();
}