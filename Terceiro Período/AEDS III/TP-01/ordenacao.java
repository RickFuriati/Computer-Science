import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

public class ordenacao {
    public static contaBancaria readFile(RandomAccessFile raf, int pesquisa) { // Lê o arquivo
        try {
            contaBancaria conta = new contaBancaria();

            raf.seek(0); // Posiciona o ponteiro no inicio do arquivo
            while (raf.getFilePointer() < raf.length()) { // Enquanto o ponteiro nao chegar no final do arquivo
                if (raf.readByte() == 0) { // Se a lapide for 0 (ativo)
                    int tam = raf.readInt();

                    conta.setID(raf.readInt());

                    if (conta.getID() == pesquisa) { // Se o id da conta for igual ao id pesquisado
                        conta.setNome(raf.readUTF());
                        conta.setNumEmails(raf.readInt());
                        
                        
                        String[] emails=new String[conta.getNumEmails()];
                        for (int i = 0; i < conta.getNumEmails(); i++) {
                            emails[i] = raf.readUTF();
                        }
                        conta.setEmail(emails);
                        conta.setNomeUsuario(raf.readUTF());
                        conta.setSenha(raf.readUTF());
                        conta.setCPF(raf.readUTF());
                        conta.setCidade(raf.readUTF());
                        conta.setTransferencias(raf.readInt());
                        conta.setSaldo(raf.readFloat());

                        return conta;
                    } else {
                        raf.skipBytes(tam - 4); // Pula o resto do registro
                    }
                } else {
                    raf.skipBytes(raf.readInt()); // Pula o registro
                }
            }

            return null;
        } catch (Exception e) {
            System.out.println("-> Erro ao ler o arquivo!");
            return null;
        }
    }

    public static void deleteFiles() { // Deleta os arquivos já existentes
        File file1 = new File("arq1.bin");
        File file2 = new File("arq2.bin");
        File file3 = new File("arq3.bin");
        File file4 = new File("arq4.bin");
        File file5 = new File("arqFinal.bin");

        file1.delete();
        file2.delete();
        file3.delete();
        file4.delete();
        file5.delete();
    }

    public static void printFile(RandomAccessFile raf) throws IOException { // Imprime o arquivo
        raf.seek(0);
        while (raf.getFilePointer() < raf.length()) {
            raf.readByte();
            raf.readInt();
            int id = raf.readInt();
            String nome = raf.readUTF();
            int qdtEmails = raf.readInt();
            String[] emails = new String[qdtEmails];
            for (int i = 0; i < qdtEmails; i++) {
                emails[i] = raf.readUTF();
            }
            raf.readUTF();
            raf.readUTF();
            raf.readUTF();
            raf.readUTF();
            raf.readInt();
            raf.readFloat();

            System.out.println("ID: " + id + " \t| Nome: " + nome);
        }
    }

