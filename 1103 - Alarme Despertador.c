#include<stdio.h>
 
int main ( ) {
  int H1, M1, H2, M2, minutes, hours, total, minhours, i;
   
  while ( 1 ) {
    scanf ( "%d %d %d %d", &H1, &M1, &H2, &M2 );
    minutes = hours = total = 0;
     
    if (H1==0 && M1==0 && H2==0 && M2==0) return 0;
     
    if ( H2>=H1 && M1<=M2 ) {
      hours=H2-H1;
      hours=hours*60;
      minutes=M2-M1;
      total=hours+minutes;
    }
    if ( H2>H1 && M1>M2 ) {
      hours=H2-H1;
      minutes=M1-M2;
      hours=hours*60;
      total=hours-minutes;
       
    }
    if ( H2<H1 && M1<=M2 ) {
      hours=(24-H1)+H2;
      hours=hours*60;
      minutes=M2-M1;
      total=hours+minutes;
    }
     
    if ( H2<=H1 && M1>M2 ) {
      hours=(24-H1)+H2;
      hours=hours*60;
      minutes=M1-M2;
      total=hours-minutes;
    }    
    printf ("%d\n", total);
  }
}
