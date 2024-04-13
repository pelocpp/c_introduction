// =====================================================================================
// Zeiger.c
// =====================================================================================

#include <stdio.h>

static void calculate (int* a, int b)
{
    *a = 4;
    b = b + *a;
    printf("%d - %d\n", *a, b);
}

void exercise_pointer()
{
    int a = 3;
    int b = 5;

    calculate(&a, b);
    printf("%d - %d\n", a, b);

    calculate(&b, a);
    printf("%d - %d\n", a, b);
}

// =====================================================================================
// End-of-File
// =====================================================================================
