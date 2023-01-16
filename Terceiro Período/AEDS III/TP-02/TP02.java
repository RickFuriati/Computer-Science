import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Scanner;



public class TP02 extends CRUD {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        RandomAccessFile raf = new RandomAccessFile("dataFile.bin", "rw"); //Arquivo de dados contendo os registros de contas bancárias
        RandomAccessFile arvoreBMindices = new RandomAccessFile("arvoreBMindices", "rw"); //Arquivo de índice Arvore B+ de ordem 5

        arvoreBM arvoreDeIndices = new arvoreBM(5); //Estrutura de arvore para armazenar o índice localmente 
        hashExtensivel.tabelaBuckets indiceHash = new hashExtensivel.tabelaBuckets();

        System.out.println("------Menu de Contas Bancárias------");
        String menu = "Digite:\n 0) Sair\n 1)Criar uma conta Bancária\n 2)Realizar uma Transferência\n 3)Buscar um ID\n 4)Atualizar um registro\n 5)Deletar um Registro\n 6)Ordenar o arquivo\n 7)Criar arquivo de índice\n 8)Comprimir arquivo de dados\n 9)Descomprimir arquivo de dados";
        int opcao = 0;
        String entrada = new String();
        ArrayList<String> dicionario= new ArrayList<String>();

