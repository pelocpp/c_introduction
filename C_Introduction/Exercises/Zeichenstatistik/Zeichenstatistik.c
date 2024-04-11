// =====================================================================================
// Zeichenstatistik.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define   BUF_SIZE       512
#define   NUM_LETTERS    26
#define   NUM_DIGITS     10

#define   FILE_NAME      "C:\\Development\\GitRepositoryCPlusPlus\\"\
                         "C_Introduction\\C_Introduction\\Exercises\\"\
                         "Zeichenstatistik\\Zeichenstatistik.c"

// function prototypes
void initLineStatistics(
    int lowers[],  // array of lower capital letters
    int uppers[],  // array of upper capital letters
    int digits[]   // array of digits
);

void computeLineStatistics(
    char line[],   // line buffer
    size_t len,    // length of line buffer
    int lowers[],  // array of lower capital letters
    int uppers[],  // array of upper capital letters
    int digits[]   // array of digits
);

void printLineStatistics(
    int lowers[],  // array of lower capital letters
    int uppers[],  // array of upper capital letters
    int digits[]   // array of digits
);

FILE* openFile(char name[]);
void closeFile(FILE* fp);

// implementation of functions
void
computeLineStatistics(
    char   line[],
    size_t len,
    int    lowers[],
    int    uppers[],
    int    digits[])
{
    int i;

    for (i = 0; i < len; i++)
    {
        char ch;

        ch = line[i];

        if (ch >= 'a' && ch <= 'z')
        {
            lowers[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            uppers[ch - 'A']++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            digits[ch - '0']++;
        }
    }
}

void
initLineStatistics(
    int lowers[],
    int uppers[],
    int digits[])
{
    int i = 0;

    for (i = 0; i < NUM_LETTERS; i++)
        lowers[i] = 0;

    for (i = 0; i < NUM_LETTERS; i++)
        uppers[i] = 0;

    for (i = 0; i < NUM_DIGITS; i++)
        digits[i] = 0;
}

void
printLineStatistics(
    int lowers[],
    int uppers[],
    int digits[])
{
    int i = 0;

    printf("Character Statistics:\n");
    printf("---------------------\n");
    printf("\n");

    printf("|%10s|%12s|\n", "Zeichen", "Haeufigkeit");
    printf("-------------------------\n");

    for (i = 0; i < NUM_LETTERS; i++)
        printf("|%10c|%12d|\n", 'a' + i, lowers[i]);
    printf("-------------------------\n");

    for (i = 0; i < NUM_LETTERS; i++)
        printf("|%10c|%12d|\n", 'A' + i, uppers[i]);
    printf("-------------------------\n");

    for (i = 0; i < NUM_DIGITS; i++)
        printf("|%10c|%12d|\n", '0' + i, digits[i]);
    printf("\n");
}

FILE* openFile(char name[])
{
    FILE* fp;

    fp = fopen(name, "r");
    if (fp == NULL)
    {
        printf("Error: File \"%s\" not found!", name);
        exit(-1);
    }

    return fp;
}

void closeFile(FILE* fp)
{
    fclose(fp);
}

void exercise_zeichenstatistik()
{
    // open file
    FILE* fp;
    char buf[BUF_SIZE];
    int lineCount;

    int lowerCaseLetters[NUM_LETTERS];
    int upperCaseLetters[NUM_LETTERS];
    int digits[NUM_DIGITS];

    initLineStatistics(
        lowerCaseLetters,
        upperCaseLetters,
        digits);

    fp = openFile(FILE_NAME);

    // read all line of this file
    lineCount = 0;
    while (fgets(buf, BUF_SIZE, fp))
    {
        // need length of line
        size_t len = strlen(buf);

        computeLineStatistics(
            buf,
            len,
            lowerCaseLetters,
            upperCaseLetters,
            digits);
    }

    closeFile(fp);

    printLineStatistics(
        lowerCaseLetters,
        upperCaseLetters,
        digits);
}

// =====================================================================================
// End-of-File
// =====================================================================================
