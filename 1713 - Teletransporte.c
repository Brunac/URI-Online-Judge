/********************************************************************************************************
* "Teletransport"
* Problema 1713 @ URI Online Judge
* Tempo: 0.808
*
* [UFMT] Hiromi Giovana Tanita
* 
********************************************************************************************************/

#include<stdio.h>
#include<string.h>
#define SIZE 111
 
unsigned long long naves;

/* Funções auxiliares de "power". */ 
void one ( unsigned long long a[SIZE][SIZE] ) {
    int i, j;
    for ( i = 1; i <= naves; i++ )
        for ( j = 1; j <= naves; j++ )
            a[i][j] = ( i == j );
}
 
void mul ( unsigned long long a[SIZE][SIZE], unsigned long long b[SIZE][SIZE] ) {
    unsigned long long res[SIZE][SIZE] = {{0}};
    int i, j, k;
 
    for ( i = 1; i <= naves; i++ )
        for ( j = 1; j <= naves; j++ )
            for ( k = 1; k <= naves; k++ ) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= 10000;
            }
 
    for ( i = 1; i <= naves; i++ )
        for ( j = 1; j <= naves; j++ )
            a[i][j] = res[i][j];
}
 
/* Eleva a matriz "a" por "n", guarda o resultado em "res". */
void power ( unsigned long long a[SIZE][SIZE], unsigned long long n, unsigned long long res[SIZE][SIZE] ) {
    one ( res );
 
    while ( n > 0 ) {
        if ( n % 2 == 0 ) {
            mul ( a, a );
            n /= 2;
        }
        else {
            mul ( res, a );
            n--;
        }
    }
}
 
 
int main ( ) {
    unsigned long long a[SIZE][SIZE], res[SIZE][SIZE];
    unsigned long long destino, bilhetes, painel, partida;
    int i, j;
 
    while ( scanf ( "%llu %llu", &naves, &bilhetes ) != EOF ) {
        scanf ( "%llu %llu", &partida, &destino );
 
        memset ( a, 0, sizeof( a ) );
        memset ( res, 0, sizeof( res ) );
        for ( i = 1; i <= naves; i++ ) {
            for ( j = 1; j <= 4; j++ ) {
                scanf ( "%llu", &painel );
		/* Monta o grafo com a quantidade de viagens de "i" até "painel". */
                a[i][painel]++;
            }
        }
	/* Eleva a matriz de adjacência pela quantidade de bilhetes. */
        power ( a, bilhetes, res );
        printf ( "%llu", res[partida][destino] );
        puts ( "" );
    }
    return 0;
}
