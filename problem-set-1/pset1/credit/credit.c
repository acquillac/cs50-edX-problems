#include <cs50.h>
#include <stdio.h>
#include <math.h>


// Luhn’s Algorithm
//
// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
// Add the sum to the sum of the digits that weren’t multiplied by 2
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid


int main(void)
{

    long credit = get_long("Enter credit card number ");
    int odd_even = 0;
    int sum = 0;
    int digits = 0;
    int start_digits = 0;
    int visa_start = 0;

    for (int i = 0; i < credit; i ++)
    {
        // Switching between odd and even && counting digits
        odd_even++;
        digits++;


        int rem = credit % 10;
        int first = credit / 10;
        int even_sum = 0;


        // Checking if the current digit is odd or even
        // Adding all odd digits together
        // On every even digit multiply the digit by 2
        if (odd_even % 2 == 0 && credit < 99)
        {
            // Storing starting digits
            start_digits = credit;
            visa_start = first;

            sum += first;
            even_sum += rem * 2;
            digits++;
        }
        else if (odd_even % 2 != 0 && credit < 99)
        {

            start_digits = credit;
            visa_start = first;
            sum += rem;
            even_sum = first * 2;
            digits++;
        }
        else if (odd_even % 2 == 0)
        {
            even_sum = rem * 2;
        }
        else
        {
            sum += rem;
        }


        // If an even number is greater than 9 seperate digits
        // then add those digits to the even sum  example: 12 == 1 + 2
        if (even_sum > 9)
        {
            int first_digit = even_sum / 10;
            int second_digit = even_sum % 10;

            sum += first_digit;
            sum += second_digit;
        }
        else if (even_sum < 9)
        {
            sum += even_sum;
        }


        credit = credit / 10;
    }


    // If checksum is true
    //check what brand the card is
    if (sum % 10 == 0)
    {
        // American Express uses 15 digits
        //starting digits = 37,34
        if (start_digits == 37 || start_digits == 34)
        {
            if (digits == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Mastercard uses 16 digits
        //starting digits = 51,52,53,54,55
        else if (start_digits == 51 || start_digits == 52 || start_digits == 53 || start_digits == 54 || start_digits == 55)
        {
            if (digits == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Visa uses 13 or 16 digits
        //starting digits = 4
        else if (visa_start == 4)
        {
            if (digits == 13 || digits == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}