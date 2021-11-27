#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    // Prompt user change owed
    float change_owed;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (change_owed < 0.009);
    printf("%f\n", change_owed);


    // Rounding change
    float change_rounded = round(change_owed * 100);
    printf("%f\n", change_rounded);


    // Counting coins needed for change
    int coins = 0;

    if (change_rounded > 0)
    {
        // Compairing change to quarter
        int quarter = change_rounded / 25;
        int quarter_val = quarter * 25;
        change_rounded = change_rounded - quarter_val;

        // Compairing change to dime
        int dime = change_rounded / 10;
        int dime_val = dime * 10;
        change_rounded = change_rounded - dime_val;

        // Compairing change to nickel
        int nickel = change_rounded / 5;
        int nickel_val = nickel * 5;
        change_rounded = change_rounded - nickel_val;

        // Compairing change to penny
        int penny = change_rounded / 1;
        int penny_val = penny * 1;
        change_rounded = change_rounded - penny_val;

        // Amount of coins used
        coins = quarter + dime + nickel + penny;

        printf("%i\n", coins);

    }
    else
    {
        printf("%i\n", coins);
    }
}