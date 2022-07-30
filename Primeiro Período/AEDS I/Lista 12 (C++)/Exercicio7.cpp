#include <iostream>

/*Implemente um carro. O tanque de combustível do carro armazena no máximo 50 litros de ga-
solina. O carro consome 15 km/litro. Deve ser possível:
•Abastecer o carro com uma certa quantidade de gasolina;
•Mover o carro em uma determinada distância (medida em km);
•Retornar a quantidade de combustível e a distância total percorrida.
•No programa principal, crie 2 carros. Abasteça 20 litros no primeiro e 30 litros no segundo.
Desloque o primeiro em 200 km e o segundo em 400 km. Exiba na tela a distância percorrida
e o total de combustível restante para cada um.*/

using namespace std;

class carro{
    int quantidadeTanque;
    int quantidade;
    int distancia;
    public:
    carro(int c_tanque){
        quantidadeTanque=c_tanque;
    }

    void abastece(){
       cout<< "\nQuantos litros deseja colocar no tanque?\n";
       scanf("%i",&quantidade);
       
       if(quantidadeTanque<=50){
           if(quantidadeTanque+quantidade<=50){
               quantidadeTanque+=quantidade;
           }else if(quantidadeTanque+quantidade>50){
               quantidadeTanque+=(50-quantidade);
           }
       }else{
           cout<<"\nO tanque esta cheio!!";
       } 
    }

    void anda(){
        cout<<"\nQuantos kms gostaria de andar?\n";
        scanf("%i",&distancia);
        if (quantidadeTanque*15<distancia){
            cout<<"\nO combustivel nao e suficiente para completar o trajeto :(";
            cout<<"\nVoce poderar andar:"<<quantidadeTanque*15;
        }
    }

    void mostraDados(){
        printf("\nVoce percorreu %i kms",distancia);
        printf("\nGastou %i litros de combustivel.",distancia/15);
        printf("\nO tanque possui %i litros de combustivel restantes.",quantidadeTanque-(distancia/15));
    }


};

int main(void){
    int quantidade1,quantidade2;
    cout<<"Digite a quantidade de combustivel do tanque do carro 1:\n";
    scanf("%i",&quantidade1);
    carro carro1(quantidade1);

    cout<<"Digite a quantidade de combustivel do tanque do carro 2:\n";
    scanf("%i",&quantidade2);
    carro carro2(quantidade2);

    carro1.abastece();
    carro1.anda();
    carro2.abastece();
    carro2.anda();

    cout<<"-------- Dados Carro 1--------\n";
    carro1.mostraDados();
    cout<<"\n-------- Dados Carro 2--------";
    carro2.mostraDados();

}