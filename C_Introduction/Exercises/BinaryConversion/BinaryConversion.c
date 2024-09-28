// =====================================================================================
// BinaryConversion.c
// =====================================================================================

#include <stdio.h>

static int binaryConvert(int number, char binary[], int len)
{
    int index = 0;
    while (number != 0)
    {
        int rest = number % 2;

        if (rest == 0)
        {
            binary[index] = '0';
        }
        else if (rest == 1)
        {
            binary[index] = '1';
        }

        index++;

        // is provided buffer large enough
        if (index >= len - 1) {
            break;
        }

        number = number / 2;
    }

    // terminate string
    binary[index] = '\0';

    // reverse digits
    for (int i = 0; i < index / 2; i++)
    {
        char tmp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = tmp;
    }

    return index;
}

void exercise_binary_conversion()
{
    char buffer[128];
    int number;
    int countDigits;

    printf("Number: ");
    scanf_s("%d", &number);
    countDigits = binaryConvert(number, buffer, 128);
    printf("Binary: %s [%d]\n", buffer, countDigits);
}

// =====================================================================================
// End-of-File
// =====================================================================================
