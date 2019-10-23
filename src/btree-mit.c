/*******************************************************************************
 * btree-mit.c                                                                 *
 * Binary Tree as outlined in Problem 5.2 from MIT Practical C Programming     *
 * Course.                                                                     *
 *                                                                             *
 * Ben Wheeless, 10/23/2019                                                    *
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define MAX_INTS    10

/* btree node structure and subsequent typedef for struct and ptr to struct */
typedef struct tnode
{
    int data ;
    struct tnode* left ;
    struct tnode* right ;
} leaf, *pLeaf ;

typedef pLeaf leafptr ;

/*******************************************************************************
 * alloc_leaf() - accepts int and uses malloc to create a new leaf node with   *
 *                int = data. Returns a ptr to newly created leaf.             *
 ******************************************************************************/
leafptr alloc_leaf(int val)
{
    leafptr newLeaf = (leafptr)malloc(sizeof(leaf)) ;

    if(newLeaf != NULL)
    {
        newLeaf->data = val ;
        newLeaf->left = NULL ;
        newLeaf->right = NULL ;
    }

    return newLeaf ;
}

/*******************************************************************************
 * add_leaf() - accepts ptr to root of tree and a new int to insert.           *
 *              returns a ptr to the new root of the tree with new leaf added. *
 * NOTE:      - recursive function.                                            *
 ******************************************************************************/
leafptr add_leaf(leafptr root, int val)
{
    leafptr newLeaf = NULL ;

    /* Termination condition */
    if(root == NULL)
    {
        newLeaf = alloc_leaf(val) ;
        return newLeaf ;
    }
    else if(val < root->data)
        root->left = add_leaf(root->left, val) ;
    else
        root->right = add_leaf(root->right, val) ;
}

/*******************************************************************************
 * preorder() - accepts ptr to root of tree and displays the leaves using      *
 *              pre-order traversal (root first, then left side, then right).  *
 ******************************************************************************/
void preorder(leafptr root)
{
    if(root != NULL)
    {
        printf("[%p] data=%d\tleft->%p\tright->%p\n", root, root->data, 
            root->left, root->right) ;
        preorder(root->left) ;
        preorder(root->right) ;
    }
}

/*******************************************************************************
 * main() - Main program entry point with test driving code                    *
 ******************************************************************************/
int main(void)
{
    int Numbers[MAX_INTS] = {3,1,0,2,8,6,5,9,4,7} ;
    int i = 0 ;
    leafptr trunk = NULL ;

    for(i = 0; i < MAX_INTS; i++)
        trunk = add_leaf(trunk, Numbers[i]) ;

    preorder(trunk) ;

    return 0 ;
}