#include <iostream>

/*Implemente a classe Funcionario e a classe Gerente.
a. crie a classe Assistente, que também é um funcionário, e que possui um número de matrícula
(faça o método GET). Sobrescreva o método exibeDados().
b. sabendo que os Assistentes Técnicos possuem um bônus salarial e que os Assistentes Admi-
nistrativos possuem um turno (dia ou noite) e um adicional noturno, crie as classes Tecnico e
Administrativo.*/

using namespace std;

class funcionario{
    string nome;
    float salario;
    public:
    funcionario(){};
    funcionario(string c_nome, float c_salario){
        nome=c_nome;
        salario=c_salario;
    }

    void setNome(string nome){
        this->nome=nome;
    }
    void setSalario(float salario){
        this->salario=salario;
    }
    string getNome(){
        return nome;
    }
    float getSalario(){
        return salario;
    }
    
    virtual void exibeDados(){
        printf("-------- Funcionario -------- \n");
        cout <<"Nome:" << nome;
        printf("\nSalario: %.2f\n",salario);
    }
};

class gerente: public funcionario{
    public:
    gerente(string nome,float salario){
        setNome(nome);
        setSalario(salario);
    }
    virtual void exibeDados(){
        printf("-------- Gerente -------- \n");
        cout <<"Nome:" << getNome();
        printf("\nSalario: %.2f\n",getSalario());
    }
};

class assistente: public funcionario{
    int matricula;
    
    public:
    assistente(int matricula, string nome, float salario){
        this->matricula=matricula;
        setNome(nome);
        setSalario(salario);
    }
    void setMatricula(int matricula){
        this->matricula=matricula;
    }
    int getMatricula(){
        return matricula;
    }
    virtual void exibeDados(){
        printf("-------- Assistente -------- \n");
        cout <<"Nome:" << getNome();
        printf("\nSalario: %.2f\n",getSalario());
        printf("Matricula: %i\n",matricula);
    }
};

class assistTec: public funcionario{
    float bonusSalarial;
    public:
    assistTec(float bonus,string nome, float salario){
        bonusSalarial=bonus;
        setNome(nome);
        setSalario(salario);
    }
    void setBonus(float bonus){
        this->bonusSalarial=bonus;
    }
    float getBonus(){
        return bonusSalarial;
    }
    virtual void exibeDados(){
        printf("-------- Assistente Tecnico -------- \n");
        cout <<"Nome:" << getNome();
        printf("\nSalario: %.2f\n",getSalario());
        printf("Bonus salarial: %.2f\n", bonusSalarial);
    }
};

class assistAdm: public funcionario{
    string turno;
    float bonusNoturno;
    public:
    
    assistAdm(string c_turno,float c_bonusNoturno,string nome, float salario){
        turno=c_turno;
        bonusNoturno=c_bonusNoturno;
        setNome(nome);
        setSalario(salario);
    }
    void setTurno(string turno){
        this->turno=turno;
    }
    void setBonusNot(float bonusNoturno){
        this->bonusNoturno=bonusNoturno;
    }
    string getTurno(){
        return turno;
    }
    float returnBonusNot(){
        return bonusNoturno;
    }
    
    virtual void exibeDados(){
        printf("-------- Assistente Administrativo -------- \n");
        cout <<"Nome:" << getNome();
        printf("\nSalario: %.2f\n",getSalario());
        printf("Turno: %s\n",turno);
        printf("Bonus noturno:%.2f\n",bonusNoturno);
    }
};

int main(void){
    string nomeGerente,nomeAssistente,nomeAssistTec,nomeAssistAdm;
    float salarioGerente,salarioAssistente,salarioAssistTec,salarioAssistAdm;
    int matricula;
    float bonusSalarial;
    string turno;
    float bonusNoturno;
    printf("Digite o nome do Gerente:\n");
    cin >> nomeGerente;
    printf("Digite o salario do Gerente:\n");
    scanf("%f",&salarioGerente);
    gerente gerente(nomeGerente,salarioGerente);
    printf("Digite o nome do Assistente:\n");
    cin >> nomeAssistente;
    printf("Digite o salario do Assistente:\n");
    scanf("%f",&salarioAssistente);
    printf("Digite a matricula do Assistente:\n");
    scanf("%i",&matricula);
    assistente assistente(matricula,nomeAssistente,salarioAssistente);
    printf("Digite o nome do Assistente Tecnico:\n");
    cin >> nomeAssistTec;
    printf("Digite o salario do Assistente Tecnico:\n");
    scanf("%f",&salarioAssistTec);
    printf("Digite o bonus salarial do Assistente Tecnico:\n");
    scanf("%f",&bonusSalarial);
    assistTec assistTec(bonusSalarial,nomeAssistTec,salarioAssistTec);
    printf("Digite o nome do Assistente Administrativo:\n");
    cin >> nomeAssistAdm;
    printf("Digite o salario do Assistente Administrativo:\n");
    scanf("%f",&salarioAssistAdm);
    printf("Digite o turno do Assistente Admninistrativo:\n");
    cin >> turno;
    printf("Digite o bonus noturno do Assistente Administrativo:\n");
    scanf("%f",&bonusNoturno);
    assistAdm assistAdm(turno,bonusNoturno,nomeAssistAdm,salarioAssistAdm);

    printf("--------Exibindo dados --------\n");
    gerente.exibeDados();
    assistente.exibeDados();
    assistTec.exibeDados();
    assistAdm.exibeDados();

    
}
