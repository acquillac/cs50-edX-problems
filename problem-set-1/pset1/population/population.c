#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculates number of years until we reach threshold
    int years = 0;
    while (start_size < end_size)
    {
        float gain = start_size / 3;
        float lose = start_size / 4;
        int new_pop = gain - lose;
        start_size = start_size + new_pop;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
