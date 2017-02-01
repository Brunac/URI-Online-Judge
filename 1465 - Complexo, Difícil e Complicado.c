#include<stdio.h>
#include<stdlib.h>

int main ( int argc, char * argv[] ) {
    
    int M, A, B;
    
    scanf ( "%d", &M );
    
    while ( M-- ) {
            
        scanf ( "%d %d", &A, &B );
        
        if ( B == 0 ) printf ( "1\n" );
        else if ( A == 0 ) printf ( "2\n" );
        else if ( abs( A ) == abs ( B ) ) printf ( "4\n" );
        else printf ( "TOO COMPLICATED\n" );
        
    }
    
    return 0;
}
