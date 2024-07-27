// =====================================================================================
// Bruchrechnen.c // Aufgabe zu Strukturen und Bruchrechnen
// =====================================================================================

#include <stdio.h>

struct Fraction
{
	int numerator;
	int denominator;
};

int ggT(int zaehler, int nenner);
void print(struct Fraction f);
struct Fraction scalarMul(struct Fraction f, int scalar);
struct Fraction add(struct Fraction f1, struct Fraction f2);
struct Fraction sub(struct Fraction f1, struct Fraction f2);
struct Fraction mul(struct Fraction f1, struct Fraction f2);

// =====================================================================================

static int ggT(int zaehler, int nenner)
{
	if (nenner == 0) {
		return zaehler;
	}
	else
	{
		return ggT(nenner, zaehler % nenner);
	}
}

static void print(struct Fraction f)
{
	printf("%d / %d", f.numerator, f.denominator);
}

static struct Fraction scalarMul(struct Fraction f, int scalar)
{
	struct Fraction result = { 0, 1 };

	result.numerator = f.numerator * scalar;
	result.denominator = f.denominator;

	return result;
}

static struct Fraction add(struct Fraction f1, struct Fraction f2)
{
	struct Fraction result = { 0, 1 };

	int mainDenominator = f1.denominator * f2.denominator;

	result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	result.denominator = mainDenominator;

	// mit kuerzen
	int teiler = ggT(result.numerator, result.denominator);

	result.numerator = result.numerator / teiler;
	result.denominator = result.denominator / teiler; ;

	return result;
}

static struct Fraction sub(struct Fraction f1, struct Fraction f2)
{
	// TO BE TESTED !!!!!!!!!!!!!!!!!!!!!!!

	struct Fraction result = { 0, 1 };

	int mainDenominator = f1.denominator * f2.denominator;

	result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	result.denominator = mainDenominator;

	// mit kuerzen
	int teiler = ggT(result.numerator, result.denominator);

	result.numerator = result.numerator / teiler;
	result.denominator = result.denominator / teiler; ;

	return result;
}

static struct Fraction mul(struct Fraction f1, struct Fraction f2)
{
	struct Fraction result = { 0, 1 };

	result.numerator = f1.numerator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;

	// mit kuerzen
	int teiler = ggT(result.numerator, result.denominator);

	result.numerator = result.numerator / teiler;
	result.denominator = result.denominator / teiler; ;

	return result;
}

// Sonderaufgabe:
// 2 / 8 und 2 / 8 = 4 / 8 = 1 / 2  
// Wie koennten wir das loesen .............................

void test_bruchrechnen()
{
	struct Fraction f = { 1, 7 };
	print(f);
	printf("\n");

	struct Fraction result;
	result = scalarMul(f, 3);
	print(result);
	printf("\n");

	// Test der Addition
	struct Fraction f1 = { 1, 3 };
	struct Fraction f2 = { 4, 3 };
	result = add(f1, f2);

	print(f1);
	printf(" + ");
	print(f2);
	printf(" = ");
	print(result);
	printf("\n");

	// Test der Multiplikation
	result = mul(f1, f2);

	print(f1);
	printf(" * ");
	print(f2);
	printf(" = ");
	print(result);
	printf("\n");
}

// =====================================================================================
// End-of-File
// =====================================================================================
