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
extern void testHelloWorld();
extern void arrays();
extern void exercises();

// entry point
int main()
{
    printf("[Collection of introductory C Code Examples - Copyright (C) 2024 Peter Loos]\n");

    // main entry points code examples
    //testHelloWorld();
    //testDatatypesVariablesConstants();
    arrays();
    //exercises();

    printf("[Done]\n");
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
