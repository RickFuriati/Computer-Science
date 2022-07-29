public class PalindromoRecursivo{

    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
        }return false;
    }

    public static boolean isPalindromo(String s){ //Inicia a função pela primeira vez a partir da posição 0 (i=0)
        return isPalindromo(s,0);
    }
    
    public static boolean isPalindromo(String s, int i){ //Recebe uma string e uma posição 
        boolean resposta;
        if(i==s.length()){  //Se a posição for igual ao tamanho a string é um palindromo
            resposta=true;
        }else if(s.charAt(i)!=s.charAt(s.length()-i-1)){ //Caso a letra da posição 'i' seja diferente da sua correspondente a partir do final do vetor a string nao é um palindromo
            resposta=false;
        }else{
            resposta=isPalindromo(s,i+1); //CHama a função novamente mas com a proxima posição (recursividade)
        }
        return resposta;
    }
    
    public static void main (String[] args){
        String entrada="";

        while(isFim(entrada)==false){
            entrada=MyIO.readLine();
            if(isPalindromo(entrada)==true){
                System.out.println("SIM");
            }else if ((isPalindromo(entrada)==false) && (isFim(entrada)==false)){ //Segunda expressão foi necessária para que quando o usuário digite "FIM" a resposta nao seja exibida na tela 
                System.out.println("NAO");

            }
        }
    }
}