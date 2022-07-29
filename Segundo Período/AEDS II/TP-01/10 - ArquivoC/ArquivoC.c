#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n=0;
    int posicao=0;
    float numero;
    scanf("%i",&n); //Lê o numero de linhas
    
    FILE *Arquivo; 
    Arquivo=fopen("Arquivo.txt","w+"); //Inicia o arquivo para leitura e escrita
    for(int aux=0;aux<n;aux++){
        scanf("%f",&numero); //Escaneia os numeros
        if(aux!=n-1){ //Caso nao seja a ultima linha, escrve o numero no arquivo e salta uma linha (com o '\n')
            fprintf(Arquivo,"%g\n",numero);
        }else{
        fprintf(Arquivo,"%g",numero); //Caso seja a ultima linha escreve o numero no arquivo e nao pula uma linha (envita erros na hora de ler ao contrario)
        }
    }
    fseek(Arquivo,0,SEEK_END); //Coloca o ponteiro do arquivo ao final do arquivo
    posicao=ftell(Arquivo); //Atribui a posição a uma variável para manipular os caracteres
    float numeroFinal; //Variável auxiliar para atribuir o numero lido no final
    for(;posicao>0;posicao--){ 
        if(fgetc(Arquivo)=='\n'){ //Começa a leitura de trás para frente procurando pelo '\n' (quebra de linha)
            fseek(Arquivo,posicao+2,SEEK_SET); //Soma 2 unidades no ponteiro do arquivo para "descer" uma linha e ler o numero imediatamente abaixo a partir do começo da linha
            fscanf(Arquivo,"%f",&numeroFinal); //Copia o numero para a variável auxiliar
            printf("%g\n",numeroFinal); //Printa o numero e salta uma linha no terminal/saída
        }else if(posicao==1){ //Quando chegar na ultima posição (primeira linha) não haverá '\n' acima da linha (por ser a primeira linha) 
            fseek(Arquivo,posicao-1,SEEK_SET);//Diminui uma posição do ponteiro e le o numero do começo da primeira linha (compensa pela falta de \n na linha inexistente acima)
            fscanf(Arquivo,"%f",&numeroFinal); //Copia o numero para variável auxiliar
            printf("%g\n",numeroFinal);// Printa o numero  
        }
        fseek(Arquivo,posicao,SEEK_SET); //Coloca o cursor na posição atribuída a variável 'posição' para dar continuidade na leitura a cada loop
    }
    fclose(Arquivo); //Fecha o arquivo
}