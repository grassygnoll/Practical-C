/******************************************************************************
 * my_strops.c                                                                *
 *                                                                            *
 * Problem 4.2 from MIT Practical C Programming Course; implementation of     *
 * strtok() function via the strspn() function.                               *
 *                                                                            *
 * Ben Wheeless, 10/19/2019                                                   *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/******************************************************************************
 * strpos() - accepts a string and a character; returns the index of the      *
 *            first occurrence of character within string or -1 if not found. *
 *****************************************************************************/
int strpos(const char * str, const char ch) {
    int i, len = strlen(str) ;

    for(i=0; i<len; i++)
        if(str[i] == ch)
            return i ;

    return -1 ;
}

/******************************************************************************
 * strspn() - accepts a string and set of delimiters; returns the index       *
 *            within the string of the first non-delimiter character.         *
 *****************************************************************************/
unsigned int mystrspn(const char * str, const char * delims) {
    int i, len = strlen(str) ;

    /* For each character of str, see if it is in delimiter characters */
    /* If not, return index of character                               */
    for(i = 0; i < len; i++) 
        if(strpos(delims, str[i]) < 0)
            return i ;

    /* If entire string doesn't match a delimiter, return index of '\0' */
    return i ;
}

/******************************************************************************
 * strcspn() - accepts a string and set of delimiters; returns the index      *
 *             within the string of the first delimiter character.            *
 *****************************************************************************/
unsigned int mystrcspn(const char * str, const char * delims) {
    int i, len = strlen(str) ;

    /* For each character of str, see if it is a delimiter character */
    /* If delimiter, return position                                 */
    for(i=0; i < len; i++)
        if(strpos(delims, str[i]) >= 0)
            return i ;

    /* If entire string doesn't match a delimiter, return index of '\0' */
    return i ;
}

/******************************************************************************
 * main() - Main program entry point                                          *
 *****************************************************************************/
int main(void) {
    char TestStr[] = "OMG, this is a string with a | in it!" ;
    char Delims[] = "|., !" ;
    unsigned int loc, dloc ;

    printf("My string  := %s\n", TestStr) ;
    printf("Length     := %ld\n", strlen(TestStr)) ;
    printf("Delimiters := %s\n", Delims) ;

    loc = mystrspn(TestStr, Delims) ;
    printf("First non-delimiter location found at position = %d\n", loc) ;
    dloc = mystrcspn(TestStr, Delims) ;
    printf("First delimiter location found at position = %d\n", dloc) ;

    return 0 ;
}
