// =====================================================================================
// HashTable.h
// =====================================================================================

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
    size_t             m_key;
    char               m_value[6];
    struct Element*    m_next;
};

// global variables
extern struct Element* hashTable[Limit];

// functions
size_t hash(size_t key);
void   initHashTable           (struct Element* table[], int length);
void   fillHashTable           (struct Element* table[], int length);
void   insert                  (struct Element* table[], int length, struct Element element);
int    search                  (size_t key, struct Element* table[], struct Element** result, size_t* pos);
void   printFirstTableElement  (size_t i, struct Element* element);
void   printTableElement       (struct Element* element);
void   printHashTable          (struct Element* table[], int length);
void   releaseHashTable        (struct Element* table[], int length);

// =====================================================================================
// End-of-File
// =====================================================================================
