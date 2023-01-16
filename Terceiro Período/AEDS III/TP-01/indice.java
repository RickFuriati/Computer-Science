import java.io.IOException;
import java.io.RandomAccessFile;



public class indice extends arvoreBM {
    
    static arvoreBM indiceArvore(RandomAccessFile raf)throws IOException{
        arvoreBM arvore = new arvoreBM(5);
        double posicao=0;
        int tamanhoRegistro=0;
        int idChave=0;
        raf.seek(4);
        RandomAccessFile arvoreBMIndices = new RandomAccessFile("arvoreBMIndices.bin", "rw");
        while(raf.getFilePointer()<raf.length()){
            if(raf.readByte()==0){
                tamanhoRegistro=raf.readInt();
                idChave=raf.readInt();
                posicao=raf.getFilePointer();
                arvore.insert(idChave, posicao);
                System.out.println("idChave: "+idChave+" posicao: "+posicao);
                arvoreBMIndices.writeInt(idChave);
                arvoreBMIndices.writeDouble(posicao);
                raf.readUTF();
                int numEmails=raf.readInt();
                for(int i=0;i<numEmails;i++){
                    raf.readUTF();
                }
                raf.readUTF();
                raf.readUTF();
                raf.readUTF();
                raf.readUTF();
                raf.readInt();
                raf.readFloat();
            }else{
                raf.skipBytes(raf.readInt());
            }
        }
        return arvore;
    }

    
}
