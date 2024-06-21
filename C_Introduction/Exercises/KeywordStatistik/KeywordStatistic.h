// =====================================================================================
// KeywordStatistic.h
// =====================================================================================

// =====================================================================================
// includes

#include <stdio.h>
#include <string.h>

// =====================================================================================
// constants

#define BUF_SIZE                256
#define MAX_KEYWORD_LENGTH      9
#define NUM_KEYWORDS            32

// =====================================================================================
// types

struct keywordStatistic
{
    char identifier[MAX_KEYWORD_LENGTH];
    int  count;
};

typedef struct keywordStatistic KeywordStatistic;

// =====================================================================================
// extern declarations

extern KeywordStatistic statisticsTable[];

// =====================================================================================
// function prototypes

extern void initKeywordTable();
extern void printKeywordTable();
extern void scanLine(char*);
extern int  isKeyword(char*);

// =====================================================================================
// End-of-File
// =====================================================================================
