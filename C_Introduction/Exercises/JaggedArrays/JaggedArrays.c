// =====================================================================================
// JaggedArrays.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>

// https://takethenotes.com/jagged-array/

// https://stackoverflow.com/questions/12958583/how-to-malloc-a-2d-jagged-array-using-a-pointer-passed-by-reference-to-a-functio

#define Length 5

#include <stdio.h>
#include <stdlib.h>

static void jagged_arrays_01()
{
    // static jagged array on the stack

    char array1[5] = { 'T', 'h', 'i', 's', '\0' };
    char array2[3] = { 'i', 's', '\0' };
    char array3[2] = { 'a', '\0' };
    char array4[7] = { 'j', 'a', 'g', 'g', 'e', 'd', '\0' };
    char array5[6] = { 'a', 'r', 'r', 'a', 'y', '\0' };

    char* jagged_array[5] = { array1, array2, array3, array4, array5 };

    for (int i = 0; i < 5; i++) {
        printf("%s ", jagged_array[i]);
    }
    printf("\n");
}

static void jagged_arrays_02()
{
    // static jagged array on the stack

    int array1[4] = { 1, 2, 3, 4 };
    int array2[2] = { 5, 6 };
    int array3[3] = { 7, 8, 9 };

    int* jagged_array[3] = { array1, array2, array3 };
}

static void jagged_arrays_03()
{
    // static jagged array on the stack - with sizes

    int array1[4] = { 1, 2, 3, 4 };
    int array2[2] = { 5, 6 };
    int array3[3] = { 7, 8, 9 };

    int sizes[] = { 4, 2, 3 };

    // output memory
    int* jagged_array[3] = { array1, array2, array3 };

    for (int i = 0; i < 3; i++) {

        for (int k = 0; k < sizes[i]; k++) {

            printf("i:%d|k:%d: %3d  ", i, k, jagged_array[i][k]);
        }
        printf("\n");
    }
}

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

    int** jagged_array = (int**) calloc(3, sizeof(int*));

    jagged_array[0] = (int*) calloc(sizes[0], sizeof(int));
    jagged_array[1] = (int*) calloc(sizes[1], sizeof(int));
    jagged_array[2] = (int*) calloc(sizes[2], sizeof(int));


    // initialize memory
    jagged_array[0][0] = 1;
    jagged_array[0][1] = 2;
    jagged_array[0][2] = 3;
    jagged_array[0][3] = 4;

    jagged_array[1][0] = 5;
    jagged_array[1][1] = 6;

    jagged_array[2][0] = 7;
    jagged_array[2][1] = 8;
    jagged_array[2][2] = 9;

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

void exercise_jagged_arrays()
{
    jagged_arrays_01();
    jagged_arrays_02();
    jagged_arrays_03();
    jagged_arrays_04();
    jagged_arrays_05();
}

// =====================================================================================
// End-of-File
// =====================================================================================
