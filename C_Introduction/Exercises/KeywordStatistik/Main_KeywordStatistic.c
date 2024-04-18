// =====================================================================================
// Main_KeywordStatistic.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "KeywordStatistic.h"

#define   FILE_NAME      "C:\\Development\\GitRepositoryCPlusPlus\\"\
                         "C_Introduction\\C_Introduction\\Exercises\\"\
                         "KeywordStatistik\\KeywordStatistic.c"


// global data
KeywordStatistic table[NUM_KEYWORDS];

void exercise_keywordstatistik()
{
    FILE* fp;
    char buffer[BUF_SIZE];

    KeywordStatistic table[NUM_KEYWORDS];

    InitTable(table);

    fp = fopen(FILE_NAME, "r");
    if (fp == (FILE*)NULL)
    {
        printf("File not found!\n");
        return;
    }

    while (fgets(buffer, BUF_SIZE, fp) != NULL)
    {
        ScanLine(buffer);
    }
    fclose(fp);

    PrintTable(table);
}

// =====================================================================================
// End-of-File
// =====================================================================================
