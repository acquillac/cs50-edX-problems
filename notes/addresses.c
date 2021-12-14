#include <stdio.h>

int main (void)
{
    int n = 50;

    // &n will show the hexadecimal address
    // %p is the format code for an address
    printf("%p\n", &n);

    // The * operator, or the dereference operator, lets us go to that location the pointer is pointing to.
    // Example: we can print *&n where we go to the address of n and that will print out the value of n, 50
    // Since thats the value at the address of n
    printf("%i\n", *&n);
}