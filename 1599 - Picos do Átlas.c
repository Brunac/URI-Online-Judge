#include<stdio.h>
#include<stdlib.h>
 
typedef struct solution {
   int p1;
   int p2;   
}typeSolution;
 
int main () {
   int mat[1002][1002];
   int N, M, s;
   int i, j, flag;
   int round=0;
   typeSolution So[1002];
   while ( scanf ( "%d %d", &N, &M ) != EOF ) {
      for ( i=1; i<=N; i++ ) {
         for ( j=1; j<=M; j++ ) {
            scanf ( "%d", &mat[i][j] );
         }
      }
      s=0;
      flag = 0;
       
      if ( N==1 && M==1 ) {
         flag=-1;
         printf ( "1 1\n" );
      }
      if ( N!=1 && M==1 ) {
         for ( i=1; i<=N; i++ ) {
            if ( i==1 ) {
               if ( mat[i][1] > mat[i+1][1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
            }
            if ( i==N ) {
               if ( mat[i][1] > mat[i-1][1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
            }
            if ( i!=1 && i!=N ) {
               if ( mat[i][1] > mat[i-1][1] && mat[i][1] > mat[i+1][1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
 
            }
         }
      }
      if ( N==1 && M!=1 ) {
         for ( j=1; j<=M; j++ ) {
            if ( j == 1 ) {
               if ( mat[1][j] > mat[1][j+1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
            }
 
            if ( j==M ) {
               if ( mat[1][j] > mat[1][j-1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
 
            }
 
            if ( j!=1 && j!=M ) {
               if ( mat[1][j] > mat[1][j-1] && mat[1][j] > mat[1][j+1] ) {
                  flag++;
                  So[flag].p1 = i;
                  So[flag].p2 = j;
               }
            }
         }
 
      }
      if ( N!=1 && M!=1 ) {
         for ( i=1; i<=N; i++ ) {
            for ( j=1; j<=M; j++ ) {
               if ( i==1 && j==1 ) {
                  //1st pos
                  if ( mat[i][j] > mat[i+1][j] && mat[i][j] > mat[i+1][j+1] && mat[i][j] > mat[i][j+1] ) {
                     flag++;
                     So[flag].p1 = i;
                     So[flag].p2 = j;
                  }
               }
               if ( i==N && j==M ) {
                  //last pos
                  if ( mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j-1] && mat[i][j] > mat[i][j-1] ) {
                     flag++;
                     So[flag].p1 = i;
                     So[flag].p2 = j;
                  }
               }
               if ( i==1 && j!=1 ) {
                  if ( i!=N && j==M ) {
                     //i.i
                     if ( mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i+1][j-1] && mat[i][j] > mat[i+1][j] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
                  if ( i!=N && j!=M ) {
                     //i.ii
                     if ( mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i][j+1] && mat[i][j] > mat[i+1][j-1]&& mat[i][j] > mat[i+1][j] && mat[i][j] > mat[i+1][j+1] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
               }
               if ( i!=1 && j==1 ) {
                  if ( i==N && j!=M ) {
                     //ii.i
                     if ( mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j+1]&& mat[i][j] > mat[i][j+1] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
                  if ( i!=N && j!=M ) {
                     //ii.ii
                     if ( mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j+1]&& mat[i][j] > mat[i][j+1]&& mat[i][j] > mat[i+1][j]&& mat[i][j] > mat[i+1][j+1] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
 
               }
               if ( i!=1 && j!=1 ) {
                   
                  if ( i!=N && j==M ) {
                     if ( mat[i][j] > mat[i-1][j-1] && mat[i][j] > mat[i-1][j]&& mat[i][j] > mat[i][j-1]&& mat[i][j] > mat[i+1][j-1]&& mat[i][j] > mat[i+1][j] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
 
                  if ( i==N && j!=M ) {
                     if ( mat[i][j] > mat[i-1][j-1] && mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j+1] && mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i][j+1] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
 
                  }
                  //ok, verify all 8 position
                  if ( i!=N && j!=M ) {
                     if ( mat[i][j] > mat[i-1][j-1] && mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j+1]&& mat[i][j] > mat[i][j-1]&& mat[i][j] > mat[i][j+1]&& mat[i][j] > mat[i+1][j-1]&& mat[i][j] > mat[i+1][j]&& mat[i][j] > mat[i+1][j+1] ) {
                        flag++;
                        So[flag].p1 = i;
                        So[flag].p2 = j;
                     }
                  }
               }
            }
         }
      }
      if ( flag == 0 ) printf ( "-1\n" );
      else {
         for ( i=1; i<=flag; i++ ) {
            printf ( "%d %d\n", So[i].p1, So[i].p2 );
         }
      }
      round++;
      printf ( "\n" );
   }
   return 0;
 
    
}
