#include <iostream>

/*Crie uma classe Empregado que inclua os atributos nome (string), sobrenome (string) e salário
mensal (número real). A classe deve incluir construtores para cada um dos atributos para evitar
lixo e também getters e setters. Crie um programa que teste a classe, criando dois objetos,
calculando o salário anual de cada, dando um aumento de 10% e calcule o salário anual novamente.*/

using namespace std;

class empregado{
    string nome;
    string sobrenome;
    float salario;
    
    
    public:
    empregado(string c_nome, string c_sobrenome, float c_salario){
        setNome(c_nome);
        sobrenome=c_sobrenome;
        salario=c_salario;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setSobrenome(string sobrenome){
        this->sobrenome=sobrenome;
    }
    void setSalario(float salario){
        this->salario=salario;
    }

    string getNome(){return nome;}
    string getSobrenome(){return sobrenome;}
    float getSalario(){return salario;}

    void aumento(){
        salario=salario+(salario*0.1);
    }

    float salarioAnual(){
        return salario*12;
    }
};

int main (void){
    string nome1, sobrenome1;
    float salario1;

    string nome2, sobrenome2;
    float salario2;
    printf("-------- Empregado 1 --------\n");
    printf("Digite o nome do funcionario:\n");
    cin >> nome1;
    printf("Digite o sobrenome do funcionario:\n");
    cin >> sobrenome1;
    printf("Digite o salario do funcionario:\n");
    cin >> salario1;

    empregado funcionario1(nome1,sobrenome1,salario1);

    printf("-------- Empregado 2 --------\n");
    printf("Digite o nome do funcionario:\n");
    cin >> nome2;
    printf("Digite o sobrenome do funcionario:\n");
    cin >> sobrenome2;
    printf("Digite o salario do funcionario:\n");
     cin >> salario2;

    empregado funcionario2(nome2,sobrenome2,salario2);

    printf("-------- Empregado 1 --------\n");
    printf("Salario Anual: %.2f \n", funcionario1.salarioAnual());
    funcionario1.aumento();
    printf("Salario anual com aumento de 10 por cento: %.2f\n",funcionario1.salarioAnual());
    
    printf("-------- Empregado 2 --------\n");
    printf("Salario Anual: %.2f \n", funcionario2.salarioAnual());
    funcionario2.aumento();
    printf("Salario anual com aumento de 10 por cento: %.2f\n",funcionario2.salarioAnual());
}