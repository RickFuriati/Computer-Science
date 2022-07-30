#include <stdio.h>
#include <string.h>
/*Suponha que temos dois arquivos cujo as linhas são ordenadas lexigraficamente. Por exemplo,
estes arquivos podem conter nomes de pessoas, linha a linha, em ordem alfabética. Escreva um
programa que receba, por linha de comando, os nomes destes dois arquivos e de um terceiro. Crie
este terceiro arquivo contendo todas as linhas destes dois arquivos ordenadas lexicograficamente.
2*/

int main (main){
    FILE *arquivo1;
    FILE *arquivo2;
    FILE *arquivo3;
    int aux1,aux2,linhas=1;
    arquivo1= fopen("arquivo1.txt","r");
    arquivo2= fopen("arquivo2.txt","r");
    arquivo3=fopen("ordemAlfabetica.txt","w");
    char i;
    char string1[20];
    char string2[20];
    char stringAux[20];
    
    while((i=fgetc(arquivo1))!=EOF){
        if(i=='\n'){
            linhas+=1;
        }
    }
    while((i=fgetc(arquivo2))!=EOF){
        if(i=='\n'){
            linhas+=1;
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);
    arquivo1= fopen("arquivo1.txt","r");
    arquivo2= fopen("arquivo2.txt","r");
    fgets(string1,20,arquivo1);
    fgets(string2,20,arquivo2);
    
    for(int j=linhas;j>0;j--){
        if(string1[0]<string2[0]){
            printf("%s",string1);
            fgets(string1,20,arquivo1);

        }
        else if(string1[0]>string2[0]){
            printf("%s",string2);
            fgets(string2,20,arquivo2);
        }
    }
    
     for (int aux=0;aux<10;aux++){
        printf("%i\n",aux);
    }
    
    
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
}