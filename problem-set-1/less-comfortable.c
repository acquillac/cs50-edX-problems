#include <cs50.h>
#include <stdio.h>

int get_block_height(void);

int main(void)
{
    int height = get_block_height();
    int block_counter = 0;

    for (int i = 0; i < height; i++)
    {
        block_counter++;

        for (int j = 0; j < block_counter; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int get_block_height(void)
{
    int n;
    do
    {
        n = get_int("Block Height: ");
    }
    while(n < 1);
    return n;
}