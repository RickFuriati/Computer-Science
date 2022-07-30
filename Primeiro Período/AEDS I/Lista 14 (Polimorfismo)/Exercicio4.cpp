#include <iostream>

/*Crie uma hierarquia de classes de domínio para uma loja que venda livros, CDs e DVDs. So-
brescreva o método toString() para que imprima:
- Para livros: nome, preço e autor;
- Para CDs: nome, preço e número de faixas;
- Para DVDs: nome, preço e duração.
Evite ao máximo repetição de código utilizando o construtor da classe principal e no método
sobrescrito. Em seguida, crie uma classe Loja com um método principal que adicione 5 produtos
diferentes (a sua escolha) a um vetor e, por fim, imprima o conteúdo do vetor.*/

using namespace std;

class produto{
    string nome;
    float preco;

    public:
    produto(){};
    produto(string c_nome,float c_preco){
        nome=c_nome;
        preco=c_preco;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setPreco(float preco){
        this->preco=preco;
    }
    virtual void toString(){
        printf("Nome do produto: %s\n",nome);
        printf("Preco do produto: %.2f\n",preco);
    }
};

class livro: public produto{
    string nome;
    string autor;
    float preco;
    public:
    livro(){};
    livro(string c_nome,string c_autor,float c_preco){
        nome=c_nome;
        autor=c_autor;
        preco=c_preco;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setAutor(string autor){
        this->autor=autor;
    }
    void setPreco(float preco){
        this->preco=preco;
    }
    virtual void toString(){
        printf("-------- Livro --------\n");
        cout <<"Nome do livro: "<<nome<<endl;
        cout <<"Nome do autor: "<<autor<<endl;
        printf("Preco do produto: %.2f\n",preco);
    }
};

class CD: public produto{
    string nome;
    int numeroFaixas;
    float preco;
    public:
    CD(){};
    CD(string c_nome,int c_numFaixas,float c_preco){
        nome=c_nome;
        numeroFaixas=c_numFaixas;
        preco=c_preco;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setFaixas(int numFaixas){
        numeroFaixas=numFaixas;
    }
    void setPreco(float preco){
        this->preco=preco;
    }
    void toString(){
        printf("-------- CD --------\n");
        cout <<"Nome do CD: "<<nome<<endl;
        printf("Numero de faixas: %i\n",numeroFaixas);
        printf("Preco do produto: %.2f\n",preco);
    }
};

class DVD: public produto{
    string nome;
    float duracao;
    float preco;
    public:
   
    DVD(string c_nome,float c_duracao,float c_preco){
        nome=c_nome;
        duracao=c_duracao;
        preco=c_preco;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setDuracao(float duracao){
        this->duracao=duracao;
    }
    void setPreco(float preco){
        this->preco=preco;
    }
   void toString(){
        printf("-------- DVD --------\n");
        cout <<"Nome do DVD: "<<nome<<endl;
        printf("Duracao: %.2f\n",duracao);
        printf("Preco do produto: %.2f\n",preco);
    }
};

int main (void){
    produto *loja[5];

    string nome1,nome2,nome3,nome4,nome5;
    float preco1,preco2,preco3,preco4,preco5;
    string autor1,autor2,autor3;
    int numFaixas1;
    float duracao1;

    printf("-------- Livro 1 --------\n");
    printf("Digite o nome do livro:\n");
    getline(cin,nome1);
    printf("Digite o nome do autor do livro:\n");
    getline(cin,autor1);
    printf("Digite o preco do livro:\n");
    scanf("%f",&preco1);
    
    fflush(stdin);
    printf("-------- Livro 2 --------\n");
    printf("Digite o nome do livro:\n");
    getline(cin,nome2);
    printf("Digite o nome do autor do livro:\n");
    getline(cin,autor2);
    printf("Digite o preco do livro:\n");
    scanf("%f",&preco2);
    
    fflush(stdin);
    printf("-------- Livro 3 --------\n");
    printf("Digite o nome do livro:\n");
    getline(cin,nome3);
    printf("Digite o nome do autor do livro:\n");
    getline(cin,autor3);
    printf("Digite o preco do livro:\n");
    scanf("%f",&preco3);

    fflush(stdin);
    printf("-------- CD 1 --------\n");
    printf("Digite o nome do CD:\n");
    getline(cin,nome4);
    printf("Digite o numero de faixas:\n");
    scanf("%i",&numFaixas1);
    printf("Digite o preco do CD:\n");
    scanf("%f",&preco4);
    
    fflush(stdin);
    printf("-------- DVD --------\n");
    printf("Digite o nome do DVD:\n");
    getline(cin,nome5);
    printf("Digite a duracao:\n");
    scanf("%f",&duracao1);
    printf("Digite o preco do DVD:\n");
    scanf("%f",&preco5);
    
    loja[0]=  new livro(nome1,autor1,preco1); 
    loja[1] = new livro(nome2,autor2,preco2);   
    loja[2] = new livro(nome3,autor3,preco3);
    loja[3] = new CD(nome4,numFaixas1,preco4);
    loja[4] = new DVD(nome5,duracao1,preco5);

    for (int aux=0;aux<5;aux++){
        loja[aux]->toString();
    }
}