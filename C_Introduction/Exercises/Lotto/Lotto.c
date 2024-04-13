// =====================================================================================
// Lotto.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>   // rand()
#include <time.h>     // time_t

// =====================================================================================

// globale Variablen
int g_feldLotto[6]; // 6 Elemente im Feld
int g_index;        // 

// Wert zum Reproduzieren:         1651144609
unsigned int g_reproduktionsWert = 1651144609;

// =====================================================================================

//  Vorwärtsdeklarationen
int naechsteZahl();
int zahlSchonVorhanden(int zahl);
void zahlEinfuegen(int zahl);
void lottoInitialisierung();
void lottoSpielen();
void lottoAusgabe();
void lottoVerifizieren();

void exercise_lotto_spielen_brute_force();
void exercise_lotto_spielen_strukturiert();

// =====================================================================================

// Realisierung
static void lottoInitialisierung()
{
    time_t t = 0;

    //srand((unsigned)time(&t));
    srand(g_reproduktionsWert);  // Mit diesem Wert lassen sich DOPPELTE reproduzieren ...

    g_index = 0;   // Bis Index 0 sind im Feld schon Lottozahlen vorhanden

    for (int i = 0; i < 6; ++i)
    {
        g_feldLotto[i] = -1;
    }
}

static int naechsteZahl()
{
    int zahl = rand() % 49 + 1;
    return zahl;
}

static int zahlSchonVorhanden(int zahl)
{
    for (int i = 0; i < g_index; ++i)
    {
        if (g_feldLotto[i] == zahl)
        {
            return 1; // true
        }
    }

    return 0;   // false
}

static void zahlEinfuegen(int zahl)
{
    g_feldLotto[g_index] = zahl;
    g_index++;
}

static void lottoSpielen()
{
    for (int i = 0; i < 6; ++i)
    {
        int zahl = naechsteZahl();
        while (zahlSchonVorhanden(zahl))
        {
            zahl = naechsteZahl();
        }

        printf("%d. Kugel: %d\n", (i+1), zahl);
        zahlEinfuegen(zahl);
    }
}

static void lottoAusgabe()
{
    printf("Ziehung der Lottozahlen:\n");
    printf("========================\n");

    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", g_feldLotto[i]);
    }
    printf("\n");
}

static void lottoVerifizieren()
{
    for (int i = 0; i < 6; ++i) {

        // int wert = g_feldLotto[i];

        for (int k = 0; k < 6; ++k) {

            if (k == i)
                continue;

            if (g_feldLotto[i] == g_feldLotto[k]) {
                printf("DOPPELTE LOTTOZAHLEN");
                exit(-1);
            }
        }
    }
}

static void exercise_lotto_spielen_strukturiert()
{
    lottoInitialisierung();   // Eingabe
    lottoSpielen();           // Verarbeitung
    lottoVerifizieren();      // Test
    lottoAusgabe();           // Ausgabe
}

// =====================================================================================

static void exercise_lotto_spielen_brute_force() {

    time_t t;
    int Max = -1;
    int Min = 101;

    srand((unsigned)time(&t));
    // oder
    //srand( 100 );

    printf("Ziehung der Lottozahlen:\n");
    printf("========================\n");

    for (int i = 0; i < 6; i++)             // wir wollen 6 Lottozahlen
    {
        int gewurfelt = rand() % 49 + 1;    //wir haben ein Zufallszahl zwischen 1 und 49 "gewürfelt"

        while (1)  // Endlosschleife
        {
            for (int m = 0; m < i; m++)
            {
                if (g_feldLotto[m] == gewurfelt)
                {
                    gewurfelt = rand() % 49 + 1;      // nochmal neu "würfeln"

                    m = -1;  // Arghhhhhhhhh
                    continue;
                }
            }

            // 'gewurfelt' ist nicht in 'g_feldLotto'
            g_feldLotto[i] = gewurfelt;
            break;
        }
    }

    // Ausgeben
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", g_feldLotto[i]);
    }
    printf("\n\n");
}

void exercise_lotto()
{
    exercise_lotto_spielen_strukturiert();
    exercise_lotto_spielen_brute_force();
}

// =====================================================================================
// End-of-File
// =====================================================================================
