// =====================================================================================
// HashTableMain.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include "HashTable.h"

void exercise_hash_table()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    initHashTable(hashTable, Limit);
    fillHashTable(hashTable, Limit);
    printHashTable(hashTable, Limit);
    releaseHashTable(hashTable, Limit);
}

// =====================================================================================
// End-of-File
// =====================================================================================
