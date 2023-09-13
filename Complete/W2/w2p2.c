/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    double priceS;
    double priceM;
    double priceL;
    double subtotal;
    double Taxtotal;
    double Total;
    int shirtNum;
    int intSubtotal;
    int intTax;
    int intTotal;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &priceS);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &priceM);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceL);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n\n", priceL);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtNum);

    intSubtotal = (int)(priceS * 100);
    subtotal = (float)(intSubtotal * shirtNum) / 100;

    intTax = (int)((subtotal * TAX + 0.005) * 100);
    Taxtotal = (float)(intTax) / 100;

    intTotal = (int)((subtotal + Taxtotal + 0.005) * 100);
    Total = (float)(intTotal) / 100;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", shirtNum);
    printf("Sub-total: $%8.4lf\n", subtotal);
    printf("Taxes    : $%8.4lf\n", Taxtotal);
    printf("Total    : $%8.4lf\n", Total);
    
    return 0;
}