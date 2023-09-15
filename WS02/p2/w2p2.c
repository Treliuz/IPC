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
    double smallPrice, medPrice, largePrice;
    double subtotal, patSub, tomSub, salSub;
    double taxTotal, patTax, tomTax, salTax;
    double Total, patTotal, tomTotal, salTotal;
    double avgCost;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int toonies;
    int loonies;
    int intRemaining;
    int shirtsPat, shirtsTom, shirtsSal;
    int intSubtotal, intPatSub, intTomSub, intSalSub;
    int intTax, intPatTax, intTomTax, intSalTax;
    int intTotal, intPatTotal, intTomTotal, intSalTotal;

    printf("Set Shirt Prices\n");
    printf("================\n");

    //Input price for shirt sizes
    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &smallPrice);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &medPrice);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);

    //Displaying previously stored prices
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", medPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);

    //Input number of shirts bought
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
    intPatSub = (int)(smallPrice * 100);
    patSub = (float)(intPatSub * shirtsPat) / 100; 

    intPatTax = (int)((patSub * TAX + 0.005) * 100);
    patTax = (float)(intPatTax) / 100;

    intPatTotal = (int)((patTax + patSub + 0.005) * 100);
    patTotal = (float)(intPatTotal) / 100;
    //Sally checkout
    intSalSub = (int)(medPrice * 100);
    salSub = (float)(intSalSub * shirtsSal) / 100;

    intSalTax = (int)((salSub * TAX + 0.005) * 100);
    salTax = (float)(intSalTax) / 100;

    intSalTotal = (int)((salTax + salSub + 0.005) * 100);
    salTotal = (float)(intSalTotal) / 100;
    //Tommy checkout
    intTomSub = (int)(largePrice * 100);
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

    //Table display of everyone's purchases
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", patSize, smallPrice, shirtsPat, patSub, patTax, patTotal);
    printf("Sally    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", salSize, medPrice, shirtsSal, salSub, salTax, salTotal);
    printf("Tommy    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", tomSize, largePrice, shirtsTom, tomSub, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        % 9.4lf % 9.4lf % 9.4lf\n\n", subtotal, taxTotal, Total);

    //Coin breakdown no tax
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subtotal);
    //toonies substraction
        toonies = intSubtotal / 200;
        intRemaining = intSubtotal % 200;
        remaining = (float)intRemaining / 100;
    printf("Toonies  %3d %9.4lf\n", toonies, remaining);
    //loonies substraction
        loonies = intRemaining / 100;
        intRemaining = intSubtotal % 100;
        remaining = (float)intRemaining / 100;
    printf("Loonies  %3d %9.4lf\n", loonies, remaining);
    //quarters substraction
        quarters = intRemaining / 25;
        intRemaining = intSubtotal % 25;
        remaining = (float)intRemaining / 100;
    printf("Quarters %3d %9.4lf\n", quarters, remaining);
    //dimes substraction
        dimes = intRemaining / 10;
        intRemaining = intSubtotal % 10;
        remaining = (float)intRemaining / 100;
    printf("Dimes    %3d %9.4lf\n", dimes, remaining); 
    //nickels substraction
        nickels = intRemaining / 5;
        intRemaining = intSubtotal % 5;
        remaining = (float)intRemaining / 100;
    printf("Nickels  %3d %9.4lf\n", nickels, remaining);
    //pennies substraction
        pennies = intRemaining / 1;
        intRemaining = intSubtotal % 1;
        remaining = (float)intRemaining / 100;
    printf("Pennies  %3d %9.4lf\n\n", pennies, remaining); 
    //Calculating average shirt price without taxes
        avgCost = subtotal / (shirtsPat + shirtsSal + shirtsTom);
    printf("Average cost/shirt: $%.4lf\n\n", avgCost);

    //Coin breakdown with tax
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", Total);
    //toonies substraction
        toonies = intTotal / 200;
        intRemaining = intTotal % 200;
        remaining = (float)intRemaining / 100;
    printf("Toonies  %3d %9.4lf\n", toonies, remaining);
    //loonies substraction
        loonies = intRemaining / 100;
        intRemaining = intTotal % 100;
        remaining = (float)intRemaining / 100;
    printf("Loonies  %3d %9.4lf\n", loonies, remaining);
    //quarters substraction
        quarters = intRemaining / 25;
        intRemaining = intTotal % 25;
        remaining = (float)intRemaining / 100;
    printf("Quarters %3d %9.4lf\n", quarters, remaining);
    //dimes substraction
        dimes = intRemaining / 10;
        intRemaining = intTotal % 10;
        remaining = (float)intRemaining / 100;
    printf("Dimes    %3d %9.4lf\n", dimes, remaining); 
    //nickels substraction
        nickels = intRemaining / 5;
        intRemaining = intTotal % 5;
        remaining = (float)intRemaining / 100;
    printf("Nickels  %3d %9.4lf\n", nickels, remaining);
    //pennies substraction
        pennies = intRemaining / 1;
        intRemaining = intTotal % 1;
        remaining = (float)intRemaining / 100;
    printf("Pennies  %3d %9.4lf\n\n", pennies, remaining);
    //Calculating average shirt price with tax
        avgCost = Total / (shirtsPat + shirtsSal + shirtsTom);
    printf("Average cost/shirt: $%.4lf\n\n", avgCost);

    return 0;
}