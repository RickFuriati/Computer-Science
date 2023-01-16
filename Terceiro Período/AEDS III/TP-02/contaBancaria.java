import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class contaBancaria { //Classe de conta bancária com todos os atributos indicados, construtores, geters e setters
    private int idConta;
        private int numEmails;
        private String nomePessoa;
        private String[] email;
        private String nomeUsuario;
        private String senha;
        private String cpf;
        private String cidade;
        private int transferenciasRealizadas;
        private float saldoConta;

        public contaBancaria() {
            this.idConta = 0;
            this.nomePessoa = new String();
            this.email = new String[numEmails];
            this.nomeUsuario = new String();
            this.senha = new String();
            this.cpf = new String();
            this.cidade = new String();
            this.transferenciasRealizadas = 1;
            this.saldoConta = 1000;
        }

        public contaBancaria(int idConta, String nomePessoa, int numEmails, String[] email, String nomeUsuario,
                String senha,
                String cpf, String cidade, int transferencias, float saldo) {
            this.idConta = idConta;
            this.nomePessoa = nomePessoa;
            this.numEmails = numEmails;
            this.email = email;
            this.nomeUsuario = nomeUsuario;
            this.senha = senha;
            this.cpf = cpf;
            this.cidade = cidade;
            this.transferenciasRealizadas = transferencias;
            this.saldoConta = saldo;
        }

        public int getID() {
            return idConta;
        }

        public void setID(int ID) {
            this.idConta = ID;
        }

        public String getNome() {
            return nomePessoa;
        }

        public void setNome(String nome) {
            this.nomePessoa = nome;
        }

        public void setNumEmails(int num) {
            this.numEmails = num;
        }

        public int getNumEmails() {
            return numEmails;
        }

        public String[] getEmail() {
            return email;
        }

        public void setEmail(String[] email) {
            this.email = email;
        }

        public String getNomeUsuario() {
            return nomeUsuario;
        }

        public void setNomeUsuario(String nomeUsuario) {
            this.nomeUsuario = nomeUsuario;
        }

        public String getSenha() {
            return senha;
        }

        public void setSenha(String senha) {
            this.senha = senha;
        }

        public String getCPF() {
            return cpf;
        }

        public void setCPF(String CPF) {
            this.cpf = CPF;
        }

        public String getCidade() {
            return cidade;
        }

        public void setCidade(String cidade) {
            this.cidade = cidade;
        }

        public int getTransferenciasRealizadas() {
            return transferenciasRealizadas;
        }

        public void setTransferencias(int transferencias) {
            this.transferenciasRealizadas = transferencias;
        }

        public float getSaldo() {
            return saldoConta;
        }

        public void setSaldo(float saldo) {
            this.saldoConta = saldo;
        }

        public void print() { //Método para printar as inromações da conta
            System.out.println("---- Informações da Conta ----");
            System.out.println("-Nome: " + this.nomePessoa);
            System.out.println("-Nome de Usuario: " + this.nomeUsuario);
            System.out.println("-Quantidade de Emails: " + this.numEmails);
            System.out.println("-Email(s): ");
            System.out.println("[ ");
            for (int i = 0; i < this.numEmails; i++) {
                if (i != numEmails - 1) {
                    System.out.print(email[i] + ";");
                } else {
                    System.out.print(email[i]);
                }
            }
            System.out.print("]");
            System.out.println("-CPF " + this.cpf);
            System.out.println("-Cidade: " + this.cidade);
            System.out.println("-Transferencias: " + this.transferenciasRealizadas);
            System.out.println("-Saldo: " + this.saldoConta);
        }

        public byte[] toByteArray() throws IOException {  //Método para transformar uma conta em um array de bytes para facilitar operações no arquivo de dados
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);

            dos.writeInt(this.getID());
            dos.writeUTF(this.getNome());
            dos.writeInt(this.getNumEmails());
            for (int i = 0; i < this.getNumEmails(); i++) {
                dos.writeUTF(this.getEmail()[i]);
            }
            dos.writeUTF(this.getNomeUsuario());
            dos.writeUTF(this.getSenha());
            dos.writeUTF(this.getCPF());
            dos.writeUTF(this.getCidade());
            dos.writeInt(this.getTransferenciasRealizadas());
            dos.writeFloat(this.getSaldo());

            dos.close();
            baos.close();

            return baos.toByteArray();// 
        }
}
