#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Player
{
    char name[100];
    int age;
    char style[100];
    int matches;
    int runs;
    int highestRun;
};


int calculateValue(struct Player player)
{
    return player.age + player.matches + player.runs + player.highestRun + (player.runs / player.matches) + (player.highestRun / player.age);
}

int main()
{
    FILE *file;
    char inputFileName[100];
    char line[200];
    int numPlayers = 6; 
    struct Player players[numPlayers];

    
    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("File not found or unable to open.\n");
        return 1; 
    }

   
    for (int i = 0; i < numPlayers; i++)
    {
        if (fgets(line, sizeof(line), file) == NULL)
        {
            break; 
        }

        sscanf(line, "%99[^\n]", players[i].name); 
        fgets(line, sizeof(line), file);           
        sscanf(line, "%d", &players[i].age);
        fgets(line, sizeof(line), file); 
        sscanf(line, "%99[^\n]", players[i].style);
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &players[i].matches);
        fgets(line, sizeof(line), file); 
        sscanf(line, "%d", &players[i].runs);
        fgets(line, sizeof(line), file); 
        sscanf(line, "%d", &players[i].highestRun);
    }

   
    fclose(file);

  
    int maxMatches = 0;
    int mepIndex = -1;
    int minAge = players[0].age;
    int ncpIndex = 0;
    int maxRuns = 0;
    int tspIndex = -1;
    int maxAvgRunPerMatch = 0;
    int hhpIndex = -1;
    int maxHighestRun = 0;
    int hrtpIndex = -1;
    int maxValue = 0;
    int mvpIndex = -1;

   
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Show All Players\n");
        printf("2. Show A Particular player information (Provide Player Name)\n");
        printf("3. Show the MOST Experienced Player (MEP)\n");
        printf("4. Show the New Comer Player (NCP)\n");
        printf("5. Show the Top Scorer Player (TSP)\n");
        printf("6. Show the Hard Hitter Player (HHP)\n");
        printf("7. Show the Highest Run Taker Player (HRTP)\n");
        printf("8. Show the MOST Valuable Player (MVP)\n");
        printf("9. Show the Allrounders\n");
        printf("10. Exit/Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n')
            ; // Clear the input buffer

        switch (choice)
        {
        case 1:
            printf("All Players:\n");
            for (int i = 0; i < numPlayers; i++)
            {
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[i].name, players[i].age, players[i].style,
                       players[i].matches, players[i].runs, players[i].highestRun);
            }
            break;
        case 2:
        {
            char playerName[100];
            printf("Enter the player's name: ");
            fgets(playerName, sizeof(playerName), stdin);
            playerName[strlen(playerName) - 1] = '\0'; 

            int playerFound = 0; 

            for (int i = 0; i < numPlayers; i++)
            {
                if (strcmp(players[i].name, playerName) == 0)
                {
                    printf("Player Information:\n");
                    printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                           players[i].name, players[i].age, players[i].style,
                           players[i].matches, players[i].runs, players[i].highestRun);

                    playerFound = 1; 
                    break;           
                }
            }

            if (!playerFound)
            {
                printf("Player not found.\n");
            }

            while (getchar() != '\n')
                ; 
            break;
        }

        case 3:
            
            maxMatches = 0;
            mepIndex = -1;
            for (int i = 0; i < numPlayers; i++)
            {
                if (players[i].matches > maxMatches)
                {
                    maxMatches = players[i].matches;
                    mepIndex = i;
                }
            }
            if (mepIndex != -1)
            {
                printf("MOST Experienced Player (MEP):\n");
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[mepIndex].name, players[mepIndex].age, players[mepIndex].style,
                       players[mepIndex].matches, players[mepIndex].runs, players[mepIndex].highestRun);
            }
            break;
        case 4:
            
            minAge = players[0].age;
            ncpIndex = 0;
            for (int i = 1; i < numPlayers; i++)
            {
                if (players[i].age < minAge)
                {
                    minAge = players[i].age;
                    ncpIndex = i;
                }
            }
            printf("New Comer Player (NCP):\n");
            printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                   players[ncpIndex].name, players[ncpIndex].age, players[ncpIndex].style,
                   players[ncpIndex].matches, players[ncpIndex].runs, players[ncpIndex].highestRun);
            break;
        case 5:
            maxRuns = 0;
            tspIndex = -1;
            for (int i = 0; i < numPlayers; i++)
            {
                if (players[i].runs > maxRuns)
                {
                    maxRuns = players[i].runs;
                    tspIndex = i;
                }
            }
            if (tspIndex != -1)
            {
                printf("Top Scorer Player (TSP):\n");
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[tspIndex].name, players[tspIndex].age, players[tspIndex].style,
                       players[tspIndex].matches, players[tspIndex].runs, players[tspIndex].highestRun);
            }
            break;
        case 6:
            
            maxAvgRunPerMatch = 0;
            hhpIndex = -1;
            for (int i = 0; i < numPlayers; i++)
            {
                int avgRunPerMatch = players[i].runs / players[i].matches;
                if (avgRunPerMatch > maxAvgRunPerMatch)
                {
                    maxAvgRunPerMatch = avgRunPerMatch;
                    hhpIndex = i;
                }
            }
            if (hhpIndex != -1)
            {
                printf("Hard Hitter Player (HHP):\n");
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[hhpIndex].name, players[hhpIndex].age, players[hhpIndex].style,
                       players[hhpIndex].matches, players[hhpIndex].runs, players[hhpIndex].highestRun);
            }
            break;
        case 7:
            
            maxHighestRun = 0;
            hrtpIndex = -1;
            for (int i = 0; i < numPlayers; i++)
            {
                if (players[i].highestRun > maxHighestRun)
                {
                    maxHighestRun = players[i].highestRun;
                    hrtpIndex = i;
                }
            }
            if (hrtpIndex != -1)
            {
                printf("Highest Run Taker Player (HRTP):\n");
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[hrtpIndex].name, players[hrtpIndex].age, players[hrtpIndex].style,
                       players[hrtpIndex].matches, players[hrtpIndex].runs, players[hrtpIndex].highestRun);
            }
            break;
        case 8:
           
            maxValue = 0;
            mvpIndex = -1;
            for (int i = 0; i < numPlayers; i++)
            {
                int value = calculateValue(players[i]);
                if (value > maxValue)
                {
                    maxValue = value;
                    mvpIndex = i;
                }
            }
            if (mvpIndex != -1)
            {
                printf("MOST Valuable Player (MVP):\n");
                printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                       players[mvpIndex].name, players[mvpIndex].age, players[mvpIndex].style,
                       players[mvpIndex].matches, players[mvpIndex].runs, players[mvpIndex].highestRun);
            }
            break;
        case 9:
            
            printf("Allrounders:\n");
            for (int i = 0; i < numPlayers; i++)
            {
                if (strstr(players[i].style, "Allrounder") != NULL)
                {
                    printf("Name: %s, Age: %d, Style: %s, Matches: %d, Runs: %d, Highest Run: %d\n",
                           players[i].name, players[i].age, players[i].style,
                           players[i].matches, players[i].runs, players[i].highestRun);
                }
            }
            break;
        case 10:
            printf("Exiting the program.\n");
            return 0; 
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
