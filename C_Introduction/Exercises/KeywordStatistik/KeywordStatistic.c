// =====================================================================================
// KeywordStatistic.c
// =====================================================================================

// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "KeywordStatistic.h"

void InitTable()
{
    int i;

    // traverse table
    for (i = 0; i < NUM_KEYWORDS; i++)
        table[i].count = 0;

    strcpy_s(table[0].identifier, MAX_KEYWORD_LENGTH, "auto");
    strcpy_s(table[1].identifier, MAX_KEYWORD_LENGTH, "break");
    strcpy_s(table[2].identifier, MAX_KEYWORD_LENGTH, "case");
    strcpy_s(table[3].identifier, MAX_KEYWORD_LENGTH, "char");
    strcpy_s(table[4].identifier, MAX_KEYWORD_LENGTH, "const");
    strcpy_s(table[5].identifier, MAX_KEYWORD_LENGTH, "continue");
    strcpy_s(table[6].identifier, MAX_KEYWORD_LENGTH, "default");
    strcpy_s(table[7].identifier, MAX_KEYWORD_LENGTH, "do");
    strcpy_s(table[8].identifier, MAX_KEYWORD_LENGTH, "double");
    strcpy_s(table[9].identifier, MAX_KEYWORD_LENGTH, "else");
    strcpy_s(table[10].identifier, MAX_KEYWORD_LENGTH, "enum");
    strcpy_s(table[11].identifier, MAX_KEYWORD_LENGTH, "extern");
    strcpy_s(table[12].identifier, MAX_KEYWORD_LENGTH, "float");
    strcpy_s(table[13].identifier, MAX_KEYWORD_LENGTH, "for");
    strcpy_s(table[14].identifier, MAX_KEYWORD_LENGTH, "goto");
    strcpy_s(table[15].identifier, MAX_KEYWORD_LENGTH, "if");
    strcpy_s(table[16].identifier, MAX_KEYWORD_LENGTH, "int");
    strcpy_s(table[17].identifier, MAX_KEYWORD_LENGTH, "long");
    strcpy_s(table[18].identifier, MAX_KEYWORD_LENGTH, "register");
    strcpy_s(table[19].identifier, MAX_KEYWORD_LENGTH, "return");
    strcpy_s(table[20].identifier, MAX_KEYWORD_LENGTH, "short");
    strcpy_s(table[21].identifier, MAX_KEYWORD_LENGTH, "signed");
    strcpy_s(table[22].identifier, MAX_KEYWORD_LENGTH, "sizeof");
    strcpy_s(table[23].identifier, MAX_KEYWORD_LENGTH, "static");
    strcpy_s(table[24].identifier, MAX_KEYWORD_LENGTH, "struct");
    strcpy_s(table[25].identifier, MAX_KEYWORD_LENGTH, "switch");
    strcpy_s(table[26].identifier, MAX_KEYWORD_LENGTH, "typedef");
    strcpy_s(table[27].identifier, MAX_KEYWORD_LENGTH, "union");
    strcpy_s(table[28].identifier, MAX_KEYWORD_LENGTH, "unsigned");
    strcpy_s(table[29].identifier, MAX_KEYWORD_LENGTH, "void");
    strcpy_s(table[30].identifier, MAX_KEYWORD_LENGTH, "volatile");
    strcpy_s(table[31].identifier, MAX_KEYWORD_LENGTH, "while");
}

void PrintTable()
{
    printf("Keyword Table:\n");
    printf("==============\n\n");

    // traverse table
    for (int i = 0; i < NUM_KEYWORDS; i++)
    {
        if (table[i].count > 0)
            printf("%12s: %3d\n", table[i].identifier, table[i].count);
    }
    printf("\n");
}

void ScanLine(char* line)
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
         //   buffer[last - first + 1] = '\0';

            index = IsKeyword(buffer);
            if (index >= 0)
                table[index].count++;
        }
        else
        {
            i++;
        }
    }
}

//void ScanLine(char* line)
//{
//    int i;
//    int first, last;
//    int index;
//    char buffer[64];
//
//    i = 0;
//    while (line[i] != '\0' && line[i] != '\n')
//    {
//        // check for begin of token
//        if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
//        {
//            // store begin of token index
//            first = i;
//            i++;
//
//            // check for end of token
//            while (line[i] != '\0' && ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')))
//                i++;
//
//            // adjust end of token index
//            last = i - 1;
//
//            // copy identifier into temporary buffer
//            {
//                int k;
//
//                for (k = first; k <= last; k++)
//                    buffer[k - first] = line[k];
//                buffer[k - first] = '\0';
//            }
//
//            // alternative: using C-Runtime Library
//            // strncpy (buffer, line + first, last - first + 1);
//            // buffer[last - first + 1] = '\0';
//
//            index = IsKeyword(buffer);
//            if (index >= 0)
//                table[index].count++;
//        }
//        else
//        {
//            i++;
//        }
//    }
//}

int IsKeyword(char* id)
{
    size_t len = strlen(id);
    if (len == 0 || len == 1 || len > 8)
        return -1;

    if (id[0] < 'a' || id[0] > 'z')
        return -1;

    // linear search
    for (int i = 0; i < NUM_KEYWORDS; i++)
    {
        if (strcmp(id, table[i].identifier) == 0)
            return i;
    }

    return -1;
}

// =====================================================================================
// End-of-File
// =====================================================================================
