/********************************************************************************************************
*                             "Eu Posso Adivinhar a Estrutura de Dados!"                                *
*                                 Problema 1340 @ URI Online Judge                                      *
*                                          Tempo: 0.004                                                 *
*                                                                                                       *
*                                                                         [UFMT] Hiromi Giovana Tanita  *
*                                                                                                       *
********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**********************************************************************
*       Estrutura de dados tipo "sacola", contém a estrutura para     *
* a pilha, fila e lista de prioridades.                               *
**********************************************************************/

typedef struct tipo_sacola {

    int elemento_fila[1000];
    int comeco_fila, final_fila;

    int elemento_pilha[1000];
    int indice_pilha;

    int elemento_lista_prioridade[1000];
    int indice_lista_prioridade;

} tipo_sacola;


/**********************************************************************
*       Funções de inserção e remoção para a Estrutura de Dados       *
*   "FILA" (Queue).                                                   *
**********************************************************************/

void insere_fila ( int valor, tipo_sacola *dado ) {
    dado->elemento_fila[ dado->final_fila++ ] = valor;
}

int remove_fila ( tipo_sacola*dado ) {
    if ( dado->comeco_fila == dado->final_fila ) {
        return -10000000;
    }
    return dado->elemento_fila[ dado->comeco_fila++ ];
}


/**********************************************************************
*       Funções de inserção e remoção para a Estrutura de Dados       *
*   "PILHA" (Stack).                                                  *
**********************************************************************/

void insere_pilha ( int valor, tipo_sacola *dado ){
    dado->elemento_pilha[ ++dado->indice_pilha ] = valor;
}

int remove_pilha ( tipo_sacola *dado ){
    if ( dado->indice_pilha <= 0 ) {
        return  -10000000;
    }
    return dado->elemento_pilha[ dado->indice_pilha-- ];
}


/**********************************************************************
*       Funções de inserção e remoção para a Estrutura de Dados       *
*   "LISTA COM PRIORIDADE" ou "FILA COM PRIORIDADE" (Priority Queue). *
**********************************************************************/

void insere_lista_prioridade ( int valor, tipo_sacola *dado ){
    int indexador_auxiliar;
    indexador_auxiliar = ++dado->indice_lista_prioridade;
    while ( indexador_auxiliar > 1 ) {
        if ( dado->elemento_lista_prioridade[ indexador_auxiliar/2 ] < valor ) {
            dado->elemento_lista_prioridade[ indexador_auxiliar ] = dado->elemento_lista_prioridade[ indexador_auxiliar/2 ];
            indexador_auxiliar=indexador_auxiliar/2;
        } else
            break;
    }
    dado->elemento_lista_prioridade[ indexador_auxiliar ] = valor;
}

int remove_lista_prioridade ( tipo_sacola *dado ) {
    int temporario, atual, proximo;
    if ( dado->indice_lista_prioridade <= 0 ) {
        return  -10000000;
    }

    temporario = dado->elemento_lista_prioridade[ 1 ];
    atual = 1;
    proximo = 2;
    dado->indice_lista_prioridade--;
    while ( proximo <= dado->indice_lista_prioridade ) {
        if ( proximo < dado->indice_lista_prioridade && dado->elemento_lista_prioridade[ proximo+1 ] > dado->elemento_lista_prioridade[ proximo ] ) {
            proximo++;
        }
        if( dado->elemento_lista_prioridade[ proximo ] > dado->elemento_lista_prioridade[ dado->indice_lista_prioridade+1 ] ) {
            dado->elemento_lista_prioridade[ atual ] = dado->elemento_lista_prioridade[ proximo ];
            atual = proximo;
            proximo = atual*2;
        } else
            break;
    }
    dado->elemento_lista_prioridade[ atual ] = dado->elemento_lista_prioridade[ dado->indice_lista_prioridade+1 ];
    return temporario;
}


/**********************************************************************
*       Função Principal.                                             *
**********************************************************************/


int main ( int argc, char *argv[] ) {
    int comando, valor;
    int n, i;
    int flag[ 3 ];
    int recebido;

    tipo_sacola data;

    while ( scanf ( "%d", &n ) != EOF ) {
        memset ( flag, 0, sizeof( flag ) );

        data.comeco_fila = 0;
        data.final_fila = 0;
        data.indice_pilha = 0;
        data.indice_lista_prioridade = 0;

        for ( i=0; i<n; i++ ) {
            scanf( "%d %d", &comando, &valor );
            /*********************************************************
            *   Se o comando for 1, insere o elemento em todas as    *
            * estruturas.                                            *
            **********************************************************/

            if ( comando == 1 ) {
                insere_fila ( valor, &data );
                insere_pilha ( valor, &data );
                insere_lista_prioridade ( valor, &data );
            }

            /*********************************************************
            *   Se o comando for 2, remove o elemento em todas as    *
            * estruturas.                                            *
            **********************************************************/
            else {
                recebido = remove_fila ( &data );
                /*****************************************************
                *  Compara o valor obtido ao fazer a remoção das     *
                * estruturas com o dado recebido. Se forem diferentes*
                * a flag deve ser 'ativada', identificando que o     *
                * resultado não pode ser a estrutura correspondente. *
                ******************************************************/
                if ( recebido != valor ) {
                    flag[0] = 1;
                }
                recebido = remove_pilha ( &data );
                if ( recebido != valor ) {
                    flag[1] = 1;
                }
                recebido = remove_lista_prioridade ( &data );
                if ( recebido != valor ) {
                        flag[2] = 1;
                }
            }
        }

        /*************************************************************
        *   No caso de todas as três flags terem sido ativadas, não  *
        * pode ser nenhuma das três estruturas, portanto, impossível.*
        **************************************************************/
        if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] == 3 )
            printf ( "impossible\n" );

        /*************************************************************
        *   No caso de terem sobrado duas flags não ativadas, pode   *
        * duas estruturas diferentes, portanto, sem certeza          *
        **************************************************************/
        else
            if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] < 2 )
                printf ( "not sure\n" );
        /*************************************************************
        *   Se apenas uma flag não tiver sido ativada, é essa a      *
        * estrutura utilizada.                                       *
        **************************************************************/
        else {
            if ( !flag[0] ) printf ( "queue\n" );
            if ( !flag[1] ) printf ( "stack\n" );
            if ( !flag[2] ) printf ( "priority queue\n" );
        }
    }
    return 0;
}
