/********************************************************************************************************
* "Bem-vindos e Bem-vindas ao Inverno!"                                                                 *
* Problema 1847 @ URI Online Judge                                                                      *
* Tempo: 0.000                                                                                          *
*                                                                                                       *
* [UFMT] Hiromi Giovana Tanita                                                                          *
*                                                                                                       * 
********************************************************************************************************/

#include<stdio.h>
  
int main ( ) {
    int a, b, c;
    scanf ( "%d %d %d", &a, &b, &c );
  
    if ( a > b && c >= b )
        puts ( ":)" );
    else if ( a < b && c <= b )
        puts ( ":(" );
    else if ( ( b > a && c > b ) && ( ( c-b ) < ( b-a ) ) )
        puts ( ":(" );
    else if ( ( b > a && c > b ) && ( ( c-b ) >= ( b-a ) ) )
        puts ( ":)" );
    else if ( ( b < a && c < b ) && ( ( b - c ) < ( a - b ) ) )
        puts ( ":)" );
    else if ( ( b < a && c < b ) && ( ( b - c ) >= ( a - b ) ) )
        puts ( ":(" );
    else if ( a == b ) {
        if ( c > b )
            puts ( ":)" );
        else
            puts ( ":(" );
    }
  
}
