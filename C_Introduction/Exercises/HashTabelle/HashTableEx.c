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

#include "HashTableEx.h"

// implementation
static size_t hash(char key[]) {

    size_t hash_value = 0;
    const char* ptr = key;
    while (*ptr != '\0') {
        hash_value += *ptr;
        ptr++;
    }

    return hash_value % Limit;
}


void initHashTableEx(Element* table[], int length)
{
    for (int i = 0; i < length; ++i) {
        table[i] = NULL;
    }
}

void fillHashTableEx(Element* table[])
{
    Element element = { "", "", NULL };

    strcpy_s(element.m_key, sizeof (element.m_key), "Fritz");
    strcpy_s(element.m_value, sizeof (element.m_value), "fritz.meier@gmx.de");
    insert(table, element);

    strcpy_s(element.m_key, sizeof(element.m_key), "Hans");
    strcpy_s(element.m_value, sizeof(element.m_value), "hans.mueller@yahoo.com");
    insert(table, element);

    strcpy_s(element.m_key, sizeof(element.m_key), "Sepp");
    strcpy_s(element.m_value, sizeof(element.m_value), "sepp.vogel@gmail.com");
    insert(table, element);
}

int searchEx(char key[], Element* table[], Element** result, size_t* pos)
{
    size_t index;
    Element* element;

    index = hash(key);

    for (element = table[index]; element != NULL; element = element->m_next) {

        // if (element->m_key == key) {
        if (strcmp (element->m_key, key) == 0) {

            *result = element;
            *pos = index;
            return 1;
        }
    }

    *result = NULL;
    return 0;
}

static void printFirstTableElement(size_t i, Element* element) {
    printf("%5zu | %6s | %s", i, element->m_key, element->m_value);
}

static void printTableElement(Element* element) {
    printf("   ==>  %6s | %s", element->m_key, element->m_value);
}

void printHashTableEx(Element* table[], int length)
{
    Element* element;

    printf("Index |  Key   | Value\n");
    printf("======|========|======\n");
    printf("\n");

    for (size_t i = 0; i != length; ++i) {

        if (table[i] != NULL) {

            element = table[i];
            printFirstTableElement(i, element);
            printf("\n");

            while (element->m_next != NULL) {

                printTableElement(element->m_next);
                element = element->m_next;
            }

            printf("\n");
        }
    }
    printf("\n");
}

static void insert(Element* table[], Element element)
{
    size_t index = hash(element.m_key);

    element.m_next = NULL;

    if (table[index] == NULL) {

        Element* ptrElement = malloc(sizeof(Element));
        if (ptrElement == (Element*)0) {
            exit(1);
        }

        memcpy(ptrElement, &element, sizeof(Element));
        table[index] = ptrElement;
    }
    else {

        // search end of chain
        Element* ptrElement = NULL;

        int length = 0;

        for (ptrElement = table[index]; ptrElement->m_next != NULL; ptrElement = ptrElement->m_next) {
            length++;
        }

        Element* ptr = malloc(sizeof(Element));
        if (ptr == (Element*)0) {
            exit(1);
        }

        ptrElement->m_next = ptr;
        memcpy(ptr, &element, sizeof(Element));
    }
}

void releaseHashTableEx(Element* table[], int length)
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
