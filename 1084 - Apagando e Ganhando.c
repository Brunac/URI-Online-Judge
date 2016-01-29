#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct PILHA {
    int dado[100001];
    int indice;
} PILHA;
 
void INSERE ( int valor, PILHA * p ){
    p->dado[++p->indice] = valor;
}
 
int REMOVE ( PILHA * p ){
    return p->dado[p->indice--];
}
 
int main ( int argc, char *argv[] ) {
    PILHA p;
    char entrada[100001];
    int qt_nums, apagar, i;
    while ( 1 ) {
        p.indice = 0;
 
        scanf ( "%d %d", &qt_nums, &apagar );
        if ( qt_nums == 0 && apagar == 0 ) return 0;
        scanf ( "%s", entrada );
 
        for ( i = 0; i < qt_nums; i++ ) {
            while ( p.indice > 0 && p.dado[p.indice] < entrada[i]-'0' && apagar > 0 ) {
                    int r = REMOVE ( &p );
                    apagar -- ;
            }
            INSERE ( entrada[i]-'0', &p );
        }
        while ( apagar-- ) 
            REMOVE ( &p );
 
        for ( i = 1; i <=p.indice; i++ ) 
            printf ( "%d", p.dado[i] );
         
        puts ("");
    }
}
