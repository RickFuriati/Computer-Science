import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Date;
import java.util.LinkedHashMap;

import javax.swing.event.ChangeEvent;

import java.text.SimpleDateFormat;
import java.util.ArrayList;


class rehash {
    
   

    static public class Hash {
        Filme tabela[];
        int m;
        public int comparacoes=0;
        //final String NULO = null;
     
        /*  public Hash() {
           
        }*/
     
        public Hash(int m) {
           this.m = m;
          
           this.tabela = new Filme[this.m];
           for (int i = 0; i < m; i++) {
              tabela[i]=null; 
           }
           
        }
     
        public int h(Filme elemento) {
            int posicHash=0;
            for(char aux : elemento.getTituloOriginal().toCharArray()){
                posicHash+=aux;
            }
            return posicHash % m;
        }

        public int reh(Filme elemento) {
            int posicHash=0;
            for(char aux : elemento.getTituloOriginal().toCharArray()){
                posicHash+=aux;
            }
            return ++posicHash % m;
        }
        
        public int h(String elemento) {
            int posicHash=0;
            for(char aux : elemento.toCharArray()){
                posicHash+=aux;
            }
            return posicHash % m;
        }

        public int reh(String elemento) {
            int posicHash=0;
            for(char aux : elemento.toCharArray()){
                posicHash+=aux;
            }
            return ++posicHash % m;
        }


        public boolean inserir(Filme elemento) {
           boolean resp = false;
           if (elemento!=null) {
            comparacoes++;
              int pos = h(elemento.getTituloOriginal());
              if (tabela[pos]==null) {
                comparacoes++;
                 tabela[pos] = elemento;
                 resp = true;
              } else  {
                pos=reh(elemento.getTituloOriginal());
                if(tabela[pos]==null){
                    comparacoes++;
                    tabela[pos]=elemento;
                    resp=true;
                }
              }
           }
           return resp;
        }
     
