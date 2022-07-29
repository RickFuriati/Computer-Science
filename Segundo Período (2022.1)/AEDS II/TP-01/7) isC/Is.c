#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 

    bool isFim(const char *s){
                                                                                                 
        if(strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
                return true;
            }
            return false;
    }

    bool isFullVogal(const char *s){ 
        int contador=0;
    
        for(int aux=0;aux<strlen(s);aux++){ //Aumenta o contador toda vez que o caractere na posição 'aux' é uma vogal
            if(s[aux]=='A'||s[aux]=='E'||s[aux]=='I'||s[aux]=='O'||s[aux]=='U'||s[aux]=='a'||s[aux]=='e'||s[aux]=='i'||s[aux]=='o'||s[aux]=='u'){
                contador++;
            }
        }
        if(contador==strlen(s)){ //Confere se o numero de correspondencias é igual ao tamanho da string (se for verdadeiro é composta somente por vogais)
            return true;
        }
        return false;
    }    

     bool isFullConsoante(const char *s){ 
        int contador=0;
        for(int aux=0;aux<strlen(s);aux++){ //Confere se não é uma vogal
            if(s[aux]!='A' & s[aux]!='E' & s[aux]!='I' & s[aux]!='O' & s[aux]!='U'& s[aux]!='a'& s[aux]!='e'& s[aux]!='i'& s[aux]!='o'& s[aux]!='u'){
                contador++;
            }
            if(s[aux]<64 ||(s[aux]>=91&&s[aux]<=96)||s[aux]>=123){ //Confere se não é um símbolo ou numero
                return false;
            }
        }
        if(contador==strlen(s)){//Confere se o numero de correspondencias é igual ao tamanho da string (se for verdadeiro é composta somente por consoantes)
            return true;
        }
        return false;
    }

    bool isInteiro(const char *s){
        int contador=0; 
        for(int aux=0;aux<strlen(s);aux++){ //Confere se é um inteiro a partir da tabela ASCII
            if(s[aux]>=48 && s[aux]<=57){
                contador++;
            }
        }
        if(contador==strlen(s)){ //Confere se o numero de correspondencias é igual ao tamanho da string 
            return true;
        }
        return false;
    }

    bool isReal(const char *s){ 
        int contador=0;
        int contadorSeparadores=0;
        for(int aux=0;aux<strlen(s);aux++){
            if((s[aux]>=48 && s[aux]<=57)||s[aux]=='.'||s[aux]==','){
                contador++;
                if(s[aux]=='.'||s[aux]==','){ //Caso o numero de vírgulas ou pontos seja maior que 1 retorna falso
                    contadorSeparadores++;
                }
            }
        }
        if(contadorSeparadores>1){
            return false;
        }
        if(contador==strlen(s)){
            return true;
        }
        return false;
    }

    int main (){
        char stringEntrada[100];
        scanf(" %[^\n]", stringEntrada); //Le a primeira linha antes do loop começar
       
        char x1[3];
        char x2[3];
        char x3[3];
        char x4[3];

        while(true){
            if(isFim(stringEntrada)==true){
                break;
            }

            if((isFullVogal(stringEntrada))==true){ //Atribui os valores de 'SIM' e 'NAO' as variáveis
                printf("SIM ");
            }else if((isFullVogal(stringEntrada))==false){
                printf("NAO ");
            }
    
            if(isFullConsoante((stringEntrada))==true){
                printf("SIM ");
            }else if(isFullConsoante(stringEntrada)==false){
                printf("NAO ");
            }
    
            if(isInteiro(stringEntrada)==true){
               printf("SIM ");
            }else if(isInteiro(stringEntrada)==false){
                printf("NAO ");
            }
    
            if(isReal(stringEntrada)==true){
                printf("SIM ");
            }else if(isReal(stringEntrada)==false){
                printf("NAO ");
            }
            printf("\n");
            scanf(" %[^\n]", stringEntrada);
        }
        
    }


