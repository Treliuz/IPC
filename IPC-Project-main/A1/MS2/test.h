#ifndef CORE_H
#define CORE_H
// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);
//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
// This function guarantees that an integer value is entered and returned. If an invalid value is 
int inputInt(void);
// This function guarantees a positive integer value is entered and returned. If a zero or a 
int inputIntPositive(void);
// This function guarantees that an integer value is entered within the range (inclusive) and 
int inputIntRange(int lowerBound, int upperBound);

char inputCharOption(char str[]);
// This function guarantees a C string value is entered containing the number of characters within

void inputCString(char* str, int minChar, int maxChar);
// The purpose of this function is to display an array of 10-character digits as a formatted phone 
void displayFormattedPhone(const char* str);
// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H