// ===========================================================================
// Strings.c // Zeichen und Zeichenketten
// ===========================================================================

#include <stdio.h>

static void strings_01()
{
    char ch;
    int n;

    ch = 'A';
    printf("%c\n", ch);

    ch = '*';
    printf("%c\n", ch);

    n = ch;
    printf("%c\n", ch);

    ch = 65;                 // ASCII table: 'A' == 65
    printf("%c\n", ch);
}

static void strings_02()
{
    int size = sizeof(char);

    char ch = '?';

    char lf = '\n';

    char cr = '\r';
}

static void strings_03()
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

// ===========================================================================

static void strings_04()
{
    // Das "Null" Zeichen

    char ch1 = '0';     // falsch

    char ch2 = 0;       // perfekt

    char ch3 = '\0';    // auch perfekt
}
    
// ===========================================================================

static void strings_05()
{
    // Konstante Zeichenkette

    "ABCDE";   // hier: empty statement

    printf("1.: %s\n\n", "ABCDE");

    // Zeichenkette in einem Feld bestehend auf char-Elementen

    char zeichen[20];

    zeichen[0] = 'A';
    zeichen[1] = 'B';
    zeichen[2] = 'C';
    zeichen[3] = 'D';
    zeichen[4] = 'E';
    zeichen[5] = 0;

    printf("2.: %s\n\n", zeichen);

    // Zeichenkette in einem Feld bestehend auf char-Elementen
    // mit Initialisierung

    const char mehrZeichen[] = { 'A', 'B', 'C', 'D', 'E', '\0' };;
    printf("3.: %s\n\n", mehrZeichen);
    
    // Zeichenkette in einem Feld bestehend auf char-Elementen
    // mit Initialisierung - ohne Terminierendes Null-Zeichen - Vorsicht !!!

    const char nochMehrZeichen[] = { 'A', 'B', 'C', 'D', 'E' };
    printf("4.: %s\n\n", nochMehrZeichen);


    // Datentyp für eine konstante Zeichenkette: const char*
    // (für die Sprache C repräsentiert die Adresse die Anfangsadresse der Zeichenkette)

    const char* s = "123456789012";  // 12 Zeichen

    printf("5.: %s\n", s);

    printf("    sizeof(s):      %zu\n", sizeof(s)    );
    printf("    sizeof(*s):     %zu\n", sizeof(*s)   );
    printf("    sizeof(char):   %zu\n", sizeof(char) );
    printf("    sizeof(int):    %zu\n", sizeof(int)  );
    printf("    sizeof(int*):   %zu\n", sizeof(int*) );
}

// ===========================================================================

static int str_length(const char* cp)   // Liefert Anzahl der Zeichen - ohne '\0' zurück
{
    int length = 0;

    while (*cp != '\0') {

        length++;
        cp++;
    }

    return length;
}

static void strings_06()
{
    const char* kette1 = "123";

    // oder

    const char kette2[20] = "123";  // Ja, da ist hinten noch Freiraum

    int length1 = str_length(kette1);

    int length2 = str_length(kette2);
}

static int str_insert(const char* source, char* destination, int destinationLength, char charToInsert, int pos)
{
    // a) teste, ob bereitgestellter Puffer (Array 'destination') groß genug ist
    int lenSource = str_length(source);

    if (destinationLength < lenSource + 1 /* einzufügendes Zeichen */ + 1 /* '\0' */) {

        return 0;
    }

    // b) bis zur Position pos (einschließlich) alle Zeichen aus 'source' nach 'destination' umkopieren
    for (int i = 0; i <= pos; ++i) {
        destination[i] = source[i];
    }

    // c) Zeichen 'charToInsert' in 'destination' einfuegen
    destination[pos + 1] = charToInsert;

    // c) restliche Zeichen von  'source' nach 'destination' umkopieren
    for (int i = pos + 1; i < lenSource; ++i) {
        destination[i + 1] = source[i];
    }

    // d) Puffer 'destination' mit einer '\0' abschließen 
    destination[lenSource + 1] = '\0';

    return 1;
}


static void strings_07()
{
    const char* kette1 = "12345";     // Konstante, kein Array, hinten gehört uns der Platz NICHT !!!

    // oder

    const char kette2[20] = "12345";  // Ja, da ist hinten noch Freiraum

    char result[20];

    int succeeded = str_insert(kette1, result, 20, '?', 2);
}

// ===========================================================================

void testStrings()
{
    strings_01();
    strings_02();
    strings_03();
    strings_04();
    strings_05();
    strings_06();
    strings_07();
}

// ===========================================================================
// End-of-File
// ===========================================================================

