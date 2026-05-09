// =====================================================================================
// ZinsberechnungDynamisch.c
// =====================================================================================

#include <stdio.h>   // printf, scanf_s
#include <stdlib.h>  // malloc, free

static int doubleCapitalWithWithAccumulation(double capitalStock, double interestRate)
{
    double newCapital = capitalStock;
    int years = 0;

    // compute number of years
    while (newCapital < 2 * capitalStock) {
        double interest = (newCapital / 100.0) * interestRate;
        newCapital = newCapital + interest;
        years = years + 1;
    }

    // compute money increase during the years
    double* capitalDevelopment = (double*)malloc(sizeof(double) * years);
    if (capitalDevelopment == NULL) {
        return -1;
    }

    newCapital = capitalStock;
    for (int i = 0; i < years; i++) {
        double interest = (newCapital / 100.0) * interestRate;
        newCapital = newCapital + interest;
        capitalDevelopment[i] = newCapital;
    }

    // print development
    for (int i = 0; i < years; i++) {
        printf("%2d. Year: %.2f\n", (i+1), capitalDevelopment[i]);
    }

    free(capitalDevelopment);

    return years;
}

void exercise_zinsberechnung_dynamisch()
{
    double capitalStock = 1000.0;
    double interestRate = 4.0;

    printf("CapitalStock: %.2f, CapitalStock: %.2f\n", capitalStock, interestRate);

    int years = doubleCapitalWithWithAccumulation(capitalStock, interestRate);

    printf("Doubled capital stock in %d years.\n", years);
}

// =====================================================================================
// End-of-File
// =====================================================================================
