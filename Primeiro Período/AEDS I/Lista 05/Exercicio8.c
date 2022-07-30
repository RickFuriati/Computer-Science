#include <stdio.h>
#include <stdbool.h>
//Fazer um método recursivo que determine se um número é ou não primo.

bool primo(int n,int base){
    if (n%base==0){
        return false;
    }else if (base > n/2){
        return true;
    }else 
        return primo(n, base+1);
}

    

    
int main (void){
    int n, resp;
    printf("Digite um numero inteiro.\n");
    scanf("%i",&n);
    resp=primo(n,2);
   
    if(resp==true){
        printf("O numero '%i' e um numero primo.",n);
    }else if (resp==false){
     printf("O numero '%i' nao e um numero primo.",n);
    }
}