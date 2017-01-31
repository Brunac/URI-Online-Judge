#include<stdio.h>
#include<stdlib.h>

int verifica ( int f, int c, int n, int ** mat, int total_cedulas ) {
	// Verifica se não está em uma posição inválida/fora da matriz
	if ( f >= 0 && c >= 0 && f < n && c < n ) {
		// Imprime a cédula da vizinhança na qual Batuke se encontra
		printf ( " %d", mat[f][c] );
		// Incrementa o total de cédulas percorridas
		total_cedulas++;
	}
	return total_cedulas;
}

int main ( int argc, char *argv[] ) {
    int n, f, c, i, j, cont = 1, total_cedulas=1, passos = 1;

    scanf ( "%d %d %d", &n, &f, &c );
    
    // Aloca a matriz n*n
    int ** mat = ( int** ) malloc ( n * sizeof ( int * ) );
    for ( i = 0; i < n; i++ ) mat[i] = ( int * ) malloc ( n * sizeof ( int ) );

    // Preenche a matriz com os números correspondentes em ordem crescente
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            mat[i][j] = cont++;
	
    // Imprime a posição inicial da matriz, contador começa com 1
	  cont = 1;
	  printf ( "%d", mat[f][c] );

    /* - O total de cédulas percorridas nunca deve ser maior que a de cédulas existentes
     * - A ordem do percurso é deslocando: direita -> abaixo -> (incrementa quantidade de passos por direção) -> esquerda -> acima -> (incrementa quantidade de passos) */
	  while ( total_cedulas < n*n ) {
        // Desloca para a direita direita
        for ( i = 0; i < passos; i++ ) {
            if ( total_cedulas < n*n ) {
                c++, cont++;
                total_cedulas = verifica ( f, c, n, mat, total_cedulas );
            }
        }
        // Desloca para baixo
        for ( i = 0; i < passos; i++ ) {
            if ( total_cedulas < n*n ) {
                f++, cont++;
                total_cedulas = verifica ( f, c, n, mat, total_cedulas );
            }
        }
        // incrementa passos
        passos++;
		
        // Desloca para a esquerda
        for ( i = 0; i < passos; i++ ) {
            if ( total_cedulas < n*n ) {
                c--, cont++;
                total_cedulas = verifica ( f, c, n, mat, total_cedulas );
            }
        }
        // Desloca para cima
        for ( i = 0; i < passos; i++ ) {
            if ( total_cedulas < n*n ) {
                f--, cont++;
                total_cedulas = verifica ( f, c, n, mat, total_cedulas );
            }
        }
        // incrementa passos
        passos++;
    }
    // Imprime quantidade total de deslocações
    printf ( "\n%d\n", cont );

    return 0;
}
