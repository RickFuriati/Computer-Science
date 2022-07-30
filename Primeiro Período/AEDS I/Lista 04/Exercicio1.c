  #include <stdio.h>
  /*Fazer uma função int par(int n) que recebe um número inteiro n e retorna o n-ésimo termo da sequência 2,4,6,8,10,12.... 
  Além disso, você deve fazer um procedimento exercicio01() para ler o valor de n e chamar a função desenvolvido nesta questão. */ 

  int par(int n){
  int termoN=0;
    for (int aux1=1;aux1<=n;aux1++){
      termoN+=2;
    }
    return termoN;
  }

  void exercicio01(void){
    int n,resultado;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);

    resultado=par(n);
    printf("O termo %i corresponde a '%i' na sequencia de numeros pares.",n,resultado);
  }

  int main(void) {
    exercicio01();
    return 0;
  }