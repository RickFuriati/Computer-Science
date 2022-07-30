#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até
10 pessoas. Cada pessoa deve ser representada por uma struct dentro de um vetor. A data
de nascimento também deve ser uma struct. O nome e a altura de cada pessoa devem ser
informados pelo teclado. A geração da data de nascimento deve ser feita aleatoriamente através
de uma função.*/

int random(int interval)
{
    return rand() % interval;
}

int minrand(int min, int max)
{
    return random(max - min) + min;
}

typedef struct{ 
    int dia,mes,ano;
}data;

void randNascimento(data *nascimento){
    nascimento -> dia=minrand(1,31);
    nascimento -> mes=minrand(1,12);
    nascimento -> ano=minrand(1950,2020);
}


typedef struct {
    char nome[20];
    float altura;
    data nascimento;
}pessoas;


int main (void){
    srand(time(NULL));
    pessoas vetor[10];
    

    for (int aux=0;aux<10;aux++){
        printf("---------- Pessoa %i ---------- \n",aux+1);
        printf("Digite o nome da pessoa:\n");
        scanf(" %[^\n]",&vetor[aux].nome);
        printf("Digite a altura da pessoa:\n");
        scanf("%f",&vetor[aux].altura);
        randNascimento(&vetor[aux].nascimento);
        printf("A data de nascimento do(a) %s gerada aleatoriamente corresponde a: %02i/%02i/%04i \n",vetor[aux].nome,vetor[aux].nascimento.dia,vetor[aux].nascimento.mes,vetor[aux].nascimento.ano);
    }
}