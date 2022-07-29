import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Date;
import java.util.LinkedHashMap;

import javax.swing.event.ChangeEvent;

import java.text.SimpleDateFormat;
import java.util.ArrayList;


class arvoreArvore {
    
    static class No {
        public char elemento; // Conteudo do no.
        public No esq; // No da esquerda.
        public No dir; // No da direita.
        public No2 outro;
        
        No(char elemento) {
            this.elemento = elemento;
            this.esq = this.dir = null;
          this.outro = null;
        }

        No(char elemento, No esq, No dir) {
            this.elemento = elemento;
            this.esq = esq;
            this.dir = dir;   
          this.outro = null;
        }
    }

    static class No2 {
        public Filme elemento; // Conteudo do no.
        public No2 esq, dir;  // Filhos da esq e dir.
    
        
        public No2(Filme elemento) {
            this.elemento = elemento;
		    this.esq = this.dir = null;
        }
    
        public No2(Filme elemento, No2 esq, No2 dir) {
            this.elemento = elemento;
            this.esq = esq;
            this.dir = dir;
        }
    }

    
    
 
    static class BST {
        public int comparacoes=0;
        private No raiz; // Raiz da arvore.

        public BST() throws Exception {
            raiz = null;
            inserir('D');
            inserir('R');
            inserir('Z');
            inserir('X');
            inserir('V');
            inserir('B');
            inserir('F');
            inserir('P');
            inserir('U');
            inserir('I');
            inserir('G');
            inserir('E');
            inserir('J');
            inserir('L');
            inserir('H');
            inserir('T');
            inserir('A');
            inserir('W');
            inserir('S');
            inserir('O');
            inserir('M');
            inserir('N');
            inserir('K');
            inserir('C');
            inserir('Y');
            inserir('Q');
            
        }
        
        public void inserir(char x) throws Exception {
            raiz = inserir(x, raiz);
        }
    
        private No inserir(char x, No i) throws Exception {
            if (i == null) {
                comparacoes++;
             i = new No(x);
    
          } else if (x < i.elemento) {
            comparacoes++;
             i.esq = inserir(x, i.esq);
    
          } else if (x > i.elemento) {
            comparacoes++;
             i.dir = inserir(x, i.dir);
    
          } else {
             throw new Exception("Erro ao inserir!");
          }
    
            return i;
        }

        public void inserir(Filme x)throws Exception{
            inserir(x, raiz);
         }
      
         public void inserir(Filme x, No i) throws Exception {
              if (i == null) {
               throw new Exception("Erro ao inserir: caractere invalido!");
      
            } else if (x.getTituloOriginal().charAt(0) < i.elemento) {
                comparacoes++;
                inserir(x, i.esq);
      
            } else if (x.getTituloOriginal().charAt(0) > i.elemento) {
                comparacoes++;
                inserir(x, i.dir);
      
            } else {
               i.outro = inserir(x, i.outro);
            }
         }
      
      
          public No2 inserir(Filme x, No2 i) throws Exception {
              if (i == null) {
                comparacoes++;
               i = new No2(x);
      
            } else if (x.getTituloOriginal().compareTo(i.elemento.getTituloOriginal()) < 0) {
                comparacoes++;
                i.esq = inserir(x, i.esq);
      
            } else if (x.getTituloOriginal().compareTo(i.elemento.getTituloOriginal()) > 0) {
                comparacoes++;
                i.dir = inserir(x, i.dir);
      
            } else {
               throw new Exception("Erro ao inserir: elemento existente!");
            }
      
              return i;
          }      

        public void pesquisar(String elemento) {
            boolean resp;
            MyIO.println("=> "+elemento);
            MyIO.print("raiz ");
            resp= pesquisar(raiz, elemento);
            if(resp==true){
                MyIO.print(" SIM\n");
            }else if(resp==false){
                MyIO.print(" NAO\n");
            }
        }
    
