#include <iostream>

/*Implemente um condicionador de ar. O condicionador possui 10 potências diferentes. Cada
unidade da potência do condicionador diminui a temperatura do ambiente em 1.8ºC. A variação
que o condicionador consegue causar está no intervalo [0ºC - 18ºC], ou seja, zero graus de variação
quando desligado e dezoito graus de variação quando ligado na potência máxima.
Através de um sensor, o condicionador é informado da temperatura externa. Dada essa tempe-
ratura e a potência selecionada, o condicionador calcula e retorna a temperatura do ambiente.
No programa principal, crie dois condicionadores. Informe duas temperaturas externas diferentes
para cada um (ex: 25ºC e 31ºC), ajuste o segundo em potência máxima (10) e o primeiro em
potência média (5). Finalmente, exiba a temperatura resultante de cada ambiente.*/

using namespace std;

class arConcidionado{
    float tempExterna;
    int potencia;
    float tempResfriada;
    public:
    arConcidionado(float c_tempExterna){
        tempExterna=c_tempExterna;
    }

    void setPotencia(){
        cout<<"Digite a potencia desejada:\n";
        scanf("%i",&potencia);
        tempResfriada=tempExterna-(potencia*1.8);
    }

    void mostraDados(){
        cout << "\nPotencia:" <<potencia;
        cout <<"\nTemperatura externa:"<<tempExterna;
        cout <<"\nTemperatura resfriada:"<<tempResfriada;
    }

};

int main(void){
    float temp1,temp2;

    cout<<"Digite a temperatura do ambiente 1:\n";
    scanf("%f",&temp1);
    cout<<"Digite a temperatura do ambiente 2:\n";
    scanf("%f",&temp2);

    arConcidionado ambiente1(temp1);
    ambiente1.setPotencia();
    arConcidionado ambiente2(temp2);
    ambiente2.setPotencia();

    cout << "\n--------Dados ambiente 1:--------";
    ambiente1.mostraDados();
    cout << "\n--------Dados ambiente 2:--------";
    ambiente2.mostraDados();

}