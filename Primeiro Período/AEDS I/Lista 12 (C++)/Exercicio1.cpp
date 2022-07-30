#include <iostream>

/*Crie uma classe para representar uma pessoa, com os atributos privados de nome, idade e altura.
Crie os métodos públicos necessários para sets e gets e também um métodos para imprimir os
dados de uma pessoa.*/

using namespace std;

class pessoa{
    string nome;
    int idade;
    float altura;

    public:
    pessoa(string c_nome, int c_idade, float c_altura){
        nome=c_nome;
        idade=c_idade;
        altura=c_altura;
    }

    void setNome(string novoNome){
        nome=novoNome;
    }
    void setIdade(int novaIdade){
        idade=novaIdade;
    }
    void setAltura(float novaAltura){
        altura=novaAltura;
    }

    string getNome(){return nome;}
    int getIdade(){return idade;}
    float getAltura(){return altura;}
};


int main(void){
    string nome;
    int idade;
    float altura;

    cout << "Digite o nome da pessoa desejada:\n";
    cin >> nome;

    cout << "Digite a idade da pessoa:\n";
    cin >> idade;

    cout <<"Digite a atura da pessoa:\n";
    cin >> altura;

    pessoa usuario(nome,idade,altura);
    cout <<"Os dados Inseridos foram:\n";
    cout <<"Nome:";
    cout << usuario.getNome();
    cout <<"\nIdade:";
    cout << usuario.getIdade();
    cout <<"\nAltura:";
    cout <<usuario.getAltura();
   
}