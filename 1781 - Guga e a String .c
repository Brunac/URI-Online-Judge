#include<stdio.h>
#include<string.h>
 
int main ( int argc, char *argv[] ) {
     
    int len, i, k;
    int T, Q;
    int cmd, qt, total_consoantes, total_vogais, roda_consoantes, roda_vogais;
 
    scanf ( "%d", &T );
    for ( k = 1; k <= T; k++ ) {
        total_consoantes=total_vogais=0;
 
        char entrada[99999] = {};
        char aux[99999] = {};
        int pos_consoantes[99999] = {};
        int pos_vogais[99999] = {};
 
 
        scanf ( "%s", entrada );
        len = strlen ( entrada );
        for ( i = 0; i < len; i++ ) {
            if ( entrada[i]=='a' || entrada[i]=='e' || entrada[i]=='i' || entrada[i]=='o' || entrada[i]=='u' ) pos_vogais[total_vogais++] = i;
            else pos_consoantes[total_consoantes++] = i;
        }
        roda_consoantes = roda_vogais = 0;
        scanf ( "%d", &Q );
        printf ( "Caso #%d:\n", k );
        while ( Q-- ) {
            scanf ( "%d", &cmd );
            if ( cmd == 0 ) {
                scanf ( "%d", &qt );
                roda_vogais += qt;
            }
            if ( cmd == 1 ) {
                scanf ( "%d", &qt );
                roda_consoantes += qt;
            }
            if ( cmd == 2 ) {
 
                if ( roda_vogais > 0 ) {
                    strcpy ( aux, entrada );
                    for ( i=0; i<total_vogais; i++ ) entrada[ pos_vogais[ (i+roda_vogais)%(total_vogais) ] ] = aux[ pos_vogais[i] ];
                }
                if ( roda_consoantes > 0 ) {
                    strcpy ( aux, entrada );
                    for ( i=0; i<total_consoantes; i++ ) entrada[ pos_consoantes[ (i+roda_consoantes)%total_consoantes ] ] = aux[ pos_consoantes[i] ];
                }
                roda_vogais = roda_consoantes = 0;
                printf ( "%s", entrada );
                puts ("");
            }
        }
    }
    return 0;
}
