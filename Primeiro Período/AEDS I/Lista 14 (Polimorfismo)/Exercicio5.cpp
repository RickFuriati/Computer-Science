#include <iostream>

/*Criar uma estrutura hierárquica que contenha as seguintes classes: Veiculo, Bicicleta e Auto-
móvel. Os métodos da classe Veiculo são todos virtuais puros e possuem a seguinte assinatura:
listarVerificacoes(), ajustar() e limpar(). Estes métodos são implementados nas sub-
classes Automóvel e Bicicleta. Acrescentar na classe Automóvel o método mudarOleo().*/

using namespace std;

class veiculo{
    public:
    veiculo(){};
    virtual  void listarVerificacoes(){
        printf("O veiculo foi verificado!\n");
    }
    virtual void ajustar(){
        printf("O veiculo foi ajustado!\n");
    }
    virtual void limpar(){
        printf("O veiculo foi limpo!\n");
    }
};

class automovel:public veiculo{
    public:
    automovel(){};
    void listarVerificacoes(){
        printf("O Automovel foi verificado!\n");
    }
    void ajustar(){
        printf("O Automovel foi ajustado!\n");
    }
    void limpar(){
        printf("O Automovel foi limpo!\n");
    }
    void mudarOleo(){
        printf("O oleo foi trocado!\n");
    }
};

class bicicleta:public veiculo{
    public:
    bicicleta(){};
    void listarVerificacoes(){
        printf("A Bicicleta foi verificada!\n");
    }
    void ajustar(){
        printf("A Bicicleta foi ajustada!\n");
    }
    void limpar(){
        printf("A Bicicleta foi limpa!\n");
    }

};

int main(void){
    veiculo veiculo1;
    veiculo1.listarVerificacoes();
    veiculo1.ajustar();
    veiculo1.limpar();

    automovel automovel1;
    automovel1.listarVerificacoes();
    automovel1.ajustar();
    automovel1.limpar();
    automovel1.mudarOleo();

    bicicleta bicicleta1;
    bicicleta1.listarVerificacoes();
    bicicleta1.ajustar();
    bicicleta1.limpar();

}