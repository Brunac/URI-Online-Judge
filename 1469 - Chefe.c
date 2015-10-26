/********************************************************************************************************
* "Chefe"
* Problema 1469 @ URI Online Judge
* Tempo: 0.616
*
* [UFMT] Hiromi Giovana Tanita
* 
********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
#define N 1555

/**********************************************************************
* Estrutura de dados utilizada para representar o grafo.
**********************************************************************/
   
typedef struct tipoGrafo {
    int vetor[ N ]; /* Vetor que armazena o número que representa cada vértice */
    int matriz[ N ][ N ]; /* Matriz de adjacência */
    int contadorDeVertices; /* Número de vértices */
    int peso[ N ]; /* Vetor com a idade respectiva de cada funcionário */
} tipoGrafo;
   
/**********************************************************************
* Função que inicializa a estrutura que representa o grafo.
**********************************************************************/
void init ( tipoGrafo * grafo ) {
    memset ( grafo->matriz, 0, sizeof ( grafo->matriz ) );
    memset ( grafo->vetor, 0, sizeof ( grafo->vetor ) );
    memset ( grafo->peso, 0, sizeof ( grafo->peso ) );
    grafo->contadorDeVertices = 1;
}
   
/**********************************************************************
* Função para inserir um novo vértice (funcionário).
**********************************************************************/
void inserirVertice ( tipoGrafo *grafo, int insere, int peso ) {
    grafo->vetor[ grafo->contadorDeVertices ] = insere; 
    /* "vetor" recebe o número identificador do funcionário na ordem em 
     * que são inseridos, este número será utilizado para indexar a matriz 
     * de adjacência */
    grafo->peso[ grafo->contadorDeVertices ] = peso;
    /* "peso" recebe a idade do funcionário. */
    grafo->contadorDeVertices++;
    /* Incrementa o número de funcionários. */
}

/**********************************************************************
* Função para inserir uma nova aresta (relação de gerência).
**********************************************************************/
void inserirAresta ( tipoGrafo *grafo, int u, int v ) {
    grafo->matriz[u][v] = 1;
    /* Marca na matriz de adjacência que "v" é gerente de "u". */
}
 
/**********************************************************************
* Função para a busca em profundidade (DFS) a partir do funcionário 
* "vertice".
**********************************************************************/
int percursoProfundidade ( tipoGrafo *grafo, int vertice ) {
    int i, j, x, pos_vertice;
    int pilha[N];
    int pilhaindex = 0;
    int vetVisitado[N];
    int menor = 99999;
   
    memset ( vetVisitado, 0, sizeof(vetVisitado) );
   
    /* Busca qual o número onde "vertice" está indexado na matriz de adjacência. */
    for ( i=1; i <=grafo->contadorDeVertices; i++ ) {
        if ( grafo->vetor[i] == vertice) {
            pos_vertice = i;
            break;
        }
    }
  
    /* Adiciona na pilha todos os gerentes do funcionário inicial. */
    for ( i=1; i < grafo->contadorDeVertices; i++ ) {
       if ( grafo->matriz[pos_vertice][ grafo->vetor[i] ] != 0 ) {
          pilhaindex++;
          pilha[ pilhaindex ] = grafo->vetor[i];
       }
    }
   
    /* Marca inicial como visitado. */
    vetVisitado[ pos_vertice ] = 1;
    
    while ( pilhaindex > 0 ) {
       /* Desempilha o elemento a ser processado (procurar todos os 
	* gerentes deste funcionário "x". */
       x = pilha[pilhaindex];
       pilhaindex--;
       
   
   
       /* Caso "x" não tenha sido visitado ainda, cmpara com todos os 
	   * outros funcionários e empilha se houver relação de gerência. */
       if ( vetVisitado[x] == 0 ) {
          for ( i=0; i <= grafo->contadorDeVertices; i++ ) {
             if ( grafo->matriz[x][grafo->vetor[i]] != 0 ) {
                if ( vetVisitado[ grafo->vetor[i] ] == 0 ) {
                    pilhaindex ++;
                    pilha[ pilhaindex ] = grafo->vetor[i] ;
                }
             }
          }
          /* Obtém a menor idade (peso) dos funcionários onde a DFS alcança. */
          if ( grafo->peso[x] < menor ) menor = grafo->peso[x];
       }
       /* Marca "x" como visitado. */
       vetVisitado[x] = 1;
    }
    return menor;
}
   
/**********************************************************************
* Função Principal.
**********************************************************************/
int main ( int argc, char *argv[] ) {
    tipoGrafo grafo;
    int i, j, idade, vertice1, vertice2, aux, resultado;
    int num_empregados, num_relacoes, num_instrucoes;
    char identificador[10];
   
    while ( scanf ( "%d %d %d", &num_empregados, &num_relacoes, &num_instrucoes ) != EOF ) {
        /* Inicializa o grafo. */
	init ( &grafo );
	
	/* Lê a idade de cada empregado e adiciona como um novo vértice. */
        for ( i = 1; i <= num_empregados; i++ ) {
            scanf ( "%d", &idade );
            inserirVertice( &grafo, i, idade );
        }
	
        /* Lê as relações de gerência e adiciona como uma nova aresta. */
        for ( i = 1; i <= num_relacoes; i++ ) {
            scanf ( "%d %d", &vertice1, &vertice2 );
            inserirAresta ( &grafo, vertice2, vertice1 );
        }
        
 
	/* Processa as instruções. */
        for ( i = 1; i <= num_instrucoes; i++ ) {
            scanf ( "%s", identificador );
            if ( identificador[0] == 'P' ) {
                int v;
                scanf ( "%d", &v );
                resultado = percursoProfundidade( &grafo, v );
                if ( resultado == 99999 ) puts ( "*" );
                else printf ( "%d\n", resultado );
		/* Flag de erro: 99999 uma vez que a maior idade na entrada é 100. */
            }
            else {
                scanf ( "%d %d", &vertice1, &vertice2 );
                int aux1, aux2;
		/* Obtém o indexador correspondente dos dois vértices para alterar
		 * a matriz de adjacência. */
                for ( j=1; j<=grafo.contadorDeVertices; j++ ) {
                    if ( grafo.vetor[j] == vertice1 ) aux1 = j;
                    if ( grafo.vetor[j] == vertice2 ) aux2 = j;
                }
                /* Troca os elementos com o indexador obtido. */
                grafo.vetor[aux1] = vertice2;
                grafo.vetor[aux2] = vertice1;
                aux = grafo.peso[aux1];
                grafo.peso[aux1] = grafo.peso[aux2];
                grafo.peso[aux2] = aux;
            }
        }
    }
    return 0;
}
