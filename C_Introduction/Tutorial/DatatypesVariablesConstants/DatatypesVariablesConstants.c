// ===========================================================================
// DatatypesVariablesConstants.c // Datatypes, Variables and Constants
// ===========================================================================

#include <stdio.h>

// TODO: Maximale Werte -- Wertebereich ergänzen

static void integral_datatypes()
{
    int n = 1;
    long l = -2;
    short s = 3;
    long long ll = -4;

    unsigned int ui = 1; 
    unsigned long ul = 2;
    unsigned short us = 3;
    unsigned long long ull = 4;

    size_t x = 0;

    size_t width_int = sizeof(int);
    size_t width_long = sizeof(long);
    size_t width_short = sizeof(short);
    size_t width_long_long = sizeof(long long);
    size_t width_size_t = sizeof(size_t);

    printf("sizeof (int):         %zu\n", width_int);
    printf("sizeof (long):        %zu\n", width_long);
    printf("sizeof (short):       %zu\n", width_short);
    printf("sizeof (long long):   %zu\n", width_long_long);
    printf("sizeof (size_t):      %zu\n", width_size_t);
}

static void floating_point_datatypes()
{
    double d = 123.456;
    float f = 654.321F;

    printf("sizeof (double):      %zu\n", sizeof(double));
    printf("sizeof (float):       %zu\n", sizeof(float));
}

static void char_string_datatypes()
{
    // chars
    char ch = 'A';
    char newLine = '\n';

    // string
    const char* s = "ABC";

    printf("ch:                   %c\n", ch);
    printf("s:                    %s\n", s);
}

static void pointer_datatypes()
{
    int n = 123;

    int* ip = &n;

    printf("n:                    %d\n", n);
    printf("&n:                   %p\n", ip);
    printf("sizeof (int*):        %zu\n", sizeof(int*));
}

static void constants()
{
    int n1 = 123;
    int n2 = 0x19AF;
    int n3 = 0b1101010101010;

    int ooops = 012;
    printf("ooops:                %d\n", ooops);
}

void testDatatypesVariablesConstants()
{
    integral_datatypes();
    floating_point_datatypes();
    char_string_datatypes();
    pointer_datatypes();
    constants();
}

// ===========================================================================
// End-of-File
// ===========================================================================
