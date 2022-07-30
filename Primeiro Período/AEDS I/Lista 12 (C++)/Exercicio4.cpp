#include <iostream>
#include <math.h>
using namespace std;

/*Definir uma classe que represente um círculo. Esta classe deve possuir métodos
Privados para:*/

class circulo{
    int raio;
    int coordenadaX;
    int coordenadaY;
    int area=0;
    int circunferencia;
    private:
    int calculaArea(){
        area=(M_PI)*pow(raio,2);
        return area;
    }
    int calculaCircunferencia(){
        circunferencia=2*3.14*raio;
        return circunferencia;
    }
    public:
    void setRaio(){
        cout<<"Qual valor gostaria de colocar o raio:\n";
        scanf("%i",&raio);
    }

    void AumentaRaio(){
        int porcentagem;
        cout<<"Em quantos porcento gostaria de aumentar o raio?\n";
        scanf("%i",&porcentagem);
        raio=raio+((porcentagem/100)*raio);
    }

    void setCentro(){
        cout <<"Digite a coordenada X do centro:\n";
        scanf("%i",&coordenadaX);
        cout <<"Digite a coordenada Y do centro:\n";
        scanf("%i",&coordenadaY);
    }

    void imprimeRaio(){
        cout <<"\nO raio corresponde a:" << raio;
    }
    void imprimeCentro(){
        cout <<"\nAs coordenadas do centro do circulo correspondem a X:" <<coordenadaX <<" Y:" <<coordenadaY;
    }
    void imprimeArea(){
        cout<<"\nA area do circulo corresponde a:"<< area;
    }
    circulo(int c_raio){
        raio=c_raio;
    }
};

int main(void){
    int raio;

    cout <<"Digite o valor do raio do circulo:\n";
    scanf("%i",&raio);
    circulo usuario(raio);
    usuario.setRaio();
    usuario.AumentaRaio();
    usuario.setCentro();
    usuario.imprimeRaio();
    usuario.imprimeCentro();
    usuario.imprimeArea();
}



