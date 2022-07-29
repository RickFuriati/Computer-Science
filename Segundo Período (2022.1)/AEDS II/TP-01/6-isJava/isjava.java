
public class isjava {
    
    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
            return true;
        }return false;
    }

    public static boolean isFullVogal(String s){ 
        int contador=0;
        for(int aux=0;aux<s.length();aux++){ //Aumenta o contador toda vez que o caractere na posição 'aux' é uma vogal
            if(s.charAt(aux)=='A'||s.charAt(aux)=='E'||s.charAt(aux)=='I'||s.charAt(aux)=='O'||s.charAt(aux)=='U'){
                contador++;
            }
        }
        if(contador==s.length()){ //Confere se o numero de correspondencias é igual ao tamanho da string (se for verdadeiro é composta somente por vogais)
            return true;
        }
        return false;
    }

    public static boolean isFullConsoante(String s){ 
        int contador=0;
        for(int aux=0;aux<s.length();aux++){ //Confere se não é uma vogal
            if(s.charAt(aux)!='A' & s.charAt(aux)!='E' & s.charAt(aux)!='I' & s.charAt(aux)!='O' & s.charAt(aux)!='U'){
                contador++;
            }
            if(s.charAt(aux)<64 ||(s.charAt(aux)>=91&&s.charAt(aux)<=96)||s.charAt(aux)>=123){ //Confere se não é um símbolo ou numero
                return false;
            }
        }
        if(contador==s.length()){//Confere se o numero de correspondencias é igual ao tamanho da string (se for verdadeiro é composta somente por consoantes)
            return true;
        }
        return false;
    }

    public static boolean isInteiro(String s){
        int contador=0; 
        for(int aux=0;aux<s.length();aux++){ //Confere se é um inteiro a partir da tabela ASCII
            if(s.charAt(aux)>=48 && s.charAt(aux)<=57){
                contador++;
            }
        }
        if(contador==s.length()){ //Confere se o numero de correspondencias é igual ao tamanho da string 
            return true;
        }
        return false;
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

            if(isFullVogal((stringEntrada.toUpperCase()))==true){ //Atribui os valores de 'SIM' e 'NAO' as variáveis
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
