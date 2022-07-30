#include <iostream>

/*Crie uma classe utilitária (Utils) com um método para converter temperaturas em graus Fahre-
nheit para graus Celsius (toCelsius()), ambas representadas em ponto-flutuante (double). Porém,
caso o valor a ser convertido seja menor que zero absoluto (-459,67°F) não poderá ser convertido.*/

using namespace std;

class utilitarios{
    float temperatura;
    public:
    utilitarios(float c_temperatura){
        temperatura=c_temperatura;
    }

    float toCelsius(float temperatura){
        if(temperatura>-459.67){
        float temperaturaCelsius;
        temperaturaCelsius=(temperatura-32)/1.8;
        return temperaturaCelsius;
        }else{
            printf("Temperatura menor que o zero absoluto!\n");
        }
    }

    float toFahrenheit(float temperatura){
        if (temperatura>-273.15){
        float temperaturaFahrenheit;
        temperaturaFahrenheit=(temperatura*1.8)+32;
        return temperaturaFahrenheit;
        }else{
            printf("Temperatura menor que o zero absoluto!\n");
        }
    }
};

int main(void){
    int resposta;
    printf("Como gostaria de converter?\n1-Celcius para Fahrenheit\n2-Fahrenheit para Celsius\n");
    scanf("%i",&resposta);
    if (resposta==1){
        float temp;
        printf("Digite a temperatura em Celsius:\n");
        scanf("%f",&temp);
        utilitarios usuario(temp);
        printf("A temperatura em Fahrenheit corresponde a: %.2f graus.\n",usuario.toFahrenheit(temp));
    }else if(resposta==2){
        float temp;
        printf("Digite a temperatura em Fahrenheit:\n");
        scanf("%f",&temp);
        utilitarios usuario(temp);
        printf("A temperatura em Celsius corresponde a: %.2f graus.\n",usuario.toCelsius(temp));
    }
}