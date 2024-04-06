// =====================================================================================
// Vector.c
// =====================================================================================

#include <stdio.h>
#include <math.h>

#include "Vector.h"

// implementation
void vectorInit(double vector[], int len)
{
    for (int i = 0; i < len; i++) {
        vector[i] = 0.0;
    }
}

double vectorLength(double vector[], int len)
{
    double result = 0.0;

    for (int i = 0; i < len; i++) {
        result += vector[i] * vector[i];
    }

    result = sqrt(result);

    return result;
}

void vectorNormalize(double result[], double vec[], int len)
{
    double norm = 1.0 / vectorLength(vec, len);

    //  normalize vector
    for (int i = 0; i < len; i++) {
        result[i] = vec[i] * norm;
    }
}

void vectorAdd(double result[], double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec1[i] + vec2[i];
    }
}

void vectorSub(double result[], double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec1[i] - vec2[i];
    }
}

void vectorScalarMul(double result[], double vec[], int len, double scalar)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec[i] * scalar;
    }
}

double vectorScalarProduct(double vec1[], double vec2[], int len)
{
    double result = 0.0;

    for (int i = 0; i < len; i++) {
        result += vec1[i] * vec2[i];
    }

    return result;
}

int isEqual(double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        if (vec1[i] != vec2[i]) {
            return 0;
        }
    }

    return 1;
}

int isUnequal(double vec1[], double vec2[], int len)
{
    return !isEqual(vec1, vec2, len);
}

void vectorPrint(double vec[], int len)
{
    printf("{ ");

    for (int i = 0; i < len - 1; i++) {
        printf("%.3f, ", vec[i]);
    }

    printf("%.3f }", vec[len - 1]);
}

// =====================================================================================
// End-of-File
// =====================================================================================
