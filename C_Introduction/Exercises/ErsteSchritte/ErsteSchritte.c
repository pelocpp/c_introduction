// =====================================================================================
// ErsteSchritte.c
// =====================================================================================

#include <stdio.h>

void exercise_erste_schritte()
{
    int zahl1;
    int zahl2;
    int ergebnis;

    printf("Bitte erste Zahl eingeben: ");
    scanf_s("%d", &zahl1);
    printf("Bitte zweite Zahl eingeben: ");
    scanf_s("%d", &zahl2);
    ergebnis = zahl1 + zahl2;
    printf("Ergebnis: %d + %d = %d\n", zahl1, zahl2, ergebnis);

    getchar(); /* Damit bleibt das Ausgabefenster offen, bis man eine Taste drueckt. */
}

// =====================================================================================
// End-of-File
// =====================================================================================
