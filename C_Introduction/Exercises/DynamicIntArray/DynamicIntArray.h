// =====================================================================================
// DynamicIntArray.h
// =====================================================================================

#pragma once

// ===========================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <crtdbg.h>

// ===========================================================================================
// Defines

#define _CRTDBG_MAP_ALLOC

// ===========================================================================================
// Types

struct dynamicIntArray
{
    int*    m_data;
    size_t  m_length;
};

typedef struct dynamicIntArray DynamicIntArray;

// ===========================================================================================
// Function Prototypes

int    initDynamicIntArray                      (      DynamicIntArray* array, size_t length);
void   releaseDynamicIntArray                   (      DynamicIntArray* array);
void   createDynamicIntArrayFromArray           (      DynamicIntArray* array, const int* values, int length);
void   createDynamicIntArrayFromDynamicIntArray (      DynamicIntArray* array, const DynamicIntArray* other);
void   fillDynamicIntArray                      (      DynamicIntArray* array, int value);
size_t getLength                                (const DynamicIntArray* array);
int    get                                      (const DynamicIntArray* array, int index);
void   set                                      (      DynamicIntArray* array, int index, int value);
int    resizeDynamicIntArray                    (      DynamicIntArray* array, int newLength);
int    shrinkToFitDynamicIntArray               (      DynamicIntArray* array);
int    minimum                                  (const DynamicIntArray* array);
int    maximum                                  (const DynamicIntArray* array);
int    indexOf                                  (const DynamicIntArray* array, int value);
int    equalsDynamicIntArray                    (const DynamicIntArray* array, const DynamicIntArray* other);
int    containsDynamicIntArray                  (const DynamicIntArray* array, int value);
void   printDynamicIntArray                     (const DynamicIntArray* array);

// =====================================================================================
// End-of-File
// =====================================================================================
