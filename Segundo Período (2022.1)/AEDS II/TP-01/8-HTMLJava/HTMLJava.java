
import java.io.*;
import java.net.*;
public class HTMLJava { 
    public static String getHtml(String endereco){ //Função fornecida no github para pegar o html de uma pagina
        URL url;
        InputStream is = null;
        BufferedReader br;
        String resp = "", line;
  
        try {
           url = new URL(endereco);
           is = url.openStream();  // throws an IOException
           br = new BufferedReader(new InputStreamReader(is));
  
           while ((line = br.readLine()) != null) {
              resp += line + "\n";
           }
        } catch (MalformedURLException mue) {
           mue.printStackTrace();
        } catch (IOException ioe) {
           ioe.printStackTrace();
        } 
  
        try {
           is.close();
        } catch (IOException ioe) {
           // nothing to see here
  
        }
  
        return resp;
    }

    public static boolean isFim(String s){ //Função para identificar quando o usuário digita "FIM" (em maiusculo)
        if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){ //Retorna verdadeiro se possuir 3 caracteres e forem "FIM"
             return true;
        }return false;
    }

    public static boolean isConsoante(char c){ //Retorna verdadeiro se o caracter for uma consoante e for uma letra minuscula (exclui maiusculos e caracteres especiais)
        if(c!='a' & c!='e' & c!='i' & c!='o' & c!='u' & c!='á'& c!='é'& c!='í'& c!='ó'& c!='ú'& c!='à'& c!='è'& c!='ì'& c!='ò'& c!='ù'& c!='ã'& c!='õ'& c!='â'& c!='ê'& c!='î'& c!='ô'& c!='û'&&(c>=97&&c<=122)){
            return true;
        }
        return false;
    }


    public static void main(String[] args){
        String nomePag;
        String endereço;
        String HTML;
        nomePag=MyIO.readLine();
        endereço=MyIO.readLine();
        int tamanho=0;
        HTML=getHtml(endereço); //Pega o tml da pagina 
 
        while(true){ //Define as variáveis no começo do loop para assegurar que os contadores sempre comecem com valor nulo
            int x1=0,x2=0,x3=0,x4=0,x5=0; //Vogais Nome das variáveis correspondem aos enunciados
            int x6=0,x7=0,x8=0,x9=0,x10=0; //Vogais com acento agudo
            int x11=0,x12=0,x13=0,x14=0,x15=0; //Vogais com crase
            int x16=0,x17=0,x18=0,x19=0,x20=0,x21=0,x22=0; //Vogais com til e acento circunflexo
            int x23=0; //Consoantes
            int x24=0; //<br>
            int x25=0; //<table>>
            String x26="";
            if(isFim(nomePag)==true){ //Termina o loop caso a entrada seja 'FIM'
                break;
            }
            tamanho=HTML.length(); //Tamanho do HTML
            for (int aux=0;aux<tamanho;aux++){ //Procura correspondências para as vogais e aumenta em uma unidade a cada correspondência
                if(HTML.charAt(aux)=='a'){x1++;}
                if((HTML.charAt(aux))=='e'){x2++;}
                if((HTML.charAt(aux))=='i'){x3++;}
                if((HTML.charAt(aux))=='o'){x4++;}
                if((HTML.charAt(aux))=='u'){x5++;}
                if((HTML.charAt(aux))=='á'){x6++;}
                if((HTML.charAt(aux))=='é'){x7++;}
                if((HTML.charAt(aux))=='í'){x8++;}
                if((HTML.charAt(aux))=='ó'){x9++;}
                if((HTML.charAt(aux))=='ú'){x10++;}
                if((HTML.charAt(aux))=='à'){x11++;}
                if((HTML.charAt(aux))=='è'){x12++;}
                if((HTML.charAt(aux))=='ì'){x13++;}
                if((HTML.charAt(aux))=='ò'){x14++;}
                if((HTML.charAt(aux))=='ù'){x15++;}
                if((HTML.charAt(aux))=='ã'){x16++;}
                if((HTML.charAt(aux))=='õ'){x17++;}
                if((HTML.charAt(aux))=='â'){x18++;}
                if((HTML.charAt(aux))=='ê'){x19++;}
                if((HTML.charAt(aux))=='î'){x20++;}
                if((HTML.charAt(aux))=='ô'){x21++;}
                if((HTML.charAt(aux))=='û'){x22++;}
                if(isConsoante(HTML.charAt(aux))==true){x23++;}
                if(HTML.charAt(aux)=='<'){ //Procura pela abertura de uma tag html
                    if(HTML.charAt(aux+1)=='b'&& HTML.charAt(aux+2)=='b'&& HTML.charAt(aux+3)=='>'){ //Confere se a tag é '<br>'
                        x24++;
                    }else if(HTML.charAt(aux+1)=='t' && HTML.charAt(aux+2)=='a' && HTML.charAt(aux+3)=='b' && HTML.charAt(aux+4)=='l' && HTML.charAt(aux+5)=='e' && HTML.charAt(aux+6)=='>'){
                        x25++; //Confere se a tag é '<table>'
                    }
                }
            }
            x1=x1-x25; //Tira as correspondências de 'a' nas tags '<table>'
            x2=x2-x25; //Tira as correspondências de 'e' nas tags '<table>'
            x23-=3*x25; //Tira as correspondências de consoantes nas tags '<table>'
            x23-=2*x24; //Tira as correspondências de consoantes nas tags '<br>'
            x26=nomePag;
            System.out.println("a("+x1+") "+"e("+x2+") "+"i("+x3+") "+"o("+x4+") "+"u("+x5+") "+"á("+x6+") "+"é("+x7+") "+"í("+x8+") "+"ó("+x9+") "+"ú("+x10+") "+"à("+x11+") "+"è("+x12+") "+"ì("+x13+") "+"ò("+x14+") "+"ù("+x15+") "+"ã("+x16+") "+"õ("+x17+") "+"â("+x18+") "+"ê("+x19+") "+"î("+x20+") "+"ô("+x21+") "+"û("+x22+") "+"consoante("+x23+") "+"<br>("+x24+") "+"<table>("+x25+") "+x26);
            nomePag=MyIO.readLine(); //Lê o proximo nome da paǵina
            if(isFim(nomePag)==true){ //Termina o loop caso a entrada seja 'FIM'
                break;
            }
            endereço=MyIO.readLine();//Lê o proximo endereço da pagina
            HTML=getHtml(endereço); //Redefine a variável HTML com o conteúdo da nova paǵina 
        }   
    }
    
}
