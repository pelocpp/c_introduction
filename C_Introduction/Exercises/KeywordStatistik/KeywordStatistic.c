// =====================================================================================
// KeywordStatistic.c
// =====================================================================================

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "KeywordStatistic.h"

void initKeywordTable()
{
    int i;

    // traverse table
    for (i = 0; i < NUM_KEYWORDS; i++)
        statisticsTable[i].count = 0;

    strcpy_s(statisticsTable[0].identifier, MAX_KEYWORD_LENGTH, "auto");
    strcpy_s(statisticsTable[1].identifier, MAX_KEYWORD_LENGTH, "break");
    strcpy_s(statisticsTable[2].identifier, MAX_KEYWORD_LENGTH, "case");
    strcpy_s(statisticsTable[3].identifier, MAX_KEYWORD_LENGTH, "char");
    strcpy_s(statisticsTable[4].identifier, MAX_KEYWORD_LENGTH, "const");
    strcpy_s(statisticsTable[5].identifier, MAX_KEYWORD_LENGTH, "continue");
    strcpy_s(statisticsTable[6].identifier, MAX_KEYWORD_LENGTH, "default");
    strcpy_s(statisticsTable[7].identifier, MAX_KEYWORD_LENGTH, "do");
    strcpy_s(statisticsTable[8].identifier, MAX_KEYWORD_LENGTH, "double");
    strcpy_s(statisticsTable[9].identifier, MAX_KEYWORD_LENGTH, "else");
    strcpy_s(statisticsTable[10].identifier, MAX_KEYWORD_LENGTH, "enum");
    strcpy_s(statisticsTable[11].identifier, MAX_KEYWORD_LENGTH, "extern");
    strcpy_s(statisticsTable[12].identifier, MAX_KEYWORD_LENGTH, "float");
    strcpy_s(statisticsTable[13].identifier, MAX_KEYWORD_LENGTH, "for");
    strcpy_s(statisticsTable[14].identifier, MAX_KEYWORD_LENGTH, "goto");
    strcpy_s(statisticsTable[15].identifier, MAX_KEYWORD_LENGTH, "if");
    strcpy_s(statisticsTable[16].identifier, MAX_KEYWORD_LENGTH, "int");
    strcpy_s(statisticsTable[17].identifier, MAX_KEYWORD_LENGTH, "long");
    strcpy_s(statisticsTable[18].identifier, MAX_KEYWORD_LENGTH, "register");
    strcpy_s(statisticsTable[19].identifier, MAX_KEYWORD_LENGTH, "return");
    strcpy_s(statisticsTable[20].identifier, MAX_KEYWORD_LENGTH, "short");
    strcpy_s(statisticsTable[21].identifier, MAX_KEYWORD_LENGTH, "signed");
    strcpy_s(statisticsTable[22].identifier, MAX_KEYWORD_LENGTH, "sizeof");
    strcpy_s(statisticsTable[23].identifier, MAX_KEYWORD_LENGTH, "static");
    strcpy_s(statisticsTable[24].identifier, MAX_KEYWORD_LENGTH, "struct");
    strcpy_s(statisticsTable[25].identifier, MAX_KEYWORD_LENGTH, "switch");
    strcpy_s(statisticsTable[26].identifier, MAX_KEYWORD_LENGTH, "typedef");
    strcpy_s(statisticsTable[27].identifier, MAX_KEYWORD_LENGTH, "union");
    strcpy_s(statisticsTable[28].identifier, MAX_KEYWORD_LENGTH, "unsigned");
    strcpy_s(statisticsTable[29].identifier, MAX_KEYWORD_LENGTH, "void");
    strcpy_s(statisticsTable[30].identifier, MAX_KEYWORD_LENGTH, "volatile");
    strcpy_s(statisticsTable[31].identifier, MAX_KEYWORD_LENGTH, "while");
}

void printKeywordTable()
{
    printf("Keyword Table:\n");
    printf("==============\n\n");

    // traverse table
    for (int i = 0; i < NUM_KEYWORDS; i++)
    {
        if (statisticsTable[i].count > 0)
            printf("%12s: %3d\n", statisticsTable[i].identifier, statisticsTable[i].count);
    }
    printf("\n");
}

void scanLine(char* line)
{
    int i;
    int first, last;
    int index;
    char buffer[64];

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        // check for begin of token
        if (islower(line[i]) || isupper(line[i]))
        {
            // store begin of token index
            first = i;
            i++;

            // check for end of token
            while (line[i] != '\0' && (islower(line[i]) || isupper(line[i])))
                i++;

            // adjust end of token index
            last = i - 1;

            // copy identifier into temporary buffer using C-Runtime Library
            strncpy_s (buffer, 64, line + first, last - first + 1);

            // search identifier in keyword table
            index = isKeyword(buffer);
            if (index >= 0) {
                statisticsTable[index].count++;
            }
        }
        else
        {
            i++;
        }
    }
}

static int isKeyword(char* id)
{
    size_t len = strlen(id);
    if (len == 0 || len == 1 || len > 8)
        return -1;

    if (id[0] < 'a' || id[0] > 'z')
        return -1;

    // linear search
    for (int i = 0; i < NUM_KEYWORDS; i++)
    {
        if (strcmp(id, statisticsTable[i].identifier) == 0)
            return i;
    }

    return -1;
}

// =====================================================================================
// End-of-File
// =====================================================================================
