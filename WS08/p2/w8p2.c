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
#include "w8p2.h"
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* resultLbsKg)
{
	if (resultLbsKg != NULL)
	{ 
		*resultLbsKg = *lbs / LBS_CONVERSION;
	}

	return *lbs / LBS_CONVERSION;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* resultLbsG)
{
	if (resultLbsG != NULL)
	{
		*resultLbsG = (int)(convertLbsKg(lbs, NULL)* 1000);
	}
	
	return (int)(convertLbsKg(lbs, NULL)* 1000);
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* resultKg, int* resultG)
{
	if (resultKg != NULL)
	{
		*resultKg = convertLbsKg(lbs, NULL);
	}
	
	if (resultG != NULL)
	{
		*resultG = convertLbsG(lbs, NULL);
	}
	
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalWeight, double* result)
{
	if (result != NULL)
	{
		*result = (double)totalWeight / (double)servingSize;
	} 

	return (double)totalWeight / servingSize; 
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServings, double* result)
{
	if (result != NULL)
	{ 
		*result = *price / *totalServings; 
	}

	return *price / *totalServings;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalories, double* result)
{
	if (result != NULL)
	{
		*result = *price / *totalCalories;
	}
	
	return *price / *totalCalories;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo *productData)
{
	struct ReportData report;

	report.sku = productData->skuNumber;
	report.price = productData->price;
	report.caloriesServing = productData->calories;
	report.pounds = productData->weight;

	report.totalServings = calculateServings(productData->weight, productData->weight, NULL);
	report.costServing = calculateCostPerServing(productData->price, report.totalServings);
	report.costCalories = calculateCostPerCal(productData->price, report.caloriesServing);
	report.kilos = convertLbsKg(productData->weight, NULL);
	report.grams = convertLbsG(productData->weight, NULL);

	return report;
}

//15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n");
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData *data, const int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data->sku, data->price, data->caloriesServing,
           data->weightPounds, data->weightKilos, data->weightGrams,
           data->totalServings, data->costServing, data->costCalories);

	if (isCheapest != 0) {
        printf(" ***");
    }

	
    printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo* cheapestProduct) 
	{
    // Check if the argument is not NULL
    if (cheapestProduct != NULL) 
	{
        // Display the recommendation message with data details
        printf("Our recommendation for the best value cat food is SKU %d.\n", cheapestProduct->skuNumber);
        printf("It provides a balance of affordability, calories, and weight.\n");
        printf("Happy shopping!\n");
    } 
	else 
	{
        // Display a message indicating no recommendation data
        printf("No recommendation data available.\n");
    }
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{


}
