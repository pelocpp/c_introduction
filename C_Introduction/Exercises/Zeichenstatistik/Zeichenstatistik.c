// =====================================================================================
// Zeichenstatistik.c
// =====================================================================================

// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define   BUF_SIZE       512
#define   NUM_LETTERS    26
#define   NUM_DIGITS     10

#define   FILE_NAME      "C:\\Development\\GitRepositoryCPlusPlus\\"\
                         "C_Introduction\\C_Introduction\\Exercises\\"\
                         "Zeichenstatistik\\Zeichenstatistik.c"

// function prototypes
static void computeLineStatistics(
    char line[],   // line buffer
    size_t len,    // length of line buffer
    int lowers[],  // array of lower capital letters
    int uppers[],  // array of upper capital letters
    int digits[]   // array of digits
);

static void printLineStatistics(
    int lowers[],  // array of lower capital letters
    int uppers[],  // array of upper capital letters
    int digits[]   // array of digits
);

static FILE* openFile(char name[]);
static void closeFile(FILE* fp);

// implementation of functions
static void
computeLineStatistics(
    char   line[],
    size_t len,
    int    lowers[],
    int    uppers[],
    int    digits[])
{
    for (int i = 0; i < len; i++)
    {
        char ch = line[i];

        if (islower(ch))
        {
            int index = ch - 'a';
            lowers[index]++;

            // oder 
            // lowers[ch - 'a']++;
        }
        else if (isupper(ch))
        {
            int index = ch - 'A';
            uppers[index]++;
        }
        else if (isdigit(ch))
        {
            int index = ch - '0';
            digits[index]++;
        }
    }
}

static void
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

    for (i = 0; i < NUM_LETTERS; i++) {
        printf("|%10c|%12d|\n", 'a' + i, lowers[i]);
    }
    printf("-------------------------\n");

    for (i = 0; i < NUM_LETTERS; i++) {
        printf("|%10c|%12d|\n", 'A' + i, uppers[i]);
    }
    printf("-------------------------\n");

    for (i = 0; i < NUM_DIGITS; i++) {
        printf("|%10c|%12d|\n", '0' + i, digits[i]);
    }
    printf("\n");
}

#if defined(_CRT_SECURE_NO_WARNINGS)

static FILE* openFile(char name[])
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

#else

static FILE* openFile(char name[])
{
    FILE* fp;
    errno_t err;

    err = fopen_s(&fp, name, "r");
    if (fp == NULL)
    {
        printf("Error: File \"%s\" not found!", name);
        exit(-1);
    }

    return fp;
}

#endif

static void closeFile(FILE* fp)
{
    fclose(fp);
}

void exercise_zeichenstatistik()
{
    // open file
    FILE* fp;
    char buf[BUF_SIZE];
    int lineCount;

    int lowerCaseLetters[NUM_LETTERS] = { 0 };
    int upperCaseLetters[NUM_LETTERS] = { 0 };
    int digits[NUM_DIGITS] = { 0 };

    fp = openFile(FILE_NAME);

    // read all line of this file
    lineCount = 0;
    while (fgets(buf, BUF_SIZE, fp) != NULL)
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
