// =====================================================================================
// HashTableMainInt.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>

#include "HashTable.h"

// global variable
Element* hashTable[Limit] = { NULL };

void exercise_hash_table_with_ints()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    initHashTable(hashTable, Limit);
    fillHashTable(hashTable);
    //fillHashTable2(hashTable);
    printHashTable(hashTable, Limit);

    size_t key = 1;
    Element* result;
    size_t pos;
    search(key, hashTable, &result, &pos);
    if (result != NULL) {
        printf("Key %zu: Value = %s\n", key, result->m_value);
    }
    else {
        printf("Key %zu not found!\n", key);
    }

    key = 0;
    search(key, hashTable, &result, &pos);
    if (result != NULL) {
        printf("Key %zu: Value = %s\n", key, result->m_value);
    }
    else {
        printf("Key %zu not found!\n", key);
    }

    releaseHashTable(hashTable, Limit);
}

// =====================================================================================
// End-of-File
// =====================================================================================
