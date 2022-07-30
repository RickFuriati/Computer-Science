#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Faça um programa que armazene em um registro de dados (estrutura composta) os dados de um
funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nasci-
mento, Codigo do Setor onde trabalha (0-99), Cargo que ocupa (string de até 30 caracteres) e
Salário. Os dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.*/

typedef struct{
    int dia;
    int mes;
    int ano;
}nascimento;

typedef struct{
    char nome[30];
    int idade;
    char sexo;
    int CPF;
    nascimento;
    int codigo_setor;
    char cargo[30];
    float salario;

}funcionario;

int main (void){
    funcionario vetor[1];
    
    printf("Digite o nome do Funcionario:\n");
    scanf("%[^\n]s",vetor[1].nome);
    printf("Digite a idade do Funcionario:\n");
    scanf("%i",&vetor[1].idade);
    printf("Digite o sexo do Funcionario: (M ou F)\n");
    scanf(" %c",&vetor[1].sexo);
    printf("Digite o CPF do Funcionario: (apenas numeros)\n");
    scanf("%i",&vetor[1].CPF);
    printf("Digite o ano do nascimento do Funcionario:\n");
    scanf("%i",&vetor[1].ano);
    printf("Digite o mes do nascimento do Funcionario:\n");
    scanf("%i",&vetor[1].mes);
    printf("Digite o dia do nascimento do Funcionario:\n");
    scanf("%i",&vetor[1].dia);
    printf("Digite o Codigo do setor do Funcionario: (0-99) \n");
    scanf("%i",&vetor[1].codigo_setor);
    printf("Digite o cargo do Funcionario:\n");
    scanf(" %[^\n]s",vetor[1].cargo);
    printf("Digite o Salario do Funcionario:\n");
    scanf("%f",&vetor[1].salario);

    printf("\n\n ------------ Funcionario '%s' ------------\n",vetor[1].nome);
    printf("Idade: %i\n",vetor[1].idade);
    printf("Sexo: %c\n",vetor[1].sexo);
    printf("CPF: %i\n",vetor[1].CPF);
    printf("Data de Nascimento: %i/%i/%i\n",vetor[1].dia,vetor[1].mes,vetor[1].ano);
    printf("Codigo do Setor:%i \n",vetor[1].codigo_setor);
    printf("Cargo: %s\n",vetor[1].cargo);
    printf("Salario: %.3f",vetor[1].salario);



}