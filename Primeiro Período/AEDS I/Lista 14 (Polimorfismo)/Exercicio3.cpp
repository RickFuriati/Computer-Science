#include <iostream>

/*Crie uma classe para representar uma conta corrente, com métodos para depositar uma quantia,
sacar uma quantia e obter o saldo. Para cada saque será debitada também uma taxa de operação
equivalente à 0,5% do valor sacado. Crie, em seguida, uma subclasse desta classe anterior para
representar uma conta corrente de um cliente especial. Clientes especiais pagam taxas de operação
de apenas 0,1% do valor sacado. Faça testes com as duas classes e verifique seus resultados.*/

using namespace std;

class contaCorrente{
    string nome;
    float saldo;
    public:
    contaCorrente(){};
    contaCorrente(float c_saldo,string c_nome){
        saldo=c_saldo;
        nome=c_nome;
    }
    void deposito(float quantiaDeposito){
        saldo+=quantiaDeposito;
    }
    virtual void saque(float quantiaSaque){
        float taxa=0.05*quantiaSaque;
        saldo-=(quantiaSaque+taxa);
        printf("Taxa de operacao:%.2f\n",taxa);
        if(quantiaSaque+taxa>saldo){
            printf("Seu saldo nao e suficiente para sacar essa quantia :(\n");
        }
    }
    void mostraSaldo(){
        printf("O saldo disponivel na conta corresponde a: %.2f reais.\n",saldo);
    }
};

class clienteEspecial: public contaCorrente{
    float saldo;
    string nome;
    public:
    clienteEspecial(float c_saldo, string c_nome){
        saldo=c_saldo;
        nome=c_nome;
    }
    
   virtual void saque(float quantiaSaque){
        float taxa=0.01*quantiaSaque;
        saldo-=(quantiaSaque+taxa);
        printf("Taxa de operacao:%.2f\n",taxa);
        if(quantiaSaque+taxa>saldo){
            printf("Seu saldo nao e suficiente para sacar essa quantia :(\n");
        }
    }
};

int main(void){
    string nome1,nome2;
    float saldo1,saldo2;
    float deposito1,deposito2;
    float saque1,saque2;

    printf("Digite o nome do cliente:\n");
    cin >> nome1;
    printf("Digite o nome do cliente especial:\n");
    cin>> nome2;

    printf("Digite o saldo do cliente:\n");
    scanf("%f",&saldo1);
    printf("Digite o saldo do cliente especial:\n");
    scanf("%f",&saldo2);

    contaCorrente cliente(saldo1,nome1);
    clienteEspecial clienteEspecial(saldo2,nome2);

    printf("-------- Cliente --------\n");
    printf("Digite o valor do deposito:\n");
    scanf("%f",&deposito1);
    printf("Digite o valor do saque:\n");
    scanf("%f",&saque1);
    cliente.deposito(deposito1);
    cliente.saque(saque1);
    cliente.mostraSaldo();

    printf("-------- Cliente Especial--------\n");
    printf("Digite o valor do deposito:\n");
    scanf("%f",&deposito2);
    printf("Digite o valor do saque:\n");
    scanf("%f",&saque2);
    clienteEspecial.deposito(deposito2);
    clienteEspecial.saque(saque2);
    clienteEspecial.mostraSaldo();


}