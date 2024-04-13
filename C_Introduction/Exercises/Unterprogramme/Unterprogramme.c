// =====================================================================================
// Unterprogramme.c
// =====================================================================================

#include <stdio.h>

static double AreaCircle(double radius)
{
    double area = 2 * 3.141592653589793 * radius;

    return area;
}

static void exercise_area_circle()
{
    double r = 20;

    double area = AreaCircle(r);

    printf("Circle with radius %f has an area %f.\n", r, area);
}

static void exercise_doubled_interest_rate()
{
    // to be done ... 
}

static int IsLeapLear(int year)
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

static int IsLeapLearCompact(int year)
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

static void exercise_is_leap_year ()
{
    int result;
    int year;

    year = 1999;
    result = IsLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2000;
    result = IsLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2003;
    result = IsLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2004;
    result = IsLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);

    year = 2024;
    result = IsLeapLear(year);
    printf("%d ist Schaltjahr: %d\n", year, result);
}


void exercise_unterprogramme()
{
    exercise_area_circle();
    exercise_doubled_interest_rate();
    exercise_is_leap_year();
}

// =====================================================================================
// End-of-File
// =====================================================================================
