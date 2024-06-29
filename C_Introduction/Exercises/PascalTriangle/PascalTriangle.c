// =====================================================================================
// PascalTriangle.c
// =====================================================================================

#include <stdio.h>

// Siehe zum Beispiel:

// https://www.w3resource.com/c-programming-exercises/for-loop/c-for-loop-exercises-33.php

#define Length   8

static void print_pascal(int arr[Length][Length])
{
    for (int i = 0; i < Length; i++)
    {
        for (int j = 0; j < Length; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

static void compute_pascal(int arr[Length][Length])
{
    for (int i = 0; i < Length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
}

void exercise_pascal_triangle()
{
    int pascal[Length][Length] = { 0 };
    compute_pascal(pascal);
    print_pascal(pascal);
}

// =====================================================================================
// End-of-File
// =====================================================================================
