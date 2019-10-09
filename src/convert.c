/* 
   MIT 6087, Practical Programming in C
   Assignment 2, Problem 2.3
   Create bitwise operator expressions to manipulate the integer 0xCAFE

   BAW, 04/02/2015
   convert.c :: Implements the conversion function(s) used in bitwise.c
*/

/************************************
 *  hex2bin()
 *
 *   Accepts a hex value (form of 0xF)
 *   Returns a four character string representing the binary representation of the hex value
*****************************************/
char* hex2bin(int hval) {
   char* binval ;

   switch(hval) {
      case 0x0:
         binval = "0000\0" ;
         break ;
      case 0x1:
         binval = "0001\0" ;
         break ;
      case 0x2:
         binval = "0010\0" ;
         break ;
      case 0x3:
         binval = "0011\0" ;
         break ;
      case 0x4:
         binval = "0100\0" ;
         break ;
      case 0x5:
         binval = "0101\0" ;
         break ;
      case 0x6:
         binval = "0110\0" ;
         break ;
      case 0x7:
         binval = "0111\0" ;
         break ;
      case 0x8:
         binval = "1000\0" ;
         break ;
      case 0x9:
         binval = "1001\0" ;
         break ;
      case 0xA:
         binval = "1010\0" ;
         break ;
      case 0xB:
         binval = "1011\0" ;
         break ;
      case 0xC:
         binval = "1100\0" ;
         break ;
      case 0xD:
         binval = "1101\0" ;
         break ;
      case 0xE:
         binval = "1110\0" ;
         break ;
      case 0xF:
         binval = "1111\0" ;
         break ;
      default:
         binval = "\0" ;
         break ;
   }

   return binval ;
}

