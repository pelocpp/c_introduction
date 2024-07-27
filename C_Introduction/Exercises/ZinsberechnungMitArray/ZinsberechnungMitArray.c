// =====================================================================================
// ZinsberechnungMitArray.c
// =====================================================================================

#include <stdio.h>

static int doubleInterestRateWithWithAccumulation(double capital, double rate, double accumulation[], int length)
{
    double newCapital = capital;

    int year = 0;

    while (newCapital < 2 * capital) {

        double interest = (newCapital / 100.0) * rate;

        newCapital = newCapital + interest;

    //    printf("Year %2d: %lf\n", year, newCapital);

        if (year < length) {

            accumulation[year] = newCapital;
        }

        year = year + 1;
    }

    return year;

    //double zinsen;
    //double doppelt = 0;
    //doppelt = kapital * 2;

    //// den eingezahlten Betrag an der Stelle 0 im Feld eintragen
    //kapitalProJahr[0] = kapital;

    //for (int jahre = 1; kapital <= doppelt; jahre++)
    //{
    //    printf("===> Jahr: %d: kapital = %lf\n", jahre, kapital);

    //    zinsen = (kapital / 100) * zinssatz;
    //    kapital = kapital + zinsen;

    //    // Feld fuellen
    //    kapitalProJahr[jahre] = kapital;  // berechnetes Kapital an der Stelle 'jahre' reinschreiben

    //    if (kapital >= doppelt)
    //    {
    //        return jahre;
    //    }
    //}

    //return 1;
}

//
//
//void exercise_doubleInterestRate()
//{
//    double capital = 1000.0;
//    double rate = 5.0;
//
//    int years = doubleInterestRate(1000.0, 5.0);
//
//    printf("After %d years, a capital of %lf with interest rate  %lf is doubled!\n",
//        years, capital, rate);
//}

#define Length  20

void exercise_zinsberechnung_mit_array()
{
    double capital = 1000.0;

    double rate = 5.0;

    //double betrag = DoubledInterestRate(zinssatz, kapital);
    //printf("Betrag: %.2lf\n", betrag);

    double accumulatedCapital[Length] = { 0.0 };

    int years = doubleInterestRateWithWithAccumulation(capital, rate, accumulatedCapital, Length);

    printf("After %d years, a capital of %lf with interest rate  %.2lf is doubled!\n",
        years, capital, rate);


  //  printf("Anzahl der Jahre: %d\n", years);

    for (int i = 0; i < years; i++)
    {
        printf("%2d. years: capital = %.2lf\n", (i + 1), accumulatedCapital[i]);
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
