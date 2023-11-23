// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// get integer value from user
int inputInt(void);

//Checks if integer is positive
int inputIntPositive(void);

//Checks if integer value is within range 
int inputIntRange(int min, int max);

//Check if entered char matches the permitted characters 
char inputCharOption(const char valid[]);

//Receives a string and checks if its length is valid
void inputCString(char* str, int minChar, int maxChar);

//Receives 10 digits and formats it into a phone number
void displayFormattedPhone(const char str[]);