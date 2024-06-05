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

// defines
#define  Limit         11
#define  MaxContents   20

// types
struct Element
{
    size_t            m_key;
    char              m_value[6];
    struct Element*   m_next;
};

// global variables
struct Element* hashTable[Limit] = { NULL };

// functions
size_t hash(size_t key);
static void initTable(struct Element* table[], int length);
static void fillTable(struct Element* table[], int length);
static void insert(struct Element* table[], int length, struct Element element);
int search(size_t key, struct Element* table[], struct Element** result, size_t* pos);
void printTable(struct Element* table[], int length);
static void releaseTable(struct Element* table[], int length);

// implementation
static size_t hash(size_t key) {
    return key % Limit;
}

static void initTable(struct Element* table[], int length)
{
    for (int i = 0; i < length; ++i) {
        table[i] = NULL;
    }
}

static void fillTable(struct Element* table[], int length)
{
    struct Element element = { 0, "", NULL};

    srand(0);

    for (size_t i = 0; i < MaxContents; ++i) {

        size_t key = 1 + rand() % 32767;
        
        char ch = 'A' + i % 26;

        element.m_key = key;
        element.m_value[0] = ch;
        element.m_value[1] = '\0';
    
        insert(table, Limit, element);
    }
}

static int search(size_t key, struct Element* table[], struct Element** result, size_t* pos)
{
    size_t index;
    struct Element* element;

    index = hash(key);

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

static void printFirstTableElement(size_t i, struct Element* element) {
    printf("%5zu | %6zu | %s", i, element->m_key, element->m_value);
}

static void printTableElement(struct Element* element) {
    printf("   ==>  %6zu | %s", element->m_key, element->m_value);
}

static void printTable(struct Element* table[], int length)
{
    struct Element* element;

    printf("Index |  Key   | Value\n");
    printf("======|========|======\n");
    printf("\n");

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
}

static void insert(struct Element* table[], int length, struct Element element)
{
    size_t index = hash(element.m_key);

    element.m_next = NULL;

    if (table[index] == NULL) {

        struct Element* ptrElement = malloc(sizeof(struct Element));
        if (ptrElement == (struct Element*) 0) {
            exit(1);
        }

        memcpy(ptrElement, &element, sizeof(struct Element));
        table[index] = ptrElement;
    }
    else {

        // search end of chain
        struct Element* ptrElement = NULL;

        int length = 0;

        for (ptrElement = table[index]; ptrElement->m_next != NULL; ptrElement = ptrElement->m_next) {
            length++;
        }

        struct Element* ptr = malloc(sizeof(struct Element));
        if (ptr == (struct Element*)0) {
            exit(1);
        }

        ptrElement->m_next = ptr;
        memcpy(ptr, &element, sizeof(struct Element));
    }
}

static void releaseTable(struct Element* table[], int length)
{
    for (size_t i = 0; i != length; ++i) {

        struct Element* element = table[i];

        while (element != NULL) {

            struct Element* current = element;

            element = element->m_next;

            free(current);
        }
    }
}

void exercise_hash_table()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    initTable(hashTable, Limit);
    fillTable(hashTable, Limit);
    printTable(hashTable, Limit);
    releaseTable(hashTable, Limit);
}

// =====================================================================================
// End-of-File
// =====================================================================================
