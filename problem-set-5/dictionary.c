// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <cs50.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = LENGTH + 1 * 'z';

// Hash table
node *table[N];

// setting word count
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get hash value of the word
    int index = hash(word);

    // go to linked list at index
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        // getting asci value
        hash_value += tolower(word[i]);
    }

    // hash value is set between 0 and N - 1
    return (hash_value % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // read strings from file
    while (fscanf(f, "%s", word) != EOF)
    {
        // allocate memory for new node
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }

        // copy word into node
        strcpy(newNode->word, word);
        newNode->next = NULL;

        // get index from hash function
        int index = hash(word);

        // insert node into hash table
        if (table[index] == NULL)
        {
            // space exists
            table[index] = newNode;
        }
        else
        {
            // add to front of list
            newNode->next = table[index];
            table[index] = newNode;
        }

        // increment size of words
        word_count++;
    }

    // close file
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // return word count
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate through buckets
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (tmp != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}
