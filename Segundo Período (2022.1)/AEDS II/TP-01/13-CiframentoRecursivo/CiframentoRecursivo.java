

public class CiframentoRecursivo {
    
    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
    }return false;
    }
    
    public static String Ciframento(String s,int k){
        return Ciframento (s,k,0);
    }
    
    public static String Ciframento(String s,int k,int i){ //Recebe uma string e a constante K que será usada na cifra (neste caso k vale 3)
        String cifra="";
        //char[] c1=s.toCharArray();
        if(i<s.length()){
            cifra+=(char)(s.charAt(i)+k);
            cifra+=Ciframento(s,k,i+1);
        }
        
        
        
        /*char[] c1=s.toCharArray(); //Converte a string em um array de chars (manipular caracteres individuais da string da erro ;-;)
       
        for(int aux=0;aux<comprimento;aux++){ //Aumenta o valor do caracter em k (+3)
            c1[aux]+=k;
        }  
        return String.valueOf(c1);  */
        return cifra;  
    }

    public static void main (String[] args){
        
        int k=3;
        String stringEntrada="";
        stringEntrada=MyIO.readLine();
        while(true){
            if(isFim(stringEntrada)==true){
                break;
            }
            MyIO.println(Ciframento(stringEntrada,k)); //É necessário usar o MYio para printar por que o system.out nao printa os caracteres especiais corretamente
            stringEntrada=MyIO.readLine(); 
        }
    }


}
