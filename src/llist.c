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

/* Definition of ElementType stored in node of Linked List */
struct ElementType 
{
    char StateCode[5] ;
    char StateName[50] ;
} ;

/* Definition of List Node structure (includes pointer to ElementType struct) */
struct ListNode 
{
    State StateData ;
    NextState Next ;
} ;

/***********************************************************************
 * IsEmpty() - list operation to determine if list has no valid nodes  *
 **********************************************************************/
int IsEmpty(StateList L)
{
    return L->Next == NULL ;
}

/******************************************************************************
 * IsLast() - accepts next node pointer (and optional list pointer)           *
 *          - returns bool value identifying of current node is last node     *
 *****************************************************************************/
int IsLast(NextState N, StateList L)
{
    return N->Next == NULL ;
}

/******************************************************************************
 * Find() - returns the location of given element in the list or NULL if not  *
 *          found.                                                            *
 *****************************************************************************/
NextState Find(State st, StateList L)
{
    NextState Loc ;

    Loc = L->Next ;
    while(Loc != NULL && strncmp(Loc->StateData->StateName, st->StateName, sizeof(st->StateName)))
        Loc = Loc->Next ;

    return Loc ;
}

/******************************************************************************
 * Insert() - accepts pointer to element, pointer to list (optional), and     *
 *            pointer to next node and inserts element as new node in given   *
 *            location                                                        *
 *****************************************************************************/
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

/**************************************
 * Main routine to test our functions * 
 *************************************/
int main(void)
{
    State MyState, MyNextState, MyThirdState, MyFinalState, MySearchState ;
    MyState = malloc(sizeof(struct ElementType)) ;
    strncpy(MyState->StateCode,"GA",5) ;
    strncpy(MyState->StateName,"GEORGIA",10) ;

    printf("My state information: \n\tState = %s\n\tCode  = %s\n\n", 
        MyState->StateName, MyState->StateCode) ;

    StateList States ;
    States = malloc(sizeof(struct ListNode)) ;
    States->Next = NULL ;

    MySearchState = malloc(sizeof(struct ElementType)) ;
    strncpy(MySearchState->StateCode,"VA",5) ;
    strncpy(MySearchState->StateName,"Virginia",11) ;

    if(IsEmpty(States)) {
        printf("Our new list is empty, adding our first node...\n") ;
        Insert(MyState, States, States) ;

        printf("Adding next node...\n") ;
        MyNextState = malloc(sizeof(struct ElementType)) ;
        strncpy(MyNextState->StateCode,"NC",5) ;
        strncpy(MyNextState->StateName,"NORTH CAROLINA",17) ;
        Insert(MyNextState, States, States->Next) ;

        printf("Adding third node...\n") ;
        MyThirdState = malloc(sizeof(struct ElementType)) ;
        strncpy(MyThirdState->StateCode,"SC",5) ;
        strncpy(MyThirdState->StateName,"SOUTH CAROLINA",17) ;
        Insert(MyThirdState, States, States->Next) ;

        printf("Adding final node...\n\n") ;
        MyFinalState = malloc(sizeof(struct ElementType)) ;
        strncpy(MyFinalState->StateCode,"FL",5) ;
        strncpy(MyFinalState->StateName,"FLORIDA",10) ;
        Insert(MyFinalState, States, States->Next) ;
    } else {
        printf("Our list is not empty!\n") ;
    }

    if(IsEmpty(States)) {
        printf("We have a problem! Just added a node, but list still tests as empty!\n") ;
    } else {
        /* Use header ptr to next node (first node) and print it's contents, then advance current */
        printf("Address of beginning of list: %p\n", States) ;
        NextState Current ;
        Current = States->Next ;
        printf("Address of first node:        %p\n", Current) ;
        printf("Current state:      %s\n", Current->StateData->StateName) ;
        printf("Current state code: %s\n", Current->StateData->StateCode) ;
        Current = Current->Next ;

        /* Enumerate down the list until hit the last node, handle that special */
        while(! (IsLast(Current, States))) {
            printf("Address of next node:         %p\n", Current) ;
            printf("Current state:      %s\n", Current->StateData->StateName) ;
            printf("Current state code: %s\n", Current->StateData->StateCode) ;
            Current = Current->Next ;
        }
        /* We are on last node, so print it but do not advance Current to next node */
        printf("Address of last node:         %p\n", Current) ;
        printf("Current state:      %s\n", Current->StateData->StateName) ;
        printf("Current state code: %s\n", Current->StateData->StateCode) ;
    }

    State findMe = MySearchState ;
    NextState foundNode = Find(findMe, States) ;
    if(foundNode != NULL)
    {
        printf("Found the state you searched for at location: %p\n", foundNode) ;
        printf("State name = %s\tState Code = %s\n", foundNode->StateData->StateName, 
            foundNode->StateData->StateCode) ;
    } else {
        printf("State not found in list.\n") ;
    }

    return 0 ;
}