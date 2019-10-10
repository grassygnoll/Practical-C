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
    while(Loc != NULL && strncmp(Loc->StateData->StateName, st->StateName, 
            sizeof(st->StateName)))
        Loc = Loc->Next ;

    return Loc ;
}

/******************************************************************************
 * FindPrevious() - returns the location of the previous node of a given      *
 *                  given element in the list. If element is not found, the   *
 *                  returned node must have NEXT field == NULL.               *
 *****************************************************************************/
NextState FindPrevious(State st, StateList L)
{
    NextState PrevLoc ;

    PrevLoc = L ;
    while(PrevLoc->Next != NULL && strncmp(PrevLoc->Next->StateData->StateName,
            st->StateName, sizeof(st->StateName)))
        PrevLoc = PrevLoc->Next ;

    return PrevLoc ;
}

/******************************************************************************
 * Delete() - accepts pointer to element and pointer to list and removes      *
 *            first occurance of element found from list (and frees memory)   *
 *****************************************************************************/
void Delete(State st, StateList L)
{
    NextState Loc, tmpNode ;

    Loc = FindPrevious(st, L) ;

    if(!IsLast(Loc, L))
    {
        tmpNode = Loc->Next ;
        Loc->Next = tmpNode->Next ;
        free(tmpNode) ;
    }
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

/******************************************************************************
 * WalkList() - Routine used to iterate over list and print out contents      *
 *****************************************************************************/
void WalkList(StateList L)
{
    NextState Current ;

    if(IsEmpty(L)) {
        printf("We have a problem! Just inserted nodes, but list still tests as empty!\n") ;
        exit(EXIT_FAILURE) ;
    } else {
        /* Use header ptr to next node (first node) and print it's contents, then advance current */
        printf("Address of beginning of list: %p\n", L) ;
        Current = L->Next ;

        /* Enumerate down the list until hit the last node, handle that special */
        while(! (IsLast(Current, L))) {
            printf("Address of next node:         %p\n", Current) ;
            printf("Current state:      %s\n", Current->StateData->StateName) ;
            printf("Current state code: %s\n", Current->StateData->StateCode) ;
            Current = Current->Next ;
        }

        /* We are on last node, so print it but do not advance Current to next node */
        printf("Address of last node:         %p\n", Current) ;
        printf("Current state:      %s\n", Current->StateData->StateName) ;
        printf("Current state code: %s\n\n", Current->StateData->StateCode) ;
    }
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

    /* For testing - change the two strncpy() calls to what you like */
    MySearchState = malloc(sizeof(struct ElementType)) ;
    strncpy(MySearchState->StateCode,"VA",5) ;
    strncpy(MySearchState->StateName,"VIRGINIA",11) ;
    /*
    strncpy(MySearchState->StateCode,"SC",5) ;
    strncpy(MySearchState->StateName,"SOUTH CAROLINA",17) ;
    */

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

    WalkList(States) ;

    State findMe = MySearchState ;
    NextState foundNodeLoc = Find(findMe, States) ;
    NextState prevNodeLoc = FindPrevious(findMe, States) ;
    if(foundNodeLoc != NULL)
    {
        printf("Found the state you searched for at location: %p\n", foundNodeLoc) ;
        printf("State name = %s\tState Code = %s\n\n", foundNodeLoc->StateData->StateName, 
            foundNodeLoc->StateData->StateCode) ;
    } else {
        printf("State not found in list.\n\n") ;
    }

    printf("Previous state location is: %p\n", prevNodeLoc) ;
    if(prevNodeLoc->Next != NULL)
        printf("Previous State Name = %s\tPrevious State Code = %s\n\n", 
            prevNodeLoc->StateData->StateName, prevNodeLoc->StateData->StateCode) ;
    else
        printf("State not found in list, previous state location set to end of list: %p\n\n",
            prevNodeLoc) ;
      
    State StateToDelete = MyThirdState ;
    Delete(StateToDelete, States) ;
    WalkList(States) ;
   
    return 0 ;
}