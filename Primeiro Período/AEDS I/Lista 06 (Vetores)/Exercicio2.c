#include<stdio.h>
/*Anteriormente fizemos a série de fibonacci. Faça o mesmo exercício novamente, porém, utilizando vetores. 
O tamanho da série será dada pelo usuário. */

int main(void){
    int tamanho,aux1=0,aux2=1,numero;
    
    printf("Digite o tamanho da sequencia de fibonacci.\n");
    scanf("%i",&tamanho);

    int fibonacci[tamanho];
    fibonacci[0]=aux1;
    printf("%i\n",fibonacci[0]);
    fibonacci[1]=aux2;
    printf("%i\n",fibonacci[1]);
    for (int aux=2;aux<tamanho;aux++){
        numero=aux1+aux2;
        fibonacci[aux]=numero;
        printf("%i\n",fibonacci[aux]);
        aux1=aux2;
        aux2=numero;
    }
}