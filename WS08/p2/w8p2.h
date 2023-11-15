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

// ----------------------------------------------------------------------------
#define MAX_PRODUCT 3
#define WEIGHT 64
#define LBS_CONVERSION 2.20462
// structures
struct CatFoodInfo
{
    int skuNumber;
    int calories;
    double price;
    double weight;
};

struct ReportData
{
    int sku;
    int caloriesServing;
    int grams;
    double price;
    double pounds;
    double kilos;
    double totalServings;
    double costServing;
    double costCalories;
};
// ----------------------------------------------------------------------------
// function prototypes
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* userInput);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* userInput);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNumber);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const double* price, const int calories, const double* weight);
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* resultLbsKg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* resultLbsG);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* resultLbsKg, int* resultLbsG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalWeight, double* results);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServings, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalories, double* result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportDaata(const struct CatFoodInfo* productData);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData *data, const int cheap);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo* cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
