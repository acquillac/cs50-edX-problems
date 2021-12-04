#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// int argc = int as an input
// argc is short hand for argument count
// argc is the number that will represent the number of words
// that the user type at the prompt

// string argv[] = an array of strings as input
// argv is short for argument vector
// a vector is a list
// it is a variable that will store all the strings
// that the user types at the prompt

int main(int argc, string argv[])
{
    // if ./args firstname
    // print Hello, firstname
    if (argc == 2)
    {
        // ./args == argv[0]
        //printf("Hello, %s\n", argv[1]);

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // printing each char in argv[1][i]
            printf("%c\n", argv[1][i]);
        }
    }
}