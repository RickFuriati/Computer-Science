#include <iostream>

/*Crie uma classe Aluno com atributos que armazenem o nome, a série que cursa e o grau. Crie
um getter e um setter, além de uma variável static que conte a quantidade de objetos criados, a
ser utilizada no construtor e destrutor. Crie um vetor com 15 objetos desta classe e preencha os
dados através do setter.*/

using namespace std;

class aluno{
    string nome;
    int serie;
    int grau;

    public:
    void setNome(string nome){
        this->nome=nome;
    }
    void setSerie(int serie){
        this->serie=serie;
    }
    void setGrau(int grau){
        this->grau=grau;
    }

    string getNome(){return nome;}
    int getSerie(){return serie;}
    int getGrau(){return grau;}

};

int main(void){
    aluno vetor[15];
    string nomeAux;
    int serieAux,grauAux;
    for(int aux=0;aux<15;aux++){
        printf("-------- Aluno %i --------\n",aux+1);
        printf("Digite o nome do aluno:\n");
        cin >> nomeAux;
        vetor[aux].setNome(nomeAux);
        printf("Digite a serie do aluno:\n");
        scanf("%i",&serieAux);
        vetor[aux].setSerie(serieAux);
        printf("Digite o grau do aluno:\n");
        scanf("%i",&grauAux);
        vetor[aux].setGrau(grauAux);
    }


}