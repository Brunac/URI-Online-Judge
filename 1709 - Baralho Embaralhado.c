#include <stdio.h>
 
int main() {
    int p, posicao, mudancas;
    while ( scanf ( "%d", &p ) != EOF ) {
        posicao = 2, mudancas = 1;
        while (posicao != 1) {
            if (posicao <= p / 2) posicao = posicao*2;
            else posicao = 2 * posicao - p - 1;
            mudancas++;
        }
        printf ( "%d\n", mudancas );
  }
  return 0;
}
