// ===========================================================================
// Strings.c // Zeichen und Zeichenketten
// ===========================================================================

#include <stdio.h>

static void strings_01()
{
    int size = sizeof(char);

    char ch = '?';

    char lf = '\n';

    char cr = '\r';
}

static void strings_02()
{
    // ASCII Tabelle

    // Symbiose:   char <=> int

    for (int i = 0; i <= 127; ++i) {

        int ascciCode = i;

        char ch = i;

        printf("Ascii-Code: %03d - Zeichen: %c\n", ascciCode, ch);

        // oder

        printf("Ascii-Code: %03d - Zeichen: %c\n", i, i);
    }
}

static void strings_03()
{
    // Das 0 Zeichen

    char ch1 = '0';     // falsch

    char ch2 = 0;       // perfekt

    char ch3 = '\0';    // auch perfekt

    "ABCDE";   // empty statement

    printf("1.: %s\n", "ABCDE");

    // Eine Zeichenkette in einem ARRAY
    char zeichen[20];

    zeichen[0] = 'A';
    zeichen[1] = 'B';
    zeichen[2] = 'C';
    zeichen[3] = 'D';
    zeichen[4] = 'E';
    zeichen[5] = 0;

    printf("2.: %s\n", zeichen);

    // Eine konstante Zeichenkette:
    // Hier sieht die Sprache C die Anfangsadresse

    char* s = "123456789012";  // 12 Zeichen

    printf("3.: %s\n", s);
    printf("4.: %zu\n", sizeof(int*));
    printf("5.: %zu\n", sizeof(s));

    char anfang = *s;

    printf("6.: %zu\n", sizeof(*s));
    printf("6.: %zu\n", sizeof(char));
}

static int str_length(char* cp)   // Liefert Anzahl der Zeichen - OHNE '\0' zurück
{
    int length = 0;

    while (*cp != '\0') {

        length++;
        cp++;
    }

    return length;
}


static void strings_04()
{
    char* kette1 = "123";

    // oder

    char kette2[20] = "123";  // Ja, da ist hinten noch Freiraum

    int length1 = str_length(kette1);

    int length2 = str_length(kette2);
}

static int str_insert(char* ursprung, char* ergebnis, int length, char welchesZeichen, int pos)
{
    // Teste, ob bereitgestellter Puffer (Array 'ergebnis') groß genug ist
    int lenUrsprung = str_length(ursprung);

    if (length < lenUrsprung + 1 /* einzufügendes Zeichen */ + 1 /* '\0' */) {

        return 0;
    }

    // a) Bis zur Position pos (einschließlich) alle Zeichen aus 'ursprung' nach 'ergebnis' umkopieren
    for (int i = 0; i <= pos; ++i) {
        ergebnis[i] = ursprung[i];
    }

    // b) Zeichen 'welchesZeichen' in 'ergebnis' anhängen
    ergebnis[pos + 1] = welchesZeichen;

    // c) Restlichen Zeichen von  'ursprung' nach 'ergebnis' umkopieren
    for (int i = pos + 1; i < lenUrsprung; ++i) {
        ergebnis[i + 1] = ursprung[i];
    }

    // d) Das ergebnis mit einer '\0' abschließen 
    ergebnis[lenUrsprung + 1] = '\0';

    return 1;  // ungleich 0 
}


static void strings_05()
{
    char* kette1 = "12345";     // Konstante, kein Array, hinten gehört uns der Platz NICHT !!!
    // oder
    char kette2[20] = "12345";  // Ja, da ist hinten noch Freiraum

    char result[20];

    int succeeded = str_insert(kette1, result, 20, '?', 2);
}

void testStrings()
{
    strings_01();
    strings_02();
    strings_03();
    strings_04();
    strings_05();
}

// ===========================================================================
// End-of-File
// ===========================================================================

