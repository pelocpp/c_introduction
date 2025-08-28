// ===========================================================================
// LowLevelProgramming.c // Low Level Programming in C
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===========================================================================
// function prototypes

static void setBit(unsigned int* value, int pos);
static void clearBit(unsigned int* value, int pos);
static int  isBitSet(unsigned int value, int pos);
static int  isBitCleared(unsigned int value, int pos);

static void low_level_01_bitwise_and();
static void low_level_02_bitwise_or();
static void low_level_03_bitwise_xor();
static void low_level_04_bitwise_negate();
static void low_level_05_left_shift();
static void low_level_06_right_shift_unsigned();
static void low_level_07_right_shift_signed();
static void low_level_08_set_clear_bit();
static void low_level_09_signed_vs_unsigned_shift();

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
// ===========================================================================

static void setBit(unsigned int* value, int pos)
{
    unsigned int mask = 1 << pos;

    *value = *value | mask;
}

static void clearBit(unsigned int* value, int pos)
{
    unsigned int mask = ~(1 << pos);

    *value = *value & mask;
}

static int isBitSet(unsigned int value, int pos)
{
    unsigned int mask = 1;

    mask = mask << pos;

    unsigned int tmp = value & mask;

    return (tmp != 0) ? 1 : 0;
}

static int isBitCleared(unsigned int value, int pos)
{
    unsigned int mask = 1;

    mask = mask << pos;

    unsigned int tmp = value & mask;

    return (tmp == 0) ? 1 : 0;
}

static void low_level_08_set_clear_bit()
{
    unsigned int s = 0b1011'0011;
    printf("Before: %04X\n", s);

    setBit(&s, 3);
    printf("After:  %04X\n", s);

    clearBit(&s, 4);
    printf("After:  %04X\n", s);
}

void low_level_09_signed_vs_unsigned_shift()
{
    // create initial mask: 1 in leftmost position
    // note: study output of this program using 'int' vs 'unsigned int' mask

    unsigned int umask = 1 << 31;
    printf("mask:  %04X\n", umask);

    // shift mask 1 position to the right
    umask = umask >> 1;
    printf("mask:  %04X\n", umask);

    // shift mask 1 position to the right
    umask = umask >> 1;
    printf("mask:  %04X\n", umask);

    // shift mask 1 position to the right
    umask = umask >> 1;
    printf("mask:  %04X\n", umask);

    // ----------------------------------

    int smask = 1 << 31;
    printf("mask:  %04X\n", smask);

    // shift mask 1 position to the right
    smask = smask >> 1;
    printf("mask:  %04X\n", smask);

    // shift mask 1 position to the right
    smask = smask >> 1;
    printf("mask:  %04X\n", smask);

    // shift mask 1 position to the right
    smask = smask >> 1;
    printf("mask:  %04X\n", smask);
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
    low_level_08_set_clear_bit();
    low_level_09_signed_vs_unsigned_shift();
}

// ===========================================================================
// End-of-File
// ===========================================================================
