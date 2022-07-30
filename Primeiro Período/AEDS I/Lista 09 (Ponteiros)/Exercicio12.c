#include<stdio.h>
#include <string.h>
#include <stdbool.h>

/*Elabore uma função que receba duas strings como parâmetros e verifique se a segunda string
ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres das strings.*/

bool contemString(char *string1, char *string2){
    int tamanho1=strlen(string1);
    int tamanho2=strlen(string2);
    int acertos=0;
    
    for (int aux=0;aux<tamanho1;aux++){
        if (*(string1+aux)==*string2){
            
            for (int aux1=0, aux2=aux;aux1<tamanho2;aux1++,aux2++){
                if (*(string1+aux2)==*(string2+aux1)) {
                   acertos++;
                }else{
                    return false;
                }
            }
            
        }
    }
     if (acertos==tamanho2){
        return true;
    }
}

int main (void){
    char string1[200];
    char string2[200];
    bool resultado;
    printf("Digite a string 1:\n");
    gets(string1);
    printf("Digite a string 2:\n");
    gets( string2);
    resultado=contemString(&string1,&string2);
    if (resultado==true){
        printf("A segunda string esta contida na primeira.\n");
    }else{
        printf("A segunda string nao esta contida na primeira.\n");
    }
    
}