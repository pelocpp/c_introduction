// ===========================================================================
// ControlStructures.c // Kontrollstrukturen
// ===========================================================================

#include <stdio.h>

static void test_if_01()
{
    int n = 1;
    int m = 2;

    if (m > n) {

        printf("erfuellt\n");
    }
}

static void test_if_02()
{
    int n = 3;
    int m = 4;

    if (m > n) {

        printf("erfuellt\n");
    }
    else {

        printf("nicht erfuellt\n");
    }
}

static void test_if_03()
{
    int n = 123;

    // Test auf Gleichheit: ==
    if (n == 123) {

        printf("erfuellt\n");
    }

    // Test auf Ungleichheit: !=
    if (n != 123) {

        printf("erfuellt\n");
    }
}

static void test_if_04()
{
    int n = 5;
    int m = 6;

    if (n >= 3 && m <= 4) {

        printf("erfuellt\n");
    }

    if (n >= 3 || m <= 4) {

        printf("erfuellt\n");
    }

    if (! (n >= 3)) {

        printf("erfuellt\n");
    }
}

static void test_if_05()
{
    int n = 5;
    int m = 6;

    if (n >= 3 && m <= 4) {

        printf("erfuellt\n");
    }

    if (n >= 3 || m <= 4) {

        printf("erfuellt\n");
    }

    if (!(n >= 3)) {

        printf("erfuellt\n");
    }
}

static void test_if_06()
{
    int n = 123;

    // Vorsicht: 1.)
    // Synonym: n != 0
    if (n) {

        printf("erfuellt\n");
    }

    // Vorsicht: 2.)
    // Synonym:
    if (n = 456) {

        printf("erfuellt\n");
    }

    // ist gleich
    if ((n = 456) != 0) {

        printf("erfuellt\n");
    }
}

static void test_if_07()
{
    int n;

    // Frage:

    n = 2;

    // Version 1:

    if (n == 1) {
        printf("n = 1\n");
    }

    if (n == 2) {
        printf("n = 2\n");
    }

    if (n == 3) {
        printf("n = 3\n");
    }

    // vs Version 2:

    if (n == 1) {
        printf("n = 1\n");
    }
    else if (n == 2) {
        printf("n = 2\n");
    }
    else if (n == 3) {
        printf("n = 3\n");
    }
}

// ===========================================================================

static void test_for_01()
{
    // for-Anweisung
    for (int i = 0; i < 5; i = i + 1) {

        printf("Bin hier: %d\n", i);
    }
}

static void test_for_02()
{
    // for-Anweisung
    for (int i = 0; i < 5; i = i + 1) {

        if (i == 3) {  // Ausnahme , unerwarteter Wert von einer Eingabe
            break;
        }

        printf("Bin hier: %d\n", i);
    }
}

static void test_for_03()
{
    // for-Anweisung
    for (int i = 0; i < 5; i = i + 1) {

        if (i == 3) {  // Ausnahme , unerwarteter Wert von einer Eingabe
            continue;
        }

        printf("Bin hier: %d\n", i);
    }
}

static void test_for_04()
{
    // for-Anweisung // Gimmicks

    int i = 0;

    // Endlos-Schleife
    for (;;) {

        // i = i + 1;
        ++i;
        //oder
        i++;

        printf("Bin hier: %d\n", i);

        if (i >= 10) {
            break;
        }
    }
}

// ===========================================================================

static void test_while_01()
{
    // for-Anweisung
    for (int i = 0; i < 5; i = i + 1) {

        printf("for -   Bin hier: %d\n", i);
    }

    // Dasselbe mit while:

    int k = 0;

    while (k < 5) {

        printf("while - Bin hier: %d\n", k);

        k++;
    }
}

// ===========================================================================

void testControlStructures()
{
    test_if_01();
    test_if_02();
    test_if_03();
    test_if_04();
    test_if_05();
    test_if_06();
    test_if_07();

    test_for_01();
    test_for_02();
    test_for_03();
    test_for_04();

    test_while_01();
}


// ===========================================================================
// End-of-File
// ===========================================================================
