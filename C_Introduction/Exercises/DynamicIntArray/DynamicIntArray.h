// =====================================================================================
// DynamicIntArray.h
// =====================================================================================

#include <stdio.h>

// ===========================================================================================
// Dynamic Array

#pragma once

// ===========================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>          // malloc, free
#include <crtdbg.h>

// ===========================================================================================
// Defines

#define _CRTDBG_MAP_ALLOC

// ===========================================================================================
// Types

struct DynamicIntArray
{
    int* m_ptr;
    size_t  m_length;
};

// ===========================================================================================
// Function Prototypes

void initDynamicIntArray(struct DynamicIntArray* array, size_t length);
void createDynamicIntArrayFromArray(struct DynamicIntArray* array, int* values, int length);

void createDynamicIntArrayFromDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other);

void fillDynamicIntArray(struct DynamicIntArray* array, int value);
size_t getLength(struct DynamicIntArray* array);
int get(struct DynamicIntArray* array, int index);
void set(struct DynamicIntArray* array, int index, int value);
void releaseDynamicIntArray(struct DynamicIntArray* array);

int resizeDynamicIntArray(struct DynamicIntArray* array, int newLength);
int shrinkToFitDynamicIntArray(struct DynamicIntArray* array);

int minimum(struct DynamicIntArray* array);
int maximum(struct DynamicIntArray* array);
int indexOf(struct DynamicIntArray* array, int value);
int equalsDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other);
int containsDynamicIntArray(struct DynamicIntArray* array, int value);
void printDynamicIntArray(struct DynamicIntArray* array);

// ===========================================================================================


// =====================================================================================
// End-of-File
// =====================================================================================
