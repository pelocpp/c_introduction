// ===========================================================================
// DynamicMemory.c // malloc and free
// ===========================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free
#include <crtdbg.h>

static void dynamic_01()
{
    // eine int Variable auf der Halde / auf dem Heap anlegen

    int* ip = (int*) malloc(sizeof(int));

    *ip = 123;

    printf("Ein Wert auf dem Heap: %d\n", *ip);

    free(ip);
}

static void dynamic_02()
{
    // eine int Variable auf der Halde / auf dem Heap anlegen

    int* ip = (int*) malloc(sizeof(int));

    if (ip != NULL) {

        *ip = 123;

        printf("Ein Wert auf dem Heap: %d\n", *ip);

        free(ip);
    }
    else {

        printf("Out of memory !\n");
    }
}

static void dynamic_03()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // eine int Variable auf der Halde / auf dem Heap anlegen

    int* ip = (int*) malloc(sizeof(int));

    *ip = 123;

    printf("Ein Wert auf dem Heap: %d\n", *ip);

    // _CrtDumpMemoryLeaks();

    free(ip);
}

// ================================================================

static void tueWasMitDenDaten(int* data)
{
    printf("tueWasMitDenDaten: %d\n", *data);

    // free(data); 
}

static void dynamic_04()
{
    int* ip = (int*)malloc(sizeof(int));

    *ip = 123;

    printf("Ein Wert auf dem Heap: %d\n", *ip);

    tueWasMitDenDaten(ip);

    printf("Ein Wert auf dem Heap: %d\n", *ip);

    free(ip);
}

// ================================================================

#define Length 10

static void dynamic_05()
{
    // ein Feld auf dem Heap anlegen

    int* ip = (int*) malloc(Length * sizeof(int));

    // mit dem Array arbeiten

    // a) Mit Zeigern arbeiten
    for (int i = 0; i < Length; i++) {
        *(ip + i) = 2 * i;
    }

    // b) In der Notation / Syntax eines Felds arbeiten
    for (int i = 0; i < Length; i++) {
        ip[i] = 2 * i;
    }

    // c) Feld ausgeben
    for (int i = 0; i < Length; i++) {
        // printf("Wert an %d: %d\n", i, ip[i]);
        printf("%02d: %d\n", i, *(ip + i));
    }

    free(ip);
}

// ================================================================

static void initData(int* data, int length)
{
    // a) Vorbelegen, mit Zeiger-Arithmetik
    for (int i = 0; i < length; ++i) {
        *(data + i) = 2 * i;
    }

    // b) Vorbelegen, mit Index-Operator
    for (int i = 0; i < length; ++i) {
        data[i] = 2 * i;
    }
}

static void printData(int* data, int length)
{
    // a) ausgeben, mit Zeiger-Arithmetik
    for (int i = 0; i < length; ++i) {
        printf("%02d: %3d\n", i, *(data + i));
    }

    // b) ausgeben, mit Index-Operator
    for (int i = 0; i < length; ++i) {
        printf("%02d: %3d\n", i, data[i]);
    }
}

// oder

static void initData1(int data[], int length)
{
    // a) Vorbelegen, mit Zeiger-Arithmetik
    for (int i = 0; i < length; ++i) {
        *(data + i) = 2 * i;
    }

    // b) Vorbelegen, mit Index-Operator
    for (int i = 0; i < length; ++i) {
        data[i] = 2 * i;
    }
}

static void printData1(int data[], int length)
{
    // a) ausgeben, mit Zeiger-Arithmetik
    for (int i = 0; i < length; ++i) {
        printf("%02d: %3d\n", i, *(data + i));
    }

    // b) ausgeben, mit Index-Operator
    for (int i = 0; i < length; ++i) {
        printf("%02d: %3d\n", i, data[i]);
    }
}

static void dynamic_06()
{
    // ein Feld auf dem Heap anlegen
    int* ip = (int*) malloc(Length * sizeof(int));

    // mit dem Feld arbeiten
    initData(ip, Length);
    printData(ip, Length);

    // mit dem Feld arbeiten
    initData1(ip, Length);
    printData1(ip, Length);

    // Feld freigeben
    free(ip);
}

// ================================================================

void testDynamic()
{
    dynamic_01();
    dynamic_02();
    dynamic_03();
    dynamic_04();
    dynamic_05();
    dynamic_06();
}

// ===========================================================================
// End-of-File
// ===========================================================================
