// ############################################################################
//
//  Assignment:  1 
//  Milestone:   3
//  Description: Main Application Entry Point
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
// ############################################################################

#include <stdio.h>

#include "clinic.h"

#define MAX_PETS 20
#define MAX_APPOINTMENTS 50

int main(void)
{
    struct Patient pets[MAX_PETS] = { {0} };
    struct Appointment appoints[MAX_APPOINTMENTS] = { {0} };
    struct ClinicData data = { pets, MAX_PETS, appoints, MAX_APPOINTMENTS };

    int patientCount = importPatients("patientData.txt", pets, MAX_PETS);
    int appointmentCount = importAppointments("appointmentData.txt", appoints, MAX_APPOINTMENTS);

    printf("Imported %d patient records...\n", patientCount);
    printf("Imported %d appointment records...\n\n", appointmentCount);

    menuMain(&data);
    
    return 0;
}

void findCheapest(const struct Part* database, const int arrSZ)
{
    int cheapestIndex = 0;
    int i;
    double cheapest = database[cheapestIndex].price;
    //find the cheapest in stock product
    for (i = 1; ___________; _______________)
    {
        if (database[i].price < ________________ && _______________)
        {
            cheapestIndex = i;
            cheapest = ______________;
        }
    }
    printf("The cheapest in stock product is: %s with price %.2f\n",
     database[minIndex].name, database[minIndex].price);
}