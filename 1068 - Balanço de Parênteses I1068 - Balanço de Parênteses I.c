#include <stdio.h>
#include <string.h>
 
typedef struct typeStack {
    char stackarray[1000];
    int index;
} typeStack;
 
 
void pushStack ( char value, typeStack *stack1 ){
    stack1->stackarray[++stack1->index] = value;
}
 
char popStack ( typeStack *stack1 ){
    if ( stack1->index<=0 ) {
        return  '1';
    }
    return stack1->stackarray[stack1->index--];
}
 
 
int main ( int argc, char* argv[] ){
 
    typeStack stack1;
 
    char N[10000];
    char receive;
    int i, repeat, incorrect, lenght;
 
    repeat=0;
 
    while( gets ( N ) != NULL ) {
        stack1.index=0;
        incorrect=0;
        lenght=strlen( N );
 
        for ( i=0; i<lenght; i++ ) {
            if ( N[i]==')' ) {
                receive=popStack ( &stack1 );
                if ( receive=='1' ) {
                    printf ("incorrect\n");
                    incorrect++;
                    continue;
                }
            }
 
            if ( N[i]=='(' ) {
                pushStack ( N[i], &stack1 );
                continue;
            }
        }
 
        if ( stack1.index==0 && incorrect<=0 ) {
            printf ("correct\n");
            continue;
        }
        if ( stack1.index!=0 && incorrect<=0 ) {
            printf ("incorrect\n");
            continue;
        }
    }
    return 0;
}
