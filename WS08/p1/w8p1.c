/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* userInput)
{
	int intInput;
	do
	{
		scanf(" %d", &intInput);
		if (intInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (intInput <= 0);
	
	if (userInput != NULL)
	{
		*userInput = intInput;
	}
	return intInput;	
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* userInput)
{
	double doubleInput;
	do
	{
		scanf(" %lf", &doubleInput);
		if (doubleInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (doubleInput <= 0);
	
	if (userInput != NULL)
	{
		*userInput = doubleInput;
	}
	return doubleInput;	
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n\n", WEIGHT);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	struct CatFoodInfo info;
	printf("Cat Food Product #%d\n", sequenceNum);
    printf("--------------------\n");
	printf("SKU           : ");
	info.skuNumber = getIntPositive(NULL);

	printf("PRICE         : $");
	info.price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	info.weight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	info.calories = getIntPositive(NULL);

	printf("\n");
	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const double *price, const int calories, const double *weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *price, *weight, calories);
}

// 7. Logic entry point
void start()
{
	int i;
	struct CatFoodInfo catFood[MAX_PRODUCT];

    for(i = 0; i < MAX_PRODUCT; i++) 
	{
        catFood[i].skuNumber = 0;
        catFood[i].price = 0.0;
        catFood[i].calories = 0;
        catFood[i].weight = 0.0;
    }

	openingMessage(MAX_PRODUCT);

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		catFood[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodData(catFood[i].skuNumber, &catFood[i].price, catFood[i].calories, &catFood[i].weight);
	}
}