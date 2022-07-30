#include <iostream>

/*Crie uma classe em C++ chamada Relogio para armazenar um horário, composto por hora,
minuto e segundo. A classe deve representar esses componentes de horário e deve apresentar os
métodos descritos a seguir:*/

using namespace std;

class relogio{
    int hora;
    int minuto;
    int segundo;

    public:
    relogio(int c_hora,int c_minuto,int c_segundo){
        hora=c_hora;
        minuto=c_minuto;
        segundo=c_segundo;
    }
    void setHora(int hora,int minuto,int segundo){
        this->hora=hora;
        this->minuto=minuto;
        this->segundo=segundo;
    }
    int getHora(){
        return hora;
        return minuto;
        return segundo;
    }
    
    void avancaSegundo(int hora,int minuto,int segundo){
        if (segundo<60){
            segundo+=1;
        }else if(segundo=60){
            segundo=0;
            if(minuto<60){
                minuto+=1;
            }else if(minuto=60){
                minuto=0;
                if(hora<24){
                    hora+=1;
                }else if(hora=24){
                    hora=0;
                }
            }
        }
    }
};

int main(void){
    int hora,minuto,segundo;
    cout <<"Digite a Hora:\n";
    scanf("%i",&hora);
    cout <<"Digite o Minutos:\n";
    scanf("%i",&minuto);
    cout <<"Digite o Segundos:\n";
    scanf("%i",&segundo);

    relogio usuario(hora,minuto,segundo);
    cout <<"Hora:"<< hora << ":" << minuto <<":"<< segundo;
    
}