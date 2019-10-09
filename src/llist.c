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
    State StateData ;
    NextState Next ;
} ;

int IsEmpty(StateList L)
{
    return L->Next == NULL ;
}

int IsLast(NextState N, StateList L)
{
    return N->Next == NULL ;
}

void Insert(State S, StateList L, NextState N) 
{
    NextState tmpState ;

    tmpState = malloc(sizeof(struct ListNode)) ;
    if(tmpState == NULL)
    {
        printf("Fatal Error: Unable to allocate new list node in memory!\n") ;
        exit(EXIT_FAILURE) ;
    }

    tmpState->StateData = S ;
    tmpState->Next = N->Next ;
    N->Next = tmpState ;
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

    if(IsEmpty(States)) {
        printf("Our new list is empty, adding our first node...\n") ;
        Insert(MyState, States, States) ;
    } else {
        printf("Our list is not empty!\n") ;
    }

    if(IsEmpty(States)) {
        printf("We have a problem! Just added a node, but list still tests as empty!\n") ;
    } else {
        NextState Current ;
        Current = States->Next ;
        printf("Current state:      %s\n", Current->StateData->StateName) ;
        printf("Current state code: %s\n", Current->StateData->StateCode) ;

        /* The below is causing a segmentation fault */
        /*
        while(! (IsLast(Current->Next, States))) {
            printf("Current state:      %s\n", Current->StateData->StateName) ;
            printf("Current state code: %s\n", Current->StateData->StateCode) ;
            Current = Current->Next ;
        }
        */
    }

    return 0 ;
}