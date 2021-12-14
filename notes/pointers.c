#include <stdio.h>

int main(void)
{
    // a variable that stores an adress is called
    // a pointer which we can think of as a value that
    // points to a location in memory
    int n = 50;

    // creating a pointer for n
    int *p = &n;

    // printing &n address
    printf("%p\n", p);
}