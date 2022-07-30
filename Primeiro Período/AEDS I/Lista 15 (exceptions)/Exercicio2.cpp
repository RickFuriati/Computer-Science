#include <iostream>
#include <math.h>
#include <stdexcept>

/*Num programa que lê um valor inteiro, faça a sua validação através do tratamento de uma
exceção. Caso não seja inteiro continuar pedindo a introdução do valor inteiro.*/

using namespace std;

int main(void){
    while(1){
        try{
            float valor;
            printf("Digite um valor qualquer:\n");
            scanf("%f",&valor);

            if(valor != (int) valor){
                throw invalid_argument("O numero fornecido nao eh inteiro :(\n");
            }else{
                printf("O numero fornecido eh inteiro :)\n");
            }
        }
            catch (invalid_argument x){
                printf("%s\n",x.what());
            }
        
    }
    
}