#include <iostream>

/*Crie uma classe denominada Elevador para armazenar as informações de um elevador dentro
de um prédio. A classe deve armazenar o andar atual (0=térreo), total de andares no prédio,
excluindo o térreo, capacidade do elevador, e quantas pessoas estão presentes nele.*/

using namespace std;

class Elevador{
    int andarAtual;
    int totalAndares;
    int capacidade;
    int numPessoas;

    public:
    Elevador(int c_andarAtual, int c_totalAndares,int c_capacidade, int c_numPessoas){
        andarAtual=c_andarAtual;
        totalAndares=c_totalAndares;
        capacidade=c_capacidade;
        numPessoas=c_numPessoas;
    }

    void setAndarAtual(int newAndarAtual){andarAtual=newAndarAtual;}
    void setTotalAndares(int newTotalAndares){totalAndares=newTotalAndares;}
    void setCapacidade(int newCapacidade){capacidade=newCapacidade;}
    void setNumPessoas(int newNumPessoas){numPessoas=newNumPessoas;}

    int getAndar(){return andarAtual;}
    int getTotalAndares(){return totalAndares;}
    int getCapacidade(){return capacidade;}
    int getNumPessoas(){return numPessoas;}

    void inicializa(int capacidaede, int totalAndares){
        this->capacidade=capacidade;
        this->totalAndares=totalAndares-1;
    }

    void entra(){
        if(numPessoas<capacidade){
        numPessoas+=1;
        }else{
            cout <<"O elevador esta cheio!";
        }
    }
    void sai(){
        if(numPessoas!=0){
            numPessoas-=1;
        }else{
            cout <<"Nao ha pessoas no elevador!";
        }
    }
    void sobe(){
        if(andarAtual<totalAndares){
            andarAtual+=1;
        }else{
            cout << "O elevador esta no ultimo andar!";
        }
    }
    void desce(){
        if(andarAtual!=0){
            andarAtual-=1;
        }else{
            cout << "O elevador esta no terreo!";
        }
    }
};

int main(void){
    int capacidade, totalAndares,numPessoas;
    cout <<"Digite a capacidade do elevador:\n";
    scanf("%i",&capacidade);
    cout <<"Digite o total de andares:\n";
    scanf("%i",&totalAndares);
    cout <<"Digite o numero de pessoas no elevador:\n";
    scanf("%i",&numPessoas);

    Elevador elevador(0,totalAndares,capacidade,numPessoas);
    elevador.entra();
}