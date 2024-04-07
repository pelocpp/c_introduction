// =====================================================================================
// DivisionMitRest.c
// =====================================================================================

#include <stdio.h>

struct Result
{
    int quotient;
    int remainder;
};

struct Result divisioMitRest(int zaehler, int nenner)
{
    struct Result result;

    result.quotient = zaehler / nenner;
    result.remainder = zaehler % nenner;

    return result;
}

void exercise_division_mit_rest()
{
    printf("Division mit Rest\n");
    printf("=================\n\n");

    printf("17 / 8:\n");

    struct Result ergebnis = divisioMitRest(17, 8);

    printf("Quotient: %d\n", ergebnis.quotient);
    printf("Rest:     %d\n", ergebnis.remainder);


    printf("5 / 7:\n");

    ergebnis = divisioMitRest(5, 7);

    printf("Quotient: %d\n", ergebnis.quotient);
    printf("Rest:     %d\n", ergebnis.remainder);


}

// =====================================================================================
// End-of-File
// =====================================================================================
