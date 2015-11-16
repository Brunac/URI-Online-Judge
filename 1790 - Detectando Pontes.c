#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
 
int dfs ( int mat[111][111], int ba ) {
    int i;
    int visitado[111];
    memset ( visitado, 0, sizeof(visitado) );
    int total = 0;
    visitado[1] = 1;
    int pilha[111];
    int pilhaindex = 0;
 
    for ( i=2; i<=ba; i++ ) {
        if ( mat[1][i] == 1 ) {
            pilhaindex++;
            pilha[pilhaindex] = i;
        }
    }
 
    while ( pilhaindex != 0 ) {
        int v = pilha[pilhaindex];
        pilhaindex--;
 
        if ( visitado[v] == 0 ) {
            for ( i=0; i<=ba; i++ ) {
                if ( mat[v][i] == 1 ) {
                    pilhaindex++;
                    pilha[pilhaindex] = i;
                }
            }
            total++;
        }
        visitado[v] = 1;
    }
    return total;
}
 
int ponte ( int mat[111][111], int tam ) {
    int res = 0;
    int before, after;
    int i, j;
 
    for ( i=1; i<=tam; i++ ) {
        for ( j=1; j<i; j++ ) {
            if ( mat[i][j] == 1 ) {
                before = dfs ( mat, tam );
                mat[i][j] = 0;
                mat[j][i] = 0;
                after = dfs ( mat, tam );
                mat[i][j] = 1;
                mat[j][i] = 1;
                //printf ( " %d-%d ", before, after );
                if ( after != before )
                    res++;
            }
        }
    }
    return res;
}
 
int main ()  {
    int mat[111][111];
    int C, P, v1, v2;
    int i;
 
    while ( scanf ( "%d %d", &C, &P) != EOF ) {
        memset ( mat, 0, sizeof(mat) );
        for ( i=0; i<P; i++ ) {
            scanf ( "%d %d", &v1, &v2 );
            mat[v1][v2] = 1;
            mat[v2][v1] = 1;
        }
        int res = ponte ( mat, C );
        printf ( "%d\n", res);
    }
 
    return 0;
}
