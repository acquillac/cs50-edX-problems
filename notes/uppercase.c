#include <cs50.h>
// ctype enables islower and toupper
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Getting string from user
    string s = get_string("Before: ");
    printf("After: ");

    // looping through characters
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if character is lowercase make uppercase
        // instead of s[i] >= 'a' && s[i] <= 'z'
        // use islower(s[i])
        if (islower(s[i]))
        {
            // using ASCII chart printf("%c", s[i] - 32);
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }


        // a short hand example of the if else would be:
        // printf("%c", toupper(s[i]));

    }
    printf("\n");
}