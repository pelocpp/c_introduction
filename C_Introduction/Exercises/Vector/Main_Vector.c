// =====================================================================================
// Main_Vector.c
// =====================================================================================

#include <stdio.h>

#include "Vector.h"

void exercise_vector()
{
    double vector[3];
    double vector1[3] = { 3, 6,  8 };
    double vector2[3] = { 8, 16, 23 };
    double result[3];

    // testing vector initialization (zero vector)
    vectorInit(vector, 3);
    vectorPrint(vector, 3);
    printf("\n");

    // testing vector length
    double length = vectorLength(vector1, 3);
    vectorPrint(vector1, 3);
    printf(": Length = %.3f\n", length);

    // testing vector normalization
    vectorNormalize(result, vector1, 3);
    printf("Normalized: ");
    vectorPrint(result, 3);
    length = vectorLength(result, 3);
    printf(": Length = %.3f\n", length);

    // testing vector addition
    vectorAdd(result, vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" + ");
    vectorPrint(vector2, 3);
    printf(" = ");
    vectorPrint(result, 3);
    printf("\n");

    // testing scalar multiplication
    vectorScalarMul(result, vector1, 3, 10.0);
    printf(" 10 ");
    printf(" * ");
    vectorPrint(vector1, 3);
    printf(" = ");
    vectorPrint(result, 3);
    printf("\n");

    // testing scalar product
    double product = vectorScalarProduct(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" * ");
    vectorPrint(vector2, 3);
    printf(" = %lf  [scalar product]\n", product);

    // testing vector comparison
    int comparison = isEqual(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" == ");
    vectorPrint(vector2, 3);
    printf(" : %d\n", comparison);

    comparison = isUnequal(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" != ");
    vectorPrint(vector2, 3);
    printf(" : %d\n", comparison);

    comparison = isEqual(vector1, vector1, 3);
    vectorPrint(vector1, 3);
    printf(" == ");
    vectorPrint(vector1, 3);
    printf(" : %d\n", comparison);
}

// =====================================================================================
// End-of-File
// =====================================================================================
