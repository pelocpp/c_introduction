// ===========================================================================
// Arrays.cpp // Felder (Arrays)
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   Length   10

static void arrays_01()
{
    int numbers[Length];
    
    int n = numbers[0];
    numbers[0] = 123;

    for (int i = 0; i < Length; i++) {
        numbers[i] = 2 * i;
    }

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers[i]);
    }
}

static void arrays_02()
{
    // array initialization with initializer list
    int numbers1[Length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers1[i]);
    }

    // ========================================

    int numbers2[] = { 1, 2, 3, 4, 5 };   // compiler computes length of array

    int length = sizeof(numbers2) / sizeof(int);

    for (int i = 0; i < length; i++) {
        printf("%2d: %d\n", i, numbers2[i]);
    }

    // ========================================

    int numbers3[10] = { 1 };

    for (int i = 0; i < 10; i++) {
        printf("%2d: %d\n", i, numbers3[i]);
    }
}

static void initArray01(int* data, int length)
{
    // watch difference
    printf("sizeof numbers: %zu\n", sizeof(data));
    printf("sizeof int: %zu\n", sizeof(int));
    printf("Length: %zu\n", sizeof(data) / sizeof(*data));

    for (int i = 0; i < length; ++i) {

        data[i] = 2 * i;       // go for this syntax
        // oder
        *(data + i) = 2 * i;
    }
}

static void initArray02(int feld[], int length)
{
    // same as above
}

static void initArray03(int feld[10], int length)
{
    // same as above
}

static void arrays_03()
{
    int numbers[Length];

    printf("sizeof numbers: %zu\n", sizeof(numbers));
    printf("sizeof int: %zu\n", sizeof(int));
    printf("Length: %zu\n", sizeof(numbers) / sizeof(*numbers));

    initArray01(numbers, Length);

    initArray02(numbers, Length);

    for (int i = 0; i < Length; ++i) {
        printf("%02d: %d\n", i, numbers[i]);
    }
}

static void createRandomNumbers()
{
    time_t now;

    time(&now);

    // Seed : Samen ===> "Es wächst eine Pfanze"  

    srand((unsigned int) now);   // Startwert für den Algorithmus  

    // oder
    unsigned int start = 123;
    srand(start);                // Startwert für den Algorithmus  

    // s == 123  // s == seed : Samen ===> Wächst eine Pfanze  

    int zahl = rand();   // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", zahl);

    zahl = rand();   // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", zahl);

    zahl = rand();   // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", zahl);
}

static void arrays_04()
{
    int numbers[Length];

    time_t now;
    time(&now);
    srand((unsigned int)now); 

    for (int i = 0; i < Length; i++) {
        numbers[i] = rand() % 10 + 1;   // 1 .. 10
    }

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers[i]);
    }
}

static void arrays_05()
{
    // Wertzuweisung von Arrays

    // Bei Arrays sieht die Runtime einen Namen als ANFANGSADRESSE.

    int numbers1[Length];
    int numbers2[Length];

    // numbers1 = numbers2;                // Wertzuweisung: so nicht !!!!

    for (int i = 0; i < Length; i++) {     // Wertzuweisung
        numbers1[i] = numbers2[i];
    }
}

void arrays()
{
    arrays_01();
    arrays_02();
    arrays_03();
    createRandomNumbers();
    arrays_04();
    arrays_05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
