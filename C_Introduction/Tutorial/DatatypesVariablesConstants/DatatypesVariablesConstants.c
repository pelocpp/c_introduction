// ===========================================================================
// DatatypesVariablesConstants.c // Datatypes, Variables and Constants
// ===========================================================================

#include <stdio.h>

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
    printf("\n");
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

static void unsignedRangesOfDatatypes()
{
    unsigned char      uchar     = -1;
    unsigned short     ushort    = -1;
    unsigned int       uint      = -1;
    unsigned long      ulong     = -1;
    unsigned long long ulonglong = -1;
    size_t             uint64    = -1;

    printf("Maximum Values\n");
    printf("unsigned char:        %u\n", uchar);
    printf("unsigned short:       %u\n", ushort);
    printf("unsigned int:         %u\n", uint);
    printf("unsigned long:        %u\n", ulong);
    printf("unsigned long long:   %llu\n", ulonglong);
    printf("size_t:               %zu\n", uint64);
    printf("\n");
}

static void signedRangesOfDatatypes()
{
    signed char      uchar     = 0x7F;
    signed short     ushort    = 0x7FFF;
    signed int       uint      = 0x7FFFFFFF;
    signed long      ulong     = 0x7FFFFFFF;
    signed long long ulonglong = 0x7FFFFFFFFFFFFFFF;

    printf("Maximum Values\n");
    printf("signed char:          %d\n", uchar);
    printf("signed short:         %d\n", ushort);
    printf("signed int:           %d\n", uint);
    printf("signed long:          %ld\n", ulong);
    printf("signed long long:     %lld\n", ulonglong);
    printf("\n");

    uchar = ~0x7F;
    ushort = ~0x7FFF;
    uint = ~0x7FFFFFFF;
    ulong = ~0x7FFFFFFF;
    ulonglong = ~0x7FFFFFFFFFFFFFFF;

    printf("Minumum Values\n");
    printf("signed char:          %d\n", uchar);
    printf("signed short:         %d\n", ushort);
    printf("signed int:           %d\n", uint);
    printf("signed long:          %ld\n", ulong);
    printf("signed long long:     %lld\n", ulonglong);
}

void mainDatatypesVariablesConstants()
{
    integral_datatypes();
    //floating_point_datatypes();
    //char_string_datatypes();
    //pointer_datatypes();
    //constants();
    unsignedRangesOfDatatypes();
    signedRangesOfDatatypes();
}

// ===========================================================================
// End-of-File
// ===========================================================================
