// =====================================================================================
// Unterprogramme.c
// =====================================================================================

#include <stdio.h>

void exercise_areaCircle();
void exercise_doubleInterestRate();
void exercise_isLeapLear();

static double areaCircle(double radius)
{
    double area = 2 * 3.141592653589793 * radius;

    return area;
}

static void exercise_areaCircle()
{
    double r = 20;

    double area = areaCircle(r);

    printf("Circle with radius %f has an area %f.\n", r, area);
}

static int doubleInterestRate(double capital, double rate)
{
    double newCapital = capital;

    int year = 1;

    while (newCapital < 2 * capital) {

        double interest = (newCapital / 100.0) * rate;

        newCapital = newCapital + interest;

        printf("Year %2d: %lf\n", year, newCapital);

        year = year + 1;
    }

    return year;
}

static void exercise_doubleInterestRate()
{
    double capital = 1000.0;

    double rate = 5.0;

    int years = doubleInterestRate(capital, rate);

    printf("After %d years, a capital of %lf with interest rate  %lf is doubled!\n",
        years, capital, rate);
}

static int isLeapLear(int year)
{
    int result;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                result = 1; // Struktogramm: Ja, Ja, Ja
            }
            else {
                result = 0; // Struktogramm: Ja, Ja, Nein
            }
        }
        else {
            result = 1; // Struktogramm: Ja, Nein
        }
    }
    else {
        result = 0; // Struktogramm: Nein
    }

    return result;
}

static int isLeapLearCompact(int year)
{
    int result;

    if (year % 400 == 0 || (year % 4 == 0 && (year % 100 != 0))) 
    {
        result = 1;
    }
    else
    {
        result = 0;
    }


    return result;
}

static void exercise_isLeapLear()
{
    int result;
    int year;

    year = 1999;
    result = isLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2000;
    result = isLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2003;
    result = isLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2004;
    result = isLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2024;
    result = isLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);
}

void exercise_unterprogramme()
{
    exercise_areaCircle();
    exercise_doubleInterestRate();
    exercise_isLeapLear();
}

// =====================================================================================
// End-of-File
// =====================================================================================
