#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoCamiseta {
    char nome[999];
    char cor[999];
    char tamanho[2];
} tipoCamiseta;

int ordena_cor ( tipoCamiseta * c1, tipoCamiseta * c2 );
int ordena_tam ( tipoCamiseta * c1, tipoCamiseta * c2 );
int ordena_nome ( tipoCamiseta * c1, tipoCamiseta * c2 );

int ordena_cor ( tipoCamiseta * c1, tipoCamiseta * c2 ) {
    const struct tipoCamiseta * elem1 = c1;
    const struct tipoCamiseta * elem2 = c2;
    if ( strcmp ( elem1->cor, elem2->cor ) > 0 ) return 1;
    else if ( strcmp ( elem1->cor, elem2->cor ) < 0 ) return -1;
    else return ordena_tam ( c1, c2 );
}

int ordena_tam ( tipoCamiseta * c1, tipoCamiseta * c2 ) {
    const struct tipoCamiseta * elem1 = c1;
    const struct tipoCamiseta * elem2 = c2;
    if ( strcmp ( elem1->tamanho, elem2->tamanho ) < 0 ) return 1;
    else if ( strcmp ( elem1->tamanho, elem2->tamanho ) > 0 ) return -1;
    else return ordena_nome ( c1, c2 );
}

int ordena_nome ( tipoCamiseta * c1, tipoCamiseta * c2 ) {
    const struct tipoCamiseta * elem1 = c1;
    const struct tipoCamiseta * elem2 = c2;
    if ( strcmp ( elem1->nome, elem2->nome ) >= 0 ) return 1;
    else return -1;
}

int main ( int argc, char *argv[] ) {
    int N, i, f=0;
    tipoCamiseta c[999];

    while ( 1 ) {
        scanf ( "%d", &N );
        if ( N == 0 ) return 0;
        if ( f > 0 ) puts ( "" );
        for ( i=0; i<N; i++ ) {
            getchar();
            gets ( c[i].nome );
            scanf ( "%s %s", c[i].cor, c[i].tamanho );
        }
        qsort ( c, N, sizeof( tipoCamiseta ), (int (*)(const void *,const void *)) ordena_cor );
        for ( i=0; i<N; i++ ) {
            printf ( "%s %s ", c[i].cor, c[i].tamanho );
            puts ( c[i].nome );
        }
        f++;
    }


    return 0;
}

