#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// single linked list
typedef struct node
{
    int number; // the number we want to store
    struct node* next; // pointer to the next number
}
node; // primary name

int main(void)
{
    node *list = NULL;
    node *temp = NULL;
    node *newNode = NULL;
    node *head = NULL;

    int values[10] = {25, 32, 55, 68, 87, 98, 14, 89, 87, 55};


// Adding values to linked list
    // allocating memory
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        // unable to allocate memory
        exit(0);
    }

    head->number = values[0]; // seting first value
    head->next = NULL;

    // Create n - 1 nodes and add to list
    temp = head;
    for (int i = 1; i < 10; i++)
    {
        newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            // unable to allocate memory
            break;
        }

        newNode->number = values[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }

// displaying list
    if (head == NULL)
    {
        exit(0);
    }

    temp = head;
    while(temp != NULL)
    {
        printf("Nodes: %i\n", temp->number);
        temp = temp->next;
    }


}
