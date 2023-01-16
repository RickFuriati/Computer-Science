import java.util.Scanner;
 
class parser {
 
    public static void main(String[] args) {
       
        Scanner scr = new Scanner(System.in);
 
        // ----------------------------------- //
 
        scr.nextLine(); // skip first line
 
        String input = scr.nextLine();
 
        int x = 0, y = 0;
 
        while(!input.equals("fim.")) { //lê até que a ultima linha seja "fim."
 
            if(input.charAt(0) == 'X') x = Integer.parseInt(input.substring(2, input.length() - 1), 16); //Caso o primeiro caracter da linha seja X ou Y transforma o valor (string) para hexadecimal
            else if(input.charAt(0) == 'Y') y = Integer.parseInt(input.substring(2, input.length() - 1), 16);
            else if(input.charAt(0) == 'W') { // Caso o primeiro caracter seja 'W' a linha corresponde a uma operação
               
                String op = input.substring(2, input.length() - 1);
                int code = 0;
 
                // Cria um código para cada operação disponível
                if(op.equals("An")) code = 0;
                else if(op.equals("nAoB")) code = 1;
                else if(op.equals("AnB")) code = 2;
                else if(op.equals("zeroL")) code = 3;
                else if(op.equals("nAeB")) code = 4;
                else if(op.equals("Bn")) code = 5;
                else if(op.equals("AxB")) code = 6;
                else if(op.equals("ABn")) code = 7;
                else if(op.equals("AnoB")) code = 8;
                else if(op.equals("nAxB")) code = 9;
                else if(op.equals("copiaB")) code = 10;
                else if(op.equals("AB")) code = 11;
                else if(op.equals("umL")) code = 12;
                else if(op.equals("AoBn")) code = 13;
                else if(op.equals("AoB")) code = 14;
                else if(op.equals("copiaA")) code = 15;
 
                //Gera a saída com o padrão XYOPcode
                System.out.println(Integer.toHexString(x).toUpperCase() + Integer.toHexString(y).toUpperCase() + Integer.toHexString(code).toUpperCase());
            }
           
 
            // --------------------- //
 
            input = scr.nextLine();
        }
 
        // ----------------------------------- //
 
        scr.close();
    }
}
