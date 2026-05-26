// =====================================================================================
// HashTableMainInt.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>

#include "HashTable.h"

#define MaxTableCapacity 10

static void exercise_hash_table_with_ints_01()
{
    Element* hashTable[MaxTableCapacity] = { NULL };

    initHashTable(hashTable, MaxTableCapacity);
    releaseHashTable(hashTable, MaxTableCapacity);
}

static void exercise_hash_table_with_ints_02()
{
    Element* hashTable[MaxTableCapacity] = { NULL };

    initHashTable(hashTable, MaxTableCapacity);

    insertKeyValue(hashTable, MaxTableCapacity, 1, "Hans");
    insertKeyValue(hashTable, MaxTableCapacity, 2, "Ludwig");  // name is too long
    insertKeyValue(hashTable, MaxTableCapacity, 3, "Max");

    printHashTable(hashTable, MaxTableCapacity);

    releaseHashTable(hashTable, MaxTableCapacity);
}

void exercise_hash_table_with_ints()
{
    //exercise_hash_table_with_ints_01();
    exercise_hash_table_with_ints_02();
}



// =====================================================================================
// End-of-File
// =====================================================================================


//void exercise_hash_table_with_ints()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    initHashTable(hashTable, MaxTableCapacity);
//    fillHashTable(hashTable);
//    //fillHashTable2(hashTable);
//    printHashTable(hashTable, Limit);
//
//    size_t key = 1;
//    Element* result;
//    size_t pos;
//    search(key, hashTable, &result, &pos);
//    if (result != NULL) {
//        printf("Key %zu: Value = %s\n", key, result->m_value);
//    }
//    else {
//        printf("Key %zu not found!\n", key);
//    }
//
//    key = 0;
//    search(key, hashTable, &result, &pos);
//    if (result != NULL) {
//        printf("Key %zu: Value = %s\n", key, result->m_value);
//    }
//    else {
//        printf("Key %zu not found!\n", key);
//    }
//
//    releaseHashTable(hashTable, Limit);
//}


