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


static void jaggedPascalTriangle_StackBased()
{
    // static jagged array on the stack

    int array1[] = { 1 };
    int array2[] = { 1, 1 };
    int array3[] = { 1, 2, 1 };
    int array4[] = { 1, 3, 3, 1 };
    int array5[] = { 1, 4, 6, 4, 1 };
    int array6[] = { 1, 5, 10, 10, 5, 1 };
    int array7[] = { 1, 6, 15, 20, 15, 6, 1 };
    int array8[] = { 1, 7, 21, 35, 35, 21, 7, 1 };

    int* jagged_pascal_arrays_stack_based[] = { array1, array2, array3, array4, array5, array6, array6, array8 };
}

// =====================================================================================
// Heap based Solution (Dynamic Jagged Array)

static void jagged_arrays_04()
{
    // static jagged array on the heap

    int** jagged_array = (int**) calloc(3, sizeof(int*));

    jagged_array[0] = (int*) calloc(4, sizeof(int));
    jagged_array[1] = (int*) calloc(2, sizeof(int));
    jagged_array[2] = (int*) calloc(3, sizeof(int));

    // release memory
    for (int i = 0; i < 3; i++) {
        free(jagged_array[i]);
    }

    free(jagged_array);

}

static void jagged_arrays_05()
{
    // static jagged array on the heap

    int sizes[] = { 4, 2, 3 };

    int* row1 = (int*) calloc(sizes[0], sizeof(int));
    row1[0] = 1;
    row1[1] = 2;
    row1[2] = 3;
    row1[3] = 4;

    int* row2 = (int*) calloc(sizes[1], sizeof(int));
    row2[0] = 5;
    row2[1] = 6;

    int* row3 = (int*) calloc(sizes[2], sizeof(int));
    row3[0] = 7;
    row3[1] = 8;
    row3[2] = 9;

    int** jagged_array = (int**)calloc(3, sizeof(int*));
    jagged_array[0] = row1;
    jagged_array[1] = row2;
    jagged_array[2] = row3;

    // output memory
    for (int i = 0; i < 3; i++) {

        for (int k = 0; k < sizes[i]; k++) {

            printf("i:%d|k:%d: %3d  ", i, k, jagged_array[i][k]);
        }
        printf("\n");
    }

    // release memory
    for (int i = 0; i < 3; i++) {
        free(jagged_array[i]);
    }
}

void exercise_jagged_pascal_arrays()
{

}

// =====================================================================================
// End-of-File
// =====================================================================================
