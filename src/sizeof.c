/*
   MIT 6087, Practical Programming in C
   Assignment 2, Problem 2.1
   Determining the size of various data types

   BAW, 10/22/2014
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
   char c = 'A' ;
   unsigned char d = 'B' ;
   short s = 200 ;
   int x = 1500 ;
   unsigned int z = 9999 ;
   unsigned long l = 99999999 ;
   float f = 9999.9999 ;

   int y = sizeof(c) ;
   printf( "c = %c\tsizeof(c) = %i\n", c, y ) ;
   y = sizeof(d) ;
   printf( "d = %c\tsizeof(d) = %i\n", d, y ) ;
   y = sizeof(s) ;
   printf( "s = %i\tsizeof(s) = %i\n", s, y ) ;
   y = sizeof(x) ;
   printf( "x = %i\tsizeof(x) = %i\n", x, y ) ;
   y = sizeof(z) ;
   printf( "z = %i\tsizeof(z) = %i\n", z, y ) ;
   y = sizeof(l) ;
   printf( "l = %lu\tsizeof(l) = %i\n", l, y ) ;
   y = sizeof(z) ;
   printf( "f = %f\tsizeof(f) = %i\n", f, y ) ;

   return 0 ;
}

