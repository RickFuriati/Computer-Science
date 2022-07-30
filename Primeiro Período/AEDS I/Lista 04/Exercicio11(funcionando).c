#include<stdio.h>
#include<math.h>
/* Refazer a função da questão anterior, omitindo todos termos cujos valores no denominador sejam
múltiplos de 2. Além disso, você deve fazer um procedimento exercicio112() para chamar a função
desenvolvido nesta questão.*/

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
        float numerador, resultado;
        int denominador;
        numerador=par(n);
        denominador=numerador+1;
        if (denominador%2!=0){
        resultado=numerador/fatorial(denominador);
        return resultado;
        }else{}
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

void exercicio11(){
    int n,x;
    float resultadoFinal;
    printf("Digite um numero inteiro\n");
    scanf("%i",&n);
    printf("Digite o valor de X.\n");
    scanf("%i",&x);
    resultadoFinal=somatorioUmsobreFatorial(n,x);
    printf("A soma dos elementos menores que o elemento %i na sequencia corresponde a:: %.3f",n,resultadoFinal);
}

int main (void){
    exercicio11();
}
