/* 
   MIT 6087, Practical Programming in C
   Assignment 3, Problem 3.3
   Rewrite a standard for loop and do while loop as a simple while loop

   BAW, 04/03/2015
*/

#include <stdio.h>

// Original
int factorial(int n) {
   int i, ret = 1 ;
   for( i = 2; i <= n; i++ )
      ret *= i ;
   return ret ;
}

// Turned into a while loop
int factorial2(int n) {
   int ret = 1 ;
   while( n > 0 ) {
      ret *= n ;
      n-- ;
   }
   return ret ;
}

// Main entry point of code
int main() {
   int seed = 0 ;
   int answer = 0 ;
   int answer2 = 0 ;

   answer = factorial(seed) ;
   printf( "%d factorial =  %d\n", seed, answer ) ;

   answer2 = factorial2(seed) ;
   printf( "%d factorial2 = %d\n", seed, answer2 ) ;

   return 0 ;
}