    public static boolean intercalacao(RandomAccessFile raf)throws IOException{
        
        deleteFiles();
        System.out.println("\n-> Distribuindo ...");

        ArrayList<contaBancaria> contas = new ArrayList<contaBancaria>();
        contaBancaria conta = new contaBancaria();

        RandomAccessFile arq1 = new RandomAccessFile("arq1.bin", "rw");
        RandomAccessFile arq2 = new RandomAccessFile("arq2.bin", "rw");

        
        raf.seek(4); 
        while(raf.getFilePointer() < raf.length()){
            if (raf.readByte() == 0) {
                raf.readInt();
                conta = CRUD.readID(raf, raf.readInt());
                contas.add(conta);
            } else {
                raf.skipBytes(raf.readInt());
            }
        }

        ArrayList<contaBancaria> contasTmp = new ArrayList<contaBancaria>(); 
        int contador = 0; 
        while (contas.size() > 0) { 
            for (int j = 0; j < 5; j++) { 
                if (contas.size() > 0) { 
                    contasTmp.add(contas.get(0)); 
                    contas.remove(0); 
                }
            }

           contasTmp.sort((contaBancaria c1, contaBancaria c2) -> c1.getID() - c2.getID());

            contador++;

            if (contador % 2 != 0) { 
                for (contaBancaria c : contasTmp) {
                    arq1.writeByte(0);
                    arq1.writeInt(c.toByteArray().length);
                    arq1.write(c.toByteArray());
                }
            } else { 
                for (contaBancaria c : contasTmp) {
                    arq2.writeByte(0);
                    arq2.writeInt(c.toByteArray().length);
                    arq2.write(c.toByteArray());
                }
            }

            contasTmp.clear(); 
        }

      

        ArrayList<contaBancaria> contas1 = new ArrayList<contaBancaria>();
        ArrayList<contaBancaria> contas2 = new ArrayList<contaBancaria>();

        System.out.println("\n-> Intercalação 1 ...");

        arq1.seek(0); 
        while (arq1.getFilePointer() < arq1.length()) { 
            arq1.readByte();
            arq1.readInt();
            conta = readFile(arq1, arq1.readInt()); 
            contas1.add(conta); 
        }

        arq2.seek(0); 
        while (arq2.getFilePointer() < arq2.length()) { 
            arq2.readByte();
            arq2.readInt();
            conta = readFile(arq2, arq2.readInt()); 
            contas2.add(conta);
        }

        RandomAccessFile arq3 = new RandomAccessFile("arq3.bin", "rw");
        RandomAccessFile arq4 = new RandomAccessFile("arq4.bin", "rw");

        contador = 0; 
        contasTmp.clear(); 
        int m = 5;

        while (contas1.size() > 0 || contas2.size() > 0) { 
                                                           
            for (int i = 0; i < m; i++) {
                if (contas1.size() > 0) { 
                                          
                    contasTmp.add(contas1.get(0));
                    contas1.remove(0);
                }
                if (contas2.size() > 0) { 
                                          
                    contasTmp.add(contas2.get(0));
                    contas2.remove(0);
                }
            }

            contasTmp.sort((contaBancaria c1, contaBancaria c2) -> c1.getID() - c2.getID()); 

            contador++;

            if (contador % 2 != 0) { 
                for (contaBancaria c : contasTmp) {
                    arq3.writeByte(0);
                    arq3.writeInt(c.toByteArray().length);
                    arq3.write(c.toByteArray());
                }
            } else { 
                for (contaBancaria c : contasTmp) {
                    arq4.writeByte(0);
                    arq4.writeInt(c.toByteArray().length);
                    arq4.write(c.toByteArray());
                }
            }

            contasTmp.clear(); 
        }


        int qdt = 2; 
        while (arq2.length() > 0) { 

            System.out.println("\n-> Intercalação " + qdt + " ..."); 
            arq3.seek(0);
            while (arq3.getFilePointer() < arq3.length()) { 
                                                            
                arq3.readByte();
                arq3.readInt();
                conta = readFile(arq3, arq3.readInt());
                contas1.add(conta);
            }

            arq4.seek(0);
            while (arq4.getFilePointer() < arq4.length()) { 
                                                            
                arq4.readByte();
                arq4.readInt();
                conta = readFile(arq4, arq4.readInt());
                contas2.add(conta);
            }

            arq1.setLength(0);
            arq2.setLength(0); 

            contador = 0;
            contasTmp.clear();
            m *= 2; 
            while (contas1.size() > 0 || contas2.size() > 0) { 
                                                               
                for (int i = 0; i < m; i++) { 
                    if (contas1.size() > 0) { 
                                              
                        contasTmp.add(contas1.get(0));
                        contas1.remove(0);
                    }
                    if (contas2.size() > 0) { 
                                              
                        contasTmp.add(contas2.get(0));
                        contas2.remove(0);
                    }
                }

                contasTmp.sort((contaBancaria c1, contaBancaria c2) -> c1.getID() - c2.getID()); 

                contador++;

                if (contador % 2 != 0) { 
                    for (contaBancaria c : contasTmp) {
                        arq1.writeByte(0);
                        arq1.writeInt(c.toByteArray().length);
                        arq1.write(c.toByteArray());
                    }
                } else { 
                    for (contaBancaria c : contasTmp) {
                        arq2.writeByte(0);
                        arq2.writeInt(c.toByteArray().length);
                        arq2.write(c.toByteArray());
                    }
                }

                contasTmp.clear(); 
            }


            qdt++;
        }

        // ------------------------------------------------------------------- //
        
        RandomAccessFile arqFinal = new RandomAccessFile("arqFinal.bin", "rw");
        arqFinal.seek(0); 
        arqFinal.writeInt(CRUD.getUltimoID()); 

        arqFinal.seek(4); 
        arq1.seek(0); 
        while (arq1.getFilePointer() < arq1.length()) { 
            arq1.readByte(); 
            arq1.readInt(); 
            conta = readFile(arq1, arq1.readInt()); 
            arqFinal.writeByte(0); 
            arqFinal.writeInt(conta.toByteArray().length); 
            arqFinal.write(conta.toByteArray()); 
        }

        // Fecha os arquivos
        arq1.close(); 
        arq2.close();
        arq3.close();
        arq4.close();
        arqFinal.close();

        return true;
    }
}
