#include <iostream>

/*Faça uma classe Animal com um método abstrato “fala”. Faça as classes Homem, Cão e Gato,
herdando de animal, redefinindo o método “fala” para retornar “Oi”, “Au au” e “Miau”, respecti-
vamente. Crie um vetor de 10 Animais e instancie Homens, Cães e Gatos nesse vetor. Faça um
loop por todos os animais do vetor, pedindo para eles falarem.*/

using namespace std;

class Animal{
    public:
    Animal(){};

    virtual void fala(){
        printf("Som de animalzinho :)\n");
    }
};

class Homem: public Animal{
    public:
    Homem(){};
    
    void fala(){
        printf("Oi\n");
    }
};

class Cao:public Animal{
    public:
    Cao(){};
     void fala(){
        printf("Au Au\n");
    }
};

class Gato:public Animal{
    public:
    Gato(){};
     void fala(){
        printf("Miau Miau\n");
    }
};

int main(void){
    Animal *vetor[10];
    vetor[0]= new Homem();
    vetor[1]= new Homem();
    vetor[2]= new Cao();
    vetor[3]= new Gato();
    vetor[4]= new Homem();
    vetor[5]= new Cao();
    vetor[6]= new Gato();
    vetor[7]= new Homem();
    vetor[8]= new Cao();
    vetor[9]= new Gato();
    
    for(int aux=0;aux<10;aux++){
        vetor[aux]->fala();
    }

    


}
