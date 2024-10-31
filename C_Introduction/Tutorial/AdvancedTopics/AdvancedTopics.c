// ===========================================================================
// AdvancedTopics.c
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------

void mainGenericProgramming();

// ---------------------------------------------------------------------------
// Vectorizing of multiple method calls

#define Fn_apply(type, fn, ...) {                    \
    void* stopper = (int[]){ 0 };                    \
    type** list = (type*[]){ __VA_ARGS__, stopper};  \
                                                     \
    for (int i = 0; list[i] != stopper; ++i) {       \
        printf("calling free for %p\n", list[i]);    \
        fn(list[i]);                                 \
    }                                                \
}

#define freeAll(...) Fn_apply(void, free, __VA_ARGS__);

static void mainAdvancedTopics01()
{
    double* dp1 = malloc(10);
    double* dp2 = malloc(100);
    double* dp3 = malloc(1000);

    freeAll(dp1, dp2, dp3);
}

// ---------------------------------------------------------------------------
// Usage of _Generic: Overloading of functions
// Note: Need to compile with /std:c11

/* Get a type name string for the argument x */
#define TYPE_NAME(X) _Generic((X), \
      int: "int", \
      char: "char", \
      double: "double", \
      default: "unknown")

static void mainAdvancedTopics02()
{
    char* which = TYPE_NAME(42.42);

    printf("Type name: %s\n", TYPE_NAME(42.42));

    // _Generic keyword acts as a switch that chooses 
    // operation based on data type of argument. 
    printf("%d\n", _Generic(1.0L, float : 1, double : 2, long double : 3, default: 0));
    printf("%d\n", _Generic(1L, float : 1, double : 2, long double : 3, default: 0));
    printf("%d\n", _Generic(1.0L, float : 1, double : 2, long double : 3));
}

static int addInteger(int a, int b) {
    return a + b;
}

static double addDouble(double a, double b) {
    return a + b;
}

#define add(a, b) _Generic(a, int: addInteger, double: addDouble)(a, b)

static void mainAdvancedTopics03()
{
    int a = 1, b = 2;
    printf("%d\n", add(a, b)); // 3

    double ad = 111.111, bd = 222.222;
    printf("%g\n", add(ad, bd)); // 333,333
}

// ---------------------------------------------------------------------------

void mainAdvancedTopics()
{
    mainAdvancedTopics01();    // Vectorizing of multiple method calls
    mainAdvancedTopics02();    // Usage of _Generic: Overloading of functions
    mainAdvancedTopics03();    // Usage of _Generic: Overloading of functions
    mainGenericProgramming();  // "Generic Programming" style in C - using void*
}

// ===========================================================================
// End-of-File
// ===========================================================================
