#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // add vote to candidate if vote is same as name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    bool tie = false;
    string winner = "";
    string winner2 = "";
    string winner3 = "";
    int most_votes = 0;
    int winner_count = 0;

    // seeing who the winner is
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != 0)
        {
            // If there is a 3 way tie
            if (candidates[i].votes == most_votes && tie == true)
            {
                winner3 = candidates[i].name;
                winner_count++;
            }
            // if there is a tie
            else if (candidates[i].votes == most_votes)
            {
                winner2 = candidates[i].name;
                winner_count++;
                tie = true;
            }
            // if there is only one winner
            else if (candidates[i].votes > most_votes)
            {
                most_votes = candidates[i].votes;
                winner = candidates[i].name;
                winner_count = 1;
            }
        }
    }

    // Print correct amount of winner
    if (winner_count == 2)
    {
        printf("%s\n", winner);
        printf("%s\n", winner2);
    }
    else if (winner_count == 3)
    {
        printf("%s\n", winner);
        printf("%s\n", winner2);
        printf("%s\n", winner3);
    }
    else
    {
        printf("%s\n", winner);
    }

    return;
}

