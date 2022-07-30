#include <iostream>
#include <stdexcept>


/*Escreva um programa para preencher valores de um vetor de inteiros com 10 posições. O usuário
irá informar os valores a serem inseridos e suas respectivas posições no array. O programa
deve tratar as exceções ArrayIndexOutOfBoundsException quando for informada uma posição
inexistente do vetor e NumberFormatException quando o valor informado não for numero.*/

using namespace std;

class NumberFormatException: public exception{
    public:
    string errorMsg(){
        return "Os numeros inseridos devem ser inteiros :(";
    }
};
class ArrayIndexOutOfBoundsException: public exception{
    public:
    string errorMsg(){
        return "O numero inserido excede o numero de posicoes do vetor :(";
    }
};

bool isNumber(const string& string){
    for(char const &ch : string){
        if(std::isdigit(ch)==0){
            return false;
        }else{
            return true;
        }
    }
}


int main(void){
    int vetor[10];
    for(int aux=0;aux<10;aux++){
        string numero,posicao;
        while(1){
            try{
                printf("Digite um numero inteiro:\n");
                cin >>numero;

                if(isNumber(numero)==false){
                    throw NumberFormatException();
                }else{
                    break;
                }
            }
            catch(NumberFormatException x){
                printf("%s\n",x.errorMsg().c_str());
            }
        }
        while(1){
            try{
                printf("Em qual posicao deseja inserir o numero?\n");
                cin >> posicao;
                int posicao_f;
                if(isNumber(posicao)==false){
                    throw ArrayIndexOutOfBoundsException();
                }else{
                    posicao_f=stoi(posicao);
                    if(posicao_f < 0 ||posicao_f > 10){
                        throw ArrayIndexOutOfBoundsException();
                    }else{
                        vetor[posicao_f]=stoi(numero);
                        break;
                    }
                }
            }
            catch (ArrayIndexOutOfBoundsException x){
                printf("%s\n",x.errorMsg().c_str());
            }
        }
        }
        for (int aux=0;aux<10;aux++){
            printf("Posicao %i: %i\n",aux,vetor[aux]);
        }
    }
