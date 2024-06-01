// ===========================================================================
// Operators.c // Operatoren und Ausdrücke
// ===========================================================================

#include <stdio.h>

// ===========================================================================
// End-of-File
// ===========================================================================

void test_03()
{
    // Inkrement

    int n = 10;

    int m;

    m = ++n;  // Pre-Inkrement

    // versus

    m = n++;  // Post-Inkrement

    // ============================

    // Tipp

    ++n;
    m = n;  // Wertzuweisung

    // versus

    m = n;  // Wertzuweisung
    n++;
}

void test_04()
{
    // Wann ist eine ganze Zahl gerade oder ungerade ???

    int n = 10;

    // ....

    if ((n % 2) == 0) {

        printf("n ist gerade: %d\n", n);
    }

    n = 11;

    if ((n % 2) == 1) {

        printf("n ist ungerade: %d\n", n);
    }
}