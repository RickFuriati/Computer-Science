#include <iostream>

/*Implemente uma classe televisão. A televisão tem um controle de volume do som e um controle
de seleção de canal. O controle de volume permite aumentar ou diminuir a potência do volume
de som em uma unidade de cada vez. O controle de canal também permite aumentar e diminuir
o número do canal em uma unidade, porém, também possibilita trocar para um canal indicado.
Também devem existir métodos para consultar o valor do volume de som e o canal selecionado.
No programa principal, crie uma televisão e troque de canal algumas vezes. Aumente um pouco
o volume, e exiba o valor de ambos os atributos.*/

using namespace std;

class televisao{
  int volume=5;
  int canal;

  public:
  televisao(int c_volume,int c_canal){
      volume=c_volume;
      canal=c_canal;
  }

    void setCanal(int canal){
        this->canal=canal;
    }

  void aumentaVolume(){
      if (volume<10){
      volume+=1;
      }else{
          cout <<"\nO volume esta no maximo!!\n";
      }
  }

  void diminuiVolume(){
      if(volume > 0){
      volume-=1;
      }else{
          cout <<"\nO volume esta no minimo!!";
      }
  }

  void aumentaCanal(){
      canal+=1;
  }

  void diminuiCanal(){
      canal-=1;
  }

    void exibeDados(){
        cout <<"\nCanal Atual:"<< canal;
        cout <<"\nVolume Atual:" <<volume; 
    }

};

int main(void){
    cout <<"Televisao em C++\n";
    int canal;
    
    cout <<"Digite o numero do canal desejado:\n";
    scanf("%i",&canal);

    televisao usuario(5,canal);

    usuario.exibeDados();
    usuario.aumentaCanal();
    usuario.aumentaCanal();
    usuario.exibeDados();
    usuario.diminuiVolume();
    usuario.diminuiVolume();
    usuario.exibeDados();

}