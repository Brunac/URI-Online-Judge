#include<stdio.h>
 
int max(int a, int b) { 
  return (a > b)? a : b; 
}
 
int knapSack(int W, int wt[], int val[], int n) {

   int i, w, K[n+1][W+1];

   for ( i = 0; i <= n; i++ ) {
       for ( w = 0; w <= W; w++ ) {
           if ( i == 0 || w == 0 )
               K[i][w] = 0;
           else if ( wt[i-1] <= w )
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main() {
    int N, T, C, V, i, j;
    int pos=0;
    int val[199999];
    int wt [199999];
    scanf ( "%d %d", &N, &T );
    for ( i=0; i<N; i++ ) {
        scanf ( "%d %d", &C, &V );
        for ( j=0; j<T/C; j++ ) {
            wt[pos] = C;
            val[pos] = V;
            pos++;
        }
    }
    printf( "%d", knapSack( T, wt, val, pos ) );
    puts ( "" );
    return 0;
}
