#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// single linked list
typedef struct sllnode // temp name
{
    int number; // the number we want to store
    struct sllnode* next; // pointer to the next number
}
sllnode; // primary name

int main(void)
{
    // setting list to null
    sllnode *list = NULL;

    // allocating memory for a node
    sllnode *n = malloc(sizeof(sllnode));
    if (n == NULL)
    {
        return 1;
    }

    // setting the value of a pointer in our node
    n->number = 1;
    n->next = NULL;

    // add node n by pointing list to it, since this is the first node
    list = n;

    // allocate memory for another node, and we can reuse our variable n to
    //  point to it, since list points to the first node already
    n = malloc(sizeof(sllnode));
    if (n == NULL)
    {
        // free list if n is NULL
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;

    // Update the pointer in our first node to point to the second node
    list->next = n;

    // repeating steps
    n = malloc(sizeof(sllnode));
    if (n == NULL)
    {
        free(list->next); // free number 2
        free(list); // free number 1
        return 1; //exiting program
    }

    n->number = 3;
    n->next = NULL;

    // Follow the next pointer of the list to the second node, and update
    // the next pointer there to point to n
    list->next->next = n;


    // printing list using a loop, by using a temp variable, tmp, to
    // point to list, the first node. Then, everytime we go over the loop, we
    // use tmp = tmp->next to pudate our temp pointer to the next node. We
    // keep going as long as the pointer points somewhere, stopping when we get to
    // the last node and tmp->next is NULL

    for (sllnode *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // free list, by using a while loop and a temp variable to point
    // to the next node before freeing the current one
    while (list != NULL)
    {
        // we point to the next node first
        sllnode *tmp = list->next;
        // then we can free the first node
        free(list);
        // now we can set the list to point to the next node
        list = tmp;
        // if list is null where there are no nodes left our while loop will stop
    }
}
