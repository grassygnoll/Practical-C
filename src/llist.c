/*******************************************************************************
 * llist.c                                                                     *
 * Linked List C implementation file for use by emigrate-rpt.c code            *
 *                                                                             *
 * Ben Wheeless, 10/08/2019                                                    *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

struct Element 
{
    char StateCode[5] ;
    char StateName[50] ;
} ;

struct ListNode 
{
    struct Element S ;
    NextState Next ;
} ;

int IsEmpty(StateList L)
{
    return L->Next == NULL ;
}

/* Main routine to test our functions */
int main(void)
{
    StateList States ;
    States = malloc(sizeof(struct ListNode)) ;
    States->Next = NULL ;

    if(IsEmpty(States))
        printf("Our new list is now empty...") ;

    return 0 ;
}