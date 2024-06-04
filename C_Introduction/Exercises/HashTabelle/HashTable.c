// =====================================================================================
// HashTable.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// defines
#define Limit       11
#define MaxContents 20

// types
struct Element
{
    size_t m_key;
    char* m_value;
    struct Element* m_next;
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

// To be Done:
// Die Tabelle freigeben ... malloc ==> free ...

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
    struct Element element;

    srand(0);

    for (size_t i = 0; i < MaxContents; ++i) {
        size_t key = 1 + rand() % 32767;
        char ch = 'A' + i % 26;

        element.m_key = key;
        element.m_value[0] = ch;
        element.m_value[1] = '\0';
    
        // static void insert(struct Element* table[], int length, struct Element* element);
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

static void printTable(struct Element* table[], int length)
{
    struct Element* element;

    printf("Index | Key | Value\n");
    printf("======|=====|======\n");
    printf("\n");

    for (int i = 0; i < length; ++i) {

        if (table[i] != NULL) {

            element = table[i];

            while (element != NULL) {

                printf("%2d | %5zu | %s\n", i, element->m_key, element->m_value);
                element = element->m_next;
            }
        }
    }
}

static void insert(struct Element* table[], int length, struct Element element)
{
    size_t index = hash(element.m_key);

    element.m_next = NULL;

    if (table[index] == NULL) {

    }
    else {

    }
}

void exercise_hash_table()
{
    initTable(hashTable, Limit);
    printTable(hashTable, Limit);
}

// =====================================================================================
// End-of-File
// =====================================================================================
