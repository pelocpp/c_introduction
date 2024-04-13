// =====================================================================================
// ArraySumMinMax.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>   // time_t

#define Length 10

static void exercise_array_zufallszahlen()
{
    printf("Zufallszahlen\n");
    printf("=============\n");

    int feld[Length];

    time_t t;
    srand((unsigned)time(&t)); // s = seed // beeinflusst rand()
    // printf("Zeit seit Einschalten: %lld\n\n", t); // in Sekunden

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < 10; i++) {

        // rand:  0 .. 32767
        int zahl = rand() % 100; // 0 .. 99
        zahl = zahl + 1;         // 1 .. 100
        feld[i] = zahl;    // 1 .. 100 
    }

    // Feld ausgeben
    for (int i = 0; i < 10; i++) {
        printf("%d\n", feld[i]);
    }
    printf("\n");
}

static void exercise_array_summe()
{
    printf("Summe\n");
    printf("=====\n");

    int feld[Length];

    time_t t;
    srand((unsigned) time(&t)); // s = seed // beeinflusst rand()

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < 10; i++) {

        // rand:  0 .. 32767
        int rest = rand() % 100; // 0 .. 99
        rest = rest + 1;         // 1 .. 100
        feld[i] = rest;    // 1 .. 100 
    }

    // Berechnung der Summe
    long sum = 0;
    for (int i = 0; i < Length; i++)
    {
        sum = sum + feld[i];
    }

    // Feld ausgeben
    for (int i = 0; i < 10; i++) {
        printf("%d\n", feld[i]);
    }

    // Summe ausgeben
    printf("\n");
    printf("Summe: %d\n\n", sum);
}

static void exercise_array_minimum()
{
    printf("Minumum\n");
    printf("=======\n");

    int feld[Length];


    time_t t;
    srand((unsigned)time(&t)); // s = seed // beeinflusst rand()

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < 10; i++) {

        // rand:  0 .. 32767
        int rest = rand() % 100; // 0 .. 99
        rest = rest + 1;         // 1 .. 100
        feld[i] = rest;    // 1 .. 100 
    }

    // Kleinstes Element suchen
    int min = 101;
    for (int i = 0; i < Length; i++)
    {
        if (feld[i] < min) {
            min = feld[i];
        }
    }

    // Feld ausgeben
    for (int i = 0; i < 10; i++) {
        printf("%d\n", feld[i]);
    }

    // Minimum und Maximum ausgeben
    printf("\n");
    printf("Minimum: %d\n\n", min);
}

static void exercise_array_maximum()
{
    printf("Maximum\n");
    printf("=======\n");

    int feld[Length];


    time_t t;
    srand((unsigned)time(&t)); // s = seed // beeinflusst rand()

    // Feld vorbelegen mit Zahlen im Bereich von 1 .. 100
    for (int i = 0; i < 10; i++) {

        // rand:  0 .. 32767
        int rest = rand() % 100; // 0 .. 99
        rest = rest + 1;         // 1 .. 100
        feld[i] = rest;    // 1 .. 100 
    }

    // Groesstes Element suchen
    int max = -1;    // 0 ginge auch
    for (int i = 0; i < Length; i++)
    {
        if (feld[i] > max) {
            max = feld[i];
        }
    }

    // Feld ausgeben
    for (int i = 0; i < 10; i++) {
        printf("%d\n", feld[i]);
    }

    // Minimum und Maximum ausgeben
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
