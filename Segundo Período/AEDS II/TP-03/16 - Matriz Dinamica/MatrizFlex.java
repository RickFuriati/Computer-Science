class Celula { //Classe célula com ponteiros para todas as direções (superior, inferior, direita, esquerda)
    public int elemento;
    public Celula inferior, superior, esquerda, direita;
    
    public Celula() { //Construtor vazio
        this(0, null, null, null, null);
    }

    public Celula(int elemento) { //Construtor que atribui apenas o elemento
        this(elemento, null, null, null, null);
    }

    public Celula(int elemento, Celula inferior, Celula superior, Celula esquerda, Celula direita) { //COnstrutor completo
        this.elemento = elemento;
        this.inferior = inferior;
        this.superior = superior;
        this.esquerda = esquerda;
        this.direita = direita;
    }
}
 
class MatrizFlex { //Classe matriz flexivel
    private Celula comeco; //Atribui uma celula de começo que inicia no canto superior esquerdo da matriz
    private int linhas, colunas;
 
    public MatrizFlex() { //Valor padrao para matriz é 3x3
        this(3, 3);
    }

    public MatrizFlex(int linhas, int colunas) { //Constroi a estrutura da matriz de acordo com a quantidade de linhas e colunas
        this.linhas = linhas;
        this.colunas = colunas;
        this.comeco = new Celula();
        Celula temp = this.comeco;
        for(int i = 1; i < this.linhas; i++) { //Prenche as linhas da matriz
            temp.inferior = new Celula();
            temp.inferior.superior = temp;
            temp = temp.inferior;
        }
        temp = null;
        for(int i = 0; i < this.linhas; i++) { 
            temp = this.comeco;
            for(int j = 0; j < i; j++) {
                temp = temp.inferior;
            }

            for(int k = 1; k < this.colunas; k++) { //Preenche as colunas da matriz
                temp.direita = new Celula();
                temp.direita.esquerda = temp;
                temp = temp.direita;
            }
        }
        temp = null;
        if(this.linhas > 1) { //Conecta os elementos das linhas para formar a estrutura da matriz (Só faz se o numero de linhas for maior que 1)
            temp = this.comeco.inferior;
            for(int i = 1; i < this.linhas; i++) { //
                Celula superior = temp.superior;
                Celula inferior = temp;
                while(superior != null && inferior != null) {
                    superior.inferior = inferior; //Conecta os elementos de acordo com a celula (superior com inferior e esquerda com direita)
                    inferior.superior = superior;
                    superior = superior.direita;
                    inferior = inferior.direita;
                }
                temp = temp.inferior;
            }
        }
    }

    public MatrizFlex soma(MatrizFlex x) { //Realiza a soma da matriz a partir de uma matriz auxiliar
        MatrizFlex resp = new MatrizFlex(x.linhas, x.colunas);
        Celula a = resp.comeco;
        for(int i = 0; i < this.linhas; i++) {
            Celula b = a; 
            for(int j = 0; j < this.colunas; j++) {
                b.elemento = somar(this, x, j, i);
                b = b.direita;
            }
            a = a.inferior;
        }

        return resp;
    }

    private int somar(MatrizFlex a, MatrizFlex b, int x, int y) { //Soma os elementos da matriz celula a celula
        int soma;
        Celula c = a.comeco;
        Celula d = b.comeco;

        for(int i = 0; i < x; i++) {
            c = c.direita;
            d = d.direita;
        }

        for(int i = 0; i < y; i++) {
            c = c.inferior;
            d = d.inferior;
        }

        soma = c.elemento + d.elemento;

        return soma;
    }

    public MatrizFlex multiplicacao(MatrizFlex x) {
        MatrizFlex resp = new MatrizFlex(x.linhas, x.colunas);
        Celula a = resp.comeco;
        int i = 0;
        while(a != null && i < this.linhas) {
            Celula b = a;
            int j = 0;
            while(b != null && j < this.colunas) {
                b.elemento = multiplicar(this, x, i, j);
                b = b.direita;
                j++;
            }
            a = a.inferior;
            i++;
        }

        return resp;
    }

    private int multiplicar(MatrizFlex a, MatrizFlex b, int x, int y) {
        int multiplicacao = 0;
        Celula c = a.comeco;
        Celula d = b.comeco;

        for(int i = 0; i < x; i++) {
            c = c.inferior;
        }

        for(int i = 0; i < y; i++) {
            d = d.direita;
        }

        int e, f;
        while(c != null && d != null) {
            e = c.elemento;
            f = d.elemento;
            multiplicacao += e * f;
            c = c.direita;
            d = d.inferior;
        }

        return multiplicacao;
    }

    public void diagonalPrincipal() { 
        if(this.linhas == this.colunas) { //Realiza operações somente com os elementos da diagonal principal (linha==coluna)
            Celula i = comeco;
            while(i != null) {
                MyIO.print(i.elemento + " ");

                i = i.direita; //Percorre a matriz da esquerda pra direita 
                if(i != null) {
                    i = i.inferior; //Percorre a matriz de cima para baixo
                }
            }
            MyIO.println("");
        }
    }

    public void diagonalSecundaria() { //Realiza opérações com elementos da diagonal secundaria
        if (this.linhas == this.colunas) {
            Celula i;

            for(i = comeco; i.direita != null; i = i.direita);

            while(i != null) {
                MyIO.print(i.elemento + " ");
                i = i.inferior;
                if (i != null) {
                    i = i.esquerda;
                }
            }
            MyIO.println("");
        }
    }

    public static void main(String[] args) {
        int operacoes = MyIO.readInt();
        for(int i = 0; i < operacoes; i++) {
            int linhas = MyIO.readInt();
            int colunas = MyIO.readInt();
            MatrizFlex Aux1 = new MatrizFlex(linhas, colunas);
            for (Celula aux = Aux1.comeco; aux != null; aux = aux.inferior){ //Le os elementos de cada uma das células da matriz após inicializa-la com as células vazias 
                for (Celula aux2 = aux; aux2 != null; aux2 = aux2.direita) {
                    aux2.elemento = MyIO.readInt();
                }
            }

            linhas = MyIO.readInt();
            colunas = MyIO.readInt();
            MatrizFlex Aux2 = new MatrizFlex(linhas, colunas);
            for (Celula aux = Aux2.comeco; aux != null; aux = aux.inferior) {
                for (Celula aux2 = aux; aux2 != null; aux2 = aux2.direita) {
                    aux2.elemento = MyIO.readInt(); 
                }
            }

            MatrizFlex soma = Aux1.soma(Aux2); //Cria matrizes auxiliares para realizar operações (uma para soma e outra para multiplicação)

            MatrizFlex multiplicacao = Aux1.multiplicacao(Aux2);

            Aux1.diagonalPrincipal(); //Printa a diagonal principal e secundária da matriz auxiliar de soma
            Aux1.diagonalSecundaria();
            for (Celula aux = soma.comeco; aux != null; aux = aux.inferior) { //Printa a matriz resultante
                for (Celula aux2 = aux; aux2 != null; aux2 = aux2.direita) {
                    MyIO.print(aux2.elemento + " ");
                }
                MyIO.println("");
            }
            for (Celula aux = multiplicacao.comeco; aux != null; aux = aux.inferior) {
                for (Celula aux2 = aux; aux2 != null; aux2 = aux2.direita) {
                    MyIO.print(aux2.elemento + " ");
                }
                MyIO.println("");
            }
        }
    }
}