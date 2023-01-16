import java.io.CharArrayReader;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.function.Predicate;

import javax.swing.plaf.basic.BasicBorders.RadioButtonBorder;

public class lzw {

    public static void createTxt(String fileName) throws IOException{ //Método para criar um arquivo txt a partir da leitura do arquivo de dados (em binário)
        RandomAccessFile raf = new RandomAccessFile(fileName, "r");
        RandomAccessFile arq = new RandomAccessFile("copia.txt", "rw");
        
        String[] emails; 

        raf.seek(4);
        while(raf.getFilePointer() < raf.length()) { //Lê o arquivo byte a byte e escreve a string resultante no arquivo "copia.txt"
            byte lapide = raf.readByte();
            if (lapide == 0) { // se o registro não estiver excluído
                int tam = raf.readInt();
                arq.writeChars(Integer.toString(tam));
                arq.writeChar(' ');
                int id = raf.readInt();
                arq.writeChars(Integer.toString(id));
                arq.writeChar(' ');
                String nome = raf.readUTF();
                arq.writeChars(nome);
                arq.writeChar(' ');
                int qtdEmails = raf.readInt();
                arq.writeChars(Integer.toString(qtdEmails));
                arq.writeChar(' ');
                emails = new String[qtdEmails];
                for (int i = 0; i < qtdEmails; i++) {
                    emails[i] = raf.readUTF();
                    arq.writeChars(emails[i]);
                    arq.writeChar(' ');
                }                
                String usuario = raf.readUTF();
                arq.writeChars(usuario);
                arq.writeChar(' ');
                String senha = raf.readUTF();
                arq.writeChars(senha);
                arq.writeChar(' ');
                String cpf = raf.readUTF();
                arq.writeChars(cpf);
                arq.writeChar(' ');
                String cidade = raf.readUTF();
                arq.writeChars(cidade);
                arq.writeChar(' ');
                int tranferencias = raf.readInt();
                arq.writeChars(Integer.toString(tranferencias));
                arq.writeChar(' ');
                float saldo = raf.readFloat();
                arq.writeChars(Float.toString(saldo));
                arq.writeChar(' ');
                arq.writeChars("|");

            } else { // se o registro estiver excluído
                raf.skipBytes(raf.readInt());
            }
        }
        
        raf.close();
        arq.close();
        
    }

    public static class token{ //Classe para armazenar os tokens
        int posic;
        String simbolo;

        public token(int posic, String simbolo){ //Construtor convencional
            this.posic = posic;
            this.simbolo=simbolo;
        }

       
    }

    public static ArrayList<String> criaDicionario(){ //Metodo para iniciar o dicionario com os 256 caracteres ASCII
        ArrayList<String> dicionario = new ArrayList<String>();
        for (int i = 0; i < 256; i++){
            dicionario.add(Character.toString((char)i));
        }
            
        return dicionario;
    }

    
    
