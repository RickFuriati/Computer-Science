#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isFim(const char *s){
                                                                                                 
if(strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
        return true;
    }
    return false;
}
        

bool isPalindromo (const char *s,int i){//Recebe uma string e uma posição 
    bool resultado=false;
    if(i==strlen(s)){ //Se a posição for igual ao tamanho a string é um palindromo
        resultado=true;
    }else if(s[i]!=s[strlen(s)-i-1]){//Caso a letra da posição 'i' seja diferente da sua correspondente a partir do final do vetor a string nao é um palindromo
        resultado=false;
    }else{
        resultado=isPalindromo(s,i+1);//CHama a função novamente mas com a proxima posição (recursividade)
    }
    return resultado;
}


int main (){
    char entrada[10000];
    scanf(" %[^\n]", entrada);
    while(true){
        if(isPalindromo(entrada,0)==true){
               printf("SIM\n");
            }else if(isPalindromo(entrada,0)==false){ //Segunda expressão foi necessária para que quando o usuário digite "FIM" a resposta nao seja exibida na tela 
                if(isFim(entrada)==true){
                    break;
                }
            printf("NAO\n");
        }
        scanf(" %[^\n]", entrada);
    }
}