#include <cs50.h>
#include <stdio.h>

// exit status
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing cli argument\n");
        return 1;
    }
    printf("Hello, %s\n", argv[1]);
    return 0;
}

// from the cli you can use echo $? to see exit status