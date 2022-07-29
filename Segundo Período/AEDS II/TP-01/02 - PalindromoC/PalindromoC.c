#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isFim(const char *s){
                                                                                                 
if(strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
        return true;
    }
    return false;
}
        
    

bool isPalindromo (char *s){
    int contador=0;
    bool resultado=false;
    for(int aux=0;aux<strlen(s);aux++){
        if(s[aux]==s[strlen(s)-aux-1]){
            contador++;
        }
    }
    if(contador==strlen(s)){
        resultado=true;
    }
    return resultado;
}


int main (){
    char entrada[1000];
    while (isFim(entrada)==false){
         scanf(" %[^\n]", entrada);
        if(isPalindromo(entrada)==true){
               printf("SIM\n");
            }else if(isPalindromo(entrada)==false){ //Segunda expressão foi necessária para que quando o usuário digite "FIM" a resposta nao seja exibida na tela 
                if(isFim(entrada)==true){
                    break;
                }
            printf("NAO\n");
        }
    }
}