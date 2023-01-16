import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;

import javax.print.DocFlavor.BYTE_ARRAY;

public class CRUD {
    static int ultimoID=0;

       public static int getUltimoID(){
        return ultimoID;
       }

        public static boolean create(RandomAccessFile raf, contaBancaria conta)  {

            try {
                raf.seek(raf.length()); // Posiciona o ponteiro no final do arquivo
                raf.writeByte(0); // Escreve a lapide (0 = ativo)
                raf.writeInt(conta.toByteArray().length); // Escreve o tamanho do registro
                raf.writeInt(conta.getID()); // Escreve o id da conta
                raf.writeUTF(conta.getNome()); // Escreve o nome da pessoa
                raf.writeInt(conta.getNumEmails()); // Escreve a quantidade de emails
                for (int i = 0; i < conta.getNumEmails(); i++) { // Escreve os emails
                    raf.writeUTF(conta.getEmail()[i]); 
                }
                raf.writeUTF(conta.getNomeUsuario()); // Escreve o nome de usuario
                raf.writeUTF(conta.getSenha()); // Escreve a senha
                raf.writeUTF(conta.getCPF()); // Escreve o cpf
                raf.writeUTF(conta.getCidade()); // Escreve a cidade
                raf.writeInt(conta.getTransferenciasRealizadas()); // Escreve a quantidade de transferencias realizadas
                raf.writeFloat(conta.getSaldo()); // Escreve o saldo da conta
    
                raf.seek(0); // Posiciona o ponteiro no inicio do arquivo
                raf.writeInt(ultimoID); // Atualiza o ultimo id
    
                return true;
            } catch (Exception e) {
                System.out.println("-> Erro ao criar registro!");
                return false;
            }

        }

        public static contaBancaria readID(RandomAccessFile raf, int ID) throws IOException { //Busca por um ID e retorna uma conta com o ID buscado
            raf.seek(4);
            int tamanhoRegistro;
            int idBusca = 0;
            contaBancaria contaAux = new contaBancaria();
            while (raf.getFilePointer() < raf.length()) {
                if (raf.readByte() == 0) {
                    tamanhoRegistro = raf.readInt();

                    idBusca = raf.readInt();

                    if (idBusca == ID) {
                        contaAux.setID(idBusca);
                        contaAux.setNome(raf.readUTF());
                        contaAux.setNumEmails(raf.readInt());
                        String[] emails = new String[contaAux.getNumEmails()];
                        for (int i = 0; i < contaAux.getNumEmails(); i++) {
                            emails[i] = raf.readUTF();
                        }
                        contaAux.setEmail(emails);
                        contaAux.setNomeUsuario(raf.readUTF());
                        contaAux.setSenha(raf.readUTF());
                        contaAux.setCPF(raf.readUTF());
                        contaAux.setCidade(raf.readUTF());
                        contaAux.setTransferencias(raf.readInt());
                        contaAux.setSaldo(raf.readFloat());
                        return contaAux;
                    } else {
                        raf.skipBytes(tamanhoRegistro - 4);
                    }
                } else {
                    raf.skipBytes(raf.readInt());
                }
            }
            return null;
        }

        public static contaBancaria readName(RandomAccessFile raf, String nomeBusca) { //Busca por um nome e retorna uma conta com os dados correspondentes
           try{ 
                contaBancaria contaAux = new contaBancaria();
                
                boolean status=false;
                raf.seek(4);
                while(raf.getFilePointer() < raf.length() && !status){
                    if(raf.readByte() == 0){
                        raf.readInt();
                        contaAux.setID(raf.readInt());
                        contaAux.setNome(raf.readUTF());
                        contaAux.setNumEmails(raf.readInt());
                        String[] emails = new String[contaAux.getNumEmails()];
                        for(int i=0; i<contaAux.getNumEmails(); i++){
                            emails[i] = raf.readUTF();
                        }
                        contaAux.setEmail(emails);
                        contaAux.setNomeUsuario(raf.readUTF());
                        contaAux.setSenha(raf.readUTF());
                        contaAux.setCPF(raf.readUTF());
                        contaAux.setCidade(raf.readUTF());
                        contaAux.setTransferencias(raf.readInt());
                        contaAux.setSaldo(raf.readFloat());
                        if(contaAux.getNome().compareTo(nomeBusca) == 0){
                            status = true;
                        }else{
                            contaAux.setID(-1);
                        }
                    }else{
                        raf.skipBytes(raf.readInt());
                    }
                }
                return contaAux;
           }catch(Exception e){
                System.out.println("erro :(");
                return null;
           }
        }

        public static boolean update(RandomAccessFile raf, contaBancaria conta)  {
            try {
                raf.seek(4); // Posiciona o ponteiro no inicio do arquivo
                while (raf.getFilePointer() < raf.length()) { // Enquanto o ponteiro nao chegar no final do arquivo
                    if (raf.readByte() == 0) { // Se a lapide for 0 (ativo)
                        int tam = raf.readInt();
    
                        if (raf.readInt() == conta.getID()) { // Se o id da conta for igual ao id da conta a ser atualizada
                            if (tam >= conta.toByteArray().length) { // Se o tamanho do registro for maior ou igual ao tamanho do registro atualizado encaixar no mesmo registro
    
                                raf.writeUTF(conta.getNome());
                                raf.writeInt(conta.getNumEmails());
                                for (int i = 0; i < conta.getNumEmails(); i++) {
                                    raf.writeUTF(conta.getEmail()[i]);
                                }
                                raf.writeUTF(conta.getNomeUsuario());
                                raf.writeUTF(conta.getSenha());
                                raf.writeUTF(conta.getCPF());
                                raf.writeUTF(conta.getCidade());
                                raf.writeInt(conta.getTransferenciasRealizadas());
                                raf.writeFloat(conta.getSaldo());
    
                                return true;
                            } else { // Se o tamanho do registro for menor que o tamanho do registro atualizado sera necessario criar um novo registro e excluir o antigo
                                raf.seek(raf.getFilePointer() - 9); // Volta o ponteiro para o inicio do registro
                                raf.writeByte(1); // Escreve a lapide 1 (excluido)
                                return create(raf, conta); // Cria um novo registro
                            }
                        } else {
                            raf.skipBytes(tam - 4); // Pula o resto do registro
                        }
                    } else {
                        raf.skipBytes(raf.readInt()); // Pula o registro
                    }
                }
                return true;
            } catch (Exception e) {
                System.out.println("-> Erro ao atualizar registro!");
                return false;
            }
        }

        public static boolean delete(RandomAccessFile raf, contaBancaria conta) throws IOException {
            raf.seek(4);
            int tamanhoRegistroAntigo;
            int ID;
            contaBancaria contaAux = new contaBancaria();
            boolean status = false;
            while (raf.getFilePointer() < raf.length()) {
                if (raf.readByte() == 0) {
                    tamanhoRegistroAntigo = raf.readInt();
                    ID = raf.readInt();
                    if(conta==null){
                        return false;
                    }else{
                        if (ID == conta.getID()) {
                            raf.seek(raf.getFilePointer() - 9);
                            raf.writeByte(1);
                            return true;
                        }else{
                            raf.skipBytes(tamanhoRegistroAntigo-4);
                        }
                    }
                    
                } else {
                    raf.skipBytes(raf.readInt());
                }
            }
            return false;
        }
}
