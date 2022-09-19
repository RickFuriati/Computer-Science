#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>



typedef struct {
    char nome[1000];
    char tituloOriginal[1000];
    char dataLancamento[1000];
    int duracao;
    char genero[1000];
    char idiomaOriginal[1000];
    char situacao[1000];
    float orcamento;
    char palavrasChave[10000][100];
    int numeroPalavras;

}Filme;

Filme filmeClone(Filme *filme){
    Filme filmeClone;
    strcpy(filmeClone.nome , filme->nome);
    strcpy(filmeClone.tituloOriginal,filme->tituloOriginal);
    strcpy(filmeClone.dataLancamento,filme->dataLancamento);
    filmeClone.duracao=filme->duracao;
    strcpy(filmeClone.genero,filme->genero);
    strcpy(filmeClone.situacao,filme->situacao);
    filmeClone.orcamento=filme->orcamento;

    return filmeClone;
}

char* removeLeadingSpaces(char* str){
    static char str1[100];
    int count = 0, j, k;
    while (str[count] == ' ') {
        count++;
    }
    for (j = count, k = 0;
         str[j] != '\0'; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';
    return str1;
}


char *tiraTags(char *html, char *texto) {
    char *start = texto;
    int contagem = 0;
    while (*html != '\0') {
        if (*html == '<') {
            if (
                (*(html + 1) == 'p') || 
                (*(html + 1) == 'b' && *(html + 2) == 'r') || 
                (*(html + 1) == '/' && *(html + 2) == 'h' && *(html + 3) == '1') || 
                (*(html + 1) == '/' && *(html + 2) == 't' && *(html + 3) == 'h') || 
                (*(html + 1) == '/' && *(html + 2) == 't' && *(html + 3) == 'd')    
            ) break;
            else contagem++;
        }
        else if (*html == '>') contagem--;
        else if (contagem == 0 && *html != '"') {
            if (*html == '&') html = strchr(html, ';');
            else if (*html != '\r' && *html != '\n') *texto++ = *html;
        }
        html++;
    }
    *texto = '\0';
    return *start == ' ' ? start + 1 : start;
}

char* substr(const char *src, int m, int n){
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}
void removeChar(char * str, char charToRemmove) {
    
    int i, j;
    int len = strlen(str);
    for(i=0; i<len; i++) {

        if(str[i] == charToRemmove) {

            for(j=i; j<len; j++) {

                str[j] = str[j+1];
            }

            len--;
            i--;
        }
    }
}
void imprimir(Filme *filme){
    //printf("%s\n",contaPalavras);
    printf("%s",filme->nome);
    printf("%s",filme->tituloOriginal);
    printf(" %s",filme->dataLancamento);
    printf("%i",filme->duracao);
    printf(" %s",filme->genero);
    printf(" %s",filme->idiomaOriginal);
    printf(" %s",filme->situacao);
    printf(" %g",filme->orcamento);
    
    printf(" [");
    for(int aux=1;aux<=filme->numeroPalavras;aux++){
        strcpy(filme->palavrasChave[aux],removeLeadingSpaces(filme->palavrasChave[aux]));
        if(aux==1){
            printf("%s",removeLeadingSpaces(filme->palavrasChave[aux]));
        }else{
             printf(", %s",filme->palavrasChave[aux]);
        }

    }
    printf("]\n");
}

void ler(char *nomeArquivo,Filme *novoFilme){
    FILE *arquivo;
    char *linha=NULL;
    size_t tamanho=0;
    ssize_t read;
    char stringAux[10000];
    char pasta[100];
    strcpy(pasta,"/tmp/filmes/");
    strcat(pasta,nomeArquivo);
    char nome[1000];
    //strcpy(pasta,strcat("/tmp/filmes/",nomeArquivo));
    
 
  
    strcpy(novoFilme->tituloOriginal,"bug");

    arquivo=fopen(pasta,"r");

    if(arquivo==NULL){
        printf("ERRO!");
        exit(EXIT_FAILURE);
    }
    
    while((read=getline(&linha,&tamanho,arquivo))!=-1){
        //Busca pelo Nome
        if (strstr(linha,"<title>")!=NULL){
           stringAux[0]='\0';
            strcpy(stringAux,removeLeadingSpaces(linha));
            strcpy(stringAux,strtok(stringAux,"(")+7);
            //strcpy(nome,stringAux);
            strcpy(nome,stringAux);
            strcpy(novoFilme->nome,nome);
            
            //printf("%s\n",novoFilme.nome);
        }
        //Busca pelo Titulo Original
        if (strstr(linha,"<p class=\"wrap\">")!=NULL){
           stringAux[0]='\0';
            strcpy(stringAux,removeLeadingSpaces(linha));
            strcpy(stringAux,(strtok(stringAux,"</p")+48));
            strcpy(stringAux,strtok(stringAux,"</"));
            //strcpy(tituloOriginal,stringAux);
            strcpy(novoFilme->tituloOriginal,stringAux);
            //printf("%s\n",novoFilme.tituloOriginal);
        }
        /*else if(strstr(linha,"<p class=\"wrap\">")==NULL){
            strcpy(novoFilme->tituloOriginal,nome);
        }*/
        //Busca pela Data de Lancamento
        if(strstr(linha,"<span class=\"release\">")!=NULL){
            char dia[10];
            char mes[10];
            char ano[10];
            char data[100];
            read=getline(&linha,&tamanho,arquivo);
            strcpy(stringAux,removeLeadingSpaces(linha));
            strcpy(stringAux,(strtok(stringAux,"(")));
            strcpy(dia,strtok(stringAux,"/"));
            strcpy(data,strcat(dia,"/"));
            strcpy(mes,strtok(NULL,"/"));
            strcat(data,mes);
            strcat(data,"/");
            strcpy(ano,strtok(NULL,"/"));
            strcat(data,ano);
            //strcpy(dataLancamento,data);
            strcpy(novoFilme->dataLancamento,data);
            //printf("%s\n",novoFilme.dataLancamento);
        }
        //Busca pela Duração
        if(strstr(linha,"span class=\"runtime")!=NULL){
            char horas[10];
            char minutos[10];
            int duracao=0;
            read=getline(&linha,&tamanho,arquivo);
            read=getline(&linha,&tamanho,arquivo);
            strcpy(stringAux,removeLeadingSpaces(linha));
            if(strstr(linha,"h")){
                strcpy(horas,strtok(stringAux,"h"));
                strcpy(minutos,strtok(NULL,"m"));
                strcpy(minutos,removeLeadingSpaces(minutos));
                duracao=(atoi(horas)*60)+atoi(minutos);
                novoFilme->duracao=duracao;
                //printf("%i\n",duracao);
            }else{
                strcpy(minutos,strtok(stringAux,"m"));
                strcpy(minutos,removeLeadingSpaces(minutos));
                duracao=atoi(minutos);
                novoFilme->duracao=duracao;
                //printf("%i\n",duracao);
            }
        }
        //Busca pelo Genero
        if(strstr(linha,"/genre/")!=NULL){
           stringAux[0]='\0';
            tiraTags(linha,stringAux);
            strcpy(stringAux,removeLeadingSpaces(stringAux));
            //strcpy(genero,stringAux);
            strcpy(novoFilme->genero,stringAux);
            //printf("%s\n",novoFilme.genero);
            
        }
          //Busca pelo idioma
        if(strstr(linha,"Idioma")!=NULL){
           stringAux[0]='\0';
            strcpy(stringAux,removeLeadingSpaces(linha));
            strcpy(stringAux,stringAux+47);
            strcpy(stringAux,substr(stringAux,0,strlen(stringAux)-5));
            //strcpy(idiomaOriginal,stringAux);
            strcpy(novoFilme->idiomaOriginal,stringAux);
            //printf("%s\n",stringAux);
        }
        //Busca pela situação
        if(strstr(linha,"<strong><bdi>Situação")!=NULL){
           stringAux[0]='\0';
            tiraTags(linha,stringAux);
            strcpy(stringAux,removeLeadingSpaces(stringAux));
            strcpy(stringAux,stringAux+11);
            //strcpy(situacao,stringAux);
            strcpy(novoFilme->situacao,stringAux);
            //printf("%s\n",novoFilme.situacao);
        }
        //Busca pelo orçamento
        if(strstr(linha,"Orçamento")!=NULL){
            float orcamento;
            strcpy(stringAux,removeLeadingSpaces(linha));
            if(strlen(stringAux)==1){
                novoFilme->orcamento=0;
                orcamento = atof(stringAux);
                //novoFilme->orcamento=0;
                //printf("%.1e\n",atof(stringAux)*1000000);
            }else{
            strcpy(stringAux,stringAux+41);
            strcpy(stringAux,substr(stringAux,2,strlen(stringAux)-5));
            removeChar(stringAux,',');
            orcamento = atof(stringAux);
            novoFilme->orcamento=orcamento;
            //printf("%.1e\n",atof(stringAux)*1000000);
            }
        }
        //Procura pelas Palavras Chave
        if(strstr(linha,"Palavras-chave")!=NULL){
            int contaPalavras=0;
            char palavraChave[10000];
            while(true){
                if(strstr(linha,"</ul>")!=NULL){break;}
                //printf("%s\n",linha);
                if(strstr(linha,"Nenhuma palavra-chave foi adicionada.")!=NULL){break;}
                
                if(strstr(linha,"/keyword/")!=NULL){
                    contaPalavras++;
                    strcpy(stringAux,linha);
                    int posicao=0;  
                    for(int aux2=0;aux2<=strlen(stringAux);aux2++){
                        
                        if((stringAux[aux2]=='\"') && (stringAux[aux2+1]=='>')){
                            posicao=aux2+2;
                        }
                    }
                    strcpy(palavraChave,substr(stringAux,posicao,strlen(stringAux)-10));
                    strcpy(novoFilme->palavrasChave[contaPalavras],palavraChave);
                }
                read=getline(&linha,&tamanho,arquivo);
                
            }  
             novoFilme->numeroPalavras=contaPalavras;
            //strcpy(novoFilme->palavrasChave[0],atoi(contaPalavras)); 
                
        }
        
    }
    if(strcmp(novoFilme->tituloOriginal,"bug")==0){
        strcpy(nome,substr(nome,0,strlen(nome)-1));
        strcpy(novoFilme->tituloOriginal,nome);
    }
    fclose(arquivo);
    if(linha) free(linha); 

}
int n=0;
#define MAXTAM 1000
Filme array[MAXTAM];

void inserirInicio(Filme x){
    if(n>=MAXTAM){
      printf("Erro ao inserir!");
      exit(1);
    }
    for(int i=n;i>0;i--){
        array[i]=array[i-1];
    }
    array[0]=x;
    n++;
}
void inserirFim(Filme x){
    if(n>=MAXTAM){
        printf("Erro ao inserir!");
        exit(1);
    }
    array[n]=x;
    n++;
}

void inserir(Filme x, int pos){
    int i;
    if(n >= MAXTAM || pos < 0 || pos > n){
        printf("Erro ao inserir!");
        exit(1);
    }
    for(i = n; i > pos; i--){
      array[i] = array[i-1];
    }
    array[pos] = x;
    n++;
}

Filme removerInicio() {
   int i;
   Filme resp;

   //validar remocao
   if (n == 0) {
      printf("Erro ao remover!");
      exit(1);
   }

   resp = array[0];
   n--;

    for(i = 0; i < n; i++){
      array[i] = array[i+1];
    }
   return resp;
}
Filme removerFim() {

   //validar remocao
   if (n == 0) {
      printf("Erro ao remover!");
      exit(1);
   }

   return array[--n];
}
Filme remover(int pos) {
   int i;
   Filme resp;

   //validar remocao
   if (n == 0 || pos < 0 || pos >= n) {
      printf("Erro ao remover!");
      exit(1);
   }

   resp = array[pos];
   n--;

   for(i = pos; i < n; i++){
      array[i] = array[i+1];
   }

   return resp;
}
void mostrar (){
   int i;

    for(i = 0; i < n; i++){
      imprimir(&array[i]);
      
    }   

}
int comparacoes=0;
int movimentacoes=0;

void insercaoPorCor(Filme *array, int n, int cor, int h){
    clock_t inicio=clock();
    for (int i = (h + cor); i < n; i+=h) {
        Filme tmp = array[i];
        int j = i - h;
        while ((j >= 0) && (strcmp(array[j].idiomaOriginal, tmp.idiomaOriginal)>0)) {
            comparacoes++;
            array[j + h] = array[j];
                movimentacoes++;

            j-=h;
        }
        array[j + h] = tmp;
        movimentacoes++;

    }
     FILE *log;
    
    log=fopen("752959_shellsort.txt","w+");
    fprintf(log,"752959\t%lims %i %i\t",(clock()-inicio),comparacoes,movimentacoes);
}

void shellsort(Filme *array, int n) {
    int h = 1;

    do { h = (h * 3) + 1; } while (h < n);

    do {
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            insercaoPorCor(array, n, cor, h);
        }
    } while (h != 1);
}

int main(void){
    char nomeArquivo[1000];
   

    scanf(" %[^\n]", nomeArquivo);
    
    while(!(nomeArquivo[0] == 'F' && nomeArquivo[1] == 'I' && nomeArquivo[2] == 'M')){
        Filme filme;
        ler(&nomeArquivo,&filme);
        inserirFim(filme);
        scanf(" %[^\n]", nomeArquivo);
    }
    shellsort(array,n);
    mostrar();
}
