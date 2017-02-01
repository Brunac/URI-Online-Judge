#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// gambiarras ftw

int main ( int argc, char *argv[] ) {
    int N, i;

    while ( scanf ( "%d", &N ) != EOF ) {
        int half = N/2;
        for ( i=1; i<=N; i=i+2 ) {
            printf("%.*s", half, "                                                                      " );
            printf("%.*s", i, "**************************************************************************************************************" );
            puts ( "" );
            half--;
        }
        half = N/2;
        printf("%.*s", half, "                                                                      " );
        printf("%.*s", 1, "**************************************************************************************************************" );
        puts ( "" );
        printf("%.*s", half-1, "                                                                      " );
        printf("%.*s", 3, "**************************************************************************************************************" );
        puts ( "" );
        puts ( "" );
    }

    return 0;
}
