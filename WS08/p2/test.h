

#define LBS_TO_KG_CONVERSION 2.20462

typedef struct {
    int sku;
    double price;
    int caloriesPerServing;
    double weightLbs;
    double weightKg;
    int weightGrams;
    double totalServings;
    double costPerServing;
    double costPerCal;
} ReportData;

struct CatFoodInfo
{
    int skuNumber;
    int calories;
    double price;
    double weight;
};

void convertLbsKg(const double *lbs, double *kg);
int convertLbsG(const double *lbs, int *g);
void convertLbs(const double *lbs, double *kg, int *g);
double calculateServings(const int servingSizeGrams, const int totalGrams, double *result);
double calculateCostPerServing(const double *price, const double *totalServings, double *result);
double calculateCostPerCal(const double *price, const double *totalCalories, double *result);
ReportData calculateReportData(const CatFoodInfo *productData);
void displayReportHeader(void);
void displayReportData(const ReportData *data, const int isCheapest);
void displayFinalAnalysis(const CatFoodInfo *cheapestProduct);

