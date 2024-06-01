// ===========================================================================
// CRT.c // C-Runtime Library
// ===========================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

void crt_01()
{
    // einzelne Zeichen

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

void crt_02()
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

void crt_03()
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

    // don't forget:  isdigit
}

#define FILE_NAME_1 "..\\C_Introduction\\Tutorial\\CRT\\CRT.c"

#define FILE_NAME_2 "C:\\Development\\Seminar_C_All_In_One_April_2024\\ErsteSchritte\\ErsteSchritte\\Datei_11.c"

#define FILE_NAME_3 R"(C:\Development\Seminar_C_All_In_One_April_2024\ErsteSchritte\ErsteSchritte\Datei_11.c)"

void crt_04()
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

void testCrt()
{
    crt_01();
    crt_02();
    crt_03();
    crt_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
