#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ( int argc, char *argv[] ) {
	
	char num[1000];

	// Usando string para ler o número pois estoura o inteiro
	while ( scanf ( "%s", &num ) ) {
		int len = strlen ( num ), i;
		if ( num[0] == '-' )
			return 0;

		if ( ( len == 1 && num[0] == '0' ) || ( len == 1 && num[0] == '1' ) )
			puts ( "0" );

		else {
			// Se o último número for 0 deve decrementar o número vizinho de acordo
			if ( num[len-1] == '0' ) {
				i = 1;
				while ( i <= len && num[len-i] == '0' ) {
					num[len-i] = '9';
					i++;
				}
				if ( i <= len && num[len-i] != '0' )
					num[len-i]--;
			}
			else 
				num[len-1]--;

			// Imprime o número final ignorando zeros a esquerda
			for ( i = 0; i < len; i++ )
				if ( !(num[i] == '0' && i == 0) )
					printf ( "%c", num[i] );
			puts ( "" );
		}
	}
}
