// =====================================================================================
// Bruchrechnen.c // Aufgabe zu Strukturen und Bruchrechnen
// =====================================================================================

#include <stdio.h>

// types
struct Fraction
{
    int numerator;
    int denominator;
};

// functions
struct Fraction scalarMul    (struct Fraction f, int scalar);
struct Fraction add          (struct Fraction f1, struct Fraction f2);
struct Fraction sub          (struct Fraction f1, struct Fraction f2);
struct Fraction mul          (struct Fraction f1, struct Fraction f2);
struct Fraction reduce       (struct Fraction f); 
int             ggT          (int numerator, int denominator);
void            print        (struct Fraction f);

void test_fraction_reduce    ();
void test_fraction_scalarMul ();
void test_fraction_add       ();
void test_fraction_sub       ();
void test_fraction_mul       ();

// =====================================================================================

static struct Fraction scalarMul(struct Fraction f, int scalar)
{
    struct Fraction result = { 0, 1 };

    result.numerator = f.numerator * scalar;
    result.denominator = f.denominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static struct Fraction add(struct Fraction f1, struct Fraction f2)
{
    struct Fraction result = { 0, 1 };

    int mainDenominator = f1.denominator * f2.denominator;

    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = mainDenominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static struct Fraction sub(struct Fraction f1, struct Fraction f2)
{
    struct Fraction result = { 0, 1 };

    int mainDenominator = f1.denominator * f2.denominator;

    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = mainDenominator;

    int divisor = ggT(result.numerator, result.denominator);

    result.numerator = result.numerator / divisor;
    result.denominator = result.denominator / divisor;

    return result;
}

static struct Fraction mul(struct Fraction f1, struct Fraction f2)
{
    struct Fraction result = { 0, 1 };

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

static struct Fraction reduce(struct Fraction f)
{
    int divisor = ggT(f.numerator, f.denominator);

    struct Fraction result = 
    {
        f.numerator / divisor, 
        f.denominator / divisor 
    };

    return result;
}

static void print(struct Fraction f)
{
    printf("%d / %d", f.numerator, f.denominator);
}

static void test_fraction_reduce()
{
    struct Fraction f = { 3, 9 };
    print(f);
    printf("\n");

    f = reduce(f);
    print(f);
    printf("\n");
}

static void test_fraction_scalarMul()
{
    struct Fraction f = { 1, 7 };
    print(f);
    printf("\n");

    struct Fraction result;
    result = scalarMul(f, 3);
    print(result);
    printf("\n");

    struct Fraction f2 = { 3, 9 };
    print(f2);
    printf("\n");

    result = scalarMul(f2, 3);
    print(result);
    printf("\n");
}

static void test_fraction_add()
{
    struct Fraction f1 = { 1, 3 };
    struct Fraction f2 = { 4, 3 };
    struct Fraction result = add(f1, f2);

    print(f1);
    printf(" + ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");

    struct Fraction f3 = { 1, 3 };
    struct Fraction f4 = { 3, 4 };
    result = add(f3, f4);

    print(f3);
    printf(" + ");
    print(f4);
    printf(" = ");
    print(result);
    printf("\n");

    struct Fraction f5 = { 2, 8 };
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
    struct Fraction f1 = { 4, 3 };
    struct Fraction f2 = { 1, 3 };
    struct Fraction result = sub(f1, f2);

    print(f1);
    printf(" - ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");
}

static void test_fraction_mul()
{
    struct Fraction f1 = { 1, 3 };
    struct Fraction f2 = { 4, 3 };
    struct Fraction result = mul(f1, f2);

    print(f1);
    printf(" * ");
    print(f2);
    printf(" = ");
    print(result);
    printf("\n");

    struct Fraction f3 = { 1, 2 };
    struct Fraction f4 = { 3, 4 };
    result = mul(f3, f4);

    print(f3);
    printf(" * ");
    print(f4);
    printf(" = ");
    print(result);
    printf("\n");

    struct Fraction f5 = { 2, 8 };
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
