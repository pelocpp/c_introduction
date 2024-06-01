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
extern void testDatatypesVariablesConstants();
extern void testControlStructures();
extern void testHelloWorld();
extern void testArrays();
extern void testSubroutines();
extern void testPointer();
extern void testMemoryManagement();
extern void testDynamic();
extern void testStrings();
extern void testStructs();
extern void testCrt();

extern void exercises();

// entry point
int main()
{
    printf("[Collection of introductory C Code Examples - Copyright (C) 2024 Peter Loos]\n");

    // main entry points code examples
    //testHelloWorld();
    //testDatatypesVariablesConstants();
    //testControlStructures();
    //testArrays();
    //testSubroutines();
    //testPointer();
    //testMemoryManagement();
    //testDynamic();
    testStrings();
    //testStructs();
    //testCrt();

    //exercises();

    printf("[Done]\n");
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
