/*******************************************************************************
 * llist-mit.c                                                                 *
 * Linked List as outlined in Problem 5.1 from MIT Practical C Programming     *
 * Course.                                                                     *
 *                                                                             *
 * Ben Wheeless, 10/22/2019                                                    *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define MAX_VAL   10

typedef struct node
{
    int data ;
    struct node* next ;
} listnode, *listnode_ptr ;

typedef listnode_ptr nodeptr ;

/* Allocates memory to store a node as defined above and populates data field with value */
nodeptr node_alloc(int value)
{
    nodeptr p = (nodeptr)malloc(sizeof(listnode)) ;
    if(p!=NULL)
    {
        p->data = value ;
        p->next = NULL ;
    }

    return p ;
} 

/* Adds a newly allocated node (via node_alloc) to the start of the list */
nodeptr add_front(nodeptr head, int value)
{
    nodeptr p = node_alloc(value) ;

    if(p==NULL)
        return head ;

    p->next = head ;
    return p ;
}

/* Adds a newly allocated node (via node_alloc) to the end of the list */
nodeptr add_back(nodeptr head, int value)
{
    nodeptr p = node_alloc(value) ;
    nodeptr tmp = head ;

    if(p==NULL)
        return head ;

    while(tmp->next != NULL)
        tmp = tmp->next ;

    tmp->next = p ;
    p->next = NULL ;

    return head ;
}

/* Walks list and prints contents to stdout */
void display(nodeptr head)
{
    int i = 0 ;

    if(head != NULL)
    {
        while(head->next != NULL)
        {
            printf("List node [%d]: %d\tAddress: %p\n", i, head->data, head) ;
            i++ ;
            head = head->next ;
        }
        printf("List node [%d]: %d\tAddress: %p\n\n", i, head->data, head) ;
    }
}

/* Finds node where data = value, returns pointer to node or NULL if not found */
nodeptr find(nodeptr head, int value)
{
    nodeptr tmpptr = head ;

    while((tmpptr->next != NULL) && (tmpptr->data != value))
    {
        tmpptr = tmpptr->next ;
    }

    if(tmpptr->data == value)
        return tmpptr ;
    else 
        return NULL ;
}

/* Main code execution */
int main(void)
{
    int numbers[MAX_VAL] = {5,10,33,2,55,78,19,76,99,2} ;
    int i = 0 ;
    nodeptr listHead = NULL ;
    nodeptr found = NULL ;

    display(listHead) ;
    listHead = add_front(listHead, numbers[4]) ;
    display(listHead) ;
    listHead = add_front(listHead, numbers[1]) ;
    display(listHead) ;
    listHead = add_front(listHead, numbers[0]) ;
    display(listHead) ;
    listHead = add_front(listHead, numbers[7]) ;
    display(listHead) ;
    listHead = add_back(listHead, numbers[6]) ;
    display(listHead) ;

    for(i = 0; i < MAX_VAL; i++)
    {
        if((found = find(listHead, numbers[i])) != NULL)
        {
            printf("Found %d at address = %p\n", numbers[i], found) ;
            printf("Value = %d\n", found->data) ;
        }
        else
            printf("find() returned NULL for value = %d\n", numbers[i]) ;
    }

    return 0 ;
}