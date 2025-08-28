// =====================================================================================
// Bruchrechnen.c // Aufgabe zu Strukturen und Bruchrechnen
// =====================================================================================

#include <stdio.h>

// types
struct fraction
{
    int numerator;
    int denominator;
};

typedef struct fraction Fraction;

// functions (methods)
Fraction scalarMul (Fraction f, int scalar);
Fraction add       (Fraction f1, Fraction f2);
Fraction sub       (Fraction f1, Fraction f2);
Fraction mul       (Fraction f1, Fraction f2);
Fraction reduce    (Fraction f); 
int      ggT       (int numerator, int denominator);
void     print     (Fraction f);

// =====================================================================================

// test functions
static void test_fraction_reduce    ();
static void test_fraction_scalarMul ();
static void test_fraction_add       ();
static void test_fraction_sub       ();
static void test_fraction_mul       ();

// =====================================================================================

static Fraction scalarMul(Fraction f, int scalar)
{
    Fraction result = { 0, 1 };

    result.numerator = f.numerator * scalar;
    result.denominator = f.denominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static Fraction add(Fraction f1, Fraction f2)
{
    Fraction result = { 0, 1 };

    int mainDenominator = f1.denominator * f2.denominator;

    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = mainDenominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static Fraction sub(Fraction f1, Fraction f2)
{
    Fraction result = { 0, 1 };

    int mainDenominator = f1.denominator * f2.denominator;

    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = mainDenominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static Fraction mul(Fraction f1, Fraction f2)
{
    Fraction result = { 0, 1 };

    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;

    // mit kuerzen
    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static int ggT(int numerator, int denominator)
{
    if (denominator == 0) {
        return numerator;
    }
    else
    {
        return ggT(denominator, numerator % denominator);
    }
}

static Fraction reduce(Fraction f)
{
    int divisor = ggT(f.numerator, f.denominator);

    Fraction result = 
    {
        f.numerator / divisor, 
        f.denominator / divisor 
    };

    return result;
}

static void print(Fraction f)
{
    printf("%d / %d", f.numerator, f.denominator);
}

static void test_fraction_reduce()
{
    Fraction f = { 3, 9 };
    print(f);
    printf("\n");

    f = reduce(f);
    print(f);
    printf("\n");
}

static void test_fraction_scalarMul()
{
    Fraction f = { 1, 7 };
    print(f);
    printf("\n");

    Fraction result;
    result = scalarMul(f, 3);
    print(result);
    printf("\n");

    Fraction f2 = { 3, 9 };
    print(f2);
    printf("\n");

    result = scalarMul(f2, 3);
    print(result);
    printf("\n");
}

static void test_fraction_add()
{
    Fraction f1 = { 1, 3 };
    Fraction f2 = { 4, 3 };
    Fraction result = add(f1, f2);

    print(f1);
    printf(" + ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");

    Fraction f3 = { 1, 3 };
    Fraction f4 = { 3, 4 };
    result = add(f3, f4);

    print(f3);
    printf(" + ");
    print(f4);
    printf(" = ");
    print(result);
    printf("\n");

    Fraction f5 = { 2, 8 };
    result = add(f5, f5);

    print(f5);
    printf(" + ");
    print(f5);
    printf(" = ");
    print(result);
    printf("\n");
}

static void test_fraction_sub()
{
    Fraction f1 = { 4, 3 };
    Fraction f2 = { 1, 3 };
    Fraction result = sub(f1, f2);

    print(f1);
    printf(" - ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");
}

static void test_fraction_mul()
{
    Fraction f1 = { 1, 3 };
    Fraction f2 = { 4, 3 };
    Fraction result = mul(f1, f2);

    print(f1);
    printf(" * ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");

    Fraction f3 = { 1, 2 };
    Fraction f4 = { 3, 4 };
    result = mul(f3, f4);

    print(f3);
    printf(" * ");
    print(f4);
    printf(" = ");
    print(result);
    printf("\n");

    Fraction f5 = { 2, 8 };
    result = mul(f5, f5);

    print(f5);
    printf(" * ");
    print(f5);
    printf(" = ");
    print(result);
    printf("\n");
}

// =====================================================================================

void exercise_bruchrechnen()
{
    test_fraction_reduce();
    test_fraction_scalarMul();
    test_fraction_add();
    test_fraction_sub();
    test_fraction_mul();
}

// =====================================================================================
// End-of-File
// =====================================================================================
