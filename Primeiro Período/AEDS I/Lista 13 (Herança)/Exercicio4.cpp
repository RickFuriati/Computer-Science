#include <iostream>

/*Crie a classe Veiculo, contendo o peso, a velocidade máxima, e o preço. Inclua um construtor sem
argumentos e um com argumentos para inicialização dos atributos. Crie métodos que funcionem
como getter e setter e print.
Crie a classe Motor, contendo o número de cilindros e a potência. Inclua um construtor sem
argumentos e um com argumentos para inicialização dos atributos. Crie métodos que funcionem
como getter e setter e print.
Crie a classe CarroPasseio, derivada das classes Veiculo e Motor. Inclua atributos como modelo e
cor. Crie um construtor para esta classe que chame explicitamente o construtor das classes base,
um getter e um setter, além de um método print, que utiliza o método print da classe base. Crie
um driver para testar sua aplicação.*/

using namespace std;

class veiculo{
    float peso, velocidadeMax, preco;
    public:
    veiculo(){};
    veiculo(float c_peso,float c_velocidadeMax,float c_preco){
        peso=c_peso;
        velocidadeMax=c_velocidadeMax;
        preco=c_preco;
    }
    
    
    void setPeso(float peso){
        this->peso=peso;
    }
    void setVelMax(float velMax){
        this->velocidadeMax=velMax;
    }
    void setPreco(float preco){
        this->preco=preco;
    }

    float getPeso(){return peso;}
    float getVelMax(){return velocidadeMax;}
    float getPreco(){return preco;}

    void printCarro(){
        printf("-------- Dados Veiculo --------\n ");
        printf("Peso: %.2f\n",peso);
        printf("Velocidade maxima: %.2f\n",velocidadeMax);
        printf("Preco: %.2f\n",preco);
    }
};

class motor{
    int numeroCilindros;
    float potencia;
    public: 
    motor(){};
    motor (int c_numeroCilindros,float c_potencia){
        numeroCilindros=c_numeroCilindros;
        potencia=c_potencia;
    }
    

    void setNumCil(int numCil){
        numeroCilindros=numCil;
    }
    void setPotencia(float potencia){
        this->potencia=potencia;
    }

    int getNumCil(){return numeroCilindros;}
    float getPotencia(){return potencia;}

    void printMotor(){
        printf("-------- Dados Motor--------\n ");
        printf("Numero de cilindros: %i\n",numeroCilindros);
        printf("Potencia: %.2f\n",potencia);
    }
};

class carroPasseio: public veiculo, public motor{
    int modelo;
    string cor;
    public:
    carroPasseio(int c_modelo,string c_cor){
        modelo=c_modelo;
        cor=c_cor;
    }

    void setModelo(int modelo){
        this->modelo=modelo;
    }
    void setCor(string cor){
        this->cor=cor;
    }

    int getModelo(){return modelo;}
    string getCor(){return cor;}

    void print(){
        printCarro();
        printMotor();
        printf("-------- Dados Carro Passeio--------\n ");
        printf("Modelo: %i\n",modelo);
        cout<<"Cor:"<<cor;
    }
    
};

int main(void){
    float peso,velocidadeMax,preco,potencia;
    int numCilindros,modelo;
    string cor;
    printf("Digite o peso do veiculo:\n");
    scanf("%f",&peso);
    printf("Digite a velocidade maxima do veiculo:\n");
    scanf("%f",&velocidadeMax);
    printf("Digite o preco do veiculo:\n");
    scanf("%f",&preco);
    printf("Digite a potencia do Motor:\n");
    scanf("%f",&potencia);
    printf("Digite o numero de cilindros do motor:\n");
    scanf("%i",&numCilindros);
    printf("Digite o modelo do carro:\n");
    scanf("%i",&modelo);
    printf("Digite a cor do carro:\n");
    cin >> cor;
    
    carroPasseio driver(modelo,cor);
    
    driver.setPeso(peso);
    driver.setVelMax(velocidadeMax);
    driver.setPreco(preco);
    driver.setNumCil(numCilindros);
    driver.setPotencia(potencia);
    driver.printCarro();
    driver.printMotor();
    driver.print();
    

}