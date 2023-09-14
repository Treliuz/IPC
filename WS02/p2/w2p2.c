/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name :Joseph Mwamba-Mukuna
Student ID#: 163997216
Email :jmwamba-mukuna@myseneca.ca
Section :NRA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    const double TAX = 0.13;
    double remaining;
    int quarters;
    double dimes;
    double nickels;
    double pennies;
    double small, med, large;
    double subtotal, patSub, tomSub, salSub;
    double taxTotal, patTax, tomTax, salTax;
    double Total, patTotal, tomTotal, salTotal;
    int Toonies;
    int Loonies;
    int intRemaining;
    int avgCost;
    int shirtsPat, shirtsTom, shirtsSal;
    int intSubtotal, intPatSub, intTomSub, intSalSub;
    int intTax, intPatTax, intTomTax, intSalTax;
    int intTotal, intPatTotal, intTomTotal, intSalTotal;

    printf("Set Shirt Prices\n");
    printf("================\n");

    //Price declaration for shirt sizes
    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &small);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &med);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large);

    //Printing previously stored prices
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", med);
    printf("LARGE  : $%.2lf\n\n", large);

    //Number of shirts bought
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtsPat);

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &shirtsTom);

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &shirtsSal);

    //Patty checkout
    intPatSub = (int)(small * 100);
    patSub = (float)(intPatSub * shirtsPat) / 100; 

    intPatTax = (int)((patSub * TAX + 0.005) * 100);
    patTax = (float)(intPatTax) / 100;

    intPatTotal = (int)((patTax + patSub + 0.005) * 100);
    patTotal = (float)(intPatTotal) / 100;
    //Sally checkout
    intSalSub = (int)(med * 100);
    salSub = (float)(intSalSub * shirtsSal) / 100;

    intSalTax = (int)((salSub * TAX + 0.005) * 100);
    salTax = (float)(intSalTax) / 100;

    intSalTotal = (int)((salTax + salSub + 0.005) * 100);
    salTotal = (float)(intSalTotal) / 100;
    //Tommy checkout
    intTomSub = (int)(large * 100);
    tomSub = (float)(intTomSub * shirtsTom) / 100;

    intTomTax = (int)((tomSub * TAX + 0.005) * 100);
    tomTax = (float)(intTomTax) / 100;

    intTomTotal = (int)((tomTax + tomSub + 0.005) * 100);
    tomTotal = (float)(intTomTotal) / 100;

    //Total price
    intSubtotal = (int)((patSub + salSub + tomSub) * 100);
    subtotal = (float)(intSubtotal) / 100;

    intTax = (int)((patTax + salTax + tomTax) * 100);
    taxTotal = (float)(intTax) / 100;

    intTotal = (int)((patTotal + salTotal + tomTotal+0.005) * 100);
    Total = (float)(intTotal) / 100;

    //Table display
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", patSize, small, shirtsPat, patSub, patTax, patTotal);
    printf("Sally    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", salSize, med, shirtsSal, salSub, salTax, salTotal);
    printf("Tommy    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", tomSize, large, shirtsTom, tomSub, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        % 9.4lf % 9.4lf % 9.4lf\n\n", subtotal, taxTotal, Total);

    //Coin breakdown
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subtotal);
    //Toonies substraction
        Toonies = intSubtotal / 200;
        intRemaining = intSubtotal % 200;
        remaining = (float)intRemaining / 100;
    printf("Toonies  %3d %9.4lf\n", Toonies, remaining);
    //Loonies substraction
        Loonies = intRemaining / 100;
        intRemaining = intSubtotal % 100;
        remaining = (float)intRemaining / 100;
    printf("Loonies  %3d %9.4lf\n", Loonies, remaining);
    //Quarters substraction
        quarters = intRemaining / 25;
        intRemaining = intSubtotal % 25;
        remaining = (float)intRemaining / 100;
    printf("Quarters  %3d %9.4lf\n", quarters, remaining);
    return 0;
}