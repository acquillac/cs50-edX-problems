#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int compute_letters(string letters);
int compute_words(string words);
int compute_sentence(string sentence);

int main(void)
{
    // Getting text input
    string text = get_string("Text: ");

    // Computing number of letters, words, and sentences
    float letter_count = compute_letters(text);
    float word_count = compute_words(text);
    float sent_count = compute_sentence(text);

    // L = average number of letters per 100 words
    float L =  100 * letter_count / word_count;
    float S =  100 *  sent_count / word_count;

    // Coleman-Liau index/ rounding to nearest whole number
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);


    // Outputing grade level
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


// Count letters
int compute_letters(string letters)
{
    string s = letters;
    int counter = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];

        if (x == ' ' || x == '!' || x == '?' || x == '.' || x == ',' || x == '"' || x == ':' || x == '\'' || x == '-')
        {
            // invalid
        }
        else
        {
            counter++;
        }
    }

    return counter;
}


// Counting words
int compute_words(string words)
{
    string s = words;
    int counter = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];
        if (x == ' ')
        {
            counter++;
        }
    }

    return counter;
}

// counting Senteces
int compute_sentence(string sentence)
{
    string s = sentence;
    int counter = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];
        if (x == '.' || x == '!' || x == '?')
        {
            counter++;
        }
    }

    if (counter == 0)
    {
        counter = 1;
    }

    return counter;
}