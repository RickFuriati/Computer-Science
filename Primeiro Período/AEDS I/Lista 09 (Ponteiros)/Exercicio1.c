#include <stdio.h>

/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real,
e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando
os ponteiros. Imprima os valores das variáveis antes e após a modificação.*/

int main (void){
    int inteiro=1;
    float real=2;
    char caracter='a';  
    int *ptrInt,*ptrChar,*ptrReal;

    ptrInt=&inteiro;
    ptrChar=&caracter;
    ptrReal=&real;

    printf("O valor do inteiro corresponde a: '%i' do real a: '%.1f' e do char '%c'.",inteiro,real,caracter);
    *ptrInt=inteiro+1;
    *ptrChar=caracter+1.0;
    *ptrReal=real+1;

    printf("\nO valor modificado (somando 1) do inteiro corresponde a: '%i' do real a: '%.1f' e do char '%c'.",inteiro,real,caracter);
}