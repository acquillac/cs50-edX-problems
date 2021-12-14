#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // adding address of x and y
    swap(&x,&y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    // inside of swap this will work
    // but it is does not change x and y in main
    // int tmp = a;
    // a = b;
    // b = tmp;

    //  ---------------------
    // | machine code        |
    // | globals             |
    // | heap                |
    // |   V                 |
    // |                     |
    // |                     |
    // | tmp = a             |
    // | swap   a = 2  b = 1 |
    // | main   x = 1  y =2  |
    //  ---------------------
    //  when this returns x and y are still 1 and 2

    // using pointers so you can go to addresses
    // a* b*
    int tmp = *a;
    *a = *b;
    *b = tmp;
    //  now x and y will be swaped properly

    //  -----------------------------
    // | machine code                |
    // | globals                     |
    // | heap                        |
    // |   V                         |
    // |                             |
    // | tmp = a                     |
    // | b = 0x127                   |
    // | swap   a = 0x123            |
    // | main   x = 0x123  y = 0x127 |
    //  -----------------------------
}

