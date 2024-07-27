// =====================================================================================
// Bruchrechnen.c
// =====================================================================================

#include <stdio.h>

static double harmonic_series_01(int n)
{
    // using while-loop
    
    int m = 1;

    double result = 0.0;
    
    while (m <= n)
    {
        result = result + 1.0 / (double) m;

        m++; // m = m + 1
    }

    return result;
}

static double harmonic_series_02(int n)
{
    // using for-loop

    double result = 0.0;

    for (int m = 1; m <= n; m++)
    {
        result = result + 1.0 / (double) m;
    }

    return result;
}

void exercise_harmonische_reihe()
{
    // obere Grenze 
    int n = 0;

    printf("Bitte Wert eingeben: ");
    scanf_s("%d", &n);

    double value = harmonic_series_01(n);
    printf("Ergebnis: %f\n", value);

    value = harmonic_series_02(n);
    printf("Ergebnis: %f\n", value);
}

// =====================================================================================
// End-of-File
// =====================================================================================


// =====================================================================================
// Aufgabe zu Strukturen / Brueche.c
// =====================================================================================

#include <stdio.h>

struct Fraction
{
	int numerator;
	int denominator;
};

// erste Funktion / erstes Unterprogramm

// https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Br%C3%BCche/_Die_Methoden
int ggT(int zaehler, int nenner)
{
	if (nenner == 0) {
		return zaehler;
	}
	else
	{
		return ggT(nenner, zaehler % nenner);
	}
}


void printBruch(struct Bruch b)
{
	printf("%d / %d", b.zaehler, b.nenner);
}

// 3 mal 1/7 = 3/7
struct Bruch scalarProdukt(struct Bruch b, int scalar)
{
	struct Bruch result;

	result.zaehler = b.zaehler * scalar;
	result.nenner = b.nenner;

	return result;
}

// 1. Aufgabe:
// 3 / 7 und 1 / 7 = 4 / 7

struct Bruch addiereBruch(struct Bruch b1, struct Bruch b2)
{
	struct Bruch result;

	int hauptNenner = b1.nenner * b2.nenner;

	result.zaehler = b1.zaehler * b2.nenner + b2.zaehler * b1.nenner;
	result.nenner = hauptNenner;

	// mit kuerzen
	int teiler = ggT(result.zaehler, result.nenner);

	result.zaehler = result.zaehler / teiler;
	result.nenner = result.nenner / teiler; ;

	return result;
}

// 2. Aufgabe:
// 3 / 7 mal 2 / 7 = 6 / 49

struct Bruch multipliziereBruch(struct Bruch b1, struct Bruch b2)
{
	struct Bruch result;

	result.zaehler = b1.zaehler * b2.zaehler;
	result.nenner = b1.nenner * b2.nenner;

	// mit kuerzen
	int teiler = ggT(result.zaehler, result.nenner);

	result.zaehler = result.zaehler / teiler;
	result.nenner = result.nenner / teiler; ;

	return result;
}

// Sonderaufgabe:
// 2 / 8 und 2 / 8 = 4 / 8 = 1 / 2  
// Wie k?nnten wir das l?sen .............................

void test_bruch()
{
	struct Bruch b = { 1, 7 };
	printBruch(b);
	printf("\n");

	struct Bruch ergebnis;
	ergebnis = scalarProdukt(b, 3);
	printBruch(ergebnis);
	printf("\n");

	// Test der Addition
	struct Bruch b1 = { 1, 3 };
	struct Bruch b2 = { 4, 3 };
	ergebnis = addiereBruch(b1, b2);

	printBruch(b1);
	printf(" + ");
	printBruch(b2);
	printf(" = ");
	printBruch(ergebnis);
	printf("\n");

	// Test der Multiplikation
	ergebnis = multipliziereBruch(b1, b2);

	printBruch(b1);
	printf(" * ");
	printBruch(b2);
	printf(" = ");
	printBruch(ergebnis);
	printf("\n");
}

//void main()
//{
//	test_bruch();
//}

// =====================================================================================
// End-of-File
// =====================================================================================
