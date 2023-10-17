/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char loopType;
    int loopNum;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    //Do-while surrounding the entire code to repeat until condition is false 
    do 
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopNum);
        
        //Check if the exit sequence was used setting variable killSwitch to 0 making the do while stop
        if (loopType == 'Q' && loopNum == 0)
        {
            printf("\n\n");
            printf("+--------------------+\n");
            printf("Loop application ENDED\n");
            printf("+--------------------+\n");               
            return 0;
        }
        
        //Checks for incorrect usage of the exit sequence
        else if (loopType == 'Q' && loopNum !=0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }

        //Anything other than the below characters are checked here and accepted or denied
        else if (loopType != 'D' && loopType != 'W' && loopType != 'F' && loopType != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

        //Checks to see if user input is within range
        else if (loopNum < 3 || loopNum > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }

        //If all conditions are satisfied begin loop
        else 
        {
            switch (loopType) 
            {
                case 'D':
                printf("DO-WHILE: ");
                    do 
                    {
                        printf("D");
                        loopNum--;
                    } while (loopNum > 0);
                    printf("\n\n");
                    break;

                case 'W':
                printf("WHILE   : ");
                    while(loopNum > 0)
                    {
                        printf("W");
                        loopNum--;
                    }
                printf("\n\n");
                break;

                case 'F':
                printf("FOR     :");
                    for (int i = 0; i < loopNum; i++)
                    {
                        printf("F");
                    }
                printf("\n\n");
                break;
            }           
        }

    //While variable killSwitch is equal to 1 loop will continue
    } while(1);

    return 0;
}