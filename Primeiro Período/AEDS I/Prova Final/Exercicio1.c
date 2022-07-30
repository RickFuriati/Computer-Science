#include <stdio.h>

/*Criar um programa de votação onde o usuário deverá escolher entre o candidato 1, 2, 3 ou candidato 4. 
Registre apenas os votos válidos, ou seja, 1, 2, 3 ou 4. O programa deverá salvar as respostas em um arquivo texto. 
Salvar cada voto e não o somatório. O programa deverá receber valores até o usuário entrar com o valor -1.*/

int main(void){
    int resposta;
    FILE *arquivo1;
    arquivo1=fopen("arquivo1.txt","w");
    printf("Entre valores inteiros de 1 a 4.\n");
    printf("Digite -1 para encerrar a votacao.\n");
    while (resposta!=-1){
        printf("Em qual candidato gostaria de votar?\n");
        scanf("%i",&resposta);
        if(resposta==1||resposta==2||resposta==3||resposta==4){
            fprintf(arquivo1,"%i\n",resposta);
        }
    }
    printf("Fim da Votacao :)");
    fclose(arquivo1);
}