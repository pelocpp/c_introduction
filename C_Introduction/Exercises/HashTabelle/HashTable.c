// =====================================================================================
// HashTable.c
// =====================================================================================

// defines
#define _CRTDBG_MAP_ALLOC

// includes
#include "HashTable.h"

#include <crtdbg.h>   // _CrtSetDbgFlag
#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free
#include <string.h>   // strncpy_s

// internal helper functions
static size_t hash                   (size_t key, size_t length);
static void   printFirstTableElement (size_t i, Element* element);
static void   printTableElement      (Element* element);

// implementation of public interface
void initHashTable(Element* table[], size_t length)
{
    for (int i = 0; i < length; ++i) {
        table[i] = NULL;
    }
}

int insertKeyValue(Element* table[], size_t length, size_t key, const char* value)
{
    size_t len = strlen(value);
    if (len >= MaxValueSize) {
        printf("Value %s too long!\n", value);
        return 0;
    }

    size_t index = hash(key, length);

    // check for existing key in chain and update value if found
    for (Element* elem = table[index]; elem != NULL; elem = elem->m_next) {
        if (elem->m_key == key) {
            // update existing value
            strncpy_s(elem->m_value, MaxValueSize, value, len);
            return 1;
        }
    }

    Element* ptrElement = malloc(sizeof(Element));
    if (ptrElement == (Element*)0) {
        printf("Out of memory!\n");
        return 0;
    }

    // initialize Element variable
    ptrElement->m_key = key;
    strncpy_s(ptrElement->m_value, MaxValueSize, value, len);
    ptrElement->m_next = NULL;

    // insert Element variable into table
    if (table[index] == NULL) {
        // slot is empty
        table[index] = ptrElement;
    }
    else {
        // insert element at begin of chain
        Element* tmp = table[index];
        table[index] = ptrElement;
        ptrElement->m_next = tmp;
    }

    return 1;
}

int searchValue(Element* table[], size_t length, size_t key, Element* elem)
{
    size_t index = hash(key, length);

    for (Element* ptrElement = table[index]; ptrElement != NULL; ptrElement = ptrElement->m_next) {

        if (ptrElement->m_key == key) {

            *elem = *ptrElement;
            elem->m_next = NULL;
            return 1;
        }
    }

    return 0;
}

void printHashTable(Element* table[], size_t length)
{
    Element* element;

    printf("Index |  Key   | Value\n");
    printf("======|========|======\n");

    for (size_t i = 0; i != length; ++i) {

        if (table[i] != NULL) {

            element = table[i];
            printFirstTableElement(i, element);

            while (element->m_next != NULL) {

                printTableElement(element->m_next);
                element = element->m_next;
            }

            printf("\n");
        }
    }
    printf("\n");
}

void releaseHashTable(Element* table[], size_t length)
{
    for (size_t i = 0; i != length; ++i) {

        Element* element = table[i];
        while (element != NULL) {

            Element* current = element;
            element = element->m_next;
            free(current);
        }
    }
}

// implementation of internal (static ) helper functions
static size_t hash(size_t key, size_t length) {
    return key % length;
}

static void printFirstTableElement(size_t i, Element* element) {
    printf("%5zu | %6zu | %5s", i, element->m_key, element->m_value);
}

static void printTableElement(Element* element) {
    printf("   ==>  %6zu | %5s", element->m_key, element->m_value);
}

// =====================================================================================
// End-of-File
// =====================================================================================
