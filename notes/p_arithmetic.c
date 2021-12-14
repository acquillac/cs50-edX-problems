#include <stdio.h>

int main(void)
{
    // not using "string" from cs50.h
    char *s = "HI!";

    // printing each char in the string
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    // Going to the char address
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}