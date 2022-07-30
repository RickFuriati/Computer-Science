#include <iostream>

/*
Crie uma classe Aluno com os atributos nome, matricula, nota,  bolsista (booleano) e horaExtra (que são horas extra curricular);
Crie os métodos de acesso get e set e um construtor onde são passados todos atributos da classe.
Crie também os seguinte método:
lancaHoras(int qtde) que acrescenta horas extras ao aluno;
Crie uma classe Turma que possui o nome da turma e um vetor de alunos de tamanho 10. Além dos métodos de acesso, a classe deverá ter os seguintes métodos:
- mostraAlunosAbaixoDaMedia();
- mostraAlunosBolsistas();
-inserirAluno(Aluno aluno);
Crie uma classe Testa com um método main.
Crie uma turma e adicione alunos nela
Mostre os alunos bolsistas da turma.
*/

using namespace std;

class Aluno{
    string nome;
    int matricula;
    float nota;
    bool bolsista;
    int horaExtra;
    public:
    Aluno(){};
    Aluno(string c_nome,int c_matricula,float c_nota, bool c_bolsista, int c_horaExtra){
        nome=c_nome;
        matricula=c_matricula;
        nota=c_nota;
        bolsista=c_bolsista;
        horaExtra=c_horaExtra;
    };
    string getNome(){return nome;}
    int getMatricula(){return matricula;}
    float getNota(){return nota;}
    bool getBolsista(){return bolsista;}
    float getHoraExtra(){return horaExtra;}

    void setNome(string nome){
        this->nome=nome;
    }
    void setMatricula(int matricula){
        this->matricula=matricula;
    }
    void setNota(float nota){
        this->nota=nota;
    }
    void setBolsista(bool bolsista){
        this->bolsista=bolsista;
    }
    void setHoraExtra(int horaExtra){
        this->horaExtra=horaExtra;
    }

    void lancaHoras(int horas){
        horaExtra+=horas;
    }
};

class Turma:public Aluno{
    string nome;
    public:
    Aluno alunos[10];
    Turma(){};
    Turma (string c_nome){
        nome=c_nome;
    }

    int mostraAlunosAbaixoDaMedia(){
        int abaixoDaMedia=0;
        int notaAux;
        for(int aux=0;aux<10;aux++){
            notaAux=alunos[aux].getNota();
            if(notaAux<6){
                abaixoDaMedia++;
            }
        }
        return abaixoDaMedia;
    }

    int mostraAlunosBolsistas(){
        int alunosBolsistas=0;
        bool bolsistaAux;
        for(int aux=0;aux<10;aux++){
            bolsistaAux=alunos[aux].getBolsista();
            if(bolsistaAux==true){
                alunosBolsistas++;
            }
        }
        return alunosBolsistas;
    };

    void inserirAluno(Aluno aluno){
        
    };
};

int main(void){
    string nomeTurma;
    string nomeAux;
    int matriculaAux;
    int notaAux;
    bool bolsistaAux;
    char respostaBolsa;
    int horaExtraAux;
    printf("Digite o nome da turma:\n");
    cin >> nomeTurma;

    Turma turma(nomeTurma);
    for(int aux=0;aux<10;aux++){
        printf("-------- Aluno %i --------\n",aux+1);
        printf("Digite o nome do aluno:\n");
        cin >> nomeAux;
        turma.alunos[aux].setNome(nomeAux);
        printf("Digite a matricula do aluno:\n");
        cin >> matriculaAux;
        turma.alunos[aux].setMatricula(matriculaAux);
        printf("Digite a nota do aluno:\n");
        cin >> notaAux;
        turma.alunos[aux].setNota(notaAux);
        printf("O aluno é bolsista? ('s' para sim e 'n' para nao)\n");
        cin >> respostaBolsa;
        if(respostaBolsa=='s'){
            turma.alunos[aux].setBolsista(true);
        }else if(respostaBolsa=='n'){
            turma.alunos[aux].setBolsista(false);
        }
        printf("Qual a contidade de horas extras do aluno?\n");
        cin >> horaExtraAux;
        turma.alunos[aux].setHoraExtra(horaExtraAux);
    }
    
    printf("A quantidade de alunos bolsistas na turma eh de: %i\n",turma.mostraAlunosBolsistas());
    printf("A quantidade de alunos abaixo da media na turma eh de: %i\n",turma.mostraAlunosAbaixoDaMedia());

}