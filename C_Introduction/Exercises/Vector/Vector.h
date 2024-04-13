// =====================================================================================
// Vector.h
// =====================================================================================

#pragma once

// function prototypes
void   vectorInit          (double vector[], int len);
double vectorLength        (double vector[], int len);
void   vectorNormalize     (double result[], double vec[],  int len);
void   vectorAdd           (double result[], double vec1[], double vec2[], int len);
void   vectorSub           (double result[], double vec1[], double vec2[], int len);
void   vectorScalarMul     (double result[], double vec[],  int len, double scalar);
double vectorScalarProduct (double vec1[],   double vec2[], int len);
int    isEqual             (double vec1[],   double vec2[], int len);
int    isUnequal           (double vec1[],   double vec2[], int len);
void   vectorPrint         (double vector[], int len);

// =====================================================================================
// End-of-File
// =====================================================================================
