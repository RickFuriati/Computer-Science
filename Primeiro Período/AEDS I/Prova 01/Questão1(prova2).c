#include <stdio.h>

/*Considere uma estrutura de conta corrente contendo o nome do titular, o CPF e o valor na conta 
(O nome e o cpf devem ser ponteiros para char). Escreva uma função que receba dois ponteiros e um valor e realize uma transferência entre as 
duas contas. 
Faça um teste cadastrando 2 contas e fazendo uma transferência.*/

typedef struct{
    char *nome[30];
    char *CPF[11];
    float valor;
}conta_corrente;

float transferencia(conta_corrente *conta1,conta_corrente *conta2, float valor){
    int resposta;
    printf("----------Tipo de transferencia:----------\n");
    printf("Digite 1 para transferir da primeira conta para segunda.\n");
    printf("Digite 2 para transferir da segunda conta para primeira.\n");
    scanf("%i",&resposta);
    if (resposta==1){
        conta1->valor=conta1->valor-valor;
        conta2->valor=conta2->valor+valor;
    }else if(resposta==2){
        conta1->valor=conta1->valor+valor;
        conta2->valor=conta2->valor-valor;
    }
    

    
}   


int main (void){
    conta_corrente vetor[2];
    float valor_transferencia;
    int resposta;
    for(int aux=0;aux<2;aux++){
        printf("---------- Pessoa %i ---------- \n",aux+1);
        printf("Digite o nome da pessoa:\n");
        scanf(" %[^\n]s",vetor[aux].nome);
        printf("Digite o CPF da pessoa:\n");
        scanf(" %[^\n]s",vetor[aux].CPF);
        printf("Digite o valor na conta da pessoa:\n");
        scanf("%f",&vetor[aux].valor);
    }
    printf("Digite o valor a ser transferido:\n");
    scanf("%f",&valor_transferencia);

    transferencia(&vetor[0],&vetor[1],valor_transferencia);

    printf("O novo balanco das contas corresponde a:\n");
    printf("----------Conta 1 ----------\n");
    printf("Nome: %s\n",vetor[0].nome);
    printf("CPF:%s\n",vetor[0].CPF);
    printf("Saldo: %.3f\n",vetor[0].valor);
    printf("----------Conta 2 ----------\n");
    printf("Nome: %s\n",vetor[1].nome);
    printf("CPF:%s\n",vetor[1].CPF);
    printf("Saldo: %.3f\n",vetor[1].valor);
}