/******************************************************************************
                          Workshop - #7 (P1)
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163997216
Email      : jmwamba-mukuna@myseneca.ca
Section    : NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 70
#define MIN_LENGTH 10 
#define MAX_LIFE 10
#define MIN_LIFE 1
#define MULTIPLE 5

#include <stdio.h>

struct PlayerInfo
{
    int lives;
    int Treasure;
    char symbol;
    char history[MAX_LENGTH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    char bombs[MAX_LENGTH];
    char treasure[MAX_LENGTH];
};

int main(void)
{
    struct PlayerInfo Stats;
    struct GameInfo Game;

    printf("================================\n"); 
    printf("         Treasure Hunt!\n"); 
    printf("================================\n\n"); 
    printf("PLAYER Configuration\n");
    printf("--------------------\n"); 
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &Stats.symbol);

    //Loop to check if user input is withing expected range
    int validLives;
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &Stats.lives);
        validLives = Stats.lives < MIN_LIFE || Stats.lives > MAX_LIFE;

        if (validLives)
        {
            printf("     Must be between %d and %d!\n", MIN_LIFE, MAX_LIFE);
        }

    } while (validLives);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    //Loop to check if user input is within expected range
    int validLength;
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE,MIN_LENGTH,MAX_LENGTH);
        scanf("%d", &Game.pathLength);
        validLength = Game.pathLength < MIN_LENGTH || Game.pathLength > MAX_LENGTH || Game.pathLength% MULTIPLE != 0;
        
        if (validLength)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_LENGTH, MAX_LENGTH);
        }
    } while (validLength);

    //Loop to check if user input is within expected range
    int validMove;
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.moves);
        validMove = Game.moves > (75 * Game.pathLength / 100) || Game.moves < Stats.lives;
        if (validMove)
        {
            printf("    Value must be between %d and %d\n", Stats.lives, 75 * Game.pathLength / 100);
        }
    } while (validMove);

    
    printf("\nBOMB Placement\n"); 
    printf("--------------\n"); 
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE); 
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"); 
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);

    //Outer for loop iterates through the path in sets of 5
    //Inner loop gets user input for bombs/treasure placement with respect of the sets of 5 from the outer loop
    int i, j;
    for (i = 0; i < Game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ",i + 1,i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++) 
        {
            scanf(" %c", &Game.bombs[i+j]);
        }
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n"); 
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n",MULTIPLE); 
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);

    
    for (i = 0; i < Game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++)
        {
            scanf(" %c", &Game.treasure[i + j]);
        }
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");

    printf("   Symbol     : %c\n", Stats.symbol);
    printf("   Lives      : %d\n", Stats.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", Game.pathLength);
    printf("   Bombs      : ");
    for ( i = 0; i < Game.pathLength; i++)
    {
        printf("%c", Game.bombs[i]);
    }

    printf("\n   Treasure   : ");
    for (i = 0; i < Game.pathLength; i++)
    {
        printf("%c", Game.treasure[i]);
    }

    //Game start
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}
