/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163887216
Email      : jmwamba-mukuna@myseneca.ca
Section    : NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void displayScheduleData(const struct Patient* patient, const struct Appointment* appoint,
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
    int i = 0;
    int patientFile = -1;
    int spotFound = 0;
    for (i = 0; i < max; i++)
    {
        //Checks if a element in patient array is free
        //Increments array if previous element is taken
        if (patient[i].patientNumber == 0)
        {
            spotFound = 1;
            patientFile = i;
        }
    }
    //Prints an error if array is full
    if (spotFound == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");       
    }
    //Checking to see if the max number of patients has been reached
    else 
    {
        patient[patientFile].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[patientFile]);
        printf("*** New patient record added ***\n\n");
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
    char newLineCheck;
    int flag = 1;
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
        do
        {
            scanf(" %c%c", &confirm, &newLineCheck);
            if ((confirm == 'n' || confirm == 'N') && (newLineCheck == '\n')) 
            {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }   
            else if ((confirm == 'y' || confirm == 'Y')  && (newLineCheck == '\n'))
            {
                patient[patientFile].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }
            else 
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (flag);
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
int compareAppointments(const void *a, const void *b) 
{
    const struct Appointment *appointmentA = (const struct Appointment *)a;
    const struct Appointment *appointmentB = (const struct Appointment *)b;
    //qsort(appoints, max, sizeof(struct Appointment), compareppointments);

    //Add total time together for each appointment 
    //creating a single integer similar to UNIX time for easier comparison and sorting
    int minA = (appointmentA->date.year * 12 * 30 * 24 * 60) + (appointmentA->date.month * 30 * 24 * 60) +
               (appointmentA->date.day * 24 * 60) + (appointmentA->time.hour * 60) + appointmentA->time.min;

    int minB = (appointmentB->date.year * 12 * 30 * 24 * 60) + (appointmentB->date.month * 30 * 24 * 60) +
               (appointmentB->date.day * 24 * 60) + (appointmentB->time.hour * 60) + appointmentB->time.min;
    //Compare result of each appointment 
    return minA - minB;
}

void sort(struct Appointment app[], int max)
{
    int i;
    int j;
    struct Appointment temp;
    //Storing the "UNIX" minutes 
    for (i = 0; i < max; i++) 
    {
        app[i].time.min = (app[i].date.year * 12 * 30 * 24 * 60) + (app[i].date.month * 30 * 24
        * 60) + (app[i].date.day * 24 * 60) + (app[i].time.hour * 60) + app[i].time.min;
    }
    //Selection sort to organize the array
    for (i = 0; i < max - 1; i++) 
    {
        int minIndex = i;
        for (j = i + 1; j < max; j++) 
        {
            if (app[j].time.min < app[minIndex].time.min) 
            {
                minIndex = j;
            }
        }

        if (minIndex != i) 
        {
            temp = app[i];
            app[i] = app[minIndex];
            app[minIndex] = temp;
        }
    }
    //Revert "UNIX" conversion to display properly
    for (i = 0; i < max; i++) 
    {
        app[i].time.min = app[i].time.min - (app[i].date.year * 12 * 30 * 24 * 60) - 
        (app[i].date.month * 30 * 24 * 60) - (app[i].date.day * 24 * 60) - (app[i].time.hour * 60);
    }
}
// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) 
{
    int i;
    int j;
    //Sorts the data
    sort(data->appointments, data->maxAppointments);
    //Display patients
    displayScheduleTableHeader(NULL, 1);
    //Prints appointment information followed by patient info
    for (i = 0; i < data->maxAppointments; i++) 
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    printf("\n");
}
// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, j;
    struct Date date;
    //Get year from user
    printf("Year        : ");
    date.year = inputIntPositive();
    //Get month from user
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    printf("Day (1-");
    //Number of days in each month
    int numOfDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //Number of days in a month 
    int totalDays = numOfDays[date.month];
    //Account for leap years since those exist for some reason I have yet to understand
    if (date.year % 4 == 0 && date.month == 2) 
    {
        totalDays = 29;
    }
    printf("%d)  : ", totalDays);
    date.day = inputIntRange(1, totalDays);
    printf("\n");
    //Sorts the data
    sort(data->appointments, data->maxAppointments);

    //Prints appointment information followed by patient info
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) 
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == 
                        date.month && data->appointments[i].date.day == date.day) 
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }  
    }
    printf("\n");
}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *app, int maxApp, struct Patient *pt, int maxPatients)
{
    struct Date date;
    struct Time time;
    int patientNumber; 
    int patientIndex; 
    int slotAvail = 1;

    //Getting user input 
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    patientIndex = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);
    if(patientIndex >= 0)
    {
        do
        {
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);
            printf("Day (1-");
            int numOfDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
            int totalDays = numOfDays[date.month];
            //Account for leap years since those exist for some reason I have yet to understand
            if (date.year % 4 == 0 && date.month == 2) 
            {
                totalDays = 29;
            }
            printf("%d)  : ", totalDays);
            date.day = inputIntRange(1, totalDays);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            //Check if slot is available
            if (timeSlotCheck(date, time, app, maxApp))
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }

            else
            {
                while ((time.hour < SOD || time.hour > EOD) || (time.hour && time.min > 0) 
                || (time.min % MINUTE_INTERVAL != 0))
                {
                    //Print error and correct user if input is out of scope
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n",
                    SOD, EOD, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0,23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0,59);
                }
                slotAvail = 0;
            }

        } while (slotAvail);

        //Writing the new values into the open slot
        patientIndex = openSlot(app, maxApp);
        app[patientIndex].date = date;
        app[patientIndex].time = time;
        app[patientIndex].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *app, int maxAppointment, struct Patient *pt, int maxPatient)
{
    struct Date date;
    int patientIndex;
    int patientNumber;
    int appointIndex;
    //Get patient number from user
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    patientIndex = findPatientIndexByPatientNum(patientNumber, pt, maxPatient);
    if(patientIndex >= 0)
    {
        printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);
            printf("Day (1-");
            int numDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
            int totalDays = numDays[date.month];
            //Account for leap years since those exist for some reason I have yet to understand
            if (date.year % 4 == 0 && date.month == 2) 
            {
                totalDays = 29;
            }
            printf("%d)  : ", totalDays);
            date.day = inputIntRange(1, totalDays);
            appointIndex = freeAppointment(patientNumber, date, app, maxAppointment);
            if (appointIndex >=0)
            {
                printf("\n");
                displayPatientData(&pt[patientIndex],FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");

                if (inputCharOption("yn") == 'y' || 'Y')
                {
                    app[appointIndex].patientNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");
                }
                else
                {
                    printf("ERROR: No appointment for this date!\n\n");
                }
            }
            
    }

    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
//Find an available time slot
int timeSlotCheck(struct Date date, struct Time time, struct Appointment* app, int maxAppointments)
{
    int i;
    int avail = 0;
    for (i = 0; i < maxAppointments; i++)
    {
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == 
            app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min)
        {
            avail = 1;
        }
    }
    return avail;
}
//Checks to find the next available slot 
int openSlot(struct Appointment* app, int maxAppointments)
{
    int i;
    for (i = 0; i < maxAppointments; i++)
    {
        if (app[i].patientNumber < 1) 
        {
            return i;
        }
        i++;
    }
    return maxAppointments;
}

//Checks to see if an appointment is valid
int freeAppointment(int patientNumber, struct Date date, struct Appointment *app, int maxAppointments)
{
    int i = 0;
    int free = 0;
    while (free == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year))
        {
            free = 1;
        }
        i++;
    }
    return i - 1;
}
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
    printf("Search by phone number: ");
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
    inputCString(patient->name, 1, NAME_LEN);
    //Removes newline
    if (patient->name[strlen(patient->name) - 1] == '\n')
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
    char number[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    phoneType = inputIntRange(1, 4);
    printf("\n");
    switch (phoneType)
    {
    case 1:
        //Storing the description
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputNumberString(number, PHONE_LEN);
        strcpy(phone->number, number);
        break;
    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputNumberString(number, PHONE_LEN);
        strcpy(phone->number, number);
        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputNumberString(number, PHONE_LEN);
        strcpy(phone->number, number);
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;
    }
    printf("\n");
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;

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
    int count = 0;

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