import java.io.RandomAccessFile;

import javax.crypto.spec.RC2ParameterSpec;

public class ArquivoJava {
    public static void main(String[] args) throws Exception{
        int n=0;
        double num=0;
        n=MyIO.readInt();
        RandomAccessFile raf=new RandomAccessFile("Arquivo.txt","rw"); //Inicia o random access file como leitura e escrita
        for(int aux=1;aux<=n;aux++){  //executa o loop 'n' vezes lendo numeros reais (double) e os escreve no arquivo
            num=MyIO.readDouble();
            raf.writeDouble(num); // O método write foi utilizado para "escrever" os numeros com o menor numero de casas decimais possível
        }   
        raf.close(); //Fecha o arquivo

        raf=new RandomAccessFile("Arquivo.txt","r"); //Abre o random access file como modo leitura
        double numero=0; //Foi necessáiro criar outra variável para leitura ao contrário para trata-la na saída
        for(int aux=n-1;aux>=0;aux--){ 
            raf.seek(aux*8); //Busca o numero na posição 'aux' multiplicado por 8 que é o numero de bytes de um double
            numero=raf.readDouble(); //Le o double na posição indicada
            if(numero==(int)numero){ // Tratamento para que, caso o numero seja um inteiro sem casas decimais, nao seja colocado um '.0' ao final (diverge com o pub.out)
                System.out.println((int)numero); 
            }else{
            System.out.println(numero); //Printa o numero da posição na tela
            }
        }
        raf.close(); //Fecha o arquivo.
    }
}

