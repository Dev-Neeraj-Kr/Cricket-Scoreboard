#include <stdio.h>
#define MAX_PLAYERS 11
struct Player 
{
    char name[30];
    int runs;
    int balls;
};

void enterPlayers(struct Player players[],int *numberOfPlayers) 
{
    printf("How many players? (1-11): ");
    scanf("%d", numberOfPlayers);
    if (*numberOfPlayers < 1 || *numberOfPlayers > MAX_PLAYERS)
    {
        printf("Please enter a number from 1 to 11.\n");
        *numberOfPlayers = 0;
        return;
    }

    for (int i = 0; i < *numberOfPlayers; i++) 
    {
        printf("\nEnter player %d name: ", i + 1);
        scanf("%29s", players[i].name);
        players[i].runs = 0;
        players[i].balls = 0;
    }
}

void enterScores(struct Player players[],int numberOfPlayers) 
{
    if (numberOfPlayers == 0)
    {
        printf("Enter player names first.\n");
        return;
    }

    for (int i = 0; i < numberOfPlayers; i++)
    {
        printf("\nEnter runs for %s: ", players[i].name);
        scanf("%d", &players[i].runs);
        printf("Enter balls faced by %s: ", players[i].name);
        scanf("%d", &players[i].balls);
    }
}

void displayScorecard(struct Player players[],int numberOfPlayers)
{
    if (numberOfPlayers == 0) 
    {
        printf("Enter player names first.\n");
        return;
    }

    int totalRuns = 0;
    printf("\n--- Scorecard ---\n");
    printf("Name\tRuns\tBalls\tStrike Rate\n");

    for (int i = 0; i < numberOfPlayers; i++) 
    {
        float strikeRate = 0;
        if (players[i].balls > 0)
        {
            strikeRate = (float) players[i].runs / players[i].balls * 100;
        }
        printf("%s\t%d\t%d\t%.2f\n",
        players[i].name,
        players[i].runs,
        players[i].balls,
        strikeRate);
        totalRuns = totalRuns + players[i].runs;
    }
    printf("Team runs: %d\n", totalRuns);
}

void showHighestScorer(struct Player players[],int numberOfPlayers)
{
    if (numberOfPlayers == 0) 
    {
        printf("Enter player names first.\n");
        return;
    }

    int highestIndex = 0;
    for (int i = 1; i < numberOfPlayers; i++)
    {
        if (players[i].runs > players[highestIndex].runs) 
        {
            highestIndex = i;
        }
    }
    printf("Highest scorer: %s with %d runs\n",
    players[highestIndex].name,
    players[highestIndex].runs);
}

int main() 
{
    struct Player players[MAX_PLAYERS];
    int numberOfPlayers = 0;
    int choice;
 
    do
    {
        printf("\n=== Cricket Scoreboard ===\n");
        printf("1. Enter player names\n");
        printf("2. Enter player scores\n");
        printf("3. Display scorecard\n");
        printf("4. Show highest scorer\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                enterPlayers(players, &numberOfPlayers);
            break;

            case 2:
                enterScores(players, numberOfPlayers);
            break;

            case 3:
                displayScorecard(players, numberOfPlayers);
            break;

            case 4:
                showHighestScorer(players, numberOfPlayers);
            break;

            case 5:
                printf("Goodbye!\n");
            break;

            default:
            printf("Invalid choice. Please choose 1 to 5.\n");
        }

    }while (choice != 5);

    return 0;
}