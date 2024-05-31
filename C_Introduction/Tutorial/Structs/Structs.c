// ===========================================================================
// Structs.c // Strukturen
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Time.h"

// ===========================================================================

//static void initTime(struct Time time, int hours, int minutes, int seconds)
//{
//    time.hours = hours;
//    time.minutes = minutes;
//    time.seconds = seconds;
//}

static void initTime(struct Time* time, int hours, int minutes, int seconds)
{
    // a) Passt -- etwas schwer lesbar
    (*time).hours = hours;
    (*time).minutes = minutes;
    (*time).seconds = seconds;

    // b) Eine alternative Syntax -- besser lesbar -- Symbol: "Pfeil"
    time->hours = hours;
    time->minutes = minutes;
    time->seconds = seconds;

}

static void printTime(struct Time* time)
{
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

//static void printTime(struct Time time)
//{
//    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
//}

// ===========================================================================

static void structs_01()
{
    struct Time now;

    now.hours = 11;
    now.minutes = 9;
    now.seconds = 33;

    struct Time than;

    than.hours = 17;
    than.minutes = 0;
    than.seconds = 0;

    printTime(&now);
    printTime(&than);
}

static void structs_02()
{
    struct Time now = { 9, 0, 0 };
    printTime(&now);

    struct Time than = { .hours = 12, .minutes = 15, .seconds = 0 };
    printTime(&than);

    struct Time later = { .seconds = 0, .minutes = 0, .hours = 17 };
    printTime(&later);
}

static void structs_03()
{
    struct Time now = { 0 };

    printTime(&now);
}

static void printZahlen(int* feld, int len)
{
    // ...
}

//static void printZahlen(int feld[], int len)
//{
//    // ...
//}
//
//static void printZahlen(int feld[100], int len)
//{
//    // ...
//}

static void structs_04()
{
    int zahlen[100];

    printZahlen(zahlen, 100);
}

struct Zahlen
{
    int daten[100];
};

static void tueWas(struct Zahlen zahlen)
{
    zahlen.daten[0] = 100;
}

static void structs_05()
{
    struct Zahlen zahlen = { 1 };

    tueWas(zahlen);
}

static void structs_06()
{
    // Bei Strukturen sieht der Compiler / hat die Runtime
    // auch die Information der Länge der Struktur

    struct Time t1 = { 0, 0, 0 };
    struct Time t2 = { 0, 0, 0 };
    t1 = t2;            // Wertzuweisung

    struct Zahlen zahlen1;
    struct Zahlen zahlen2 = { 0 };
    zahlen1 = zahlen2;  // Wertzuweisung
}

static void structs_07()
{
    // Aufruf von initTime :

    // 2 Möglichkeiten des AUFRUFS :

    // A) 
    // Eine Struktur-Variable, die auf dem STACK liegt
    struct Time time;

    initTime(&time, 1, 2, 3);

    // B)
    // Eine Struktur-Variable, die auf dem HEAP liegt
    struct Time* pt = (struct Time*) malloc(sizeof(struct Time));

    initTime(pt, 1, 2, 3);

    free(pt);
}

void testStructs()
{
    structs_01();
    structs_02();
    structs_03();
    structs_04();
    structs_05();
    structs_06();
    structs_07();
}

// ===========================================================================
// End-of-File
// ===========================================================================
