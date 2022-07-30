#include <stdio.h>

/*Receba números digitados pelo usuários e armazene em um vetor de tamanho 10. Caso ele digiteum número negativo, peça para digitar novamente.
 Ao final diga a quantidade de números parese a quantidade de números ímpares.*/

 int main (void){
     int par=0,impar=0,numero;
     int vetor[10];

     for (int aux1=0;aux1<10;aux1++){
        printf("Digite um numero para o vetor.\n");
        scanf("%i",&numero);
        while (numero<0){
            printf("Digite o numero novamente.\n");
            scanf("%i",&numero);
        }
        vetor[aux1]=numero;
        if (numero%2==0){
            par++;
        }else{
            impar++;}
    }

    printf("A quantidade de numeros pares corresponde a:%i\n",par);
    printf("A quantidade de numeros impares corresponde a:%i\n",impar);
 }