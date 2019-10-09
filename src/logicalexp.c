/* 
   MIT 6087, Practical Programming in C
   Assignment 2, Problem 2.2
   Create logical expressions to test a character variable for numerous values

   BAW, 10/22/2014
*/

#include <stdio.h>

int main(void) {
   char c ;

   /* 48 to 57 = digit; 65 to 90 = upper case; 97-122 = lower case */
   /*
   for( int i = 65; i <= 122; ++i )
      printf( "%i, char value = %c\n", i, i ) ;
   */

   while( (c = getchar()) != '\0') {
      if( c != '\n' ) {
         if( c >= 48 && c <= 57 )
            printf( "%c (int value = %i)\tDigit\n", c, c ) ;
         else if( c >= 65 && c <= 90 )
            printf( "%c (int value = %i)\tUppercase Letter\n", c, c ) ;
         else if( c >= 97 && c <= 122 )
            printf( "%c (int value = %i)\tLowercase Letter\n", c, c ) ;
         else if( c == 9 || c == 32 )
            printf( "%c (int value = %i)\tWhite Space\n", ' ', c ) ;
         else if( c != 10 )
            printf( "%c (int value = %i)\tOther\n", c, c ) ;
      } else 
         printf( "%c (int value = %i)\tWhite Space\n", ' ', c ) ;
   }

   return 0 ;
}

