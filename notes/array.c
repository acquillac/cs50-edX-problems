#include <stdio.h>
#include <cs50.h>

float average(int length, int array[]);

const int TOTAL = 3;

int main (void)
{
    //int TOTAL = get_int("Total number of scores: ");
    int scores[TOTAL];

    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(TOTAL, scores));
}


// length of the aray, actual array
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}