        public boolean pesquisar(String elemento) {
            boolean resp=false;
            int pos=h(elemento);    

            if (tabela[pos] != null) {
                comparacoes++;
                if (tabela[pos].getTituloOriginal().compareTo(elemento) == 0) {
                    comparacoes++;
                    MyIO.println("Posicao: " + pos);
                    resp = true;
                }else {
                    pos=reh(elemento);
                    if(tabela[pos]!=null){
                        comparacoes++;
                        if(tabela[pos].getTituloOriginal().compareTo(elemento)==0){
                            MyIO.println("Posicao: " + pos);
                            resp = true;
                        }
                    }
                }
            }
            return resp;
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
    
        SimpleDateFormat default_dateFormat = new SimpleDateFormat("dd/MM/yyyy"); // Formatação padrão da data como dia/mes/ano
        public Filme(){ //Construtor vazio: Apenas inicia a classe sem nenhum valor atribuído
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
        //Métodos set e get para todos os atributos
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
    
        //Método clone, que retorna um objeto "filme" com os mesmos atributos de um outro objeto filme
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
        //Método para imprimir os atributos da classe
        //Para imprimir a data do formato indicado é necessário formata-la no print line
        public void imprimir(){
            MyIO.println(this.nome +" "+this.tituloOriginal+" "+default_dateFormat.format(this.dataLancamento)+" "+this.duracao+" "+this.genero+" "+this.idiomaOriginal+" "+this.situacao+" "+this.orcamento+" "+this.palavrasChave);
        }
    
        public String tiraTags(String linha){ //Função para remover as tags de uma linha
            String stringAuxiliar=""; //String auxiliar que irá armazenar o conteúdo de uma tag
            stringAuxiliar=linha.trim(); //Retira os espaços do começo e do final da linha
            while((linha.contains("<")==true)&&(linha.contains(">")==true)){ //Enquanto a linha possuir tags de abertura e fechameento ("< >") executa o loop 
                stringAuxiliar=linha.substring(linha.indexOf("<"),linha.indexOf(">",linha.indexOf("<"))+1); //String formada pelos caracteres que se encontram dentro do idex formado pela abertura ("<") e fechamento de tag (">")
                 linha=linha.replace(stringAuxiliar,""); //Substitui o string auxiliar (tag) por um espaço vazio 
            }
            linha=linha.trim(); //Remove novamente os espaços em branco do começo de do final da linha 
            return linha; //Retorna a linha sem nenhuma tag 
        }
    
        //Método para ler os atributos de um html e atribui-los aos atributos da classe por meio de setters
        
        public void ler(String nomeArquivo){
            String linha=""; //Variável para armazenar uma linha por vez do arquivo
            String stringAuxiliar=""; //String que armazena apenas o atributo desejado (ignora tags e espaços)
            //String stringAuxiliar1="";
            BufferedReader reader;
            Date dataAuxiliar;
            try{
                //Leitura linha a linha inicialmente foi feita com um raf (RandomAccessFile) porém caracteres especiais (acentos cedilha) nao são reconhecidos durante o tratamento de caracteres :(
                reader=new BufferedReader(new FileReader("/tmp/filmes/"+nomeArquivo));
                
                linha=reader.readLine(); //Lê uma linha do arquivo
                while(linha!=null){ //Enquanto a linha nao for "null" (fim do arquivo) executa o código
                    //Foram necessários várias comparações no loop para assegurar que ele seja executado uma vez, e em cada execução do loop ele procura por um atributo da classe Filme
                    
                    //Busca pelo atributo "Nome"
                    if(linha.contains("<title>")==true){ //Busca por uma correspondência da tag "<title>" na linha, caso seja verdadeiro a linha contém o nome do filme
                       linha=linha.substring(linha.indexOf(">"), linha.lastIndexOf("<")); //Remove os espaços e a tag <title> da linha
                        stringAuxiliar=linha.substring(1,linha.indexOf("(")-1); //Armazena a linha resultante (começando a posição 1 e indo até o primeiro index de "(" que corresponde ao fim do nome do título)
                        setNome(stringAuxiliar); // Atribui o nome encontrado no html ao atributo da classe Filme 
                    }
                    stringAuxiliar=""; //"Limpa" a string auxiliar 
                    
                    //Busca pelo atributo "Titulo Original"
                    if(linha.contains("<p class=\"wrap\">")==true){ //Procura pela tag "wrap" que indica onde no arquivo HTML está a informação do título original
                        stringAuxiliar=linha.substring(linha.lastIndexOf("</strong>")+10,linha.lastIndexOf("<")); //Remove as tags e deixa somente o titulo original
                        setTituloOriginal(stringAuxiliar);
                    }
                    //Busca pelo atributo "Data de Lançamento"
                    if(linha.contains("<span class=\"release\">")==true){ //Busca pela tag "release" que indica onde a data se encontra no arquivo HTML
                        linha=reader.readLine(); //Pula uma linha para encontrar a data (está uma linha abaixo da tag)
                        stringAuxiliar=linha.trim(); //Retira os espaços em branco do começo e do final da linha
                        stringAuxiliar=linha.replace("(BR)", ""); //Retira a tag do país entre parénteses (especificidade do HTML)
                        stringAuxiliar=linha.trim(); //Assegura que não há espaços em branco após a remoção das tags 
                        try{ 
                            dataAuxiliar=default_dateFormat.parse(stringAuxiliar); //Transforma a data obtida em string numa variável do tipo "Date"
                            setDataLancamento(dataAuxiliar); //Deta o atributo data de lançamento da classe como a data obtida no método
                        }catch(java.text.ParseException e){
                            e.printStackTrace(); //Catch para o erro de formatação incorreta de data
                        }
                    }   
                    //Busca pelo atributo "Duração"
                    if(linha.contains("<span class=\"runtime")==true){ //Busca pela tag "runtime" que indica o local onde a duração do filme se encontra no HTML
                        int horas=0; //Variáveis para armazenar os valores das horas,minutos e duração 
                        int minutos=0;
                        int duracao=0;
                        linha=reader.readLine(); //Pula duas linhas, o valor desejado (duração), encontra-se duas linhas abaixo da tag
                        linha=reader.readLine();
                        stringAuxiliar=linha.trim(); //Retira os espaços em branco do começo e do final da string 
                        stringAuxiliar=stringAuxiliar.replace(" ", ""); //Retira os espaços em branco no meio da string
                        if(stringAuxiliar.contains("h")&&(stringAuxiliar.contains("m"))){ //Caso o filme possua duração na casa das horas, trata os dois valores (horas e minutos)
                            horas=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("h"))); //Cria uma substring que contém apenas o valor numérico das horas (começa de 0 e vai até o index de "h") e atribui seu valor inteiro a variável de horas
                            minutos=Integer.parseInt(stringAuxiliar.substring(stringAuxiliar.indexOf("h")+1,stringAuxiliar.indexOf("m"))); //Cria uma substring que contém apenas o valor numérico dos minutos (começa no index de "h" +1 e vai até o index de "m") e atribui seu valor inteiro a variável de minutos
                        }else if(stringAuxiliar.contains("h")&&stringAuxiliar.contains("m")==false){
                            horas=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("h")));
                        }else{
                            stringAuxiliar=linha.trim(); // Remove os espaços em branco no começo e no final da string
                            stringAuxiliar=stringAuxiliar.replace(" ", ""); 
                            minutos=Integer.parseInt(stringAuxiliar.substring(0,stringAuxiliar.indexOf("m"))); //Cria uma substring apenas com o valor dos minutos
                        }
    
                        duracao=(horas*60) + minutos; //Transforma as horas para minutos e soma com a variável dos minutos: resulta na duração
                        setDuracao(duracao); //seta a duração (inteiro)
                    }   
                    //Busca pelo atributo "Genero"
                    if(linha.contains("<a href=\"/genre")==true){ //Busca pela tag "genre" que indica o genero no HTML
                        stringAuxiliar=linha.trim(); 
                        
                        linha=tiraTags(linha);
                        linha=linha.replace("&nbsp;", ""); //Tira "&nbsp" da string (especificidade do html)
                        stringAuxiliar=linha.trim(); 
                        setGenero(stringAuxiliar); 
                    }   
    
                    //Busca pelo atributo "Situação"
                    
                    if(linha.contains("<strong><bdi>Situação")==true){ //Procura pela tag situação 
                        stringAuxiliar=linha.trim();
                        linha=tiraTags(linha); 
                        linha=linha.replace("Situação", "");//retira "situação" da string 
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
                    //Busca pelo atributo "Orçamento"
                    if(linha.contains("<p><strong><bdi>Orçamento")==true){  //Procura pela tag "orçamento"
                        stringAuxiliar=linha.trim();
                        stringAuxiliar=tiraTags(stringAuxiliar);  
                        stringAuxiliar=stringAuxiliar.replace("Orçamento", ""); //Tira "orçamento" da string
                        stringAuxiliar=stringAuxiliar.substring(1); //Retira o primeiro caracter da string (corresponde ao "$")
                        stringAuxiliar=stringAuxiliar.replace("$", ""); //Assegura que o caracter de "$" foi removido
                        if(stringAuxiliar.length()==1){ //Caso o tamanho do orçamento seja 1 o html possui apenas "-"
                            stringAuxiliar="0"; //Atribui 0 aos filmes que nao possuem orçamento disponível
                        }else{
                            stringAuxiliar=stringAuxiliar.replace(",", ""); //Retira os espaços da string
                        }
    
                        setOrcamento(Float.parseFloat(stringAuxiliar)); //Formata a string em um float 
                    }    
                    //Busca pelo atributo "Palavras Chave" 
                    if(linha.contains("Palavras-chave")==true){
                        
                        while(linha.contains("</ul>")==false){ //Executa um loop até que a linha corresponda ao fechamento da tag "ul" 
                            if(linha.contains("/keyword/")==true){ //Se a linha possui "keyword" ela contém uma palavra chave do filme 
                                stringAuxiliar=linha.trim(); 
                                stringAuxiliar=tiraTags(stringAuxiliar); 
                                palavrasChave.add(stringAuxiliar); //Adiciona a palavra chave ao array list de palavras chave
                            }
                            linha=reader.readLine();
                        }
                        
                    }
                    if(tituloOriginal==""){ //Caso o titulo original seja nulo no final do código, o nome e o titulo original são iguais 
                        setTituloOriginal(nome); //Atribui o titulo original como o nome 
                    }
                linha=reader.readLine(); //Le a proxima linha (continua o loop principal)
                }
                reader.close(); //Fecha o reader do arquivo
            }catch(IOException excecao){ //Exceção para leitura do arquivo
                excecao.printStackTrace();
    
            }
        }
    }
    public static void main(String[] args) throws Exception{
        MyIO.setCharset("utf-8"); //Seta a codificação como UTF-8 para assegurar que caracteres especiais e acentos sejam lidos 
        String nomeArquivo=""; 
        
        //Lista listaFilmes=new Lista(100);
        Hash rehash=new Hash(21);
        long tempoIni=System.currentTimeMillis();
        nomeArquivo=MyIO.readLine(); //Lê o nome do arquivo 
        while (true){ 
            if(nomeArquivo.compareTo("FIM")==0){ //Se o nome do arquivo for 'FIM' sai do loop
                break;
            }
            Filme novoFilme=new Filme(); //Cria um novo objeto de filme
            novoFilme.ler(nomeArquivo); //Lê os atributos do HTML apontado pelo nome fornecido na entrada
            rehash.inserir(novoFilme);
            nomeArquivo=MyIO.readLine(); //Lê a proxima linha e continua o loop
            //novoFilme.imprimir();
        }
      
        
        String chaveBusca=new String();
        chaveBusca=MyIO.readLine();
        //MyIO.println(chaveBusca);
        
        while (true){ 
            if(chaveBusca.compareTo("FIM")==0){ //Se o nome do arquivo for 'FIM' sai do loop
                break;
            }
            
            //arvoreBusca.pesquisar(chaveBusca);
            MyIO.println("=> "+chaveBusca);
            if(rehash.pesquisar(chaveBusca)==false){
                MyIO.println("NAO");
            }
            
            chaveBusca=MyIO.readLine();

        }
        Arq.openWrite("752959_hashRehash.txt");
        Arq.println("752959\t"+(System.currentTimeMillis()-tempoIni)+" ms\t"+ rehash.comparacoes); 
        Arq.close();  

    
    }
}


