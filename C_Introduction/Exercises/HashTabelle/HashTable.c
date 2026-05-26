// =====================================================================================
// HashTable.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

// #includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <crtdbg.h>

#include "HashTable.h"

// internal helper functions
static size_t hash(size_t key, size_t length);
static void   printFirstTableElement(size_t i, Element* element);
static void   printTableElement(Element* element);

// implementation
static size_t hash(size_t key, size_t length) {
    return key % length;
}

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

    Element* ptrElement = malloc(sizeof(Element));
    if (ptrElement == (Element*)0) {
        printf("Out of memory!\n");
        exit(1);
    }

    ptrElement->m_key = key;
    strncpy_s(ptrElement->m_value, MaxValueSize, value, len);
    ptrElement->m_next = NULL;

  //  table[index] = ptrElement;

    if (table[index] == NULL) {

        table[index] = ptrElement;
    }
    else {

        // insert element at begin of chain
        Element* tmp = table[index];

        table[index] = ptrElement;

        ptrElement->m_next = tmp;




        //// search end of chain
        //Element* ptrElement = NULL;

        //size_t length = 0;

        //for (ptrElement = table[index]; ptrElement->m_next != NULL; ptrElement = ptrElement->m_next) {
        //    length++;
        //}

        //Element* ptr = malloc(sizeof(Element));
        //if (ptr == (Element*)0) {
        //    printf("Out of memory!\n");
        //    exit(1);
        //}

        //ptrElement->m_next = ptr;
        //memcpy(ptr, &element, sizeof(Element));
    }


    return 1;
}

static void insertElement(Element* table[], size_t length, Element element)
{
    size_t index = hash(element.m_key, length);

    element.m_next = NULL;

    if (table[index] == NULL) {

        Element* ptrElement = malloc(sizeof(Element));
        if (ptrElement == (Element*) 0) {
            printf("Out of memory!\n");
            exit(1);
        }

        memcpy(ptrElement, &element, sizeof(Element));
        table[index] = ptrElement;
    }
    else {

        // search end of chain
        Element* ptrElement = NULL;

        size_t length = 0;

        for (ptrElement = table[index]; ptrElement->m_next != NULL; ptrElement = ptrElement->m_next) {
            length++;
        }

        Element* ptr = malloc(sizeof(Element));
        if (ptr == (Element*) 0) {
            printf("Out of memory!\n");
            exit(1);
        }

        ptrElement->m_next = ptr;
        memcpy(ptr, &element, sizeof(Element));
    }
}

int search(Element* table[], size_t length, size_t key, Element** result, size_t* pos)
{
    size_t index;
    Element* element;

    index = hash(key, length);

    for (element = table[index]; element != NULL; element = element->m_next) {

        if (element->m_key == key) {

            *result = element;
            *pos = index;
            return 1;
        }
    }

    *result = NULL;
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

static void printFirstTableElement(size_t i, Element* element) {
    printf("%5zu | %6zu | %5s", i, element->m_key, element->m_value);
}

static void printTableElement(Element* element) {
    printf("   ==>  %6zu | %5s", element->m_key, element->m_value);
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

// =====================================================================================
// End-of-File
// =====================================================================================

//void fillHashTable(Element* table[])
//{
//    Element element = { 0, "", NULL };
//
//    element.m_key = 0;
//    element.m_value[0] = '7';
//    element.m_value[1] = '7';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 2;
//    element.m_value[0] = '9';
//    element.m_value[1] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 5;
//    element.m_value[0] = '4';
//    element.m_value[1] = '0';
//    element.m_value[2] = '\0';
//
//    insert(table, element);
//}
//
//void fillHashTable2(Element* table[])
//{
//    Element element = { 0, "", NULL };
//
//    element.m_key = 13;
//    element.m_value[0] = '1';
//    element.m_value[1] = '3';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 19;
//    element.m_value[0] = '1';
//    element.m_value[1] = '9';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 34;
//    element.m_value[0] = '3';
//    element.m_value[1] = '4';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 43;
//    element.m_value[0] = '4';
//    element.m_value[1] = '3';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//
//    element.m_key = 92;
//    element.m_value[0] = '9';
//    element.m_value[1] = '2';
//    element.m_value[2] = '\0';
//
//    insertElement(table, element);
//}
//
