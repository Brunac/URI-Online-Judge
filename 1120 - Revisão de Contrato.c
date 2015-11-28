#include<stdio.h>
#include<string.h>
 
int main ( ) {
    int len, i, zero_flag, empty_flag;
    char input[8888], N;
    while ( 1 ) {
        scanf ( "%c\n", &N );
        scanf ( "%s", input );
        if ( N == '0' || strcmp ( input, "0" ) == 0 ) return 0;
        len = strlen ( input );
        empty_flag = 1, zero_flag = 0;
        for ( i=0; i<len; i++ ) {
            if ( input[i] == '0' && zero_flag == 2 ) printf ( "%c", input[i] );
            if ( input[i] != '0' && N!='0' && input[i] != N ) {
                printf ( "%c", input[i] );
                empty_flag = 0;
                zero_flag = 2;
            }
        }
        if ( N!= '0' && empty_flag == 1 && zero_flag == 1 ) printf ( "0" );
        else if ( N!='0' && empty_flag == 1 ) printf ( "0" );
        puts ( "" );
        getchar();
    }
}