        public boolean pesquisar(No no, String x) {
          boolean resp=false;
    
         
            if (no != null) {
                resp=pesquisarSegundaArvore(no.outro, x);
                if(resp==false){
                    MyIO.print(" ESQ ");

                    resp=pesquisar(no.esq,x); // Elementos da esquerda.
                }
                if(resp==false){
                    MyIO.print(" DIR ");

                    resp=pesquisar(no.dir,x); // Elementos da direita.
                }
               
            }
        
            return resp;
          
        }
    

        public boolean pesquisarSegundaArvore(No2 no, String x) {
          boolean resp;
            if (no == null) {
                comparacoes++;
              //  MyIO.print(" NAO");

             resp = false;
    
          } else if (x.compareTo(no.elemento.getTituloOriginal()) < no.elemento.getTituloOriginal().compareTo(x)) { 
            MyIO.print("esq "); 
            comparacoes++;         
             resp = pesquisarSegundaArvore(no.esq, x); 
    
          } else if (x.compareTo(no.elemento.getTituloOriginal()) > no.elemento.getTituloOriginal().compareTo(x)) { 
            MyIO.print("dir ");
            comparacoes++;
             resp = pesquisarSegundaArvore(no.dir, x); 
    
          } else { 
            //MyIO.print(" SIM");
             resp = true; 
          }
          return resp;
        }
    
        public void mostrar(){
            mostrar(raiz);
         }
      
         public void mostrar(No i){
            if (i != null){
                //MyIO.print(" esq");
               mostrar(i.esq);
               mostrar(i.outro);
               //MyIO.print(" dir");
               mostrar(i.dir);
            }
         }
      
         public void mostrar(No2 i){
            if (i != null){
               mostrar(i.esq);
               //System.out.println(i.elemento);
               mostrar(i.dir);
            }
        }

        public void caminharCentral() {
            System.out.print("[ ");
            caminharCentral(raiz);
            System.out.println("]");
        }

        private void caminharCentral(No i) {
            if (i != null) {
                caminharCentral(i.esq); // Elementos da esquerda.
                System.out.print(i.elemento + " "); // Conteudo do no.
                caminharCentral(i.dir); // Elementos da direita.
            }
        }

        public void caminharPre() {
            System.out.print("[ ");
            caminharPre(raiz);
            System.out.println("]");
        }

        private void caminharPre(No i) {
            if (i != null) {
                System.out.print(i.elemento + " "); // Conteudo do no.
                caminharPre(i.esq); // Elementos da esquerda.
                caminharPre(i.dir); // Elementos da direita.
            }
        }

        public void caminharPos() {
            System.out.print("[ ");
            caminharPos(raiz);
            System.out.println("]");
        }

        private void caminharPos(No i) {
            if (i != null) {
                caminharPos(i.esq); // Elementos da esquerda.
                caminharPos(i.dir); // Elementos da direita.
                System.out.print(i.elemento + " "); // Conteudo do no.
            }
        }

        private No maiorEsq(No i, No j) {

            // Encontrou o maximo da subarvore esquerda.
            if (j.dir == null) {
                i.elemento = j.elemento; // Substitui i por j.
                j = j.esq; // Substitui j por j.ESQ.

                // Existe no a direita.
            } else {
                // Caminha para direita.
                j.dir = maiorEsq(i, j.dir);
            }
            return j;
        }

        public int getAltura() {
            return getAltura(raiz, 0);
        }

        public int getAltura(No i, int altura) {
            if (i == null) {
                altura--;
            } else {
                int alturaEsq = getAltura(i.esq, altura + 1);
                int alturaDir = getAltura(i.dir, altura + 1);
                altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
            }
            return altura;
        }

    }

    
    
    
    static class Filme{
        private String nome;
        private String tituloOriginal;
        private Date dataLancamento;
        private int duracao;
        private String genero;
        private String idiomaOriginal;
        private String situacao;
        private float orcamento;
        private ArrayList<String> palavrasChave;
        //private String palavrasChave;
    
