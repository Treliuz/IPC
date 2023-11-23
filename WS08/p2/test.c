/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <stdio.h>
// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int value;
    char newLine = 'x';
    while (newLine != '\n') 
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n') 
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }    return value;  
}
int inputIntPositive(void)
{
    int value;
    char newLine = 'x';
    while (newLine != '\n' || value <= 0) {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } else if(value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    }
    return value; 
}
int inputIntRange(int lowerBound, int upperBound)
{
    int value;
    char newLine = 'x';
    while (newLine != '\n' || value < lowerBound || value > upperBound) {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } else if(value < lowerBound || value > upperBound) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    }
    return value;
}
char inputCharOption(const char* validChar)
{
    char value;
    char newLine = 'x';
    int i, isValid = 0;
    while(isValid != 1) 
    {
        scanf("%c%c", &value, &newLine);
        for(i=0; validChar[i] != '\0'; i++) 
        {
            if(value == validChar[i]) 
            {
                isValid = 1;
            }
        }

        if(isValid != 1) 
        {            
            printf("ERROR: Character must be one of [%s]: ", validChar);
        }
    }
    return value;
}
void inputCString(char* string, int minLength, int maxLength)
{
    int i, length = 0;
    while(length < minLength || length > maxLength) {
        scanf("%[^\n]%*c", string);
        length = 0;
        for(i=0; string[i] != '\0'; i++) {
            length++;
        }
        if(length < minLength || length > maxLength) {
            if(minLength == maxLength) {
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            } 
            else if(length > maxLength) 
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLength);
            }
        }
    }
}
void displayFormattedPhone(const char* str)
{
    if(str == NULL) {
        printf("(___)___-____");
        return;
    }
    int i, isAllNumber = 1, length = 0;
    length = 0;
    for(i=0; str[i] != '\0'; i++) 
    {
        length++;
        if(str[i] < 48 || str[i] > 57) 
        {
            isAllNumber = 0;
        }
    }
    if(length == 10 && isAllNumber) 
    {
        printf("(");
        for(i=0; i<3; i++) {
            printf("%c", str[i]);
        }
        printf(")");
        for(i=3; i<6; i++) 
        {
            printf("%c", str[i]);        
        }
        printf("-");
        for(i=6; i<10; i++) 
        {
            printf("%c", string[i]);
        }
    } 
    else 
    {
        printf("(___)___-____");
    }
}