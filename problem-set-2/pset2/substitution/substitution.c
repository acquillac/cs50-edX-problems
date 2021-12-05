#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool key_length(string key);
bool key_alphabetic(string key);
bool key_doublechars(string key);
string ciphertext(string text, string key);
bool validate_char(char c);

int main(int argc, string argv[])
{
    // if cmd arguments == 2 example ./substitution key
    if (argc == 2)
    {
        string key = argv[1];

        // if key is valid get text and cipher text
        if (!key_length(key) && !key_alphabetic(key) && !key_doublechars(key))
        {
            // get plain text
            string plaintext = get_string("plaintext: ");

            // ciphertext
            string result = ciphertext(plaintext, key);

            // print cipher text
            printf("ciphertext: %s\n", result);
        }
        else if (key_length(key))
        {
            // key must contain 26 chars
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (key_alphabetic(key))
        {
            // key must be alphabetical
            printf("Key must only contain alphabetic charaters.\n");
            return 1;
        }
        else if (key_doublechars(key))
        {
            // key can not contain repeats
            printf("Key must not contain repeated charaters.\n");
            return 1;
        }
        else
        {
            // default error
            printf("Usage: ./substitution key\n");
            return 1;
        }

    }
    else
    {
        // no cmd arguments were passed
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// key is invalid if key is not eqaul to 26
bool key_length(string key)
{
    if (strlen(key) != 26)
    {
        return 1;
    }
    return 0;
}

// checking that charater is alphabetic
bool key_alphabetic(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }
    return 0;
}

// checking that key has no same characters
bool key_doublechars(string key)
{
    int counter = 0;

    // looping through key and counting matches
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int x = 0, b = strlen(key); x < b; x++)
        {

            if (key[i] == key[x])
            {
                counter++;
            }
        }
    }

    // if more than 26 matchs key is invalid
    if (counter > 26)
    {
        return 1;
    }

    return 0;
}

// cipertext
string ciphertext(string text, string key)
{
    // converting key to uppercase
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!toupper(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }

    // looping through text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int index = 0;
        char c;
        bool valid = validate_char(text[i]);

        // if char from text is alphabetic
        if (valid)
        {
            if (text[i] == tolower(text[i]))
            {
                for (c = 'a'; c <= 'z'; c++)
                {
                    if (c == text[i])
                    {
                        text[i] = key[index];
                        text[i] = tolower(text[i]);
                        break;
                    }

                    index++;
                }
            }
            else
            {
                for (c = 'A'; c <= 'Z'; c++)
                {
                    if (c == text[i])
                    {
                        text[i] = key[index];
                        text[i] = toupper(text[i]);
                        break;
                    }

                    index++;
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