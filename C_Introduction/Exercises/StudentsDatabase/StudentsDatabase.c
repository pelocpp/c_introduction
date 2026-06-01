// =====================================================================================
// StudentsDatabase.c
// =====================================================================================
//
//#define FILE_NAME     "..\\Students.txt"
//
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
//
//#include <stdio.h>    // printf, FILE, fopen_s, fgets, fclose
//#include <stdint.h>   // uint16_t, uint32_t
//#include <stdlib.h>   // malloc, free
//#include <string.h>   // strtok, strtoull, strtoul, strlen, strcpy_s


#include "StudentsDatabase.h"

#include <stdio.h>    // printf, FILE, fopen_s, fgets, fclose
//#include <stdint.h>   // uint16_t, uint32_t
#include <stdlib.h>   // malloc, free
#include <string.h>   // strtok, strtoull, strtoul, strlen, strcpy_s

// =================================================================================
// internal function prototypes

static void readDatabase();
static void printDatabase();
static void readDatabase();
static void sortDatabaseByName();
static void sortDatabaseByYear();

static int sortByName(const void* voidPtrA, const void* voidPtrB);
static int sortByPassingYear(const void* voidPtrA, const void* voidPtrB);

// =================================================================================
// file global variables

static Student g_students[MAX_DATABASE_SIZE];
static size_t  g_index = 0;

// =================================================================================
// implementation

static void readDatabase()
{
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, FILE_NAME, "r");

    if (fp == NULL) {
        printf("File %s not found\n", FILE_NAME);
    }
    else {
        while (1) {
            // read line by line
            char line[256];
            char* result = fgets(line, 256, fp);
            if (result == NULL) {
                break;
            }

            // remove trailing line-break '\n'
            size_t posLinebreak = strlen(line);
            line[posLinebreak - 1] = '\0';

            // read id
            char* tokenId = strtok(line, " ,");
            if (tokenId == NULL) {
                continue;
            }

            // read name
            char* tokenName = strtok(NULL, " ,");
            if (tokenName == NULL) {
                continue;
            };

            // read passing year
            char* tokenYear = strtok(NULL, " ,");
            if (tokenYear == NULL) {
                continue;
            };

            // converting id and passing year from char* to decimal value
            uint32_t id = (uint32_t) strtoull(tokenId, NULL, 10);
            uint16_t passingYear = (uint16_t) strtoul(tokenYear, NULL, 10);

            // need to allocate dynamically allocated memory for the name
            size_t nameLen = strlen(tokenName);
            char* name = (char*) malloc((nameLen + 1) * sizeof(char));
            if (name == NULL) {
                printf("Out of memory !");
                fclose(fp);
                return;
            }

            // copy name from temporary buffer to heap
            strcpy_s(name, nameLen + 1, tokenName);

            // create student record
            Student entry = { .m_id = id, .m_name = name , .m_passingYear = passingYear };

            // copy student record into students database
            g_students[g_index] = entry;
            g_index++;
        }

        fclose(fp);
    }
}

static int sortByName(const void* voidPtrA, const void* voidPtrB)
{
    const Student* studentA = (const Student*) voidPtrA;
    const Student* studentB = (const Student*)voidPtrB;

    int lena = (int) strlen(studentA->m_name);
    int lenb = (int) strlen(studentB->m_name);

    if (lena == lenb) {

        // names have same length
        for (int i = 0; i < lena; i++) {
            if (studentA->m_name[i] != studentB->m_name[i]) {
                return studentA->m_name[i] - studentB->m_name[i];
            }
        }

        // names are the same
        return 0;
    }

    // design decicion: consider the name with less character 
    // to be the lesser of two strings
    return lena - lenb;
}

static int sortByPassingYear(const void* voidPtrA, const void* voidPtrB)
{
    const Student* studentA = (const Student*) voidPtrA;
    const Student* studentB = (const Student*) voidPtrB;

    return studentA->m_passingYear - studentB->m_passingYear;
}

static void sortDatabaseByName()
{
    qsort(g_students, g_index, sizeof(struct student), sortByName);
}

static void sortDatabaseByYear()
{
    qsort(g_students, g_index, sizeof(struct student), sortByPassingYear);
}

static void printDatabase()
{
    for (int i = 0; i < MAX_DATABASE_SIZE; i++) {
        if (g_students[i].m_id != 0) {
            printf("Id: %3u: %12s - Passing Year: %5d\n", 
                g_students[i].m_id, g_students[i].m_name, g_students[i].m_passingYear);
        }
    }
    printf("\n");
}

static void releaseDatabase()
{
    for (int i = 0; i < MAX_DATABASE_SIZE; i++) {
        if (g_students[i].m_name != NULL) {
            free((char*) g_students[i].m_name);
        }
    }
}


void run_students_database()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    readDatabase();
    printDatabase();

    // sort by name
    printf("Students sorted by name:\n\n");
    sortDatabaseByName();
    printDatabase();

    // sort by passing year
    printf("\nStudents sorted by passing year:\n\n");
    sortDatabaseByYear();
    printDatabase();

    releaseDatabase();
}

// =====================================================================================
// End-of-File
// =====================================================================================
