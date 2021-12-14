#include <stdio.h>
// not using <cs50.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    // prints HI!
    printf("%s\n", s);

    // prints address for each char in our string
    printf("%p\n", &s[0]); // 0x12001
    printf("%p\n", &s[1]); // 0x12002
    printf("%p\n", &s[2]); // 0x12003

    // prints each char in our string
    printf("%c\n", *&s[0]); // H
    printf("%c\n", *&s[1]); // I
    printf("%c\n", *&s[2]); // !
}
