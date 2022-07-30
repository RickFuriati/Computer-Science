#include<stdio.h>
#include<math.h>
/*Fazer uma função que recebe um número inteiro n, um número real x e retorna o somatório dos
n primeiros termos da sequência mostrada na questão anterior. Além disso, você deve fazer um
procedimento exercicioXX() para chamar a função desenvolvido nesta questão*/

double fatorial (int n){ //Desenvolvida na questão 8
    float fatorial=1,auxiliar;
    auxiliar=n;
    for (int aux1=1;aux1<=n;aux1++){
        fatorial=fatorial*auxiliar;
        auxiliar--;
    } 
    return fatorial;
}

int par(int n){ //Desenvolvida na questão 1
int termoN=0;
  for (int aux1=1;aux1<=n;aux1++){
    termoN+=2;
  }
  return termoN;
}

double parSobreImpar(int n){ //Desenvolvida na questão 6
        float numerador, denominador, resultado;
        numerador=par(n);
        denominador=numerador+1;
        resultado=numerador/fatorial(denominador);
        return resultado;
    }
    
double FuncaoExercicio06 (int n, int x){ //Desenvolvida na questão 6
        float resultado=0;
        resultado=parSobreImpar(n)*pow(x,n);
        return resultado;
}

double funcaoExercicio9 (int n, int x){ //Desenvolvida na questao 9
    float resultatoFinal;
        resultatoFinal=FuncaoExercicio06(n,x);
    return resultatoFinal;
}

double somatorioUmsobreFatorial (int n, int x){
    float resultado;
    for (int aux1=1;aux1<=n;aux1++){
        resultado=resultado+funcaoExercicio9(aux1,x);
    }
    return resultado;
}

void exercicio10(){
    int n,x;
    float resultadoFinal;
    printf("Digite um numero inteiro\n");
    scanf("%i",&n);
    printf("Digite o valor de X.\n");
    scanf("%i",&x);
    resultadoFinal=somatorioUmsobreFatorial(n,x);
    printf("A soma dos  %i elementos na sequencia corresponde a: %.3f",n,resultadoFinal);
}

int main (void){
    exercicio10();
}

