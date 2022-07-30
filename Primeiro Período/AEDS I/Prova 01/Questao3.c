#include<stdio.h>
/*Escreva uma função RECURSIVA, int SomaSerie(int i, int j, int k), 
que imprime na tela a soma de valores do intervalo [ i , j ], com incremento k.*/

int somaSerie(int i, int j, int k){
  int soma=0;
  if (i>=j){ //condição de parada
   return j;
    
  }else{
  soma=i+somaSerie(i+k,j,k); //começa com o valor de i e soma usando a função porém a variavel 'i' passa a ter o valor de i+k (faz o incremento)
    printf("%i\n",soma);
  return soma; 
  } 
}

int main (void){
int i,j,k,resposta;
printf("Digite o valor do primeiro numero da serie (i).\n");
scanf("%i",&i);
printf("Digite o valor do ultimo numero da serie (j).\n");
scanf("%i",&j);
printf("Digite o valor do incremento (k).\n");
scanf("%i",&k);

resposta=somaSerie(i,j,k);
printf("A soma dos elementos da serie (%i - %i) com incremento %i corresponde a: %i",i,j,k,resposta);
}