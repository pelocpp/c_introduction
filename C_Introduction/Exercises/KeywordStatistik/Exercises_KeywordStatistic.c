// =====================================================================================
// Exercises_KeywordStatistic.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "KeywordStatistic.h"


#define FILE_NAME     "..\\C_Introduction\\Exercises\\KeywordStatistik\\KeywordStatistic.c"

#define FILE_NAME_1   "C:\\Development\\GitRepositoryCPlusPlus\\"\
                      "C_Introduction\\C_Introduction\\Exercises\\"\
                      "KeywordStatistik\\KeywordStatistic.c"

// global data
KeywordStatistic statisticsTable[NUM_KEYWORDS] = { 0 };

void exercise_keywordstatistik()
{
    FILE* fp;
    char buffer[BUF_SIZE];

    KeywordStatistic table[NUM_KEYWORDS];

    initKeywordTable(table);

    fp = fopen(FILE_NAME_1, "r");
    if (fp == (FILE*) 0)
    {
        printf("File not found!\n");
        return;
    }

    while (fgets(buffer, BUF_SIZE, fp) != NULL)
    {
        scanLine(buffer);
    }
    fclose(fp);

    printKeywordTable();
}

// =====================================================================================
// End-of-File
// =====================================================================================
