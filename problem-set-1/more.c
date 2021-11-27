//#include <cs50.h>
#include <stdio.h>

int user_integer(void);

int main(void)
{
    int height = user_integer();
    int block_counter = 0;
    int spaces = height - 1;

    for (int j = 0; j < height; j++)
    {
        block_counter++;
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }

        for (int b = 0; b < block_counter; b++)
        {
            printf("#");
        }

        printf("  ");

        for (int b = 0; b < block_counter; b++)
        {
            printf("#");
        }

        spaces--;
        printf("\n");
    }
}

int user_integer(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}