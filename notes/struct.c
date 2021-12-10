#include <cs50.h>
#include <stdio.h>
#include <string.h>

// creating data stucture
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // creating people array using person data structure
    person people[2];

    // populating array
    people[0].name = "Brian";
    people[0].number = "8665421354";
    people[1].name = "David";
    people[1].number = "1234567890";

     for (int i = 0; i < 2; i++)
     {
         // Checking if the name "David" exists inside
         // the people[i].names array
         if(strcmp(people[i].name, "David") == 0)
         {
            // Displaying name if found
            printf("Found %s\n", people[i].number);
            return 0;
         }
     }
     printf("Not found");
     return 1;
}

// Example of a simple phone book. There is nothing
// wrong with this but the design flaw is leaving
// lots of room for human error. Example: if our
// phone book had thousands or millions or names and numbers,
// if this was a crud application it would get very messy
// trying not to mess up the index's of the names or numbers arrays.
// Instead we would use a data structures as seen above ^


// int main(void)
// {
//     string names[] = {"Brian", "David"};
//     string numbers[] = {"123412312314", "12398999999"};

//     for (int i = 0; i < 2; i++)
//     {
//         if(strcmp(names[i], "David") == 0)
//         {
//             printf("Found %s\n", numbers[i]);
//             return 0;
//         }
//     }
//     printf("Not found");
//     return 1;
// }