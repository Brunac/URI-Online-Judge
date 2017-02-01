#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ( int argc, char *argv[] ) {
    int A, C, X[10005];
    int i, j, k;
    while ( scanf ( "%d %d", &A, &C ) != EOF ) {
        if ( A == 0 )  return 0;;
        for ( i = 0; i < C; i++ ) scanf ( "%d", &X[ i ]  );
        j = 0;
        for ( i = 1; i < C; i++ ) {
            if ( X[ i ] != X[ j ] ) {
                j++;
                X[ j ] = X[ i ];
            }
        }
        C = j + 1;
        X[ C ] = A;
        int low = X[ 0 ], ret = 0;
        for ( i = 1; i < C; i++ ) {
            if ( X[ i - 1 ] < X[ i ] && X[ i ] > X[ i + 1 ] ) {
                ret += X[ i ] - low;
                low = A;
            }
            else {
                if ( X[ i ] < low ) low = X[ i ];
            }
        }
        printf ( "%d\n", ret + A - low );
    }
}
