/******************************************************************************
 * ins_sort.c                                                                 *
 *                                                                            *
 * Problem 4.1 from MIT Practical C Programming Course; implementation of     *
 * insertion sort shift_element() function using pointers/pointer arithmetic  *
 * instead of array indexing                                                  *
 *                                                                            *
 * Ben Wheeless, 10/19/2019                                                   *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define INT_COUNT_MAX   50
/*
#define INT_COUNT_MAX   5
*/
#define array_len(arr) (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof((arr)[0]))

/* Initializing my array with unorganized numbers */
int MyIntegers[INT_COUNT_MAX] = {
                        6,4,2,2,9,5,1,3,6,7,
                        8,10,12,74,14,42,19,88,89,25,
                        76,77,92,33,36,99,50,52,18,70,
                        7,64,67,69,61,57,6,3,34,35,
                        45,48,49,51,93,82,63,91,92,16
                     } ;
/*
int MyIntegers[INT_COUNT_MAX] = {0,2,1,3,4} ;
*/

/* Shifts array element up within the array */
void shift_element(unsigned int i)
{
    int ivalue ;

    for(ivalue = MyIntegers[i]; i && MyIntegers[i-1] > ivalue; i--)
        MyIntegers[i] = MyIntegers[i-1] ;

    MyIntegers[i] = ivalue ;
}

/* Enumerates array checking for out of order element and shifts element if needed */
void insertion_sort()
{
    unsigned int i, len = array_len(MyIntegers) ;

    for(i = 1; i < len; i++)
        if(MyIntegers[i] < MyIntegers[i-1])
            shift_element(i) ;
}

/* Shift array element up within array using pointers */
void ptr_shift_element(int *pElement)
{
    int ival ;

    for(ival = *pElement; *(pElement - 1) > ival; pElement--)
        *pElement = *(pElement-1) ;

    *pElement = ival ;
}

/* Enumerates array checking for out of order element and shifts element if needed */
void ptr_insertion_sort()
{
    unsigned int len = array_len(MyIntegers) ;
    int * current = NULL ;
    int * last = MyIntegers + len ;

    for(current = MyIntegers + 1; current < last; current++)
        if( *current < *(current - 1))
            ptr_shift_element(current) ;
}

/* Main Prgram Entry Point */
int main(void)
{
    for(int i = 0; i < INT_COUNT_MAX; i++)
        printf("MyIntegers[%d] = %d\tMemory address = %p\n", i, MyIntegers[i], &MyIntegers[i]) ;

    /*
    insertion_sort() ;
    */
    ptr_insertion_sort() ;

    for(int i = 0; i < INT_COUNT_MAX; i++)
        printf("MyIntegers[%d] = %d\tMemory address = %p\n", i, MyIntegers[i], &MyIntegers[i]) ;

    return 0 ;
}
