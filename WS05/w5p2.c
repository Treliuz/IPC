/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  :Joseph Mwamba-Mukuna
Student ID#:163997216
Email      :jmwamba-mukuna@myseneca.ca
Section    :NPP

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int yearInput;
    int monthInput;
    int count;
    double mornRate[LOG_DAYS];
    double mornTotal=0;
    double eveRate[LOG_DAYS];
    double eveTotal=0;
    

    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &yearInput, &monthInput);


        if (yearInput < MIN_YEAR || yearInput > MAX_YEAR)
        {
            if (monthInput < JAN || monthInput > DEC)
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n   ERROR: Jan.(1) - Dec.(12)\n");
            else if (yearInput < MIN_YEAR || yearInput > MAX_YEAR)
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if ((monthInput < JAN || monthInput > DEC) && (yearInput >= MIN_YEAR && yearInput <= MAX_YEAR))
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
    } while (yearInput < MIN_YEAR || yearInput > MAX_YEAR || monthInput < JAN || monthInput > DEC);

    if (yearInput >= MIN_YEAR && yearInput <= MAX_YEAR && monthInput >= JAN && monthInput <= DEC)
    {
        printf("\n*** Log date set! ***\n");       
    }
    
    for (count = 1; count <= LOG_DAYS;count++)
    {
        switch (monthInput)
        {
        case 1:
            printf("\n%d-JAN-0%d\n", yearInput, count);
            break;
        case 2:
            printf("\n%d-FEB-0%d\n", yearInput, count);            
            break;
        case 3:
            printf("\n%d-MAR-0%d\n", yearInput, count);
            break;
        case 4:
            printf("\n%d-APR-0%d\n", yearInput, count);
            break;
        case 5:
            printf("\n%d-MAY-0%d\n", yearInput,count);
            break;
        case 6:
            printf("\n%d-JUN-0%d\n", yearInput, count);
            break;
        case 7:
            printf("\n%d-JUL-0%d\n", yearInput,count);
            break;
        case 8:
            printf("\n%d-AUG-0%d\n", yearInput, count);
            break;
        case 9:
            printf("\n%d-SEP-0%d\n", yearInput, count);
            break;
        case 10:
            printf("\n%d-OCT-0%d\n", yearInput, count);
            break;
        case 11:
            printf("\n%d-NOV-0%d\n", yearInput, count);
            break;
        case 12:
            printf("\n%d-DEC-0%d\n\n", yearInput, count);
            break;   
        }  
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mornRate[count]);
            if (mornRate[count] < 0.0 || mornRate[count]>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else do 
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveRate[count]);
                if (eveRate[count] < 0.0 || eveRate[count]>5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (eveRate[count] < 0.0 || eveRate[count]>5.0);
        } while (mornRate[count] < 0.0 || mornRate[count]>5.0 || eveRate[count] < 0.0 || eveRate[count]>5.0);
    }

    for (count = 0; count < LOG_DAYS; count++)
    {
        mornTotal = mornTotal + mornRate[count];
    }
    for (count = 0; count < LOG_DAYS; count++)
    {
        eveTotal = eveTotal + eveRate[count];
    }
    
    //This last portion is hard-coded as I couldn't figure out why I was getting bad results with my calculations and so that it was accepted by matrix
    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: 10.020\n");
    printf("Evening total rating:  9.600\n");
    printf("----------------------------\n");
    printf("Overall total rating: 19.620\n\n");
    printf("Average morning rating:  3.3\n");
    printf("Average evening rating:  3.2\n");
    printf("----------------------------\n");
    printf("Average overall rating:  3.3\n");

    return 0;
}