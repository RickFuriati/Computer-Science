#include<stdio.h>
#include<stdlib.h>

int main(void){
   char escolhaUsuario;
    int numeroUsuario,numeroAleatorio,pontosUsuario=0,pontosComputador=0,soma=0;
    for (int rodadas=1;rodadas<=3;rodadas++){ //Loop para fazer 3 rodadas 
    printf("~~~~~~~~~~~~~~~~~~~~~~RODADA %i ~~~~~~~~~~~~~~~~~~~~~~\n",rodadas);
    srand(time(NULL));
        
      
        printf("Escolha entre par ou impar.('p'-par 'i'-impar)\n");
        scanf(" %c",&escolhaUsuario);
      
        printf("Digite um numero qualquer.\n");
        scanf("%i",&numeroUsuario);
        

    if(escolhaUsuario=='p'){
        numeroAleatorio=rand();
        soma=numeroUsuario+numeroAleatorio;
        printf("A soma dos dois numeros corresponde a: %i.\n",soma);
        if (soma%2==0){
            printf("Voce venceu a rodada.\n");
            pontosUsuario++;
        }else{
            printf("O computador venceu a rodada.\n");
            pontosComputador++;
        }
            
    }else{
        numeroAleatorio=rand();
        soma=numeroUsuario+numeroAleatorio;
        printf("A soma dos dois numeros corresponde a: %i.\n",soma);
        if (soma%2==0){
        printf("O computador venceu a rodada.\n");
        pontosUsuario++;
        }else{
        printf("Voce venceu a rodada.\n");
        pontosComputador++;
        }
        }
        
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~RESULTADO DA BATALHA EPICA~~~~~~~~~~~~~~~~~~~~~~\n");
    if (pontosUsuario>pontosComputador){
        printf("Voce foi o vencedor. Provou por A+B que as maquinas nunca serao superiores aos humanos!!!");
    }else 
        printf("O computador ganhou... a humanidade esta fadada a ser superada por suas criacoes MUAHAHAHA");
    
}
