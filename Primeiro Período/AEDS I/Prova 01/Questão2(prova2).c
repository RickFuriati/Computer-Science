#include <stdio.h>

/*Escreva um programa que declare vetor de caracteres com 26 posições. Você criar uma função void (procedimento) 
para inicializar o vetor com as letras do alfabeto usando ponteiros. Faça outra função void para exibir os elementos do vetor.*/

void procecimentoQuestao2(){
    char vetorAlfabeto[26];
    int alfabeto=97;
    for (int aux=0;aux<=26;aux++){
        *(vetorAlfabeto+aux)==alfabeto;
        ++alfabeto;
    }
}
void exibeAlfabeto(char *vetorAlfabeto){
    printf("O vetor com as letras do alfabeto usando ponteiros corresponde a:\n");
    for (int aux=1;aux<=26;aux++){
    printf("%c - ",*vetorAlfabeto+aux);
    }
}


int main (void){
    char vetorAlfabeto[26];
    procecimentoQuestao2();
    exibeAlfabeto(&vetorAlfabeto);
}