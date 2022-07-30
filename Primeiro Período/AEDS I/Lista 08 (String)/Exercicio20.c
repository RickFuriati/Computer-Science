#include<stdio.h>
#include<string.h>

/*Faça um programa que preencha uma matriz de string com os modelos de cinco carros (exemplos
de modelos: Fusca, Gol, Vectra, etc.). Em seguida, preencha um vetor com o consumo desses
carros, isto e, quantos quiloometros cada um deles faz com um litro de ^ combustível. Calcule e
mostre: (a) O modelo de carro mais economico; (b) Quantos litros de combustível cada um dos
carros cadastrados consome para percorrer uma distancia de 1.000 quiloometros*/

int main (void){
    char modeloCarros [5][50];
    int consumoCarros[5];
    int carroEconomico=1;
    for (int aux=0;aux<5;aux++){
        printf("----------- Carro %i -----------\n",aux+1);
        printf("Digite o modelo do carro:\n");
        scanf(" %[^\n]s",&modeloCarros[aux]);
        printf("Digite o consumo do carro (km/L):\n");
        scanf("%i",&consumoCarros[aux]);

        if (consumoCarros[aux]>consumoCarros[1]){
            carroEconomico=aux;
        }
    }
    printf("O carro mais economico foi o carro de modelo %s\n",modeloCarros[carroEconomico]);
    for (int aux=0;aux<5;aux++){
        printf("----------- Carro: %s -----------\n",modeloCarros[aux]);
        printf("Consumo: %i Km/L.\n", consumoCarros[aux]);
        printf("Este carro consome %.2f litros para percorrer 1000km.\n",(float)1000/(float)consumoCarros[aux]);
    }
    
}