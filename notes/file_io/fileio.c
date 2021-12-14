#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // open file phonebook.csv and "a" --> means append or add
    FILE *file = fopen("phonebook.csv", "a");
    // checking that file exists
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // saving to that file
    fprintf(file, "%s,%s\n", name, number);

    // closing file
    fclose(file);
}
