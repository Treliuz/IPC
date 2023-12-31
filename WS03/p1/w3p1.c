/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  :Joseph Mwamba-Mukuna
Student ID#:163997216
Email      :jmwamba-mukuna@myseneca.ca
Section    :NRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const double product1Price = 111.49;
    const double product2Price = 222.99;
    const double product3Price = 334.49;
    double averagePrice;
    const int product1Id = 111;
    const int product2Id = 222;
    const int product3Id = 111;
    const char product1Tax = 'Y';
    const char product2Tax = 'N';
    const char product3Tax = 'N';
    
    //Product information display
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product1Id);
    printf("  Taxed: %c\n", product1Tax);
    printf("  Price: $%.4lf\n\n", product1Price);
    
    printf("Product-1 (ID:%d)\n", product2Id);
    printf("  Taxed: %c\n", product2Tax);
    printf("  Price: $%.4lf\n\n", product2Price);

    printf("Product-1 (ID:%d)\n", product3Id);
    printf("  Taxed: %c\n", product3Tax);
    printf("  Price: $%.4lf\n\n", product3Price);
    
    //Finding average price for products
    averagePrice = (product1Price + product2Price + product3Price) / 3;
    printf("The average of all prices is: $%.4lf\n\n", averagePrice);

    printf("About Relational and Logical Expressions!\n"); 
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");         
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");    

    //Logic testing on table information
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", product1Tax == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", product2Tax && product3Tax == 'N');
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", product3Price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product3Price > product1Price + product2Price);
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d ", product1Price >= product3Price - product2Price);
    //Indent to show it's the same line
        printf("(price difference: $%.2lf)\n\n", product3Price - product2Price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2Price >= averagePrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product1Id != product2Id && product1Id != product3Id);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product2Id != product1Id && product2Id != product3Id);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", product3Id != product1Id && product3Id != product2Id);
    return 0;
}