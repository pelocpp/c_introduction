// ===========================================================================
// Operators.c // Operatoren und Ausdrücke
// ===========================================================================

#include <stdio.h>

static void testOperators_01()
{
    int n = 3 + 4 * 5;   // "Punkt-vor-Strich"    // 23

    int m = -1 + -2 + -3;                         // -6

    int k = 1 + 2 - 3 * 5 + 6 - 8 * 9;            // -78

    int l = 1 + (2 - 3) * (5 + 6) - 8 * 9;        // -82
}

static void testOperators_02()
{
    // Inkrement

    int n = 10;

    int m;

    m = ++n;  // Pre-Inkrement
    printf("m = %d\n", m);

    // versus

    m = n++;  // Post-Inkrement
    printf("m = %d\n", m);

    // ============================

    // Tipp

    ++n;
    m = n;  // Wertzuweisung
    printf("m = %d\n", m);

    // versus

    m = n;  // Wertzuweisung
    n++;
    printf("m = %d\n", m);
}

static void testOperators_03()
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

void mainOperators()
{
    testOperators_01();
    testOperators_02();
    testOperators_03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
