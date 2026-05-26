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

static void exercise_hash_table_with_ints_03()
{
    Element* hashTable[MaxTableCapacity] = { NULL };

    initHashTable(hashTable, MaxTableCapacity);

    insertKeyValue(hashTable, MaxTableCapacity, 1, "Susan");
    insertKeyValue(hashTable, MaxTableCapacity, 2, "Hans");
    insertKeyValue(hashTable, MaxTableCapacity, 2, "Sepp");
    insertKeyValue(hashTable, MaxTableCapacity, 2, "Anton");
    insertKeyValue(hashTable, MaxTableCapacity, 3, "Eva");

    printHashTable(hashTable, MaxTableCapacity);

    releaseHashTable(hashTable, MaxTableCapacity);
}

static void exercise_hash_table_with_ints_04()
{
    Element* hashTable[MaxTableCapacity] = { NULL };

    initHashTable(hashTable, MaxTableCapacity);

    insertKeyValue(hashTable, MaxTableCapacity, 1, "Hans");
    insertKeyValue(hashTable, MaxTableCapacity, 2, "Sepp");
    insertKeyValue(hashTable, MaxTableCapacity, 3, "Anton");

    printHashTable(hashTable, MaxTableCapacity);

    size_t key = 2;
    Element elem = { 0, "", NULL };
    int found = searchValue(hashTable, MaxTableCapacity, key, &elem);
    if (found) {
        printf("Key %zu has value %s\n", key, elem.m_value);
    }

    key = 0;
    found = searchValue(hashTable, MaxTableCapacity, key, &elem);
    if (! found) {
        printf("Key %zu not found!\n", key);
    }

    releaseHashTable(hashTable, MaxTableCapacity);
}


void exercise_hash_table_with_ints()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    exercise_hash_table_with_ints_01();  // just create and release a hash table
    exercise_hash_table_with_ints_02();  // create, insert, print and release
    exercise_hash_table_with_ints_03();  // test hash table collision
    exercise_hash_table_with_ints_04();  // searching entries
}

// =====================================================================================
// End-of-File
// =====================================================================================
