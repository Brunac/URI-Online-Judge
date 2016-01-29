#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct dataType {
    char data_stack[1000];
    int stackIndex;
} dataType;
 
void pushStack ( char value, dataType *data ){
    data->data_stack[++data->stackIndex] = value;
}
 
char popStack ( dataType *data ){
    if ( data->stackIndex<=0 ) {
        return  'F';
    }
    return data->data_stack[data->stackIndex--];
}
 
int main ( int argc, char *argv[] ) {
 
    dataType stack1;
 
    int N, lenght, i, total;
    char diamonds[10000];
    char recept;
 
    scanf ( "%d\n", &N );
 
    while ( N-- ) {
 
        total=0;
        stack1.stackIndex=0;
 
        gets(diamonds);
        lenght = strlen ( diamonds );
 
        for ( i=0; i<lenght; i++ ) {
            if ( diamonds[i]=='<' ) pushStack( diamonds[i], &stack1 );
            if ( diamonds[i]=='>' ) {
                recept=popStack ( &stack1 );
                if ( recept=='<' ) total++;
            }
        }
        printf ( "%d\n", total );
    }
 
    return 0;
}
