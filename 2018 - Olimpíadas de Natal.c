#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef struct country {
	char name[999];
	int g, s, b;
} country;

int sortname ( country *c1, country *c2 ) {
	const struct country * elem1 = c1, * elem2 = c2;
	if ( strcmp ( elem1->name, elem2->name) >= 0 ) return 1;
	else return -1;
}

int sortbronze ( country * c1, country * c2 ) {
	const struct country * elem1 = c1, * elem2 = c2;
	if ( elem1-> b < elem2-> b ) return 1;
	else if ( elem1->b > elem2->b ) return -1;
	else return sortname ( c1, c2 );
}

int sortsilver ( country * c1, country * c2 ) {
	const struct country * elem1 = c1, * elem2 = c2;
	if ( elem1-> s < elem2-> s ) return 1;
	else if ( elem1->s > elem2->s ) return -1;
	else return sortbronze ( c1, c2 );
}

int sortgold ( country * c1, country * c2 ) {
	const struct country * elem1 = c1, * elem2 = c2;
	if ( elem1-> g < elem2-> g ) return 1;
	else if ( elem1->g > elem2->g ) return -1;
	else return sortsilver ( c1, c2 );
}


int main ( ) {
	char p[999], aux[999];
	country c[999];
	int total=0, i, f;
	
	while ( gets(p) != NULL ) {
		gets ( aux );
		f=0;
		for ( i=0; i<total; i++ ) {
			if ( !strcmp( c[i].name, aux ) ) {
				c[i].g++;
				f=1;
			}
		}
		if ( !f ) {
			strcpy ( c[total].name, aux );
			c[total].g=1, c[total].b=c[total].s=0;
			total++;
		}
		gets ( aux );
		f=0;
		for ( i=0; i<total; i++ ) {
			if ( !strcmp( c[i].name, aux ) ) {
				c[i].s++;
				f=1;
				break;
			}
		}
		if ( !f ) {
			strcpy ( c[total].name, aux );
			c[total].s=1, c[total].b=c[total].g=0;
			total++;
		}
		
		gets ( aux );
		f=0;
		for ( i=0; i<total; i++ ) {
			if ( !strcmp( c[i].name, aux ) ) {
				c[i].b++;
				f=1;
			}
		}
		if ( !f ) {
			strcpy ( c[total].name, aux );
			c[total].b=1, c[total].g=c[total].s=0;
			total++;
		}
	}
	qsort ( c, total, sizeof(country), (int (*)(const void *,const void *)) sortgold );
	puts ( "Quadro de Medalhas" );
	for ( i=0; i<total; i++ ) {
		printf ( "%s %d %d %d\n", c[i].name, c[i].g, c[i].s, c[i].b );
	}
}
