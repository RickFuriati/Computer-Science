
public class IsRecursivoJava {
    
    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
        }return false;
    }

    public static boolean isVogal(char c){
        if(c=='A' || c=='E' || c=='I' || c=='O'|| c=='U'){
            return true;
        }
        return false;
    }
    public static boolean isSimbolo(char c){
        if((c<65 || (c>=91&&c<=96)||c>=123)){
            return true;
        }
        return false;
    }
    public static boolean isFullVogal(String s){
        return isFullVogal(s, 0);
    }
    public static boolean isFullVogal(String s,int i){ 
        
        if(i==s.length()){ //Se o contador i for igual ao tamanho da string ela é composta somente por vogais
            return true;
        }else if(isVogal(s.charAt(i))==false){ //Caso a letra da string na posição 'i' for uma consoante retorna falso, a string nao é composta somente por vogais
            return false;
        }else{
            return isFullVogal(s, i+1); //Retorna a função na proxima posição da string 

        }
        
    }
    public static boolean isFullConsoante(String s){
        return isFullConsoante(s,0);
    }

    public static boolean isFullConsoante(String s, int i){ 
        
        if(i==s.length()){ //Se o contador i for igual ao tamanho da string ela é composta somente por consoantes
            return true;
        }else if ((isVogal(s.charAt(i))==true)||isSimbolo(s.charAt(i))==true){//Caso a letra da string na posição 'i' for uma vogal retorna falso, a string nao é composta somente por consoantes
            return false;
        }else{
            return isFullConsoante(s,i+1); //Retorna a função na proxima posição da string 
        }
    }

    public static boolean isInteiro(String s){
        return isInteiro(s,0);
    }
    public static boolean isInteiro(String s,int i){
        
        if(i==s.length()){
            return true;
        }else if(!(s.charAt(i)>=48 && s.charAt(i)<=57)){
            return false;
        }else{
            return isInteiro(s,i+1);
        }
    }

    public static boolean isReal(String s){ 
        int contador=0;
        int contadorSeparadores=0;
        for(int aux=0;aux<s.length();aux++){
            if((s.charAt(aux)>=48 && s.charAt(aux)<=57)||s.charAt(aux)=='.'||s.charAt(aux)==','){
                contador++;
                if(s.charAt(aux)=='.'||s.charAt(aux)==','){ //Caso o numero de vírgulas ou pontos seja maior que 1 retorna falso
                    contadorSeparadores++;
                }
            }
        }
        if(contadorSeparadores>1){
            return false;
        }
        if(contador==s.length()){
            return true;
        }
        return false;
    }

    public static void main(String[] args){
        String stringEntrada="";
        stringEntrada=MyIO.readLine(); //Le a primeira linha antes do loop começar
       
        String x1="";
        String x2="";
        String x3="";
        String x4="";

        while(true){
            if(isFim(stringEntrada)==true){
                break;
            }
            
            if(isFullVogal(stringEntrada.toUpperCase())==true){ //Atribui os valores de 'SIM' e 'NAO' as variáveis
                x1="SIM";
            }else if(isFullVogal(stringEntrada.toUpperCase())==false){
                x1="NAO";
            }
    
            if(isFullConsoante(stringEntrada.toUpperCase())==true){
                x2="SIM";
            }else if(isFullConsoante(stringEntrada.toUpperCase())==false){
                x2="NAO";
            }
    
            if(isInteiro(stringEntrada)==true){
                x3="SIM";
            }else if(isInteiro(stringEntrada)==false){
                x3="NAO";
            }
    
            if(isReal(stringEntrada)==true){
                x4="SIM";
            }else if(isReal(stringEntrada)==false){
                x4="NAO";
            }

            System.out.println(x1+" "+x2+" "+x3+" "+x4);
            stringEntrada=MyIO.readLine(); 
        }
    }

}

