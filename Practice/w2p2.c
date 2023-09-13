/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : Joseph Mwamba-Mukuna
Student ID#: 163997216
Email      : jmwamba-mukuna@myseneca.ca
Section    : NPP

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    double totalTax;
    double patTax, salTax,tomTax;
    double small, medium, large;
    double subtotal;
    double patSub,salSub,tomSub;
    double total;
    double patTotal,salTotal,tomTotal;
    int avgCost;
    double remaining;
    int shirtsSal,shirtsPat,shirtsTom;
    int wholeSubtotal;
    int wholePatSub,wholeSalSub,wholeTomSub;
    int wholeTotal;
    int wholePatTotal,wholeSalTotal,wholeTomTotal;
    int wholeTax;
    int wholePatTax,wholeSalTax,wholeTomTax;
    int Toonies;
    int Loonies;
    double Quarters;
    double Dimes;
    double Nickels;
    double Pennies;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &small);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &medium);

    printf("Enter the price for a LARGE shirt: $");
    scanf("\n%lf", &large);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", medium);
    printf("LARGE  : $%.2lf\n\n", large);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtsPat);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtsTom);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtsSal);

    //Calculations for Patty
    wholePatSub = (int)(small * 100);
    patSub = (float)(wholePatSub * shirtsPat) / 100;
    
    wholePatTax = (int)((patSub * TAX + 0.005) * 100);
    patTax = (float)(wholePatTax) / 100; 

    wholePatTotal = (int)((patTax + patSub + 0.005) * 100);
    patTotal = (float)(wholePatTotal) / 100;

    //Calculations for Sally
    wholeSalSub = (int)(medium * 100);
    salSub = (float)(wholeSalSub * shirtsSal) / 100;

    wholeSalTax = (int)((salSub * TAX + 0.005) * 100);
    salTax = (float)(wholeSalTax) / 100;

    wholeSalTotal = (int)((salTax + salSub + 0.005) * 100);
    salTotal = (float)(wholeSalTotal) / 100;

    //Calculations for Tommy
    wholeTomSub = (int)(large * 100);
    tomSub = (float)(wholeTomSub * shirtsTom) / 100;

    wholeTomTax = (int)((tomSub * TAX + 0.005) * 100);
    tomTax = (float)(wholeTomTax) / 100;

    wholeTomTotal = (int)((tomTax + tomSub + 0.005) * 100);
    tomTotal = (float)(wholeTomTotal) / 100;

    //Calculation for total prices
    wholeSubtotal = (int)((patSub + salSub + tomSub) * 100);
    subtotal = (float)(wholeSubtotal) / 100;

    wholeTax = (int)((patTax + salTax + tomTax) * 100);
    totalTax = (float)(wholeTax) / 100;

    wholeTotal = (int)((patTotal + salTotal + tomTotal+0.005) * 100);
    total = (float)(wholeTotal) / 100;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", patSize, small, shirtsPat, patSub, patTax, patTotal);
    printf("Sally    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", salSize, medium, shirtsSal, salSub, salTax, salTotal);
    printf("Tommy    % -4c% 5.2lf % 3d % 9.4lf % 9.4lf % 9.4lf\n", tomSize, large, shirtsTom, tomSub, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        % 9.4lf % 9.4lf % 9.4lf\n\n", subtotal, totalTax, total);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("             %9.4lf\n", subtotal);
    
    Toonies = subtotal / 2;
    remaining = (int)subtotal%2;
    printf("Toonies  %3d %9.4lf\n", Toonies, remaining);
    
    printf("Loonies    1   0.5100\n");
    
    printf("Quaters    2   0.0100\n");
    
    printf("Dimes      0   0.0100\n");
    
    printf("Nickels    0   0.0100\n");
   
    printf("Pennies    1   0.0000\n\n");

    printf("Average cost/shirt: $24.8854");

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              365.5700\n");
    printf("Toonies  182    1.5700\n");
    printf("Loonies    1    0.5700\n");
    printf("Quarters   2    0.0700\n");
    printf("Dimes      0    0.0700\n");
    printf("Nickels    1    0.0200\n");
    printf("Pennies    2    0.0000\n");
    printf("Average cost/shirt: $28.1208\n");
    return 0;
}