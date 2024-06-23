// =====================================================================================
// KeywordStatisticMain.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "KeywordStatistic.h"

#define   FILE_NAME   "C:\\Development\\GitRepositoryCPlusPlus\\"\
                      "C_Introduction\\C_Introduction\\Exercises\\"\
                      "KeywordStatistik\\KeywordStatistic.c"


// global data
KeywordStatistic statisticsTable[NUM_KEYWORDS] = {};

void exercise_keywordstatistik()
{
    FILE* fp;
    char buffer[BUF_SIZE];

    KeywordStatistic table[NUM_KEYWORDS];

    initKeywordTable(table);

    fp = fopen(FILE_NAME, "r");
    if (fp == (FILE*)NULL)
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