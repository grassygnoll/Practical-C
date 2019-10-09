/* 
   MIT 6087, Practical Programming in C
   Assignment 3, Problem 3.1
   Register variable profiling via Fibonacci Sequence

   BAW, 04/03/2015
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25
static unsigned int results_buffer[NMAX] ;

void fibonacci() {
   /*unsigned int a = 0 ;
   unsigned int b = 1 ;
   unsigned int c ;
   int n ;*/
   register unsigned int a = 0 ;
   register unsigned int b = 1 ;
   register unsigned int c ;
   register int n ;

   results_buffer[0] = a ;
   results_buffer[1] = b ;
   for( n = 2; n < NMAX; n++ ) {
      c = a + b ;
      results_buffer[n] = c ;
      a = b ;
      b = c ;
   }
}

int main( void ) {
   int n, ntests = 10000000 ;
   clock_t tstart, tend ;
   double favg ;

   /* Begin Profiling */
   tstart = clock() ;

   for( n = 0; n < ntests ; n++ )
      fibonacci() ;

   tend = clock() ;
   /* End of Profiling */

   favg = ((double)(tend -tstart))/CLOCKS_PER_SEC/ntests ;
   printf("Avg. execution time: %8.6f msec\n", favg*1000) ;
   return 0 ;
}

