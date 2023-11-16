#include <stdio.h>
#include <ctype.h>

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
	int userInput;
	char newLine;

	scanf("%d%c", &userInput, &newLine);
	while (1)
	{
		if (scanf("%d%c", &userInput, &newLine) == 2)
		{
			if (newLine == '\n' )
			{
				return userInput;
			}
		}
		else
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}
}