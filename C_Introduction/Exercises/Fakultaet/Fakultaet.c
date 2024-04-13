// =====================================================================================
// Fakultaet.c
// =====================================================================================

#include <stdio.h>

static long long fakultaet(int n)
{
     int i;
     long long result;

     result = 1;
     for (i = 2; i <= n; i++)
         result *= i;

     return result;
}

void exercise_fakultaet()
{
    int n = 5;
    long long fakul_5 = fakultaet(n);
    printf("%d! = %lld\n", n, fakul_5);

    // ================================

    for (int i = 1; i <= 30; ++i) {

        long long result = fakultaet(i);

        //if (i == 25)
        //    printf("Stopper\n");

        printf("%d! = %lld\n", i, result);
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
