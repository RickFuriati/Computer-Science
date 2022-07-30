#include <stdio.h>
/*Fazer uma função void mostrarParesEmOrdemDecrescente(int n) que recebe um número inteiro n e mostra na tela (em ordem decrescente)
 todos os valores menores do que n para a sequência do exercício anterior. A sua função mostrarParesEmOrdemDecrescente deve utilizar 
 a função par desenvolvido na questão anterior. Além disso, você deve fazer um procedimento exercicio02() para ler o valor de n e 
 chamar a função desenvolvido nesta questão.*/

int par(int n){
int termoN=0;
  for (int aux1=1;aux1<=n;aux1++){
    termoN+=2;
  }
  return termoN;
}

int mostrarParesEmOrdemDecrescente(int N){
    int resultado,n;
    n=N;
    for(int aux2=1;aux2<=N;aux2++){
      resultado=par(n);
      if (resultado<N){
      printf("%i\n",resultado);
      }
      n-=1;
    }
    return resultado;
  }

  void exercicio02(void){
    int resultado, N;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&N);
    mostrarParesEmOrdemDecrescente(N);
  }


int main(void) {
  exercicio02();
  return 0;
}