        SimpleDateFormat default_dateFormat = new SimpleDateFormat("dd/MM/yyyy"); // Formata??o padr?o da data como dia/mes/ano
        public Filme(){ //Construtor vazio: Apenas inicia a classe sem nenhum valor atribu?do
            nome ="";
            tituloOriginal="";
            dataLancamento= null;
            duracao=0;
            genero="";
            idiomaOriginal="";
            situacao="";
            orcamento=0;
            palavrasChave= new ArrayList<String>();
        }
        //Construtor completo: Inicia a classe com todos os atributos
        public Filme (String nome, String tituloOriginal, Date dataLancamento, int duracao, String genero, String idiomaOriginal, String situacao, Float orcamento,ArrayList<String> palavrasChave){
            this.nome=nome;
            this.tituloOriginal=tituloOriginal;
            this.dataLancamento=dataLancamento;
            this.duracao=duracao;
            this.genero=genero;
            this.idiomaOriginal=idiomaOriginal;
            this.situacao=situacao;
            this.orcamento=orcamento;
            this.palavrasChave=palavrasChave;
        }
        //M?todos set e get para todos os atributos
        public void setNome(String nome){this.nome=nome;}
        public String getNome(){return this.nome;}
    
        public void setTituloOriginal(String tituloOriginal){this.tituloOriginal=tituloOriginal;}
        public String getTituloOriginal(){return this.tituloOriginal;}
    
        public void setDataLancamento(Date dataLancamento){this.dataLancamento=dataLancamento;}
        public Date getDataLancamento(){return this.dataLancamento;}
    
        public void setDuracao(int duracao){this.duracao=duracao;}
        public int getDuracao(){return this.duracao;}
    
        public void setGenero(String genero){this.genero=genero;}
        public String getGenero(){return this.genero;}
    
        public void setIdiomaOriginal(String idiomaOriginal){this.idiomaOriginal=idiomaOriginal;}
        public String getIdiomaOriginal(){return this.idiomaOriginal;}
    
        public void setSituacao(String situacao){this.situacao=situacao;}
        public String getSituacao(){return this.situacao;}
    
        public void setOrcamento(float orcamento){this.orcamento=orcamento;}
        public float getOrcamento(){return this.orcamento;}
    
        public void setPalavrasChave(ArrayList<String> palavrasChave){this.palavrasChave=palavrasChave;}
        public ArrayList<String> getPalavrasChave(){return this.palavrasChave;}
    
        //M?todo clone, que retorna um objeto "filme" com os mesmos atributos de um outro objeto filme
        public Filme clone(){
            Filme filmeClone = new Filme();
            filmeClone.nome=this.nome;
            filmeClone.tituloOriginal=this.tituloOriginal;
            filmeClone.dataLancamento=this.dataLancamento;
            filmeClone.duracao=this.duracao;
            filmeClone.genero=this.genero;
            filmeClone.idiomaOriginal=this.idiomaOriginal;
            filmeClone.situacao=this.situacao;
            filmeClone.orcamento=this.orcamento;
            filmeClone.palavrasChave=this.palavrasChave;
            return filmeClone;
        }
        //M?todo para imprimir os atributos da classe
        //Para imprimir a data do formato indicado ? necess?rio formata-la no print line
        public void imprimir(){
            MyIO.println(this.nome +" "+this.tituloOriginal+" "+default_dateFormat.format(this.dataLancamento)+" "+this.duracao+" "+this.genero+" "+this.idiomaOriginal+" "+this.situacao+" "+this.orcamento+" "+this.palavrasChave);
        }
    
        public String tiraTags(String linha){ //Fun??o para remover as tags de uma linha
            String stringAuxiliar=""; //String auxiliar que ir? armazenar o conte?do de uma tag
            stringAuxiliar=linha.trim(); //Retira os espa?os do come?o e do final da linha
            while((linha.contains("<")==true)&&(linha.contains(">")==true)){ //Enquanto a linha possuir tags de abertura e fechameento ("< >") executa o loop 
                stringAuxiliar=linha.substring(linha.indexOf("<"),linha.indexOf(">",linha.indexOf("<"))+1); //String formada pelos caracteres que se encontram dentro do idex formado pela abertura ("<") e fechamento de tag (">")
                 linha=linha.replace(stringAuxiliar,""); //Substitui o string auxiliar (tag) por um espa?o vazio 
            }
            linha=linha.trim(); //Remove novamente os espa?os em branco do come?o de do final da linha 
            return linha; //Retorna a linha sem nenhuma tag 
        }
    
