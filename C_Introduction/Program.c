// =====================================================================================
// C Introduction
// Program.c
// Entry Point for all Examples
// 
// https://github.com/pelocpp
// https://peterloos.de
// =====================================================================================

#pragma message("Collection of introductory C Code Examples - Copyright (C) 2024 Peter Loos")

#include <stdio.h>

// function prototypes
extern void mainHelloWorld();
extern void mainDatatypesVariablesConstants();
extern void mainOperators();
extern void mainControlStructures();
extern void mainArrays();
extern void mainSubroutines();
extern void mainNestedScope();
extern void mainPointer();
extern void mainMemoryManagement();
extern void mainDynamic();
extern void mainStrings();
extern void mainStructs();
extern void mainCrt();

extern void exercises();

// entry point
int main()
{
    printf("[Collection of introductory C Code Examples - Copyright (C) 2024 Peter Loos]\n");

    // main entry points code examples
    mainHelloWorld();
    mainDatatypesVariablesConstants();
    mainOperators();
    mainControlStructures();
    mainArrays();
    mainSubroutines();
    mainNestedScope();
    mainPointer();
    mainMemoryManagement();
    mainDynamic();
    mainStrings();
    mainStructs();
    mainCrt();

    //exercises();

    printf("[Done]\n");
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
