// ===========================================================================
// Structs.c // Strukturen
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Time.h"

// ===========================================================================

static void initTime(Time* time, int hours, int minutes, int seconds)
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

static void printTime(Time* time)
{
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

//static void initTime(Time time, int hours, int minutes, int seconds)
//{
//    time.hours = hours;
//    time.minutes = minutes;
//    time.seconds = seconds;
//}

//static void printTime(Time time)
//{
//    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
//}

// ===========================================================================

static void structs_01()
{
    Time now;

    now.hours = 11;
    now.minutes = 9;
    now.seconds = 33;

    Time than;

    than.hours = 17;
    than.minutes = 0;
    than.seconds = 0;

    printTime(&now);
    printTime(&than);
}

static void structs_02()
{
    // ----------------------
    // using initializer list

    Time t1 = { 9, 15, 30 };
    printTime(&t1);

    Time t2 = { 9 };
    printTime(&t2);

    // -------------------------------------------
    // designated initializers for aggregate types

    Time t3 = { .hours = 10, .minutes = 30, .seconds = 59};
    printTime(&t3);

    Time t4 = { .hours = 10 };
    printTime(&t4);

    Time t5 = { .seconds = 10 };
    printTime(&t5);

    Time t6 = { .seconds = 20, .minutes = 30, .hours = 12 };
    printTime(&t6);
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

static void structs_03()
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

static void structs_04()
{
    struct Zahlen zahlen = { 1 };

    tueWas(zahlen);
}

static void structs_05()
{
    // Bei Strukturen sieht der Compiler / hat die Runtime
    // auch die Information der Länge der Struktur

    Time t1 = { 0, 0, 0 };
    Time t2 = { 0, 0, 0 };
    t1 = t2;            // Wertzuweisung

    struct Zahlen zahlen1;
    struct Zahlen zahlen2 = { 0 };
    zahlen1 = zahlen2;  // Wertzuweisung
}

static void structs_06()
{
    // Aufruf von initTime :

    // 2 Möglichkeiten des AUFRUFS :

    // A) 
    // Eine Struktur-Variable, die auf dem STACK liegt
    Time time;

    initTime(&time, 1, 2, 3);

    // B)
    // Eine Struktur-Variable, die auf dem HEAP liegt
    Time* pt = (Time*) malloc(sizeof(Time));

    initTime(pt, 1, 2, 3);

    free(pt);
}

void mainStructs()
{
    structs_01();
    structs_02();
    structs_03();
    structs_04();
    structs_05();
    structs_06();
}

// ===========================================================================
// End-of-File
// ===========================================================================
