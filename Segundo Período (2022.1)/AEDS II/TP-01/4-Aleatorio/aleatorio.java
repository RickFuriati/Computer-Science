import java.util.Random;

public class aleatorio {
    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
        }return false;
    }
    public static String inverteLetras(String s, char c1, char c2){ //Recebe uma string e dois caracteres 
        char[] stringAux=s.toCharArray(); //Converte a string em um array de chars (manipular caracteres individuais da string da erro ;-;)
        for (int aux=0;aux<s.length();aux++){   //Percorre a string e troca todas as correspondências do caracter 1 (c1) pelo caracter 2 (c2)
            if(stringAux[aux]==c1){
                stringAux[aux]=c2;
            }
        }
        
        return String.valueOf(stringAux); //Converte a o vetor de chars resultante em uma string 
    }


    public static void main(String[] args){
        String stringEntrada="";
        Random gerador= new Random(); //Cria um gerador e a semente indicada (4 neste caso)
        gerador.setSeed(4);
        char c1;
        char c2;
        stringEntrada=MyIO.readLine(); //Le a primeira linha antes do loop começar
       
        while(true){
            if(isFim(stringEntrada)==true){ //Caso a entrada for FIM o loop é terminado
                break;
            }  
            c1=(char)('a'+(Math.abs(gerador.nextInt())%26)); //Gera caracteres aleatórios a cada execução do loop
            c2=(char)('a'+(Math.abs(gerador.nextInt())%26));
            MyIO.println(inverteLetras(stringEntrada, c1, c2)); //Printa a string resultante com os caracteres trocados
            stringEntrada=MyIO.readLine(); //Le uma nova string para continuar com o loop
        }

    }
}

