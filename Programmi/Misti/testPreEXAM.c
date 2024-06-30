
#include <stdio.h>
int x = 12 ;
 int main ( ) {
 int y = 2 ;
 int *p;
 {
 int y = 4 ;
 if (y>2) {
 int x = 2 ;
 p = &x ;
 *p += 8 ;
 printf( "%d\n" , x/4*2) ;
 }
 printf( "%d %d\n" , x , y ) ;
 }
 printf( "%d\n" , *p) ;
 }