    public static ArrayList<String> compressao(String fileName) throws IOException{ //Metodo de compressao que recebe o nome do arquivo a ser comprimido
        long start = System.currentTimeMillis();
        createTxt(fileName); //Metodo que transforma o arquivo de bytes em um arquivo txt 
        RandomAccessFile raf2 = new RandomAccessFile("copia.txt","r"); //Arquivo em txt auxiliar para leitura 
        RandomAccessFile raf3 = new RandomAccessFile(fileName+"_comprimido.bin","rw"); //Arquivo resultante após a compressão dos dados
        String dados = new String(); 
        while(raf2.getFilePointer() < raf2.length()) { //Lê os dados caracter a caracter 
            dados+=raf2.readChar();
        }
        //System.out.println(dados);
        ArrayList<String> dicionario=criaDicionario(); //Inicia o dicionário

        int i=0; //Variavel que controla o loop
        int comecoPrefixo=0; //Posição inicial do prefixo
        int finalPrefixo=1; //Posicão final do prefixo
        String prefixo=""; //Prefixo
        String prefixoValido=""; //Prefixo válido (ultimo prefixo que foi encontrado no dicionário)
        String dadosAux=dados; //String auxiliar para manipulação dos dados
        String simbolo=""; //Simbolo (corresponde ao caracter mais a direita do prefixo, contido no token após encontrar uma falha)
        String arquivoFinal=new String();
        //System.out.println("Tamanho:"+dados.length());
        
        String token = new String();
        
        while(i<dados.length()){ //Percorre toda a string de dados  
            
            prefixo=dadosAux.substring(comecoPrefixo,finalPrefixo); //Prefixo a ser buscado no dicionario 
            simbolo=Character.toString(prefixo.charAt(prefixo.length()-1)); //Simbolo mais a direita do prefixo
            
            //System.out.println("Prefixo:"+prefixo);
            //System.out.println("Simbolo:"+simbolo);

            if(dicionario.contains(prefixo)==true){ //Verifica se o dicionario contém o prefixo 
                finalPrefixo++; //Caso contenha avança o final do prefixo em uma posição na string de dados (novo prefixo aumenta em um caracter o prefixo anterior)
            }else{ //Caso o dicionario não contenha o prefixo é necessário adiciona-lo ao diciionario e gerar um token
                dicionario.add(prefixo); //Adiciona o prefixo ao dicionario
                prefixoValido=dadosAux.substring(comecoPrefixo,finalPrefixo-1); //Ultimo prefixo encontrado no dicionario
                token falha=new token(dicionario.indexOf(prefixoValido),simbolo); //Gera um token para falha
                //System.out.println("["+falha.posic+";"+falha.simbolo+"] ");                
                raf3.writeShort(falha.posic); //Escreve no arquivo compactado a posição da falha 
                raf3.writeShort(dicionario.indexOf(simbolo)); //Escreve no arquivo compactado a posição do simbolo 
                
                arquivoFinal+=Integer.toString(falha.posic)+",";
                arquivoFinal+=Integer.toString(dicionario.indexOf(simbolo))+",";
                comecoPrefixo=finalPrefixo; //Novo prefixo começa na posição final do prefixo anterior
                finalPrefixo=comecoPrefixo+1; //Aumenta em uma posição o final do prefixo para que o primeiro prefixo comparado tenha sempre tamanho =1 
               
            }
            i++;
        }
        raf2.close();
        raf3.close();
        long time = (System.currentTimeMillis() - start);
        System.out.println("Arquivo resultante após a compressão:");
        System.out.println(arquivoFinal);
        System.out.println("\nTempo de execução: " + time + " milissegundos");
       
        float tamanhoOriginal = new File(fileName).length(); // Calcula o tamanho do arquivo original
        float tamanhoFinal = new File(fileName+"_comprimido.bin").length(); // Calcula o tamanho do arquivo compactado

        System.out.println("Tamanho do arquivo original: " + tamanhoOriginal + " bytes"); // Imprime o tamanho do arquivo original
        System.out.println("Tamanho do arquivo compactado: " + tamanhoFinal + " bytes"); // Imprime o tamanho do arquivo compactado
        System.out.println("Taxa de compressão: " + (tamanhoOriginal / tamanhoFinal) + " vezes"); // Imprime a taxa de compressão
        
        File copia= new File("copia.txt");
        copia.delete();
        return dicionario; //Retorna o resultado resultante após a compressão
    }

    public static void decompressao(String fileName, ArrayList<String> dicionario) throws IOException{ //Método para decompressão que recebe o nome do arquivo original (busca o arquivo comprimido de acordo com a convenção de nomeclatura para facilitar testes)
        long start = System.currentTimeMillis();
        RandomAccessFile raf = new RandomAccessFile(fileName+"_comprimido.bin","r");
        String dadosOriginais=new String(); //String para armazenar os dados originais (após decompressão)
        int posic=0;
        
        while(raf.getFilePointer() < raf.length()) { //Lê o arquivo comprimido buscando no dicionario pela posição lida
            posic=raf.readShort();
            dadosOriginais+=dicionario.get(posic); //Gera a string final a partir das buscas no dicionário
        } 
        System.out.println("Arquivo resultante após a decompressão:"); 
        System.out.println(dadosOriginais);         
        raf.close();
        long time = (System.currentTimeMillis() - start);
        System.out.println("\nTempo de execução: " + time + " milissegundos");
    }

    public static void mostraDicionario(ArrayList<String> dicionario){ //Método para mostrar o dicionário resultantr
        for(int i=0;i<dicionario.size();i++){
            System.out.println("["+i+";"+dicionario.get(i)+"]");
        }
    }

    
}