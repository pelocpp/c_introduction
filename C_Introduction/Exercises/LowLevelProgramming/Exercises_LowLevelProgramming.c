// =====================================================================================
// Exercises_LowLevelProgramming.c
// =====================================================================================

#include <stdio.h>

// =====================================================================================
// function prototypes

static int countOnes(unsigned int value);
static int countZeros(unsigned int value);
static int countOnesEx(unsigned int value);
static int countZerosEx(unsigned int value);

static void powerOfTwo();
static void printIntAsBinary(unsigned int value);

static unsigned int encodeColor(unsigned char red, unsigned char green, unsigned char blue);
static void decodeColor(unsigned int color, unsigned char* red, unsigned char* green, unsigned char* blue);

static void exercise_01_count_ones_and_zeros();
static void exercise_01_count_ones_and_zeros_ex();
static void exercise_02_print_binary();
static void exercise_03_testPowerOfTwo();
static void exercise_04_encodeColor();
static void exercise_05_decodeColor();

// ===========================================================================

static int countOnes(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp != 0) {
            result++;
        }

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

static int isBitSet(unsigned int value, int pos)
{
    unsigned int mask = 1;
    mask = mask << pos;
    unsigned int tmp = value & mask;
    return (tmp != 0) ? 1 : 0;
}

static int countOnesEx(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitSet(value, pos)) {
            ++result;
        }
    }

    return result;
}

static int isBitCleared(unsigned int value, int pos)
{
    unsigned int mask = 1;
    mask = mask << pos;
    unsigned int tmp = value & mask;
    return (tmp == 0) ? 1 : 0;
}

static int countZeros(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp == 0) {
            result++;
        }

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

static int countZerosEx(unsigned int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitCleared(value, pos)) {
            ++result;
        }
    }

    return result;
}

static void exercise_01_count_ones_and_zeros()
{
    int value = 7;
    printf("Value: %08X\n", value);
    int count = countOnes(value);
    printf("1's found in %08X: %d\n", value, count);

    value = -1;
    printf("Value: %08X\n", value);
    count = countOnes(value);
    printf("1's found in %08X: %d\n", value, count);

    value = 7;
    printf("Value: %08X\n", value);
    count = countZeros(value);
    printf("0's found in %08X: %d\n", value, count);

    value = -1;
    printf("Value: %08X\n", value);
    count = countZeros(value);
    printf("0's found in %08X: %d\n", value, count);

    value = 0;
    printf("Value: %08X\n", value);
    count = countZeros(value);
    printf("0's found in %08X: %d\n", value, count);
}

static void exercise_01_count_ones_and_zeros_ex()
{
    int value = 7;
    printf("Value: %08X\n", value);
    int count = countOnesEx(value);
    printf("1's found in %08X: %d\n", value, count);

    value = -1;
    printf("Value: %08X\n", value);
    count = countOnesEx(value);
    printf("1's found in %08X: %d\n", value, count);

    value = 7;
    printf("Value: %08X\n", value);
    count = countZerosEx(value);
    printf("0's found in %08X: %d\n", value, count);

    value = -1;
    printf("Value: %08X\n", value);
    count = countZerosEx(value);
    printf("0's found in %08X: %d\n", value, count);

    value = 0;
    printf("Value: %08X\n", value);
    count = countZerosEx(value);
    printf("0's found in %08X: %d\n", value, count);
}

// ===========================================================================

static void printIntAsBinary(unsigned int value)
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1 << (numBits - 1);

    for (int i = 0; i < numBits; ++i)
    {
        int bit = 0;
        
        if ((value & mask) != 0) {
            bit = 1;
        }

        printf("%d", bit);

        // print blank after every 4th digit
        if ((i+1) % 4 == 0) {
            printf(" ");
        }

        // shift mask 1 position to the right
        mask = mask >> 1;
    }
}

static void exercise_02_print_binary()
{
    printIntAsBinary(7);
    printf("\n");

    printIntAsBinary(-1);
    printf("\n");

    printIntAsBinary(2'147'483'647);
    printf("\n");
}

// ===========================================================================

static void powerOfTwo()
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1;

    int index = 0;

    do
    {
        ++index;
        printf("%2d: %u\n", index, mask);

        mask = mask << 1;

        --numBits;

    } while (numBits != 0);
}

static void exercise_03_testPowerOfTwo()
{
    powerOfTwo();
}

// ===========================================================================

static unsigned int encodeColor(unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned int redChannel = red;
    unsigned int greenChannel = green;
    unsigned int blueChannel = blue;

    redChannel = redChannel << 16;
    greenChannel = greenChannel << 8;

    unsigned int result = redChannel | greenChannel | blueChannel;
    return result;
}

static void decodeColor(unsigned int color, unsigned char* red, unsigned char* green, unsigned char* blue)
{
    *red = (color & 0x00FF0000) >> 16;
    *green = (color & 0x0000FF00) >> 8;
    *blue = (color & 0x000000FF) >> 0;
}

static void exercise_04_encodeColor()
{
    // 255 - 0 - 255: Magenta
    unsigned int magenta = encodeColor(255, 0, 255);
    printf("Magenta: %08X\n", magenta);

    // 255 - 102 - 102: very red light
    unsigned int veryRedLight = encodeColor(255, 102, 102);
    printf("veryRedLight: %08X\n", veryRedLight);
}

static void exercise_05_decodeColor()
{
    // light green:  0 - 255 - 51
    unsigned int lightGreen = encodeColor(0, 255, 51);

    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;

    decodeColor(lightGreen, &red, &green, &blue);

    printf("LightGreen\n");
    printf("Red:   %u\n", red);
    printf("Green: %u\n", green);
    printf("Blue:  %u\n", blue);
}

// ===========================================================================

void exercise_low_level_programming()
{
    exercise_01_count_ones_and_zeros();
    exercise_01_count_ones_and_zeros_ex();
    exercise_02_print_binary();
    exercise_03_testPowerOfTwo();
    exercise_04_encodeColor();
    exercise_05_decodeColor();
}

// =====================================================================================
// End-of-File
// =====================================================================================

