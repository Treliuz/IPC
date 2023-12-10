/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163997216 
Email      : jmwamba-mukuna@myseneca.ca
Section    : NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "core.h"

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!

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
//Get user input
int inputInt(void)
{
	int userInput;
	char newLine;

	while (newLine != '\n')
	{
		scanf("%d%c", &userInput, &newLine);
		if (newLine != '\n' )
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}
	return userInput;
}
//Check if entered int is positive
int inputIntPositive(void)
{
	int userInput;
	char newLine;
	while (newLine != '\n' || userInput <= 0)
	{
		scanf("%d%c", &userInput, &newLine);
		if (newLine != '\n') 
		{
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        } 
		
		else if(userInput <= 0) 
		{
            printf("ERROR! Value must be > 0: ");
        }
	}
	return userInput;
}
//Check if int is within range
int inputIntRange(int min, int max)
{
	int userInput;
	char newLine;
	while (newLine != '\n' || userInput < min || userInput > max)
	{
		scanf("%d%c", &userInput, &newLine);
		if (newLine != '\n')
		{
			clearInputBuffer();
            printf("Error! Input a whole number: ");
		}
		else if (userInput < min || userInput > max)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
		}
		
	}
	return userInput;
}

char inputCharOption(const char* validChar)
{
	char userInput;
	char newLine;
	int i = 0;
	int flag = 0;
	while(!flag)
	{
		scanf("%c%c", &userInput, &newLine);
		//Loops through valid characters and checks if userinput matches  
		for (i = 0; validChar[i] != '\0'; i++)
		{
			if (userInput == validChar[i])
			{
				flag = 1;
			}
		}
		
		if (!flag)
		{
			printf("ERROR: Character must be one of [%s]: ", validChar);
		}
		
	}
	return userInput;
}

void inputCString(char* str, int minLength, int maxLength)
{
	int length = 0;
	char ch;
	do
    {
		length = 0;
        //scanf("%[^\n]", str);
        //clearInputBuffer();

        //Read char until a newline or maxLength is reached
        while (ch != '\n' && length <= maxLength)
        {
			ch = getchar();
            str[length] = ch;
            length++;
        }

		if (ch == '\n' && length <= (maxLength + 1)) {
            length--;
            str[length] = '\0';
        }
		else 
		{
			str[maxLength] = '\0';
            clearInputBuffer();
		}

        if (length < minLength || length > maxLength)
        {
            if(minLength == maxLength) 
			{
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            } 
            
			else if(length > maxLength) 
            {
                printf("ERROR: String length must be no more than %d chars: ", maxLength);

            }
			else 
			{
				printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
			}
        }

    } while (length < minLength || length > maxLength);
}

void inputNumberString(char* str, int maxLength)
{
	int validInput = 0;
	int length;
    while (!validInput)
	{
        scanf("%s", str);

        // Clear input buffer
    	clearInputBuffer();
		length = strlen(str);
        if (length != maxLength) 
		{
            printf("Invalid 10-digit number! Number: ");
        } else 
		{
            validInput = 1;
        }
    } 
}

void displayFormattedPhone(const char* str)
{
	int i, length = 0;
	int digitCheck = 1;
	//If str is NULL will print the format for the phone number
	if(str == NULL)
	{
		printf("(___)___-____");
		return;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		length++;
		//Checks for ASCII value instead of using isdigit because I couldn't get it to work :(
		if(str[i] < 48 || str[i] > 57) 
        {
            digitCheck = 0;
        }
	}
	//Checking if length requirement is met and if all inputs are digits 
	if (length == 10 && digitCheck)
	{
		//Printing the first 3 digits in the parenthesis
		printf("(");
        for(i = 0; i < 3; i++) 
		{
            printf("%c", str[i]);
		}
		printf(")");
		for(i = 3; i < 6; i++) 
        {
            printf("%c", str[i]);        
        }
        printf("-");
        for(i = 6; i < 10; i++) 
        {
            printf("%c", str[i]);
        }
	}

	else
	{
		printf("(___)___-____");
	}
}