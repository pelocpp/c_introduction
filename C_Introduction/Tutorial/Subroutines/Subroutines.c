// ===========================================================================
// Subroutines.c // Unterprogramme (Prozeduren / Funktionen)
// ===========================================================================

#include <stdio.h>

// Vorwärtsdeklaration / Forward Declaration
void printHello(int count, float demoWert); 

static void testSubroutine()
{
    int wieOft = 7;

    printHello(wieOft, 123.456F);   // Aufruf
}

// procedure
static void printHello(int count, float demoWert)
{
    printf("demoWert: %f\n", demoWert);  // %d => dezimalen Wert

    if (demoWert < 0.0F) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        printf("Hello\n");
    }
}

// function
static int summeMalZehn(int zahl1, int zahl2)
{
    int result;

    result = zahl1 + zahl2;

    return 10 * result;
}

static void testFunction()
{
    int ergebnis = 0;

    int ergebnisVonPrintf = 0;

    ergebnis = summeMalZehn(11, 12);

    ergebnisVonPrintf = printf("Ergebnis: %d\n", ergebnis);

    printf("ergebnisVonPrintf: %d\n", ergebnisVonPrintf);
}

void mainSubroutines()
{
    testSubroutine();
    testFunction();
}

// ===========================================================================
// End-of-File
// ===========================================================================
