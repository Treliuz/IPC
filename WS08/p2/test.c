// w8p2.c

#include "w8p2.h"
#include <stdio.h>

void convertLbsKg(const double *lbs, double *kg) {
    *kg = *lbs / LBS_TO_KG_CONVERSION;
}

int convertLbsG(const double *lbs, int *g) {
    *g = (int)(*lbs * 453.592);
    return *g;
}

void convertLbs(const double *lbs, double *kg, int *g) {
    convertLbsKg(lbs, kg);
    convertLbsG(lbs, g);
}

double calculateServings(const int servingSizeGrams, const int totalGrams, double *result) {
    *result = (double)totalGrams / servingSizeGrams;
    return *result;
}

double calculateCostPerServing(const double *price, const double *totalServings, double *result) {
    *result = *price / *totalServings;
    return *result;
}

double calculateCostPerCal(const double *price, const double *totalCalories, double *result) {
    *result = *price / *totalCalories;
    return *result;
}

ReportData calculateReportData(const CatFoodInfo *productData) {
    ReportData report;
    report.sku = productData->sku;
    report.price = productData->price;
    report.caloriesPerServing = productData->caloriesPerServing;
    report.weightLbs = productData->weight;
    
    convertLbs(&report.weightLbs, &report.weightKg, &report.weightGrams);
    
    calculateServings(64, report.weightGrams, &report.totalServings);
    calculateCostPerServing(&report.price, &report.totalServings, &report.costPerServing);
    calculateCostPerCal(&report.price, &report.caloriesPerServing, &report.costPerCal);
    
    return report;
}

void displayReportHeader(void) {
    printf("Analysis Report (Note: Serving = %dg\n", SERVING_SIZE_GRAMS);
    printf("---------------\n");
    printf("SKU $Price Bag-lbs Bag-kg Bag-g Cal/Serv Servings $/Serv $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const ReportData *data, const int isCheapest) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8.0lf %8.1lf %7.2lf %7.5lf",
           data->sku, data->price, data->weightLbs, data->weightKg, data->weightGrams,
           data->caloriesPerServing, data->totalServings, data->costPerServing, data->costPerCal);
    if (isCheapest) {
        printf(" ***");
    }
    printf("\n");
}

void displayFinalAnalysis(const CatFoodInfo *cheapestProduct) {
    printf("\nFinal Analysis\n--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n", cheapestProduct->sku, cheapestProduct->price);
    printf("Happy shopping!\n");
}

void start() {
    CatFoodInfo products[NUM_PRODUCTS];
    ReportData reportData[NUM_PRODUCTS];
    int cheapestIndex = 0;

    // ... (code to input CatFoodInfo data)

    displayReportHeader();

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        reportData[i] = calculateReportData(&products[i]);
        displayReportData(&reportData[i], i == cheapestIndex);
        
        // Update cheapestIndex based on cost per serving comparison
        if (reportData[i].costPerServing < reportData[cheapestIndex].costPerServing) {
            cheapestIndex = i;
        }
    }

    displayFinalAnalysis(&products[cheapestIndex]);
}
