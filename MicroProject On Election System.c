#include<stdio.h>
#include<conio.h>

struct Candidate 
{
    char name[50];
    int votes;
};

void main() 
{
    int num_candidates,i,vote,num_voters,winner_index=0;
    clrscr();
    printf("Enter the number of candidates: ");
    scanf("%d",&num_candidates);

    struct Candidate candidates[num_candidates];

    // Input the candidate names
    for (i=0;i<num_candidates;i++) 
    {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s",candidates[i].name);
        candidates[i].votes = 0;
    }

    // Allow voters to cast their votes
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i=0;i<num_voters;i++) 
    {
        printf("Voter %d, enter your vote (1-%d): ", i + 1, num_candidates);
        scanf("%d", &vote);

        if (vote<1 || vote>num_candidates) 
        {
            printf("Invalid vote!\n");
            continue;
        }

        candidates[vote - 1].votes++;
    }

    // Print the results
    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) 
    {
        printf("%d. %s: %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    for (i = 1; i < num_candidates; i++) 
    {
        if (candidates[i].votes > candidates[winner_index].votes) 
        {
            winner_index = i;
        }
    }
    printf("\nThe winner is %s!\n", candidates[winner_index].name);
    getch();
}
