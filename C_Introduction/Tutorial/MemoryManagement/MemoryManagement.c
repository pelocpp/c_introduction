// ===========================================================================
// MemoryManagement.c // Memory Management
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>

int programGlobal = 123;               // globale Variable, im gesamten Programm verfügbar

static int fileGlobal = 456;           // globale Variable, aber nur in dieser Datei verfügbar

static void memoryManagement_01()
{
    printf("global:            %d\n", programGlobal);
    printf("file static:       %d\n", fileGlobal);

    programGlobal++;
    fileGlobal++;
}

static void memoryManagement_02()
{
    static int functionGlobal = 111;       // globale Variable, aber nur im Scope dieser Funktion verfügbar

    functionGlobal++;

    printf("function global:   %d\n", functionGlobal);
}

static void memoryManagement_03()
{
    auto int local1 = 0;               // lokale Variable, nur im Scope dieser Funktion verfügbar
    int local2 = 0;                    // lokale Variable, nur im Scope dieser Funktion verfügbar

    local1++;
    local2++;

    printf("local:             %d\n", local1);
    printf("local:             %d\n", local2);
}

static void memoryManagement_04()
{
    // eine int Variable auf der Halde / auf dem Heap anlegen

    int* ip = (int*)malloc(sizeof(int));
    if (ip != NULL) {

        *ip = 123;

        int n = *ip;

        printf("dynamic:           %d\n", n);
    }

    free(ip);
}


void mainMemoryManagement()
{
    memoryManagement_01();
    memoryManagement_01();

    memoryManagement_02();
    memoryManagement_02();

    memoryManagement_03();
    memoryManagement_03();

    memoryManagement_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
