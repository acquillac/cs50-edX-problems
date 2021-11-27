#include <stdio.h>
//#include <cs50.h>

int get_positive_number(void);

int main(void)
{
    int i = get_positive_number();
    printf("Positive int was: %i\n", i);
}

// prompt user for positive integer
int get_positive_number(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n<1);
    return n;
}