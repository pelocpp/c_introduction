// =====================================================================================
// JaggedPascalTriangle.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>
#include <stdlib.h>

#define  Length 5

// =====================================================================================
// Stack based Solution (Static Jagged Array)

static void exercise_jagged_pascal_triangle_stack_based()
{
    // static jagged array on the stack
    int triangleRow1[] = { 1 };
    int triangleRow2[] = { 1, 1 };
    int triangleRow3[] = { 1, 2, 1 };
    int triangleRow4[] = { 1, 3, 3, 1 };
    int triangleRow5[] = { 1, 4, 6, 4, 1 };
    int triangleRow6[] = { 1, 5, 10, 10, 5, 1 };
    int triangleRow7[] = { 1, 6, 15, 20, 15, 6, 1 };
    int triangleRow8[] = { 1, 7, 21, 35, 35, 21, 7, 1 };

    int* triangle[] =
    {
        triangleRow1, triangleRow2, triangleRow3, triangleRow4,
        triangleRow5, triangleRow6, triangleRow7, triangleRow8
    };

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j <= i; j++) {

            printf(" %3d ", triangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// =====================================================================================
// Heap based Solution (Dynamic Jagged Array)

static int** createPascalTriangle(int rows);
static void printPascalTriangle(int** triangle, int rows);
static void releasePascalTriangle(int** triangle, int rows);

static int** createPascalTriangle(int rows)
{
    // create triangle on the heap
    int** triangle = (int**) calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {

        triangle[i] = (int*) calloc(i+1, sizeof(int));
    }

    // fill triangle
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            }
            else
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    return triangle;
}

static void printPascalTriangle(int** triangle, int rows)
{
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j <= i; j++) {

            printf(" %3d ", triangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void releasePascalTriangle(int** triangle, int rows)
{
    // release dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

static void exercise_jagged_pascal_triangle_heap_based()
{
    const int Rows = 12;
    int** triangle = createPascalTriangle(Rows);
    printPascalTriangle(triangle, Rows);
    releasePascalTriangle(triangle, Rows);
}

// =====================================================================================

void exercise_jagged_pascal_arrays()
{
    exercise_jagged_pascal_triangle_stack_based();
    exercise_jagged_pascal_triangle_heap_based();
}

// =====================================================================================
// End-of-File
// =====================================================================================