        //M?todo para ler os atributos de um html e atribui-los aos atributos da classe por meio de setters
        
        public void ler(String nomeArquivo){
            String linha=""; //Vari?vel para armazenar uma linha por vez do arquivo
            String stringAuxiliar=""; //String que armazena apenas o atributo desejado (ignora tags e espa?os)
            //String stringAuxiliar1="";
            BufferedReader reader;
            Date dataAuxiliar;
            try{
                //Leitura linha a linha inicialmente foi feita com um raf (RandomAccessFile) por?m caracteres especiais (acentos cedilha) nao s?o reconhecidos durante o tratamento de caracteres :(
                reader=new BufferedReader(new FileReader("/tmp/filmes/"+nomeArquivo));
                
                linha=reader.readLine(); //L? uma linha do arquivo
                while(linha!=null){ //Enquanto a linha nao for "null" (fim do arquivo) executa o c?digo
                    //Foram necess?rios v?rias compara??es no loop para assegurar que ele seja executado uma vez, e em cada execu??o do loop ele procura por um atributo da classe Filme
                    
                    //Busca pelo atributo "Nome"
                    if(linha.contains("<title>")==true){ //Busca por uma correspond?ncia da tag "<title>" na linha, caso seja verdadeiro a linha cont?m o nome do filme
                       linha=linha.substring(linha.indexOf(">"), linha.lastIndexOf("<")); //Remove os espa?os e a tag <title> da linha
                        stringAuxiliar=linha.substring(1,linha.indexOf("(")-1); //Armazena a linha resultante (come?ando a posi??o 1 e indo at? o primeiro index de "(" que corresponde ao fim do nome do t?tulo)
                        setNome(stringAuxiliar); // Atribui o nome encontrado no html ao atributo da classe Filme 
                    }
                    stringAuxiliar=""; //"Limpa" a string auxiliar 
                    
                    //Busca pelo atributo "Titulo Original"
                    if(linha.contains("<p class=\"wrap\">")==true){ //Procura pela tag "wrap" que indica onde no arquivo HTML est? a informa??o do t?tulo original
                        stringAuxiliar=linha.substring(linha.lastIndexOf("</strong>")+10,linha.lastIndexOf("<")); //Remove as tags e deixa somente o titulo original
                        setTituloOriginal(stringAuxiliar);
                    }
                    //Busca pelo atributo "Data de Lan?amento"
                    if(linha.contains("<span class=\"release\">")==true){ //Busca pela tag "release" que indica onde a data se encontra no arquivo HTML
                        linha=reader.readLine(); //Pula uma linha para encontrar a data (est? uma linha abaixo da tag)
                        stringAuxiliar=linha.trim(); //Retira os espa?os em branco do come?o e do final da linha
                        stringAuxiliar=linha.replace("(BR)", ""); //Retira a tag do pa?s entre par?nteses (especificidade do HTML)
                        stringAuxiliar=linha.trim(); //Assegura que n?o h? espa?os em branco ap?s a remo??o das tags 
                        try{ 
                            dataAuxiliar=default_dateFormat.parse(stringAuxiliar); //Transforma a data obtida em string numa vari?vel do tipo "Date"
                            setDataLancamento(dataAuxiliar); //Deta o atributo data de lan?amento da classe como a data obtida no m?todo
                        }catch(java.text.ParseException e){
                            e.printStackTrace(); //Catch para o erro de formata??o incorreta de data
                        }
                    }   
                    //Busca pelo atributo "Dura??o"
                    if(linha.contains("<span class=\"runtime")==true){ //Busca pela tag "runtime" que indica o local onde a dura??o do filme se encontra no HTML
                        int horas=0; //Vari?veis para armazenar os valores das horas,minutos e dura??o 
                        int minutos=0;
                        int duracao=0;
                        linha=reader.readLine(); //Pula duas linhas, o valor desejado (dura??o), encontra-se duas linhas abaixo da tag
                        linha=reader.readLine();
                        stringAuxiliar=linha.trim(); //Retira os espa?os em branco do come?o e do final da string 
                        stringAuxiliar=stringAuxiliar.replace(" ", ""); //Retira os espa?os em branco no meio da string
                        if(stringAuxiliar.contains("h")&&(stringAuxiliar.contains("m"))){ //Caso o filme possua dura??o na casa das horas, trata os dois valores (horas e minutos)
                            horas=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("h"))); //Cria uma substring que cont?m apenas o valor num?rico das horas (come?a de 0 e vai at? o index de "h") e atribui seu valor inteiro a vari?vel de horas
                            minutos=Integer.parseInt(stringAuxiliar.substring(stringAuxiliar.indexOf("h")+1,stringAuxiliar.indexOf("m"))); //Cria uma substring que cont?m apenas o valor num?rico dos minutos (come?a no index de "h" +1 e vai at? o index de "m") e atribui seu valor inteiro a vari?vel de minutos
                        }else if(stringAuxiliar.contains("h")&&stringAuxiliar.contains("m")==false){
                            horas=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("h")));
                        }else{
                            stringAuxiliar=linha.trim(); // Remove os espa?os em branco no come?o e no final da string
                            stringAuxiliar=stringAuxiliar.replace(" ", ""); 
                            minutos=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("m"))); //Cria uma substring apenas com o valor dos minutos
                        }
    
                        duracao=(horas*60) + minutos; //Transforma as horas para minutos e soma com a vari?vel dos minutos: resulta na dura??o
                        setDuracao(duracao); //seta a dura??o (inteiro)
                    }   
                    //Busca pelo atributo "Genero"
                    if(linha.contains("<a href=\"/genre")==true){ //Busca pela tag "genre" que indica o genero no HTML
                        stringAuxiliar=linha.trim(); 
                        
                        linha=tiraTags(linha);
                        linha=linha.replace("&nbsp;", ""); //Tira "&nbsp" da string (especificidade do html)
                        stringAuxiliar=linha.trim(); 
                        setGenero(stringAuxiliar); 
                    }   
    
                    //Busca pelo atributo "Situa??o"
                    
                    if(linha.contains("<strong><bdi>Situa??o")==true){ //Procura pela tag situa??o 
                        stringAuxiliar=linha.trim();
                        linha=tiraTags(linha); 
                        linha=linha.replace("Situa??o", "");//retira "situa??o" da string 
                        stringAuxiliar=linha.trim(); 
                        setSituacao(stringAuxiliar);
                    }   
    
                    //Busca pelo atributo "Idioma Original"
                    if(linha.contains("Idioma")==true){  //Procura pela tag "idioma"
                        stringAuxiliar=linha.trim(); 
                        stringAuxiliar=tiraTags(stringAuxiliar);
                        stringAuxiliar=stringAuxiliar.replace("Idioma original", ""); //Retira "Idioma original" da string
                        stringAuxiliar=stringAuxiliar.trim();
                        setIdiomaOriginal(stringAuxiliar);
                        
                    }                  
                    //Busca pelo atributo "Or?amento"
                    if(linha.contains("<p><strong><bdi>Or?amento")==true){  //Procura pela tag "or?amento"
                        stringAuxiliar=linha.trim();
                        stringAuxiliar=tiraTags(stringAuxiliar);  
                        stringAuxiliar=stringAuxiliar.replace("Or?amento", ""); //Tira "or?amento" da string
                        stringAuxiliar=stringAuxiliar.substring(1); //Retira o primeiro caracter da string (corresponde ao "$")
                        stringAuxiliar=stringAuxiliar.replace("$", ""); //Assegura que o caracter de "$" foi removido
                        if(stringAuxiliar.length()==1){ //Caso o tamanho do or?amento seja 1 o html possui apenas "-"
                            stringAuxiliar="0"; //Atribui 0 aos filmes que nao possuem or?amento dispon?vel
                        }else{
                            stringAuxiliar=stringAuxiliar.replace(",", ""); //Retira os espa?os da string
                        }
    
                        setOrcamento(Float.parseFloat(stringAuxiliar)); //Formata a string em um float 
                    }    
                    //Busca pelo atributo "Palavras Chave" 
                    if(linha.contains("Palavras-chave")==true){
                        
                        while(linha.contains("</ul>")==false){ //Executa um loop at? que a linha corresponda ao fechamento da tag "ul" 
                            if(linha.contains("/keyword/")==true){ //Se a linha possui "keyword" ela cont?m uma palavra chave do filme 
                                stringAuxiliar=linha.trim(); 
                                stringAuxiliar=tiraTags(stringAuxiliar); 
                                palavrasChave.add(stringAuxiliar); //Adiciona a palavra chave ao array list de palavras chave
                            }
                            linha=reader.readLine();
                        }
                        
                    }
                    if(tituloOriginal==""){ //Caso o titulo original seja nulo no final do c?digo, o nome e o titulo original s?o iguais 
                        setTituloOriginal(nome); //Atribui o titulo original como o nome 
                    }
                linha=reader.readLine(); //Le a proxima linha (continua o loop principal)
                }
                reader.close(); //Fecha o reader do arquivo
            }catch(IOException excecao){ //Exce??o para leitura do arquivo
                excecao.printStackTrace();
    
            }
        }
    }
    public static void main(String[] args) throws Exception{
        MyIO.setCharset("utf-8"); //Seta a codifica??o como UTF-8 para assegurar que caracteres especiais e acentos sejam lidos 
        String nomeArquivo=""; 
        nomeArquivo=MyIO.readLine(); //L? o nome do arquivo 
        //Lista listaFilmes=new Lista(100);
        BST arvoreBusca=new BST();
        //arvoreBusca.caminharCentral();
        long tempoIni=System.currentTimeMillis();
        while (true){ 
            if(nomeArquivo.compareTo("FIM")==0){ //Se o nome do arquivo for 'FIM' sai do loop
                break;
            }
            Filme novoFilme=new Filme(); //Cria um novo objeto de filme
            novoFilme.ler(nomeArquivo); //L? os atributos do HTML apontado pelo nome fornecido na entrada
            arvoreBusca.inserir(novoFilme);
            nomeArquivo=MyIO.readLine(); //L? a proxima linha e continua o loop
            //novoFilme.imprimir();
        }
        int n=0;
        n=MyIO.readInt();
        String operacao="";
        //String nomeFilmeOP="";
        String linhaOP="";
        for(int aux=0;aux<n;aux++){
            linhaOP=MyIO.readLine();
            operacao=linhaOP.substring(0,1);
            
            if(linhaOP.length()>1){
                linhaOP=linhaOP.substring(2);
            }
            linhaOP.trim();
            
            if(operacao.compareTo("I")==0){

                Filme novoFilme=new Filme();
                novoFilme.ler(linhaOP);
                arvoreBusca.inserir(novoFilme);

            }else if(operacao.compareTo("R")==0){
                //arvoreBusca.remover(linhaOP);
               // MyIO.println("(R) "+listaFilmes.removerFim().getNome());
            }
        }
        
        String chaveBusca=new String();
        chaveBusca=MyIO.readLine();
        //MyIO.println(chaveBusca);
        
        while (true){ 
            if(chaveBusca.compareTo("FIM")==0){ //Se o nome do arquivo for 'FIM' sai do loop
                break;
            }
            arvoreBusca.pesquisar(chaveBusca);
            chaveBusca=MyIO.readLine();

        }
        Arq.openWrite("752959_arvoreArvore.txt");
        Arq.println("752959\t"+(System.currentTimeMillis()-tempoIni)+" ms\t"+ arvoreBusca.comparacoes); 
        Arq.close();  

    
    }
}



