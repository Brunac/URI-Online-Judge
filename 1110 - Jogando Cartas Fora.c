/********************************************************************************************************
* "Jogando Cartas Fora"                                                                                 *
* Problema 1110 @ URI Online Judge                                                                      *
* Tempo: 0.076                                                                                          *
*                                                                                                       *
* [UFMT] Hiromi Giovana Tanita                                                                          *
*                                                                                                       * 
********************************************************************************************************/
 
#include <stdio.h>
 
/**********************************************************************
*       Struct com um vetor que representa o baralho de cartas e      *
*   os índices de começo e fim da estrutura.                          *
**********************************************************************/
typedef struct typeDeck {
    int cards[200];
    int head, tail;
} typeDeck;
 
/**********************************************************************
*       Função para inserir as cartas no fundo do baralho após a      *
*   anterior ser descartada.                                          *
**********************************************************************/
void pushDeck ( typeDeck*deck, int n ) {
    deck->cards[deck->tail++] = n;
}
 
/**********************************************************************
*       Função para remover a carta que está no topo do baralho.      *
**********************************************************************/
int popDeck ( typeDeck*deck ) {
    return deck->cards[deck->head++];
}
 
/**********************************************************************
*       Função Principal.                                             *
**********************************************************************/
int main ( int argc, char argv[] ) {
    typeDeck deck;
    int n, i, value, drinkme, discarded;
 
    while ( scanf ( "%d", &n ) != EOF ) {
        drinkme = 0;
        deck.tail = n;
        deck.head = 0;
 
        /**********************************************************************
        *       O laço deve fazer loop até o valor de entrada ser "zero",     *
        *   então o programa acaba e não mostra nada.                         *
        **********************************************************************/
        if ( n == 0 )
            return 0;
            
        /**********************************************************************
        *       Laço para preencher o deck de acordo com o valor de entrada   *
        **********************************************************************/
        for ( i = 0; i < n; i++ )
            deck.cards[i] = i + 1;
 
        /**********************************************************************
        *       Enquanto houve mais de uma carta no baralho, o laço deve ser  *
        *   executado.                                                        *
        **********************************************************************/
        while ( deck.head != deck.tail - 1 ) {
 
            /**********************************************************************
            *       Uma carta deve ser removida enquanto a seguinte deve ser re-  *
            *   colocada na fila.                                                 *
            *   Obs: Uma referência a Alice in Wonderland devia ser obrigatória.  *                                                      *
            **********************************************************************/
            if ( drinkme == 0 ) {
                discarded=popDeck ( &deck );
 
                /**********************************************************************
                *       A primeira carta SEMPRE será a primeira a ser descartada.     *
                *   Seguindo o exemplo correto de saída do URI.                       *
                **********************************************************************/
                if ( discarded == 1 )
                    printf ( "Discarded cards: %d", discarded );
                else
                    printf ( ", %d", discarded );
                    
                /**********************************************************************
                *       A variável contadora é incrementada para que a próxima carta  *
                *   seja colocada no final da fila.                                   *
                **********************************************************************/
                drinkme++;
            }
            else {

                /**********************************************************************
                *       A carta seguinte é removida do topo e colocada no final do    *
                *   baralho.                                                          *
                **********************************************************************/
                value=popDeck ( &deck );
                pushDeck ( &deck, value );
 
                /**********************************************************************
                *       A variável contadora é decrementada para que a próxima carta  *
                *   seja descartada.                                                  *
                **********************************************************************/
                drinkme--; //Variável decrementada para que a próxima carta seja removida
            }
        }
 
        /**********************************************************************
        *       Quando restar apenas uma carta, a posição "tail-1" vai ser a  *
        *   carta restante.                                                   *
        **********************************************************************/
        printf ("\n");
        printf ("Remaining card: %d\n", deck.cards[deck.tail-1]);
    }
}
