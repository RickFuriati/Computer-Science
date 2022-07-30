#include <stdio.h>
#include <string.h>
/*Fazer um programa para simular uma agenda de telefones. Para cada contato deve-se ter os seguintes dados:
✦ Nome
✦ E-mail
✦ Telefone (uma estrutura a parte contendo campo para DDD e número)
✦ Data de aniversário (uma estrutura a parte contendo campo para dia,
mês, ano)
✦ Observação : Uma linha (string) para alguma observação especial.
1. Definir a estrutura acima.
2. Declarar a variável agenda (array) de contatos.
3. Criar o menu para:
a) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
b) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse mês.
c) Definir um bloco de instruções insere pessoa.
Caso o array esteja totalmente preenchido, informar agenda cheia
d) Definir um bloco de instruções imprime agenda com as opções:
i) imprime nome, telefone e e-mail
ii) imprime todos os dados. */

typedef struct{
    int DDD;
    int numero;
}telefone;

typedef struct{
    int dia;
    int mes;
    int ano;
}data_nascimento;

typedef struct{
    char nome[20];
    char email[20];
    telefone;
    data_nascimento;
    char observacao[30];
}contato;


int main (void){
    int numeroContatos;
    char respostaMenu;
    printf("------------- Agenda em C -------------\n ");
    printf("Quantos contatos gostaria de criar?\n");
    scanf("%i",&numeroContatos);

    contato agenda[numeroContatos];

    for (int aux=0;aux<numeroContatos;aux++){
        printf("------------- Contato %i -------------\n",aux+1);
        printf("Digite o nome do contato:\n");
        scanf(" %[^\n]s",agenda[aux].nome);
        printf("Digite o email do contato:\n");
        scanf(" %[^\n]s",agenda[aux].email);
        printf("Digite o DDD do telefone do contato:\n");
        scanf("%i",&agenda[aux].DDD);
        printf("Digite o numero do telefone do contato:\n");
        scanf("%i",&agenda[aux].numero);
        printf("Digite o ano do nascimento do contato:\n");
        scanf("%i",&agenda[aux].ano);
        printf("Digite o mes do nascimento do contato:\n");
        scanf("%i",&agenda[aux].mes);
        printf("Digite o dia do nascimento do contato:\n");
        scanf("%i",&agenda[aux].dia);
        printf("Digite uma observacao para o contato:\n");
        scanf(" %[^\n]s",agenda[aux].observacao);
    }
    fflush(stdin);
    printf("------------- Menu de Acoes -------------\n");
    printf("Digite 'a' para buscar na agenda por um nome.\n");
    printf("Digite 'b' para buscar as pessoas que nasceram em um determinado mes.\n");
    printf("Digite 'c' para adicionar um nome na agenda.\n");
    printf("Digite 'd' para exibir os dados da agenda.\n");
    scanf("%c",&respostaMenu);
    if (respostaMenu=='a'){
        char nomeBusca[20];
        printf("Digite o nome a ser buscado:\n");
        scanf(" %[^\n]s",nomeBusca);
        printf("O(s) contatos de nome %s:\n",nomeBusca);
        for(int aux=0;aux<numeroContatos;aux++){
            if(strcmp(nomeBusca,agenda[aux].nome)==0){
                printf("\nNome: %s \n",agenda[aux].nome);
                printf("E-mail:%s\n",agenda[aux].email);
                printf("Telefone: (%i)%i\n",agenda[aux].DDD,agenda[aux].numero);
                printf("Data de Nascimento: %i/%i/%i\n",agenda[aux].dia,agenda[aux].mes,agenda[aux].ano);
                printf("Observacao:%s\n",agenda[aux].observacao);
            }else{
                printf("a\n");
            }
        }
    }else if(respostaMenu=='b'){
        int mesBusca;
        printf("Digite o mes a ser buscado:\n");
        scanf("%i",&mesBusca);
        printf("O(s) contatos que nasceram no mes %i:\n",mesBusca);
        for (int aux=0;aux<numeroContatos;aux++){
            if(agenda[aux].mes==mesBusca){
                printf("\nNome: %s \n",agenda[aux].nome);
                printf("E-mail: %s\n",agenda[aux].email);
                printf("Telefone: (%i)%i\n",agenda[aux].DDD,agenda[aux].numero);
                printf("Data de Nascimento: %i/%i/%i\n",agenda[aux].dia,agenda[aux].mes,agenda[aux].ano);
                printf("Observacao: %s\n",agenda[aux].observacao);
            }
        }
    }else if (respostaMenu=='c'){
        printf("A agenda esta cheia.\n");
    }else if (respostaMenu=='d'){
        int respostaD;
        printf("Digite 1 para exibir nome, telefone e e-mail.\n");
        printf("Digite 2 para exibir todos os dados.\n");
        scanf("%i",&respostaD);
        if (respostaD==1){
            for(int aux=0;aux<numeroContatos;aux++){
                printf("\nNome: %s \n",agenda[aux].nome);
                printf("E-mail: %s\n",agenda[aux].email);
                printf("Telefone: (%i)%i\n",agenda[aux].DDD,agenda[aux].numero);
            }
        }else if (respostaD==2){
            for(int aux=0;aux<numeroContatos;aux++){
                printf("\nNome: %s \n",agenda[aux].nome);
                printf("E-mail: %s\n",agenda[aux].email);
                printf("Telefone: (%i)%i\n",agenda[aux].DDD,agenda[aux].numero);
                printf("Data de Nascimento: %i/%i/%i\n",agenda[aux].dia,agenda[aux].mes,agenda[aux].ano);
                printf("Observacao: %s\n",agenda[aux].observacao);
            }
        }
    }
}