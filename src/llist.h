/*******************************************************************************
 * llist.h                                                                     *
 * Linked List header file for use by emigrate-rpt.c code                      *
 *                                                                             *
 * Ben Wheeless, 10/08/2019                                                    *
 ******************************************************************************/

#ifndef _LLIST_H
#define _LLIST_H

/* Declare the structure stored in each node */
struct ElementType ;
typedef struct ElementType *ElementPtr ;
typedef ElementPtr State ;

/* Declare the struct of each node itself and typedefs for easier reference */
struct ListNode ;
typedef struct ListNode *ListNodePtr ;
typedef ListNodePtr StateList ;
typedef ListNodePtr NextState ;

/* Declare some methods for use with our List */
StateList MakeEmpty(StateList L) ;
int IsEmpty(StateList L) ;
int IsLast(NextState N, StateList L) ;
NextState Find(State S, StateList L) ;
NextState FindPrevious(State S, StateList L) ;
void Delete(State S, StateList L) ;
void Insert(State S, StateList L, NextState N) ;
void DeleteList(StateList L) ;
NextState Header(StateList L) ;
NextState First(StateList L) ;
NextState Advance(NextState N) ;
State Retrieve(NextState N) ;

#endif
