#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main ( ) {
    int N, i, j, vet[100001];
    unsigned long long int resultado;
    
    while ( 1 ) {
        scanf ( "%d", &N );
        
        if ( N == 0 ) 
          return 0;
        
        resultado = 0;
        
        for ( i = 0; i < N; i ++ ) {
            scanf ( "%d", &vet[ i ] );
            if ( i > 0 ) {
                resultado += abs ( vet[ i-1 ] );
                vet[ i ] += vet[ i - 1 ];
            }
        }
        printf ( "%llu", resultado );
        puts ( "" );
    }
}
