#include <iostream>
#include <stdexcept>

/*Crie um programa que receba n números e some esses numeros enquanto a soma não for superior
a 100. O programa deverá imprimir o valor somado (antes de atingir o número maior que 100) e
deverá informar quantos números foram somados e qual a média. Refaça seu programa utilizando
as seguintes regras:
a. Utilize os tratamentos de exceção para lidar com a entrada de dados.
b. Quando a soma for superior a 100, o programa deverá gerar uma exceção criada pelo progra-
mador (veja transparência da aula pra ver como fazer), com nome ExcecaoAcimaDeCem.
c. Lance essa exceção, com o uso de throws.*/

using namespace std;

class ExcecaoAcimaDeCem: public exception{
    public:
    string errorMsg(){
        return "A soma passou de 100 :)";
    }
};
int main(void){
    float soma=0;
    int numeroAtual=0;

    while (1){
        try{
            float numero;
            printf("Digite um numero qualquer:\n");
            scanf("%f",&numero);

            soma+=numero;
            numeroAtual++;

            printf("A soma encontra-se em: %.2f\n",soma);
            printf("Ate o momento a soma foi efetuada %i vezes.\n",numeroAtual);
        
            if(soma>100){
                throw ExcecaoAcimaDeCem();
            }        
        }
        catch (ExcecaoAcimaDeCem x){
            printf("%s\n",x.errorMsg().c_str());
            return false;
        }
    }
}