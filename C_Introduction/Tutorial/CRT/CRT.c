// ===========================================================================
// CRT.c // C-Runtime Library
// ===========================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

// ===========================================================================
// <string.h> examples

static void crt_01()
{
    char text[] = "This is a simple string";
    size_t length;

    length = strlen(text);
    printf("String \"%s\" has %zu characters.\n", text, length);
}

static void crt_02()
{
    char text[20] = { '\0' };

    strcpy_s(text, sizeof (text), "Hallo!");
    printf("%s\n", text);

    strcpy_s(text, sizeof(text), "Yes - You!");
    printf("%s\n", text);
}

static void crt_03()
{
    char* s = "123456789";

    printf("%zu\n", strlen(s));
    printf("%zu\n", sizeof("123456789"));

    // string concatenation
    char dest[50] = "ABCDEF";
    // char* dest = "ABCDEF";  // <====== VORSICHT
    strcat_s(dest, 50, "123456789");
    printf("%s\n", dest);
}

static void crt_04()
{
    const char string1[] = "Hello";
    const char string2[] = "World";
    const char string3[] = "Hello";

    if (strcmp(string1, string2) == 0)
    {
        printf("The strings %s und %s are identical.\n", string1, string2);
    }
    else
    {
        printf("The strings %s und %s are different.\n", string1, string2);
    }

    if (strcmp(string1, string3) == 0)
    {
        printf("The strings %s und %s are identical.\n", string1, string3);
    }
    else
    {
        printf("The strings %s und %s are different.\n", string1, string3);
    }
}

// ===========================================================================
// <ctype.h> examples

static void crt_05()
{
    // single character functions
    char ch;

    ch = 'A';
    printf("%d\n", isalpha(ch));

    ch = '1';
    printf("%d\n", isalpha(ch));

    printf("%d\n", isdigit(ch));

    ch = 'A';
    ch = tolower(ch);
    printf("%c\n", ch);

    ch = toupper(ch);
    printf("%c\n", ch);
}

static void crt_06()
{
    // ascii to integer
    int n = atoi("1234");
    printf("%d\n", n);

    n = atoi("1234XXX");
    printf("%d\n", n);

    n = atoi("XXX1234");
    printf("%d\n", n);

    n = atoi("0");
    printf("%d\n", n);
}

// ===========================================================================
// <stdlib.h> examples

#define FILE_NAME_1 "..\\C_Introduction\\Tutorial\\CRT\\CRT.c"

#define FILE_NAME_2 "C:\\Development\\Seminar_C_All_In_One_April_2024\\ErsteSchritte\\ErsteSchritte\\Datei_11.c"

#define FILE_NAME_3 R"(C:\Development\Seminar_C_All_In_One_April_2024\ErsteSchritte\ErsteSchritte\Datei_11.c)"

static void crt_07()
{
    FILE* fp;

    fp = fopen(FILE_NAME_1, "r");

    if (fp == NULL) {
        printf("File %s not found\n", FILE_NAME_1);
    }
    else {

        // Lese alle Zeilen aus der Datei ein:

        while (1) {

            char line[256];
            char* result = fgets(line, 256, fp);

            if (result == NULL) {
                break;
            }

            // remove line-break '\n'
            size_t indexLineBreak = strlen(line);
            line[indexLineBreak - 1] = '\0';

            printf("> %s\n", line);
        }

        fclose(fp);
    }
}

void mainCrt()
{
    crt_01();
    crt_02();
    crt_03();
    crt_04();
    crt_05();
    crt_06();
    crt_07();
}

// ===========================================================================
// End-of-File
// ===========================================================================
