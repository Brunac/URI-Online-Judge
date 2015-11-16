#include<stdio.h>
#include<string.h>
 
int mcc ( int v[], int n, int s ) {
 
    int ansr[s+1];
    int i, j;
 
    memset ( ansr, 1000009, sizeof(ansr) );
    ansr[0] = 0;
 
    for ( i=0; i<=s; i++ ) {
        for ( j=0; j<n; j++ ) {
            if ( v[j] <= i && ansr[i - v[j]] + 1 < ansr[i] ) ansr[i] = ansr[i - v[j]] + 1;
        }
    }
 
    return ansr[s];
}
 
int main ( ) {
 
    int t, n, m, i;
    int blocks[26];
 
    scanf ( "%d", &t );
    while ( t-- ) {
        scanf ( "%d %d", &n, &m );
        for ( i = 0; i < n; i++ ) scanf ( "%d", &blocks[i] );
        printf ( "%d", mcc( blocks, n, m ) );
        puts ( "" );
    }
 
    return 0;
}
