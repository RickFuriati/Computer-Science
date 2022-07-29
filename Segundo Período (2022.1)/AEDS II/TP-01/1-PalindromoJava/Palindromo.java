public class Palindromo{

    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
        }return false;
    }

    public static boolean isPalindromo(String s){
        int contador=0;
        boolean resultado=false;
        for(int aux=0;aux<s.length();aux++){
            if(s.charAt(aux)==s.charAt(s.length()-aux-1)){ //Percorre a string comparando a letra da primeira posição com a letra da ultima posição -aux (quantidade de vezes do loop) e -1 (para desconsiderar a primeira posição e as posições ja percorridas pelo loop )
                contador++;//Aumenta toda vez que a letra analisada (do incio para o final) for igual a sua correspondente (do final para o inicio).
            }
        }
        if (contador==s.length()){ //Prova real: Caso o contador seja igual ao comprimento da string a stirng é um palíndromo
            resultado=true;
        }
        return resultado;
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