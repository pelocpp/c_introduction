// ===========================================================================
// LowLevelProgramming.c // Low Level Programming in C
// ===========================================================================

//#include <iostream>
//#include <bitset>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ===========================================================================
// function prototypes

static void low_level_01_bitwise_and();
static void low_level_02_bitwise_or();
static void low_level_03_bitwise_xor();
static void low_level_04_bitwise_negate();
static void low_level_05_left_shift();
static void low_level_06_right_shift_unsigned();
static void low_level_07_right_shift_signed();

// ===========================================================================

static void low_level_01_bitwise_and()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1100'1101;
    unsigned short word = word1 & word2;

    printf("%04X\n", word1);
    printf("%04X\n", word2);
    printf(" &\n");
    printf("%04X\n", word);
    printf("\n");
}

static void low_level_02_bitwise_or()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;
    unsigned short word = word1 | word2;

    printf("%04X\n", word1);
    printf("%04X\n", word2);
    printf(" |\n");
    printf("%04X\n", word);
    printf("\n");
}

static void low_level_03_bitwise_xor()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;
    unsigned short word = word1 ^ word2;

    printf("%04X\n", word1);
    printf("%04X\n", word2);
    printf(" ^\n");
    printf("%04X\n", word);
    printf("\n");
}

static void low_level_04_bitwise_negate()
{
    unsigned short word = 0b1011'0011;
    unsigned short wordNegated = ~ word;

    printf("%04X\n", word);
    printf(" ~\n");
    printf("%04X\n", wordNegated);
    printf("\n");
}

static void low_level_05_left_shift()
{
    unsigned char byte = 0b0010'0011;
    unsigned char byteShifted = byte << 1;

    printf("%04X << %d = %04X\n", byte, 1, byteShifted);
    printf("\n");
}

static void low_level_06_right_shift_unsigned ()
{
    unsigned char byte = 0b1010'0011;
    unsigned char byteShifted = byte >> 1;

    printf("%04X >> %d = %04X\n", byte, 1, byteShifted);
    printf("\n");
}

static void low_level_07_right_shift_signed()
{
    signed char byte = 0b0010'0011;
    signed char byteShifted = byte >> 2;

    printf("%4d >> %d = %4d\n", byte, 2, byteShifted);
    printf("\n");

    byte = -0b1000'0000;
    byteShifted = byte >> 3;

    printf("%4d >> %d = %4d\n", byte, 3, byteShifted);
    printf("\n");
}

// ===========================================================================

void mainLowLevelProgramming()
{
    low_level_01_bitwise_and();
    low_level_02_bitwise_or();
    low_level_03_bitwise_xor();
    low_level_04_bitwise_negate();
    low_level_05_left_shift();
    low_level_06_right_shift_unsigned();
    low_level_07_right_shift_signed();
}

// ===========================================================================
// End-of-File
// ===========================================================================
