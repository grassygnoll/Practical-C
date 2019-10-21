/******************************************************************************
 * shell_sort.c                                                               *
 *                                                                            *
 * Problem 4.3 from MIT Practical C Programming Course; implementation of     *
 * a generic insertion sort algorithm, known as shell sort using array        *
 * arithmitic or pointer implementation.                                      *
 *                                                                            *
 * Ben Wheeless, 10/20/2019                                                   *
 *                                                                            *
 * CONSIDERATIONS:                                                            *
 * 1) Remove DEBUG printf statements                                          *
 * 2) Enhance with ptr arithmitic rather than array indexing                  *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0
#define INT_COUNT_MAX   50
/*
#define INT_COUNT_MAX   10
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
int MyIntegers[INT_COUNT_MAX] = { 77,62,14,9,30,21,80,25,70,55 } ;
*/


/* Shifts array elements by "gap" (shell sort) */
void shift_by_gap(unsigned int i, unsigned int gap) {
    int tmpval ;

    for( tmpval = MyIntegers[i]; ((i >= gap) && (MyIntegers[i-gap] > tmpval)); i -= gap) {
        if(DEBUG) {
            printf("\t[shift_by_gap()]: tmpval = %d\ti = %d\tgap = %d\n", tmpval, i, gap) ;
            printf("\t[shift_by_gap()]: MyIntegers[i] = %d\tMyIntegers[i-gap] = %d\n",
                MyIntegers[i], MyIntegers[i-gap]) ;
        }

        MyIntegers[i] = MyIntegers[i-gap] ;
        
        if(DEBUG) {
            printf("\t[shift_by_gap()]: i = %d\tMyIntegers[i] = %d\n", i, MyIntegers[i]) ;
            int j = i - gap ;
            printf("\t[shift_by_gap()]: next values...\n") ;
            printf("\t[shift_by_gap()]: i = %d\tMyIntegers[%d] = %d\n", j, j, MyIntegers[j]) ;
        }
    }

    MyIntegers[i] = tmpval ;
    if(DEBUG) {
        printf("\t[shift_by_gap()]: i = %d\tMyIntegers[i] = %d\n", i, MyIntegers[i]) ;
    }
}

/* Enumerates array and sorts via shell sort algorithm */
void shell_sort(void) {
    unsigned int gap, i, len = array_len(MyIntegers) ;

    for(gap = len/2; gap > 0; gap /= 2) {
        if(DEBUG) {
            printf("[shell_sort()]: len = %d\tgap = %d\n", len, gap) ;
        }

        for(i = gap; i < len; i++) {
            if(DEBUG)
                printf("[shell_sort()]: i = %d\tMyIntegers[i] = %d\tMyIntegers[i-gap] = %d\n", 
                    i, MyIntegers[i], MyIntegers[i-gap]) ;
            if(MyIntegers[i] < MyIntegers[i-gap]) {
                shift_by_gap(i,gap) ;
            }
        }
    }
}

/* Main Prgram Entry Point */
int main(void)
{
    for(int i = 0; i < INT_COUNT_MAX; i++)
        printf("MyIntegers[%d] = %d\tMemory address = %p\n", i, MyIntegers[i], &MyIntegers[i]) ;

    printf("\n...sorting via shell sort...\n\n") ;
    shell_sort() ;

    for(int i = 0; i < INT_COUNT_MAX; i++)
        printf("MyIntegers[%d] = %d\tMemory address = %p\n", i, MyIntegers[i], &MyIntegers[i]) ;

    return 0 ;
}
