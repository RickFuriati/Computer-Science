#include<stdio.h>
#include<string.h>

/*O codigo de César é uma das mais simples e conhecidas técnicas de criptografia. É um tipo de
substituic ̧ao na qual cada letra do texto é substituída por outra, que se apresenta no alfabeto
abaixo dela um numero fixo de vezes. Por exemplo, com uma troca de três posições, ‘A’ seria
substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente um programa que faça uso
desse Codigo de César (3 posicões), entre com uma string e retorne a string codificada. Exemplo:
String: a ligeira raposa marrom saltou sobre o cachorro cansado Nova string: D OLJHLUD
UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR*/

int main (void){
    char string[200];
    char atual;
    printf("Digite uma string:\n");
    gets(string);
    printf("A string codificada com a cifra de cesar corresponde a:\n");
    for (int aux=0;aux<strlen(string);aux++){
        if (string[aux]!=' '){
        string[aux]=(((string[aux]-97)+3)%26)+97;
        }

        printf("%c",string[aux]);
    }
}