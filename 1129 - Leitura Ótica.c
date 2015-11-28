#include <stdio.h>
 
int main ( ) {
    int N, A, B, C, D, E, flag, choice;
    while ( 1 ) {
        scanf ( "%d", &N );
        if ( N==0 ) return 0;
        while ( N-- ) {
            flag = 0;
            scanf ( "%d %d %d %d %d", &A, &B, &C, &D, &E );
            if ( A<=127 ) flag++, choice=1;
            if ( B<=127 ) flag++, choice=2;
            if ( C<=127 ) flag++, choice=3;
            if ( D<=127 ) flag++, choice=4;
            if ( E<=127 ) flag++, choice=5;
            if ( flag != 1 ) printf ( "*\n" );
            else {
                if ( choice == 1 ) printf ( "A\n" );
                if ( choice == 2 ) printf ( "B\n" );
                if ( choice == 3 ) printf ( "C\n" );
                if ( choice == 4 ) printf ( "D\n" );
                if ( choice == 5 ) printf ( "E\n" );
            }
        }
    }
}
