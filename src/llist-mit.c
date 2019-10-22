/*******************************************************************************
 * llist-mit.c                                                                 *
 * Linked List as outlined in Problem 5.1 from MIT Practical C Programming     *
 * Course.                                                                     *
 *                                                                             *
 * Ben Wheeless, 10/22/2019                                                    *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

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
            printf("List node [%d]: %d\n", i, head->data) ;
            i++ ;
            head = head->next ;
        }
        printf("List node [%d]: %d\n\n", i, head->data) ;
    }
}

/* Main code execution */
int main(void)
{
    nodeptr listHead = NULL ;

    display(listHead) ;
    listHead = add_front(listHead, 55) ;
    display(listHead) ;
    listHead = add_front(listHead, 10) ;
    display(listHead) ;
    listHead = add_front(listHead, 5) ;
    display(listHead) ;
    listHead = add_front(listHead, 76) ;
    display(listHead) ;
    listHead = add_back(listHead, 19) ;
    display(listHead) ;

    return 0 ;
}