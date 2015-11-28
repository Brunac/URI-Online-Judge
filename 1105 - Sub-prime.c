#include <stdio.h>
 
typedef struct tipo_banco{
    int devendo, valor, res;
} banco;
 
banco bancos[1000]; 

int main(){
    int l, r, b, n, i, d, c, v;
    while ( 1 ) {
        scanf ( "%d %d", &b, &n );
        if ( b == 0 && n == 0 ) break;
        for (i = 1; i <= b; i++) scanf ( "%d", &bancos[i].res );
        while ( n-- ) {
            scanf ( "%d %d %d", &d, &c, &v );
            bancos[d].devendo = c;
            bancos[d].valor = v;
            bancos[c].res += v;
            bancos[d].res -= v;
            bancos[d].valor -= v;
        }
        l = 1;
        for (i = 1; i <= b; i++){
            if (bancos[i].res < 0) {
                l = 0;
                break;
            }
        }
        if ( l ) printf ( "S\n" );
        else printf ( "N\n" );
    }
}
