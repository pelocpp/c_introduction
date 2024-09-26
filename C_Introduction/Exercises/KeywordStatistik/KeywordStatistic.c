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
        statisticsTable[i].m_count = 0;

    statisticsTable[ 0].m_identifier = "auto";
    statisticsTable[ 1].m_identifier = "break";
    statisticsTable[ 2].m_identifier = "case";
    statisticsTable[ 3].m_identifier = "char";
    statisticsTable[ 4].m_identifier = "const";
    statisticsTable[ 5].m_identifier = "continue";
    statisticsTable[ 6].m_identifier = "default";
    statisticsTable[ 7].m_identifier = "do";
    statisticsTable[ 8].m_identifier = "double";
    statisticsTable[ 9].m_identifier = "else";
    statisticsTable[10].m_identifier = "enum";
    statisticsTable[11].m_identifier = "extern";
    statisticsTable[12].m_identifier = "float";
    statisticsTable[13].m_identifier = "for";
    statisticsTable[14].m_identifier = "goto";
    statisticsTable[15].m_identifier = "if";
    statisticsTable[16].m_identifier = "int";
    statisticsTable[17].m_identifier = "long";
    statisticsTable[18].m_identifier = "register";
    statisticsTable[19].m_identifier = "return";
    statisticsTable[20].m_identifier = "short";
    statisticsTable[21].m_identifier = "signed";
    statisticsTable[22].m_identifier = "sizeof";
    statisticsTable[23].m_identifier = "static";
    statisticsTable[24].m_identifier = "struct";
    statisticsTable[25].m_identifier = "switch";
    statisticsTable[26].m_identifier = "typedef";
    statisticsTable[27].m_identifier = "union";
    statisticsTable[28].m_identifier = "unsigned";
    statisticsTable[29].m_identifier = "void";
    statisticsTable[30].m_identifier = "volatile";
    statisticsTable[31].m_identifier = "while";
}

void printKeywordTable()
{
    printf("Keyword Table:\n");
    printf("==============\n\n");

    // traverse table
    for (int i = 0; i < NUM_KEYWORDS; i++)
    {
        if (statisticsTable[i].m_count > 0)
            printf("%12s: %3d\n", statisticsTable[i].m_identifier, statisticsTable[i].m_count);
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
                statisticsTable[index].m_count++;
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
        if (strcmp(id, statisticsTable[i].m_identifier) == 0)
            return i;
    }

    return -1;
}

// =====================================================================================
// End-of-File
// =====================================================================================
