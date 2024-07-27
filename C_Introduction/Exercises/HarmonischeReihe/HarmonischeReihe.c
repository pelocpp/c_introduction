// =====================================================================================
// HarmonischeReihe.c
// =====================================================================================

#include <stdio.h>

static double harmonic_series_01(int n)
{
    // using while-loop
    
    int m = 1;

    double result = 0.0;
    
    while (m <= n)
    {
        result = result + 1.0 / (double) m;

        m++; // m = m + 1
    }

    return result;
}

static double harmonic_series_02(int n)
{
    // using for-loop

    double result = 0.0;

    for (int m = 1; m <= n; m++)
    {
        result = result + 1.0 / (double) m;
    }

    return result;
}

void exercise_harmonische_reihe()
{
    // obere Grenze 
    int n = 0;

    printf("Bitte Wert eingeben: ");
    scanf_s("%d", &n);

    double value = harmonic_series_01(n);
    printf("Ergebnis: %f\n", value);

    value = harmonic_series_02(n);
    printf("Ergebnis: %f\n", value);
}

// =====================================================================================
// End-of-File
// =====================================================================================
