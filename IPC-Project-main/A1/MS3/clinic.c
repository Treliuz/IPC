/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int validRecFlag = 0;
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            validRecFlag = 1;
        }
    }

    if (!validRecFlag)
    {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOption;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &searchOption);
        printf("\n");
        //Jump to different functions depending on user selection
        switch (searchOption) {
            case 1:
                searchPatientByPatientNumber(patient, max);
                clearInputBuffer();
                suspend();
                break;
            case 2:
                searchPatientByPhoneNumber(patient, max);
                clearInputBuffer();
                suspend();
                break;
        }
    } while (searchOption != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int size = 0;
    for (i = 0; i < max; i++)
    {
        //Checks if a element in patient array is free
        //Increments array if previous element is taken
        if (patient[i].patientNumber != 0)
        {
            size++;
        }
    }
    //Checking to see if the max number of patients has been reached
    if (size < max)
    {
        patient[size].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + size);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    //Prints an error if array is full
    else 
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patientNum;
    int patientFile;
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");
    patientFile = findPatientIndexByPatientNum(patientNum, patient, max);
    //If patient file is found jump to the edit function
    if (patientFile != -1)
    {
        menuPatientEdit(&patient[patientFile]);
    }
    else 
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientNum;
    int patientFile;;
    char confirm;
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");
    patientFile = findPatientIndexByPatientNum(patientNum, patient, max);
    //If patient file is found jump to the removal function
    if (patientFile != -1)
    {
        //Displaying patient information
        printf("Name  : %s\n", patient[patientFile].name);
        printf("Number: %05d\n", patient[patientFile].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientFile].phone.number);
        printf(" (%s)", patient[patientFile].phone.description);
        printf("\n\n");
        //Getting confirmation from user to remove patient record
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'n' || confirm == 'N') 
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }

        else if (confirm == 'y' || confirm == 'Y')
        {
            
            patient[patientFile].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else 
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int compareAppointments(const void *a, const void *b) {
    const struct Appointment *appA = (const struct Appointment *)a;
    const struct Appointment *appB = (const struct Appointment *)b;
    //qsort(appoints, max, sizeof(struct Appointment), compareAppointments);

    // Compare total minutes
    int minA = (appA->date.year * 12 * 30 * 24 * 60) + (appA->date.month * 30 * 24 * 60) +
               (appA->date.day * 24 * 60) + (appA->time.hour * 60) + appA->time.min;

    int minB = (appB->date.year * 12 * 30 * 24 * 60) + (appB->date.month * 30 * 24 * 60) +
               (appB->date.day * 24 * 60) + (appB->time.hour * 60) + appB->time.min;

    return minA - minB;
}
// View ALL scheduled appointments
// Todo:


// View appointment schedule for the user input date
// Todo:


// Add an appointment record to the appointment array
// Todo:


// Remove an appointment record from the appointment array
// Todo:


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum;
    int patientFile;

    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    printf("\n");
    patientFile = findPatientIndexByPatientNum(patientNum, patient, max);
    //Checks if the patient exists
    if (patientFile != -1)
    {
        //Display patient information
        printf("Name  : %s\n", patient[patientFile].name);
        printf("Number: %05d\n", patient[patientFile].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientFile].phone.number);
        printf(" (%s)", patient[patientFile].phone.description);
        printf("\n\n");
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int found = 0;
    char phoneNum[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Seach by phone number: ");
    fgets(phoneNum, sizeof(phoneNum), stdin);
    printf("\n");
    //Tabular format header
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        //Compare phone numbers to find a match
        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            found++;
        }
    }
    printf("\n");
    //Checking if the number was found
    if (!found)
    {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int nextNum = 0;
    int i;
    for (i = 0; i < max; i++) 
    {
        if (patient[i].patientNumber > nextNum) 
        {
            nextNum = patient[i].patientNumber;
        }
    }
    return nextNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) 
    {
        if (patient[i].patientNumber == patientNumber) 
        {
            return i;
        }
    }
    // If record isn't found return -1
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    //gets name from user and inputs into array
    fgets(patient->name, sizeof(patient->name), stdin);
    if (patient->name[strlen(patient->name) - 1] == '\n');
    {
        //Replaces newline character with null terminator
        patient->name[strlen(patient->name) - 1] = '\0';
    }

    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int phoneType;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &phoneType);
    printf("\n");

    switch (phoneType)
    {
    case 1:
        //Storing the description
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        //Clearing buffer then getting user input for the phone number
        clearInputBuffer();
        printf("Number : ");
        fgets(phone->number, sizeof(phone->number), stdin);
        printf("\n");
        break;
    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        fgets(phone->number, sizeof(phone->number), stdin);
        printf("\n");
        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        fgets(phone->number, sizeof(phone->number), stdin);
        printf("\n");
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = 0;
        break;
    default:
        printf("Error:\n");
        break;
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i;

    FILE *fp;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while(i < max && fscanf(fp,  "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name,
        patients[i].phone.description, patients[i].phone.number)!=EOF)
        {
            i++;
        }
        fclose(fp);
    }

    else
    {
        printf("ERROR: File could not be read\n");
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i;
    int count;

    FILE *fp;
    fp = fopen(datafile, "r");

    if(fp != NULL)
    {
        for (i = 0; i < max && !feof(fp); i++) 
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, 
            &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);

            if (!feof(fp)) 
            {
                count++;
            }
        }
        fclose(fp);
    }

    else
    {
        printf("ERROR: File could not be read\n");
    }

    return count;
}