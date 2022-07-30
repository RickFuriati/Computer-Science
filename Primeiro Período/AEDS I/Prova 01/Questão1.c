#include<stdio.h>
/*Criar um algoritmo que leia os limites inferior e superior de um intervalo e imprima todos os números pares no intervalo aberto e seu somatório. 
Suponha que os dados digitados são para um intervalo crescente, ou seja, o primeiro valor é menor que o segundo.*/

int main (void){
    int maiorNumero,menorNumero,somatorio=0,numeroAtual;

    printf("Digite o menor numero desejado (limite inferior do intervalo).\n");
    scanf("%i",&menorNumero);
    printf("Digite o maior numero desejado (limite superior do intervalo).\n");
    scanf("%i",&maiorNumero);
    
    if((menorNumero%2!=0)||(menorNumero==1)){ //Confere se o menor numero é impar, caso seja ele soma 1 para que a sequência comece pelo par imediatamente depois do numero(menorNumero)
        menorNumero++;
    }
    numeroAtual=menorNumero;

    for (numeroAtual;numeroAtual<=maiorNumero;numeroAtual+=2){ //Realiza as somas e as iterações do par já na estrtura do for
            somatorio+=numeroAtual;
            printf("%i\n",numeroAtual);
        }
    
    printf("O somatorio dos numeros pares do intervalor corresponde a: %i",somatorio);
}

