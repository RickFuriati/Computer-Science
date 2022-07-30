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
    int aux1,aux2,linhas=0;
    int linha1=0,linha2=1;
    char nomeArquivo1[20];
    char nomeArquivo2[20];
    char nomeArquivoFinal[20];
    printf("Digite o nome do primeiro arquivo:\n");
    gets(nomeArquivo1);
    printf("Digite o nome do segundo arquivo:\n");
    gets(nomeArquivo2);
    printf("Digite o nome do arquivo resultante:\n");
    gets(nomeArquivoFinal);

    arquivo1= fopen(nomeArquivo1,"r");
    arquivo2= fopen(nomeArquivo2,"r");
    arquivo3=fopen(nomeArquivoFinal,"w");
    char i;
    char string1[20];
    char string2[20];
    char stringAux[20];

    while((i=fgetc(arquivo1))!=EOF){
        if(i=='\n'){
            linha1+=1;
        }
    }
    while((i=fgetc(arquivo2))!=EOF){
        if(i=='\n'){
            linha2+=1;
        }
    }
    linhas=linha1+linha2;
    printf("%i %i %i\n",linhas,linha1,linha2);
    fclose(arquivo1);
    fclose(arquivo2);
    arquivo1= fopen(nomeArquivo1,"r");
    arquivo2= fopen(nomeArquivo1,"r");
    fgets(string1,20,arquivo1);
    fgets(string2,20,arquivo2);
    
    char nomes[10];
    
    for(int j=0;j<linhas;j++){
       if(j<=linha1){
            if(string1[0]<string2[0]){
                fprintf(arquivo3,"%s",string1);
                fgets(string1,20,arquivo1);
            }
            else if(string1[0]>string2[0]){
                fprintf(arquivo3,"%s",string2);
                fgets(string2,20,arquivo2);
            }
        }else{
           fprintf(arquivo3,"%s",string1);
            fgets(string1,20,arquivo1);

        }
    }
    
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
}