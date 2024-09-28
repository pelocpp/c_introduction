// =====================================================================================
// ArraySumMinMax.c
// =====================================================================================

#include <stdio.h>   // printf
#include <stdlib.h>  // rand
#include <time.h>    // time

#define  Length      10

static void exercise_array_zufallszahlen()
{
    printf("Zufallszahlen\n");
    printf("=============\n");

    int feld[Length] = { 0 };

    time_t t;                    // srand erzeugt Startwert fuer den Zufallszahlengenerator,
    srand((unsigned) time(&t));  // der von rand verwendet wird
                                
    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < Length; i++) {

        int zahl = rand();       // rand():  0 .. 32767
        zahl = zahl % 100;       // 0 .. 99
        zahl = zahl + 1;         // 1 .. 100
        feld[i] = zahl;
    }

    // Feld ausgeben
    for (int i = 0; i < Length; i++) {
        printf("%2d\n", feld[i]);
    }
    printf("\n");
}

static void exercise_array_summe()
{
    printf("Summe\n");
    printf("=====\n");

    int feld[Length] = { 0 };

    time_t t;                    // srand erzeugt Startwert fuer den Zufallszahlengenerator,
    srand((unsigned) time(&t));  // der von rand verwendet wird

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < Length; i++) {

        int zahl = rand();       // rand():  0 .. 32767
        zahl = zahl % 100;       // 0 .. 99
        zahl = zahl + 1;         // 1 .. 100
        feld[i] = zahl;
    }

    // Berechnung der Summe
    long sum = 0;
    for (int i = 0; i < Length; i++)
    {
        sum = sum + feld[i];
    }

    // Feld ausgeben
    for (int i = 0; i < Length; i++) {
        printf("%2d\n", feld[i]);
    }

    // Summe ausgeben
    printf("\n");
    printf("Summe: %d\n\n", sum);
}

static void exercise_array_minimum()
{
    printf("Minumum\n");
    printf("=======\n");

    int feld[Length] = { 0 };

    time_t t;                    // srand erzeugt Startwert fuer den Zufallszahlengenerator,
    srand((unsigned)time(&t));   // der von rand verwendet wird
    
    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < Length; i++) {

        int zahl = rand();       // rand():  0 .. 32767
        zahl = zahl % 100;       // 0 .. 99
        zahl = zahl + 1;         // 1 .. 100
        feld[i] = zahl;
    }

    // Kleinstes Element suchen
    int min = feld[0];
    for (int i = 1; i < Length; i++)
    {
        if (feld[i] < min) {
            min = feld[i];
        }
    }

    // Feld ausgeben
    for (int i = 0; i < Length; i++) {
        printf("%2d\n", feld[i]);
    }

    // Minimum ausgeben
    printf("\n");
    printf("Minimum: %d\n\n", min);
}

static void exercise_array_maximum()
{
    printf("Maximum\n");
    printf("=======\n");

    int feld[Length] = { 0 };

    time_t t;
    srand((unsigned)time(&t)); // s = seed // beeinflusst rand()

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < Length; i++) {

        // rand:  0 .. 32767
        int rest = rand() % 100; // 0 .. 99
        rest = rest + 1;         // 1 .. 100
        feld[i] = rest;    // 1 .. 100 
    }

    // Groesstes Element suchen
    int max = feld[0];
    for (int i = 1; i < Length; i++)
    {
        if (feld[i] > max) {
            max = feld[i];
        }
    }

    // Feld ausgeben
    for (int i = 0; i < Length; i++) {
        printf("%2d\n", feld[i]);
    }

    // Maximum ausgeben
    printf("\n");
    printf("Maximum: %d\n\n", max);
}

void exercise_array_minimum_maximum()
{
    exercise_array_zufallszahlen();
    exercise_array_summe();
    exercise_array_minimum();
    exercise_array_maximum();
}

// =====================================================================================
// End-of-File
// =====================================================================================
