#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct tipoRena {
    char nome[999];
    int peso;
    int idade;
    float altura;
} tipoRena;
 
int ordena_peso (tipoRena * rena1, tipoRena * rena2);
int ordena_idade (tipoRena * rena1, tipoRena * rena2);
int ordena_altura (tipoRena * rena1, tipoRena * rena2);
int ordena_nome (tipoRena * rena1, tipoRena * rena2);
 
int ordena_peso ( tipoRena * rena1, tipoRena * rena2 ) {
    const struct tipoRena * elem1 = rena1;
    const struct tipoRena * elem2 = rena2;
   if ( elem1->peso < elem2->peso ) return 1;
   else if ( elem1->peso > elem2->peso ) return -1;
   else return ordena_idade ( rena1, rena2 );
}
 
int ordena_idade ( tipoRena * rena1, tipoRena * rena2 ) {
    const struct tipoRena * elem1 = rena1;
    const struct tipoRena * elem2 = rena2;
    if ( elem1->idade > elem2->idade ) return 1;
    else if ( elem1->idade < elem2->idade ) return -1;
    else return ordena_altura ( rena1, rena2 );
}
 
int ordena_altura ( tipoRena * rena1, tipoRena * rena2 ) {
    const struct tipoRena * elem1 = rena1;
    const struct tipoRena * elem2 = rena2;
    if ( elem1->altura > elem2->altura ) return 1;
    else if ( elem1->idade < elem2->idade ) return -1;
    else return ordena_nome ( rena1, rena2 );
}
 
int ordena_nome ( tipoRena * rena1, tipoRena * rena2 ) {
    const struct tipoRena * elem1 = rena1;
    const struct tipoRena * elem2 = rena2;
    if ( strcmp ( elem1->nome, elem2->nome) >= 0 ) return 1;
    else return -1;
}
 
/** \n || **/
 
int main ( int argc, char *argv[] ) {
    int casos_teste, total_renas, renas_usadas;
    tipoRena _renas[1999];
    int i, j;
 
    scanf ( "%d", &casos_teste );
    for ( i = 1; i <= casos_teste; i++ ) {
        printf ( "CENARIO {%d}\n", i );
        scanf ( "%d %d", &total_renas, &renas_usadas );
        for ( j = 0; j < total_renas; j++ )
            scanf ( "%s %d %d %f", _renas[j].nome, &_renas[j].peso, &_renas[j].idade, &_renas[j].altura );
        qsort ( _renas, total_renas, sizeof( tipoRena ), (int (*)(const void *,const void *)) ordena_peso );
        for ( j = 0; j < renas_usadas; j++ )
            printf ( "%d - %s\n", j+1, _renas[j].nome );
    }
 
    return 0;
}
