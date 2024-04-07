// =====================================================================================
// HarmonischeReihe.c
// =====================================================================================

#include <stdio.h>

void exercise_harmonische_reihe()
{
    // Obere Grenze 
    int n = 20;

    printf("Bitte wert eingeben: ");
    scanf_s("%d", &n);

    // mit while-Schleife
    int m = 1;
    double ergebnis = 0.0;
    while (m <= n)
    {
        ergebnis = ergebnis + 1.0 / (double)m;

        m++; // m = m + 1
    }

    // oder mit for-Schleife

    printf("Ergebnis: %f", ergebnis);
}

// =====================================================================================
// End-of-File
// =====================================================================================
