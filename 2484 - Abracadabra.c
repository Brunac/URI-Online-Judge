#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ( ) {
    char str[999];
    int i, j, k;

    while ( scanf ( "%s", str ) != EOF ) {
        int len = strlen ( str );

        for ( i=0; i<len; i++ ) {
            k = 0;
            printf("%.*s", i, "                                                                                                                                  " );
            for ( j = len - 1 - i; j >= 0; j-- ) {
                printf ( "%c", str[k++] );
                if ( j > 0 ) printf ( " " );
            }
            puts ( "" );
        }
        puts ( "" );
    }
}