        while (true) {
            System.out.println(menu);
            opcao = sc.nextInt();
            if (opcao == 0) {
                break;
            }

            switch (opcao) {
                case 1:
                    contaBancaria conta = new contaBancaria();
                    System.out.println("---- Criação de Nova Conta ----");
                    System.out.println("Digite o nome da pessoa:");
                    sc.nextLine();
                    entrada = sc.nextLine();
                    conta.setNome(entrada);
                    System.out.println("Digite quantos emails gostaria de cadastrar: ");
                    int aux = sc.nextInt();
                    String[] email = new String[aux];
                    for (int i = 0; i < aux; i++) {
                        System.out.println("Digite o email:");
                        entrada = sc.next();
                        email[i] = entrada;
                    }
                    conta.setNumEmails(aux);
                    conta.setEmail(email);

                    System.out.println("Digite o nome de usuario: ");
                    sc.nextLine();
                    entrada = sc.nextLine();
                    conta.setNomeUsuario(entrada);

                    System.out.println("Digite a senha: ");
                    entrada = sc.next();
                    conta.setSenha(entrada);

                    System.out.println("Digite o cpf: ");
                    entrada = sc.next();
                    conta.setCPF(entrada);

                    System.out.println("Digite a cidade: ");
                    sc.nextLine();
                    entrada = sc.nextLine();
                    conta.setCidade(entrada);

                    System.out.println("Digite o saldo: ");
                    float saldo= sc.nextFloat();
                    conta.setSaldo(saldo);
                    conta.setID(++ultimoID);
                    create(raf, conta); //Cria a nova conta bancária
                    //arvoreDeIndices = indice.indiceArvore(raf); //Atualiza o arquivo de índices

                    break;
                case 2:
                    int tipoTransferencia = 0;
                    System.out.println("---- Transferencia Bancária ----");
                    System.out.println("Digite o tipo de transferencia:\n 1)Deposito\n 2)Transferencia entre contas");
                    contaBancaria contaTransf = new contaBancaria();
                    tipoTransferencia = sc.nextInt();

                    if (tipoTransferencia == 1) { 
                        boolean status = false; //Depósito bancário

                        while (true) {
                            float valor = 0;
                            int saida = 0;
                            String contaAux = new String();
                            System.out.println("---- Depósito Bancário ----");
                            System.out.println("Digite o nome de pessoa da conta:");
                            contaAux = sc.next();
                            contaTransf = CRUD.readName(raf, contaAux);
                            if (contaTransf.getID() == -1) { //Verifica se a conta existe
                                System.out.println("Conta nao encontrada :9");
                                System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                saida = sc.nextInt();
                                if (saida == 2) {
                                    break;
                                }
                            } else {
                                System.out.println("Digite o valor que deseja depositar");
                                entrada = sc.next();
                                valor = Float.parseFloat(entrada);
                                contaTransf.setSaldo(contaTransf.getSaldo() + valor);
                                status = CRUD.update(raf, contaTransf);
                                if (status == false) { //Verifica se a atualização foi bem sucedida
                                    System.out.println("Erro no deposito :(");

                                    System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                    saida = sc.nextInt();
                                    if (saida == 2) {
                                        break;
                                    }
                                } else if (status == true) {
                                    System.out.println("Deposito realizado com sucesso!");
                                }

                                System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                saida = sc.nextInt();
                                if (saida == 2) {
                                    break;
                                }

                            }

                        }

                    } else if (tipoTransferencia == 2) {
                        boolean status = false;
                        while (status == false) {
                            float valor = 0;
                            int saida = 0;
                            String contaAux1 = new String();
                            String contaAux2 = new String();
                            contaBancaria contaTransf1 = new contaBancaria();
                            contaBancaria contaTransf2 = new contaBancaria();
                            System.out.println("---- Transferencia Bancária ----");
                            System.out.println("Digite o nome de pessoa da conta de origem:");
                            contaAux1 = sc.next();
                            contaTransf1 = CRUD.readName(raf, contaAux1);
                            if (contaTransf1.getID() == -1) { //Verifica se a conta existe
                                System.out.println("Conta " + contaAux1 + " nao encontrada :9");
                                System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                saida = sc.nextInt();
                                if (saida == 2) {
                                    break;
                                }
                            } else {
                                System.out.println("Digite o valor que deseja transferir");
                                entrada = sc.next();
                                valor = Float.parseFloat(entrada);

                                if (contaTransf1.getSaldo() < valor) { //Verifica se a conta possui saldo suficiente
                                    System.out.println("Saldo Insuficiente :(");
                                }
                                System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                saida = sc.nextInt();
                                if (saida == 2) {
                                    break;
                                }
                                System.out.println("Digite o nome de pessoa da conta de destino:");
                                contaAux2 = sc.next();
                                contaTransf2 = CRUD.readName(raf, contaAux2);
                                if (contaTransf2.getID() == -1) {
                                    System.out.println("Conta " + contaAux2 + " nao encontrada :9");
                                    System.out.println("Deseja tentar novamente?\n 1)Sim\n 2)Nao");
                                    saida = sc.nextInt();
                                    if (saida == 2) {
                                        break;
                                    }
                                } else {
                                    contaTransf1.setSaldo(contaTransf1.getSaldo() - valor);
                                    contaTransf2.setSaldo(contaTransf2.getSaldo() + valor);
                                    CRUD.update(raf, contaTransf1);
                                    CRUD.update(raf, contaTransf2);

                                    System.out.println("Transferencia realizada com sucesso!");
                                }
                            }

                        }

                    } else {
                        System.out.println("Tipo inválido!");
                    }
                    break;
                case 3:
                    boolean status;
                    System.out.println("---- Busca de ID----");
                    System.out.println("Digite o ID que deseja Buscar");
                    entrada = sc.next();
                    contaBancaria resultadoBusca = CRUD.readID(raf, Integer.parseInt(entrada));
                    ;
                    if (resultadoBusca != null) {
                        resultadoBusca.print();
                    } else {
                        System.out.print("O id " + entrada + " não foi encontrado :(\n");
                    }

                    break;
                case 4:
                    int caso = 0;
                    String nome = new String();
                    System.out.println("---- Atualizar Registro ----");
                    System.out.println("Digite o nome da pessoa do registro que deseja atualizar:");
                    nome = sc.next();
                    contaBancaria contaNova = CRUD.readName(raf, nome);

                    System.out.println("Qual campo deseja atualizar?");
                    System.out.println(
                            "1)Nome\n 2)Nome de Usuario\n 3)Email\n 4)Cidade\n 5)CPF\n 6)Transferencias \n 7)Saldo");
                    entrada = sc.next();
                    caso = Integer.parseInt(entrada);

                    if (caso == 1) {
                        System.out.println("---- Atualizando Nome ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        contaNova.setNome(entrada);
                        CRUD.update(raf, contaNova);

                    } else if (caso == 2) {
                        System.out.println("---- Atualizando Nome de Usuario ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        contaNova.setNomeUsuario(entrada);
                        CRUD.update(raf, contaNova);
                    } else if (caso == 3) {
                        System.out.println("---- Atualizando Email ----");
                        System.out.println("Digite a nova quantidade de emails:");
                        entrada = sc.next();
                        contaNova.setNumEmails(Integer.parseInt(entrada));
                        String[] emails = new String[contaNova.getNumEmails()];
                        for (int i = 0; i < contaNova.getNumEmails(); i++) {
                            System.out.println("Digite o " + (i + 1) + " email:");
                            entrada = sc.next();
                            emails[i] = entrada;
                        }
                        contaNova.setEmail(emails);
                        CRUD.update(raf, contaNova);

                    } else if (caso == 4) {
                        System.out.println("---- Atualizando Cidade ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        contaNova.setCidade(entrada);
                        CRUD.update(raf, contaNova);

                    } else if (caso == 5) {
                        System.out.println("---- Atualizando CPF ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        contaNova.setCPF(entrada);
                        CRUD.update(raf, contaNova);
                    } else if (caso == 6) {
                        System.out.println("---- Atualizando Transferencias ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        CRUD.update(raf, contaNova);
                    } else if (caso == 7) {
                        System.out.println("---- Atualizando Saldo ----");
                        System.out.println("Digite o novo valor:");
                        entrada = sc.next();
                        CRUD.update(raf, contaNova);
                    }

                    arvoreDeIndices = indice.indiceArvore(raf);
                    break;
                case 5:

                    System.out.println("---- Deletar Registro ----");
                    System.out.println("Digite o ID do registro que deseja deletar:");
                    entrada = sc.next();
                    CRUD.delete(raf, CRUD.readID(raf, Integer.parseInt(entrada)));
                    arvoreDeIndices = indice.indiceArvore(raf);
                    break;
                case 6:
                    System.out.println("---- Ordenação ----");
                    if (ordenacao.intercalacao(raf) == true) {
                        System.out.println("Ordenação realizada com sucesso!");
                    } else {
                        System.out.println("Erro na ordenação!");
                    }
                    break;
                case 7:
                    System.out.println("---- Criando Índice----");
                    int tipo = 0;
                    System.out.println("Escolha o tipo de índice:");
                    System.out.println("1) Árvore B+ de ordem 5");
                    System.out.println("2) Hash Estendido");
                    System.out.println("3) Lista Invertida");
                    tipo = sc.nextInt();

                    switch (tipo) {
                        case 1:
                            arvoreDeIndices = indice.indiceArvore(raf);
                            break;
                        case 2:
                            indiceHash = hashExtensivel.indiceHash(raf);
                            break;
                        case 3:
                        System.out.println("Escolha o tipo de lista invertida:");
                        System.out.println("1) Pelo nome");
                        System.out.println("2) Pela Cidade");

                        int tipoLista = sc.nextInt();

                        if(tipoLista==1){
                            System.out.print("\n-> Digite o nome: ");
                            String name = sc.next();
                            if(listaInvertida.listarNome(raf, name)) System.out.println("\n-> Listado com sucesso!");
                            else System.out.println("\n-> Erro ao listar!");
                        }else if(tipoLista==2){
                            System.out.print("\n-> Digite a cidade: ");
                            String city = sc.next();
                            if(listaInvertida.listarCidade(raf, city)) System.out.println("\n-> Listado com sucesso!");
                            else System.out.println("\n-> Erro ao listar!");
                        }else{
                            System.out.println("2) Pela Cidade");
                        }
                            break;
                    }

                    break;
                case 8:
                    caso=0;
                    System.out.println("Qual algoritmo deseja utiliar?");
                    System.out.println("1) Huffman \n2) LZW");
                    caso = sc.nextInt();

                    if(caso==1){
                        System.out.println("Alogritmo Huffman");
                        System.out.println("Digite o nome do arquivo de dados:");
                        String nomeArquivo = sc.next();
                        HuffmanTree.compactar(nomeArquivo);
                    }else if(caso==2){
                        System.out.println("Alogritmo LZW");
                        System.out.println("Digite o nome do arquivo de dados:");
                        String nomeArquivo = sc.next();
                        dicionario=lzw.compressao(nomeArquivo);
                    }
                    break;
                
                case 9:
                caso=0;
                System.out.println("Qual algoritmo deseja utiliar?");
                System.out.println("1) Huffman \n2) LZW");
                caso = sc.nextInt();

                if(caso==1){
                    System.out.println("Alogritmo Huffman");
                    System.out.println("Digite o nome do arquivo de dados:");
                    String nomeArquivo = sc.next();
                    HuffmanTree.descompactar(nomeArquivo);
                }else if(caso==2){
                    System.out.println("Alogritmo LZW");
                    System.out.println("Digite o nome do arquivo de dados:");
                    String nomeArquivo = sc.next();
                    //lzw.decompressao(nomeArquivo,lzw.compressao(nomeArquivo));
                    lzw.decompressao(nomeArquivo,dicionario);
                }
                break;
                    
                }   
            
        }
        raf.close();
    }

}
