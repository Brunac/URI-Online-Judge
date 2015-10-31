/********************************************************************************************************
* "Dudu Faz Serviço"                                                                                    *
* Problema 1610 @ URI Online Judge                                                                      *
* Tempo: 0.072                                                                                          *
*                                                                                                       *
* [UFMT] Hiromi Giovana Tanita                                                                          *
*                                                                                                       * 
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10001
 
typedef struct estruturaNo {
    int valor; /* Número da tarefa. */
    struct estruturaNo *prox; /* Ponteiro para a lista de adjacência. */
} tipoNo;
 
tipoNo * lst[N]; /* Declarando vetor de estrutura, desta forma teremos um vetor de listas */

/* Alocação dinâmica de um novo "vértice". */
tipoNo *alocaNo (int valor) {
    tipoNo *novoNo = NULL;
    novoNo = (tipoNo*) malloc (sizeof(tipoNo));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}
 
/* Insere um novo elemento na lista de adjacência. */
void insereFim (tipoNo **lista, int valor ) {
    tipoNo *novo_No = alocaNo(valor);
    tipoNo *aux;
 
    if ( *lista == NULL ) *lista=novo_No;
    else {
        aux = *lista;
        while ( aux-> prox != NULL ) {
            aux = aux->prox;
        }
    aux->prox = novo_No;
    }
}
 
/* Adiciona w para a lista de v. */
void adicionaVertice ( int v, int w ) {
    insereFim ( &lst[v], w );
}

/* Alteração de DFS para verificar ciclo. */
int verificaCiclo ( int v, int visitado[], int pilha[] ) {
    if ( visitado[v] == 0 ) {
        /* Marca o nodo atual como visitado e parte da pilha. */
        visitado[v] = 1;
        pilha[v] = 1;
    }
    /* Procura todos os vértices adjacentes a v como em uma DFS. */
    while ( lst[v] != NULL ) {
        if ( !visitado[lst[v]->valor] && verificaCiclo ( lst[v]->valor, visitado, pilha ) )
            return 1;
        else if ( pilha[lst[v]->valor] )
            return 1;
        lst[v] = lst[v]->prox;
    }
    /* Remove v da pilha. */
    pilha[v] = 0;
    return 0;
}

/* Função que encapsula a verificação de ciclo. Inicializa variáveis e chama a função verificaCiclo para cada vértice. */
int Ciclo ( int tam ) {
    int i;
    int visitado[N];
    int pilha[N];
    memset ( visitado, 0, sizeof(visitado) );
    memset ( pilha, 0, sizeof(pilha) );
 
    for ( i=0; i<tam; i++ )
        if ( verificaCiclo( i, visitado, pilha ) )
        return 1;
 
    return 0;
}
 
int main( int argc, char *argv[] ) {
    int T, X, M, A, B;
    scanf ( "%d", &T ); /* Casos de teste. */
    while ( T-- ) {
        scanf ( "%d %d", &X, &M ); /* X: vertices, M: arestas*/
        int i;
        /* Inicializa a lista de adjacência. */
        for ( i=0; i<=X; i++ )
            lst[i] = NULL;
        /* Lê os vértices A e B e adiciona uma aresta entre eles (adicionando A em B na lista encadeada). */
        while ( M-- ) {
            scanf ( "%d %d", &A, &B );
            adicionaVertice ( A, B );
        }
        /* Verifica se há ciclo. */
        if ( Ciclo ( X+1 ) )
            puts ( "SIM" );
        else
            puts ( "NAO" );
    }
 
    return 0;
}
