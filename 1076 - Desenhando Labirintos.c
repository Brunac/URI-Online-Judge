#include<stdio.h>
#include<stdlib.h>
#define N 190

typedef struct tipo_fila {
    int elemento_fila[ 1000 ], comeco_fila, final_fila;
} tipo_fila;

void insere_fila ( int valor, tipo_fila *dado ) {
    dado->elemento_fila[ dado->final_fila++ ] = valor;
}

int remove_fila ( tipo_fila *dado ) {
    if ( dado->comeco_fila == dado->final_fila )
        return -10000000;
    else
        return dado->elemento_fila[ dado->comeco_fila++ ];
}

typedef struct tipo_grafo {
    int vetor_de_vertices[ N ], matriz_de_adjacencia[ N ][ N ], contador_de_vertices;
} tipo_grafo;

void inserir_vertice ( tipo_grafo *grafo, int vertice_a_ser_inserido ) {
    grafo->vetor_de_vertices[ grafo->contador_de_vertices ] = vertice_a_ser_inserido;
    grafo->contador_de_vertices++;
}

void inserir_aresta ( tipo_grafo *grafo, int vertice_inicial, int vertice_final ) {
    grafo->matriz_de_adjacencia[ vertice_inicial ][ vertice_final ] = 1;
    grafo->matriz_de_adjacencia[ vertice_final ][ vertice_inicial ] = 1;
}

void inicializa_grafo ( tipo_grafo *grafo ) {
    grafo->contador_de_vertices = 0;
    int i, j;
    for ( i=0; i<N; i++ ) {
        for ( j=0; j<N; j++ ) {
            grafo->matriz_de_adjacencia[ i ][ j ] = 0;
        }
    }
}

int percurso_em_largura ( tipo_grafo *grafo, int vertice_de_inicio ) {

    int i, x;
    int total = 0;

    int vetor_de_vertices_visitados[ N ];
    for ( i = 0; i <= grafo->contador_de_vertices; i++ )
       vetor_de_vertices_visitados[ i ] = 0;

    tipo_fila fila;
    fila.comeco_fila = 0;
    fila.final_fila = 0;

    for ( i = 0; i <= grafo->contador_de_vertices; i++ ) {
       if ( grafo->matriz_de_adjacencia[ vertice_de_inicio ][ i ] != 0 )
          insere_fila ( i, &fila );
    }

    vetor_de_vertices_visitados[ vertice_de_inicio ] = 1;

    while ( 1 ) {
       x = remove_fila ( &fila );
       if ( x == -10000000 )
          break;
       if ( vetor_de_vertices_visitados[ x ] == 0 ) {
          for ( i = 0; i <= grafo->contador_de_vertices; i++ ) {
             if ( grafo->matriz_de_adjacencia[ x ][ i ] != 0 ) {
                if ( vetor_de_vertices_visitados[ i ] == 0 )
                   insere_fila ( i, &fila );
                   vetor_de_vertices_visitados[ x ] = 1;
             }
          }
          total++;
       }
    }
    return total*2;
}

int main ( int argc, char *argv[ ] ) {

    int T, V, A;
    int vertice1, vertice2, inicio;
    int i;

    tipo_grafo grafo;

    scanf ( "%d", &T );

    while ( T-- ) {

        scanf ( "%d", &inicio );
        scanf ( "%d %d", &V, &A );

        inicializa_grafo ( &grafo );

        for ( i=0; i<V; i++ )
            inserir_vertice ( &grafo, i );

        while ( A-- ) {
            scanf ( "%d %d", &vertice1, &vertice2 );
            inserir_aresta ( &grafo, vertice1, vertice2 );
        }

        int total = percurso_em_largura ( &grafo, inicio );
        printf ( "%d\n", total );
    }

    return 0;
}
