// ===========================================================================
// MultidimensionalArrays.c // Multidimensional Arrays
// ===========================================================================

// https://www.programiz.com/c-programming/c-multi-dimensional-arrays

// https://www.skillvertex.com/blog/how-to-pass-a-2d-array-as-a-parameter-in-c/

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free
#include <crtdbg.h>

static void multidimensional_arrays_01()
{
    // Different ways to initialize two-dimensional array

    int numbers1[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int numbers2[][3]  = { {1, 2, 3}, {4, 5, 6} };

    int numbers3[2][3] = { 1, 2, 3, 4, 5, 6 };

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("[%d][%d]: %2d   ", i, j, numbers1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("[%d][%d]: %2d   ", i, j, numbers1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("[%d][%d]: %2d   ", i, j, numbers1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void multidimensional_arrays_02()
{
    int numbers1[2][3][4] =
    {
        {
            { 1, 2, 3, 4 }, 
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        },
        {
            { 13, 14, 15, 16 }, 
            { 17, 18, 19, 20 }, 
            { 21, 22, 23, 24 }
        } 
    };

    int numbers2[2][3][4] =
    {
        1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12 , 13, 14, 15, 16 , 17, 18, 19, 20, 21, 22, 23, 24
    };

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                printf("[%d][%d][%d]: %2d   ", i, j, k, numbers1[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                printf("[%d][%d][%d]: %2d   ", i, j, k, numbers2[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

static void multidimensional_arrays_03()
{
}

static void multidimensional_arrays_04()
{
}

static void multidimensional_arrays_05()
{
}

static void multidimensional_arrays_06()
{
}

static void multidimensional_arrays_07()
{
}

static void multidimensional_arrays_08()
{
}

static void multidimensional_arrays_09()
{
}



// ================================================================

void mainMultidimensionalArrays()
{
    multidimensional_arrays_01();
    multidimensional_arrays_02();
    multidimensional_arrays_03();
    multidimensional_arrays_04();
    multidimensional_arrays_05();
    multidimensional_arrays_06();
    multidimensional_arrays_07();
    multidimensional_arrays_08();
    multidimensional_arrays_09();
}

// ===========================================================================
// End-of-File
// ===========================================================================
