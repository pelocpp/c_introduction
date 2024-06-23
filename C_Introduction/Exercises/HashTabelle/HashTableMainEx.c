// =====================================================================================
// HashTableMain.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>

#include "HashTableEx.h"

// global variable
Element* hashTableEx[Limit] = { NULL };

void exercise_hash_table_ex()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    initHashTableEx(hashTableEx, Limit);
    fillHashTableEx(hashTableEx);
    printHashTableEx(hashTableEx, Limit);

    char* key = "Anton";
    Element* result;
    size_t pos;
    searchEx(key, hashTableEx, &result, &pos);
    if (result != NULL) {
        printf("Key %s: Value = %s\n", key, result->m_value);
    }
    else {
        printf("Key %s not found!\n", key);
    }

    key = "Fritz";
    searchEx(key, hashTableEx, &result, &pos);
    if (result != NULL) {
        printf("Key %s: Value = %s\n", key, result->m_value);
    }
    else {
        printf("Key %s not found!\n", key);
    }

    releaseHashTableEx(hashTableEx, Limit);
}

// =====================================================================================
// End-of-File
// =====================================================================================
