#include<stdio.h>
#include<string.h>
 
int arr[100009];
 
int main ( ) {
    int n, k, i, ki;
 
    while ( scanf ( "%d %d", &n, &k ) != EOF ) {
        memset ( arr, 0, sizeof(arr) );
        for ( i = 0; i < n; i++ ) {
            scanf ( "%d", &ki );
            arr[ki]++;
            if ( arr[ki] == 1 ) {
                if ( i == 0 ) printf ( "%d", ki );
                else printf ( " %d", ki );
            }
        }
        puts ( "" );
    }
 
}
