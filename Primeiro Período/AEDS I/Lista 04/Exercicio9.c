#include<stdio.h>
#include<math.h>

/* Fazer uma função que recebe um número inteiro n, um número real x e retorna o n-ésimo termo
da sequência abaixo. Utilize os funçãos desenvolvidos anteriormente. Além disso, você deve
fazer um procedimento exercicio09() para ler o valor de n e chamar a função desenvolvido nesta
questão.
2x/3!,4x^2/5!,6x^3/7!,8x^4/9! ,10x^5/11! ... */

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

double funcaoExercicio9 (int n, int x){
    float resultatoFinal;
        resultatoFinal=FuncaoExercicio06(n,x);
        printf("%f\n",resultatoFinal);
    return resultatoFinal;
}

void exercicio09(){
    int n,x;
    float resultadoFinal;
    printf("Digite um numero inteiro\n");
    scanf("%i",&n);
    printf("Digite o valor de X.\n");
    scanf("%i",&x);
    resultadoFinal=funcaoExercicio9(n,x);
    printf("O termo %i da sequencia par sobre fatorial impar corresponde a: %.2f",n,resultadoFinal);
}

int main (void){
    exercicio09();
}


