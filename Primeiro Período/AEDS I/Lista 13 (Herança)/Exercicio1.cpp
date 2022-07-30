#include <iostream>
#include <string>
/*Crie uma classe chamada NotaFiscal que um hardware utilize para representar uma nota fiscal
em uma loja de peças. Uma nota fiscal deve incluir quatro dados como atributos:
a. Número da peça (string);
b. Descrição da peça (string);
c. Quantidade comprada (inteiro);
d. Preço (número real).
A classe deve incluir ainda getters e setters para cada um dos atributos. Ainda, deve haver um
método getTotalNota que calcule e retorne o total de um vetor de objetos. Escreva um programa
que teste cada um dos métodos da classe.*/

using namespace std;

class notaFiscal{
    string numPeca;
    string descricao;
    int quantidade;
    float preco;

    public:
    void setNumPeca(){
        cout<<"Digite o numero da peca:\n";
        scanf("%[^\n]",&numPeca);
    }
    void setDescricao(){
        cout<<"Digite a descricao da peca:\n";
        scanf(" %[^\n]",&descricao);
    }
    void setQuantidade(){
        cout<<"Digite a quantidade de pecas:\n";
        scanf("%i",&quantidade);
    }
    void setPreco(){
        cout<<"Digite o preco da unidade:\n";
        scanf("%f",&preco);
    }

    string getNumPeca(){return numPeca;}
    string getDescricao(){return descricao;}
    int getQuantidade(){return quantidade;}
    float getPreco(){return preco;}

    void totalNota(){
        cout<<"------Total da Nota------\n";
        printf("Total: %.2f",quantidade*preco);
    }
};

int main(void){
    notaFiscal usuario;
    usuario.setNumPeca();
    usuario.setDescricao();
    usuario.setPreco();
    usuario.setQuantidade();
    usuario.totalNota();
}