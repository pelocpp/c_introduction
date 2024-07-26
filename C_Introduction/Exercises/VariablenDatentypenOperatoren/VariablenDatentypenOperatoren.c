// =====================================================================================
// VariablenDatentypenOperatoren.c
// =====================================================================================

#include <stdio.h>

static void exercise_variablen_datentypen_operatoren_01()
{
    int stunden;         // Eingabe Stunden im Bereich [0..24)
    int minuten;         // Eingabe Minuten im Bereich [0..60)
    int sekunden;        // Eingabe Sekunden im Bereich [0..60)
    int sekundenTotal;   // Wert im Bereich [0-86.400) Sekunden (24 * 60 * 60)

    printf("Bitte Stunden eingeben: ");
    scanf_s("%d", &stunden);
    printf("Bitte Minuten eingeben: ");
    scanf_s("%d", &minuten);
    printf("Bitte Sekunden eingeben: ");
    scanf_s("%d", &sekunden);

    // Verarbeitung
    int sekundenStunden = stunden * 60 * 60;    // Stunden in Sekunden umrechnen
    int sekundenMinuten = minuten * 60;         // Minuten in Sekunden umrechnen
    sekundenTotal = sekundenStunden + sekundenMinuten + sekunden;

    printf("%d Stunden, %d Minuten und %d Sekunden sind %d Sekunden.\n",
        stunden, minuten, sekunden, sekundenTotal);
}

static void exercise_variablen_datentypen_operatoren_02()
{
    int sekundenTotal;   // Eingabe Sekunden im Bereich [0-86.400)
    int stunden;         // Stunden im Bereich [0..24)
    int minuten;         // Minuten im Bereich [0..60)
    int sekunden;        // Sekunden im Bereich [0..60)

    printf("Bitte Sekunden eingeben: ");
    scanf_s("%d", &sekundenTotal);

    int total = sekundenTotal;

    // Verarbeitung
    sekunden = sekundenTotal % 60;

    sekundenTotal = sekundenTotal - sekunden;
    sekundenTotal = sekundenTotal / 60;

    minuten = sekundenTotal % 60;

    sekundenTotal = sekundenTotal - minuten;
    sekundenTotal = sekundenTotal / 60;

    stunden = sekundenTotal;

    printf("%d Sekunden sind %d Stunden, %d Minuten und %d Sekunden.\n",
        total, stunden, minuten, sekunden);
}

void exercise_variablen_datentypen_operatoren()
{
    exercise_variablen_datentypen_operatoren_01();
    exercise_variablen_datentypen_operatoren_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
