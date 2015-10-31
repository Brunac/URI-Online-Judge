/********************************************************************************************************
* "Recuperação da Árvore"                                                                               *
* Problema 1191 @ URI Online Judge                                                                      *
* Tempo: 0.084                                                                                          *
*                                                                                                       *
* [UFMT] Hiromi Giovana Tanita                                                                          *
*                                                                                                       * 
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/************************************************
*   Estrutura da árvore.                        *
************************************************/
typedef struct tipoArvore {
    char valor;
    int peso;
    struct tipoArvore *esquerdo;
    struct tipoArvore *direito;
} tipoArvore;
 
/************************************************
*   Estrutura para o peso de cada letra.        *
************************************************/
typedef struct pesoLetras {
    int peso;
    char letra;
} tipoPeso;
 
/************************************************
*   Função para alocar elementos.               *
************************************************/
tipoArvore *alocaElemento ( char valor, int peso ) {
    tipoArvore *novo = NULL;
    novo = (tipoArvore* ) malloc ( sizeof ( tipoArvore ) );
    novo->esquerdo = NULL;
    novo->valor = valor;
    novo->peso = peso;
    novo->direito = NULL;
    return novo;
}
 
/************************************************
*   Função de inserir na árvore com base no pe- *
* so de cada letra.                             *
************************************************/
void inserirArvore ( tipoArvore **arvore, char valor, int peso ) {
    if ( *arvore == NULL ) {
        *arvore = alocaElemento ( valor, peso );
    }
    else {
        if ( peso < (*arvore)->peso ) {
            inserirArvore ( &(*arvore)->esquerdo, valor, peso );
        }
        else {
            inserirArvore ( &(*arvore)->direito, valor, peso );
        }
    }
}
 
/************************************************
*   Função para imprimir em pós-ordem.          *
************************************************/
void imprimePosOrdem ( tipoArvore *arvore ) {
    if ( arvore != NULL ) {
        imprimePosOrdem ( arvore->esquerdo );
        imprimePosOrdem ( arvore->direito );
        printf ( "%c", arvore->valor );
    }
}
 
/************************************************
*   Função que busca o peso de determinada le-  *
* tra no vetor de struct pesoE.                 *
************************************************/
int retornaPeso ( tipoPeso pesoE[], char letra, int len ) {
    int i, peso;
    for ( i=0; i<len; i++ ) {
        if ( pesoE[i].letra == letra ) {
            peso = i;
            break;
        }
    }
    return peso;
}
 
/************************************************
*   Função principal.                           *
************************************************/
int main ( int argc, char *argv[] ) {
    tipoArvore *arvore;
    tipoPeso pesoE[28];
    char preordem[27], ordem[27];
    int len, i, ps;
 
    /********************************************
    *   Recebe as duas strings, uma com a árvore*
    * em pré-ordem e com a árvore em ordem.     *
    *********************************************/
    while ( scanf ( "%s %s", preordem, ordem ) != EOF ) {
        arvore = NULL;
        len = strlen ( ordem );
 
        /****************************************
        *   Determina-se o peso de cada letra   *
        * tendo como base a string em ordem.    *
        *****************************************/
        for ( i=0; i<len; i++ ) {
            pesoE[i].letra = ordem[i];
            pesoE[i].peso = i;
        }
 
        /****************************************
        *   Manda-se cada elemento da pré-ordem *
        * para a árvore junto do peso desse e-  *
        * elemento em questão.                  *
        *****************************************/
        for ( i=0; i<len; i++ ) {
                ps = retornaPeso ( pesoE, preordem[i], len );
                inserirArvore ( &arvore, preordem[i], ps );
        }
        /****************************************
        *   Imprime a árvore em pós-ordem.      *
        *****************************************/
        imprimePosOrdem ( arvore );
        printf( "\n" );
    }
    return 0;
}
