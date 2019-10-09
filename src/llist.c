/*******************************************************************************
 * llist.c                                                                     *
 * Linked List C implementation file for use by emigrate-rpt.c code            *
 *                                                                             *
 * Ben Wheeless, 10/08/2019                                                    *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

struct ElementType 
{
    char StateCode[5] ;
    char StateName[50] ;
} ;

struct ListNode 
{
    struct ElementType S ;
    NextState Next ;
} ;

int IsEmpty(StateList L)
{
    return L->Next == NULL ;
}

/* Main routine to test our functions */
int main(void)
{
    State MyState ;
    MyState = malloc(sizeof(struct ElementType)) ;
    strncpy(MyState->StateCode,"GA",5) ;
    strncpy(MyState->StateName,"GEORGIA",10) ;

    printf("My state information: \n\tState = %s\n\tCode  = %s\n\n", 
        MyState->StateName, MyState->StateCode) ;

    StateList States ;
    States = malloc(sizeof(struct ListNode)) ;
    States->Next = NULL ;

    if(IsEmpty(States))
        printf("Our new list is now empty...") ;

    return 0 ;
}