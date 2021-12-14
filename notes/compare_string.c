#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    // section 2
    //char *t = s;
    // this will make the first char upper in both s and t
    // this is because we are using the same address
    // t[0] = toupper(t[0]);


    // section 3
    // to actually copy a string we need to copy s somewhere else in memory
    // with malloc we give *t a new chunck of memory to store the copy of s
    char *t = malloc(strlen(s)+ 1);

    // if our computer is out of memory malloc will return NULL
    // or a special value that indicates there isnta an address to point to
    if (t == NULL)
    {
        // So if t == NULL we want to exit our program
        return 1;
    }

    for (int i = 0, n = strlen(s); i < n + 1; i++)
    {
        t[i] = s[i];
    }

    // Also checking that t has a length
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // We should free the memory that we allocated earlier, whoch marks it as usable again
    free(t);
}

// section 1

// this will always remain "Different"
// each string is a pointer to char *, to a different location in memory
// where the first character of each string is located. So even though
// we could have the same character this will always end "Different"
// int main(void)
// {
//     char *s = get_string("s: ");
//     char *t = get_string("t: ");

//     if (s == t)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }