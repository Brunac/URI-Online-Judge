/********************************************************************************************************
* "Tabelas Hash"                                                                                        *
* Problema 1256 @ URI Online Judge                                                                      *
* Tempo: 0.060                                                                                          *
*                                                                                                       *
* [UFMT] Hiromi Giovana Tanita                                                                          *
*                                                                                                       * 
********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
 
/************************************************
*   Alocação dinâmica da matriz que guardará a  *
* tabela hash.                                  *
************************************************/
int**alocacao ( int**mat, int lar, int alt ) {
    int i, j;
        mat = ( int** ) malloc ( lar*sizeof ( int* ) );
        for ( i = 0; i < lar; i++ ) {
            mat[i] = ( int* ) malloc ( alt*sizeof ( int ) );
         }
   return ( mat );
}
 
/************************************************
*   Função Hash - Gera a chave que determina a  *
* posição na altura da matriz onde o elemento   *
* será colocado.                                *
************************************************/
int funcaoHash ( int chave, int M ) {
    int tab_chave;
    tab_chave = chave%M;
    return tab_chave;
}
 
/************************************************
*   Insere o elemento na tabela Hash.           *
************************************************/
int** insereHash ( int**Tab, int chave, int M ) {
    int indice, i;
    i=0;
    indice = funcaoHash ( chave, M );
    while ( Tab[indice][i]!=-1111 ) i++;
 
    Tab[indice][i] = chave;
    return ( Tab );
}
 
/************************************************
*   Imprime a tabela conforme pede-se no pro-   *
* blema.                                        *
************************************************/
void imprime ( int**mat, int lar, int alt ) {
    int i, j;
    for (i=0; i<lar; i++){
        printf ( "%d -> ", i );
        for (j=0; j<alt; j++){
            if ( mat[i][j] == -1111 ) {
                    puts("\\");
                    break;
            }
            else printf( "%d -> ", mat[i][j] );
            if ( j==alt-1 ) {
                    puts("\\");
            }
        }
    }
}
 
/************************************************
*   Função principal.                           *
************************************************/
int main ( int argc, char *argv[] ) {
    int N, M, C, chave, aux;
    int i, j;
    int **Tab;
 
    /********************************************
    *   Número de casos de teste.               *
    *********************************************/
    scanf ( "%d", &N );
    while ( N-- ) {
 
        /****************************************
        *   Quantidade de posições na tabela e  *
        * número de chaves a serem inseridas.   *
        *****************************************/
        scanf ( "%d %d", &M, &C );
        Tab = alocacao ( Tab, M, C );
 
        /****************************************
        *   Inicialização da matriz.            *
        *****************************************/
        for ( i=0; i<M; i++ ) {
            for ( j=0; j<C; j++ ) {
                Tab[i][j]=-1111;
            }
        }
 
        /****************************************
        *   Recebendo as chaves.                *
        * Aux utilizado apenas para não alterar *
        * o valor de C, que será necessário na  *
        * função de impressão.                  *
        *****************************************/
        aux = C;
        while ( aux-- ) {
            scanf ( "%d", &chave );
            Tab = insereHash ( Tab, chave, M );
        }
        imprime ( Tab, M, C );
        if ( N>0 ) printf ( "\n" );
    }
    return 0;
}
