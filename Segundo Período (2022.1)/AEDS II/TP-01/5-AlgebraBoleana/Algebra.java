import javax.management.StringValueExp;

public class Algebra {
    public static String tiraEspacos(String s){ //Função para retirar os espaços da string de entrada para facilitar a manipulação das variáveis
        s=s.replace(" ","");
        return s;
    }
    public static String replaceA(String s,String valor){ //Troca o caractere 'A' pelo seu valor (em forma de string)
         s=s.replace("A",valor); 
        return s;
    }
    public static String replaceB(String s,String valor){//Troca o caractere 'B' pelo seu valor (em forma de string)
        s=s.replace("B",valor);
       return s;
    }
    public static String replaceC(String s,String valor){//Troca o caractere 'C' pelo seu valor (em forma de string)
        s=s.replace("C",valor);
       return s;
    }   

    public static String nega(String s){ //Troca os valores de 'not()' que podem ser resolvidos sem outros operadores lógicos
        s=s.replace("not(0)","1");
        s=s.replace("not(1)","0");
        return s;
    }

    public static String and(String s){
        String operacaoAnd="";
        int and=s.lastIndexOf("and"); //Busca o ultimo índice de uma string 'and'
        int finalAnd=s.indexOf(")", and); //Busca o índice do primeiro parênteses que encontrar a partir da posição do and (equação acima)
        operacaoAnd=s.substring(and,finalAnd+1); //Cria uma string somente com a operação 'and()' a ser efetuada, foi necessário somar 1 ao final para incluir o parênteses na string da operação
        int resultado=1; //O resultado é atribuido por padrão como 1
        for(int aux=0;aux<operacaoAnd.length();aux++){
            if(operacaoAnd.charAt(aux)=='0'){ //Ao percorrer a string com a expressão procura por um valor igual a '0' que zera o valor da operação lógica
                resultado=0;
            }
        }
        s=s.replace(operacaoAnd,String.valueOf(resultado)); //Substitui a expressao encontrada pelo resultado calculado no loop acima
        return s; //Retorna a string com a operação 'and' trocada pelo seu resultado 
    }

    public static String or(String s){
        String operacaoOr="";
        int or=s.lastIndexOf("or"); //Busca o ultimo índice de uma string 'or'
        int finalOr=s.indexOf(")", or);//Busca o índice do primeiro parênteses que encontrar a partir da posição do or (equação acima)
        operacaoOr=s.substring(or,finalOr+1);//Cria uma string somente com a operação 'or' a ser efetuada, foi necessário somar 1 ao final para incluir o parênteses na string da operação
        int resultado=0; //Resultado é atribuído por padrao como 0
        for(int aux=0;aux<operacaoOr.length();aux++){
            if(operacaoOr.charAt(aux)=='1'){ //Ao percorrer a string com a expressão procura por um valor igual a '1' que faz operação lógica passar a ter valor 1
                resultado=1;
            }
        }
        s=s.replace(operacaoOr,String.valueOf(resultado)); //Substitui a expressao encontrada pelo resultado calculado no loop acima
        return s;//Retorna a string com a operação 'or' trocada pelo seu resultado 
    }

    public static String ultimaExp(String s){ //Retorna qual das expressões lógicas encontra-se na maior posição da string (ultima operação)
        int and=s.lastIndexOf("and");   //Realizar as operações "de trás para frente" assegura que a ordem dos parênteses e operações nao seja alterada
        int or=s.lastIndexOf("or");
        int not=s.lastIndexOf("not");
        String resposta="";
        if(and>or && and>not){ 
            resposta="and";
        }else if(or>and && or>not){
            resposta="or";
        }else if(not>or && not>and){
            resposta="not";
        }
        return resposta;
    }
    

    public static void main(String[] args){
        int n=0;
        String entrada="";
        String expressao="";
        n=MyIO.readInt();
        
        while(true){
            if(n==0){ //Condição de parada do loop: Quando a entrada de quantos operadores for igual a 0
                break;
            }
            int array[]=new int[n]; //Cria um vetor para armazenar os valores das variáveis atribuídos pelo usuário
            for(int aux=0;aux<n;aux++){
                array[aux]=MyIO.readInt(); //Preenche o vetor criado no loop
            }
            entrada=MyIO.readLine(); //Lê a expressão boleana em si
            entrada=tiraEspacos(entrada);//Retira os espaços da string de entrada
            if(n==1){ //atribui os valores de acordo com o numero de variáveis (sendo o máximo de 3 variáveis, maior limitação do programa XD)
                entrada=replaceA(entrada,String.valueOf(array[0]));
            }else if(n==2){
                entrada=replaceA(entrada,String.valueOf(array[0]));
                entrada=replaceB(entrada,String.valueOf(array[1]));
            }else if(n==3){
                entrada=replaceA(entrada,String.valueOf(array[0]));
                entrada=replaceB(entrada,String.valueOf(array[1]));
                entrada=replaceC(entrada,String.valueOf(array[2]));
            }
            entrada=nega(entrada);//Nega todos os valores de not que não requerem operações 
            while(entrada.length()!=1){ //Busca pela ultima expressão até que o tamanho da string seja igual a 1 (corresponde ao resultado)
                String ultimaExp=ultimaExp(entrada); //A cada chamada de operador lógico a string de entrada é reduzida com as respostas da operação efetuada
                if(ultimaExp=="and"){
                    entrada=and(entrada);
                }else if(ultimaExp=="or"){
                    entrada=or(entrada);
                }else if(ultimaExp=="not"){
                    entrada=nega(entrada);
                }
            }
            expressao=entrada; //Atribui a entrada a uma variável auxiliar com a expressão final
            System.out.println(expressao); //Printa o resultado das operações boleanas
            n=MyIO.readInt(); //Lê a proxima quantidade de variáveis para iniciar o próximo loop
        }
    }
}

