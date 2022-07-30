#include <stdio.h>
//Fazer um método recursivo que multiplique dois números naturais, através de somas sucessivas

int multi(int a, int b){
	int resultado=0;
	if (b>0){
	resultado= a+multi(a,b-1);
	}
    return resultado;
}

int main (void){
    int a=0,b=0,resp=0;
    printf("Digite o valor do primeiro numero a ser multiplicado.\n");
    scanf("%i",&a);
    printf("Digite o valor do segundo numero a ser multiplicado.\n");
    scanf("%i",&b);

    resp=multi(a,b);
    printf("O resultado da multiplicacao corresponde a: %i",resp);
}