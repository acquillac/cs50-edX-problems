#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool digit_check(string input);
bool validate_key(int key);
bool validate_char(char c);
string cipher_text(string text, int shift);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string s = argv[1];
        bool digits = digit_check(s);

        if (digits)
        {
            int key = atoi(s);
            bool valid = validate_key(key);

            // if key is not less than 0
            if (valid)
            {
                string plaintext = get_string("plaintext: ");
                cipher_text(plaintext, key);
                printf("ciphertext: %s\n", plaintext);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Checking that each char in the
// key is a digit
bool digit_check(string input)
{
    bool valid = true;
    string s = input;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int check = atoi(&s[i]);

        if (!check)
        {
            valid = false;
        }
    }

    return valid;
}

// Makeing sure that the key
// is not less than 0
bool validate_key(int key)
{
    if (key < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Ciphering the text recived from
// "plaintext" string
string cipher_text(string text, int shift)
{
    string s = text;
    int key = shift;

    for (int i = 0, n = strlen(s); i < n; i++)
    {

        bool valid = validate_char(s[i]);

        // if char is a letter ciphertext
        if (valid)
        {

            // checking if upper or lowercase
            if (s[i] == tolower(s[i]))
            {
                // using ci = (pi + k) % 26 formula
                s[i] = s[i] + key % 26;


                // if char is negative
                // reset char and add difference
                if (s[i] < 0)
                {
                    int add = s[i] - 'z';
                    s[i] = 96 + add;
                }

                // adjusting char if char
                // is greater than z
                if (s[i] > 'z')
                {
                    s[i] = s[i] - 26;
                }
            }
            else if (s[i] == toupper(s[i]))
            {
                // using ci = (pi + k) % 26 formula
                s[i] = s[i] + key % 26;

                // if char is negative
                // reset char and add difference
                if (s[i] < 0)
                {
                    int add = s[i] - 'z';
                    s[i] = 64 + add;
                }

                // adjusting char if char
                // is greater than z
                if (s[i] > 'Z')
                {
                    s[i] = s[i] - 26;
                }
            }
        }
    }

    return text;
}


// checking that char is letter
bool validate_char(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}