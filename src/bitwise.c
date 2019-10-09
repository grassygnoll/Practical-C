/* 
   MIT 6087, Practical Programming in C
   Assignment 2, Problem 2.3
   Create bitwise operator expressions to manipulate the integer 0xCAFE

   BAW, 04/02/2015
*/

#include <stdio.h>
#include "convert.h"

/* MAIN entry of code */
int main(void) {
   int val = 0xCAFE ;

   // Here we bitwise 'And' our value val with all 1's (0xF = 1111) 
   // Thus, our possible successful output values would be 1111 (0xF), 
   // 1110 (0xE), 1101 (0xD), 1011 (0xB), and 0111 (0x7) to answer our
   // first question: 
   // 1. Test if at least 3 of last 4 bits (LSB) are on...
   printf( "\nOriginal value: '0x%X'\n\n", val ) ;
   printf( "Question 1: Are 3 of last 4 bits (LSB) on?\n" ) ;
   printf( "\tThe HEX value: '0x%X' = %i in signed decimal\n", val, val ) ;
   printf( "\tThe HEX value: '0x%X' = %u in unsigned decimal\n", val, val ) ;

   int i = 0 ;
   int newVal = val ;
   while( newVal != 0x0 ) {
      i++ ;
      //printf( "Into while loop, cnt = %i, val = '0x%X', newVal = '0x%X'\n", i, val, newVal ) ;

      int hex2eval = newVal & 0xF ;
      char* binval = hex2bin(hex2eval) ;
      printf( "\tThe HEX value: '0x%X' = %s in binary\n", hex2eval, binval ) ;
      newVal = newVal >> 4 ;
   }
   
   int bits = val & 0xF ;
   if( bits == 0x7 || bits == 0xB || bits >= 0xD ) 
      printf( "\n\tConfirmed: At least 3 of the last 4 bits (LSB) are on.\n\n" ) ;

   // 2. Reverse the byte order (i.e. change 0xCAFE to 0xFECA)
   printf( "Question 2: Reverse the byte order (change 0xCAFE to 0xFECA).\n" ) ;
   // Broke this into component steps for clarity. Question 3 below, I did in 1 step.
   int rshift = val >> 8 ;
   int anded = val & 0xFF ;
   // The '+' works here, but the point is you can use '|' as well between the main 
   // expressions to accomplish the same result. 
   // int reverse = ((val & 0xFF) << 8) | (val >> 8)
   int reverse = (anded << 8) + rshift ;
   printf( "\tRight shifted by 8 = '0x%X'\n", rshift ) ;
   printf( "\tAnded with '0xFF'  = '0x%X'\n", anded ) ;
   printf( "\tReversed           = '0x%X'\n\n", reverse ) ;

   // 3. Rotate 4 bits (i.e. change 0xCAFE to 0xECAF)
   printf( "Question 3: Rotate four bits (change 0xCAFE to 0xECAF).\n" ) ;
   // Basically - shift off the right hex value (E), resulting in 0xCAF,
   // then add that value to the right shifted value left shifted 12 bits (0xE000).
   // Result should be 0xCAF + 0xE000 = 0xECAF.  Can also or '|' them together:
   // int rightRotate = (val >> 4 ) | ((val & 0xF) << 12) ;
   int rightRotate = (val >> 4) | ((val & 0xF) << 12) ;
   printf( "\tRotated            = '0x%X'\n\n", rightRotate ) ;

   return 0 ;
}

