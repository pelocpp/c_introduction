// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// function prototypes
static int  str_length  (const char* src);

static void str_toUpper (char* src);
static void str_toLower (char* src);
static void str_reverse (char* src); 

static void chr_replace (char* src, int pos, char ch);
static int  chr_append  (const char* src, char ch, char* dest, int destLen);
static int  chr_insert  (const char* src, int pos, char ch, char* dest, int destLen);
static int  chr_remove  (const char* src, int pos, char* dest, int destLen);

static int  str_replace (const char* src, int pos, const char* toReplace, char* dest, int destLen);
static int  str_append  (const char* src, const char* toAppend, char* dest, int destLen);
static int  str_insert  (const char* src, int pos, const char* toInsert, char* dest, int destLen);
static int  str_remove  (const char* src, int pos, int count, char* dest, int destLen);

static void exercise_01_str_toUpper();
static void exercise_01_str_toLower();
static void exercise_01_str_reverse();

static void exercise_02_chr_replace();
static void exercise_02_chr_append();
static void exercise_02_chr_insert();
static void exercise_02_chr_remove();

static void exercise_03_str_replace();
static void exercise_03_str_append();
static void exercise_03_str_insert();
static void exercise_03_str_remove();

// =====================================================================================

static int str_length(const char* src)
{
    int i = 0;

    while (src[i] != '\0') {
        i++;
    }

    return i;
}

// =====================================================================================

static void str_toUpper(char* src)
{
    int i = 0;

    while (src[i] != '\0') {

        if (src[i] >= 'a' && src[i] <= 'z') {
            src[i] = src[i] - 32;   // 32 = 'a' - 'A'
        }

        i++;
    }
}

static void exercise_01_str_toUpper()
{
    char s[] = "!abcde123vwxyz?";
    printf("%s\n", s);

    str_toUpper(s);
    printf("%s\n", s);
}

// =====================================================================================

void str_toLower(char* src)
{
    int i = 0;

    while (src[i] != '\0') {

        if (src[i] >= 'A' && src[i] <= 'Z') {
            src[i] = src[i] + 32;   // 32 = 'a' - 'A'
        }

        i++;
    }
}

static void exercise_01_str_toLower()
{
    char s[] = "!ABCDE123VWXYZ?";
    printf("%s\n", s);

    str_toLower(s);
    printf("%s\n", s);
}

// =====================================================================================

void str_reverse(char* src)
{
    // compute length
    int length = str_length(src);

    // swap chars
    for (int i = 0; i < length / 2; i++) {

        char ch = src[length - 1 - i];
        src[length - 1 - i] = src[i];
        src[i] = ch;
    }
}

static void exercise_01_str_reverse()
{
    char s[] = "!abcde123vwxyz?";
    printf("%s\n", s);

    str_reverse(s);
    printf("%s\n", s);
}

// =====================================================================================
// =====================================================================================

static void chr_replace(char* src, int pos, char ch) {

    int srcLen = str_length(src);

    if (pos >= srcLen) {
        return;
    }

    src[pos] = ch;
}

static void exercise_02_chr_replace()
{
    char string[10] = "ABCDE";
    // const char* s = "ABCDE";  // crashes
    printf("String: %s\n", string);

    chr_replace(string, 2, '!');
    printf("Result: %s\n", string);  // <=== "AB!DE"

    string[0] = 'A';
    string[1] = '\0';
    chr_replace(string, 0, '!');
    printf("Result: %s\n", string);  // <=== "!"
}

// =====================================================================================

static int chr_append(const char* src, char ch, char* dest, int destLen) {

    int srcLen = str_length(src);

    if (srcLen + 1 /* char to insert */ + 1 /* '\0' */ > destLen) {
        printf("Error in str_append: Result buffer not large enough!\n");
        return 0;
    }

    // copy 'src' to 'dest'
    for (int i = 0; i < srcLen; ++i) {
        dest[i] = src[i];
    }

    // append character 'ch' at the end of 'dest'
    dest[srcLen] = ch;

    // terminate 'dest'
    dest[srcLen + 1] = '\0';

    return 1;
}

static void exercise_02_chr_append()
{
    char result[7] = "";
    char* s = "ABCDE";
    printf("String: %s\n", s);

    chr_append(s, '!', result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABCDE!"

    s = "";
    chr_append(s, '!', result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "!"
}

// =====================================================================================

static int chr_insert(const char* src, int pos, char ch, char* dest, int destLen) {

    int srcLen = str_length(src);

    if (srcLen + 1 /* char to insert */ + 1 /* '\0' */ > destLen) {
        printf("Error in chr_insert: Result buffer not large enough!\n");
        return 0;
    }

    if (pos > srcLen) {
        printf("Error in chr_insert: pos out of range!\n");
        return 0;
    }

    // copy first part of 'src' to 'dest'
    for (int index = 0; index < pos; ++index) {
        dest[index] = src[index];
    }

    // copy character to insert into 'dest'
    dest[pos] = ch;

    // copy second part of 'src' to 'dest'
    for (int i = pos; i < srcLen; ++i) {
        dest[i + 1] = src[i];
    }

    // terminate 'dest'
    dest[srcLen + 1] = '\0';

    return 1;
}

static void exercise_02_chr_insert()
{
    char result[7] = "";
    char* s = "ABCDE";
    printf("String: %s\n", s);

    chr_insert(s, 2, '!', result, sizeof (result));
    printf("Result: %s\n", result);  // <=== "AB!CDE"

    chr_insert(s, 0, '!', result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "!ABCDE"

    chr_insert(s, 5, '!', result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABCDE!"
}

// =====================================================================================

static int chr_remove(const char* src, int pos, char* dest, int destLen) {

    int srcLen = str_length(src);
    
    if (srcLen - 1 >= destLen) {
        printf("Error in chr_remove: Result buffer not large enough!\n");
        return 0;
    }

    // copy first part from 'src' to 'dest'
    for (int i = 0; i < pos; ++i) {
        dest[i] = src[i];
    }

    // copy second part from 'src' to 'dest', omitting character at position 'pos'
    for (int i = pos + 1; i < srcLen; ++i) {
        dest[i-1] = src[i];
    }

    // terminate 'dest'
    dest[srcLen - 1] = '\0';

    return 1;
}

static void exercise_02_chr_remove()
{
    char result[5] = "";
    char* s = "ABCDE";
    printf("String: %s\n", s);

    chr_remove(s, 2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABDE"

    chr_remove(s, 0, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "BCDE" 

    chr_remove(s, 4, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABCD" 
}

// =====================================================================================
// =====================================================================================

static int str_replace(const char* src, int pos, const char* toReplace, char* dest, int destLen)
{
    int srcLen = str_length(src);
    int toReplaceLen = str_length(toReplace);

    if (srcLen + 1 > destLen) {
        printf("Error in str_replace: Result buffer not large enough!\n");
        return 0;
    }

    if (pos + toReplaceLen > srcLen) {
        printf("Error in str_replace: String to replace too long or wrong position\n");
        return 0;
    }

    // copy first part from 'src' to 'dest'
    for (int i = 0; i < pos; i++) {
        dest[i] = src[i];
    }

    // replace upcoming 'toReplaceLen' characters with 'toReplace'
    for (int i = 0; i < toReplaceLen; i++) {
        dest[pos + i] = toReplace[i];
    }

    // copy remainder, if any, from 'src' to 'dest'
    for (int k = pos + toReplaceLen; k < srcLen; k++) {
        dest[k] = src[k];
    }

    // terminate 'dest'
    dest[srcLen] = '\0';

    return 1;
}

static void exercise_03_str_replace()
{
    char result[10] = "";
    char* s1 = "123456789";
    char* s2 = "ABC";
    str_replace(s1, 3, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "123ABC789" 

    s1 = "123456";
    s2 = "ABC";
    str_replace(s1, 0, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABC456"

    s1 = "123456";
    s2 = "ABC";
    str_replace(s1, 3, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "123ABC"

    s1 = "123456";
    s2 = "ABCDEF";
    str_replace(s1, 0, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABCDEF"   
}

// =====================================================================================

static int str_append(const char* src, const char* toAppend, char* dest, int destLen)
{
    int srcLen = str_length(src);
    int toAppendLen = str_length(toAppend);

    if (srcLen + toAppendLen + 1 > destLen) {
        printf("Error in str_append: Result buffer not large enough!\n");
        return 0;
    }

    // copy 'src' to 'dest'
    for (int i = 0; i < srcLen; i++) {
        dest[i] = src[i];
    }

    // appending 'toAppend'
    for (int k = 0; k < toAppendLen; k++) {
        dest[srcLen + k] = toAppend[k];
    }

    // terminate 'dest'
    dest[srcLen + toAppendLen] = '\0';

    return 1;
}

static void exercise_03_str_append()
{
    char result[11] = "";
    char* s1 = "12345";
    char* s2 = "ABCDE";
    str_append(s1, s2, result, sizeof (result));
    printf("Result: %s\n", result);  // <=== "12345ABCDE" 

    s1 = "12345";
    s2 = "";
    str_append(s1, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "12345" 

    s1 = "";
    s2 = "12345";
    str_append(s1, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "12345" 

    s1 = "";
    s2 = "";
    str_append(s1, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "" 
}

// =====================================================================================

static int str_insert(const char* src, int pos, const char* toInsert, char* dest, int destLen)
{
    int srcLen = str_length(src);
    int toInsertLen = str_length(toInsert);

    if (srcLen + toInsertLen + 1 > destLen) {
        printf("Error in str_insert: Result buffer not large enough!\n");
        return 0;
    }

    // copy first part from 'src' to 'dest'
    for (int i = 0; i < pos; i++) {
        dest[i] = src[i];
    }

    // copy string 'toInsert' from 'src' to 'dest'
    for (int i = 0; i < toInsertLen; i++) {
        dest[pos + i] = toInsert[i];
    }

    // copy remainder from 'src' to 'dest'
    for (int i = pos; i < srcLen; i++) {
        dest[toInsertLen + i] = src[i];
    }

    // terminate 'dest'
    dest[srcLen + toInsertLen] = '\0';

    return 1;
}

static void exercise_03_str_insert()
{
    char result[9] = "";
    char* s1 = "ABCDE";
    char* s2 = "123";
    str_insert(s1, 2, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "AB123CDE"

    str_insert(s1, 0, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "123ABCDE"

    str_insert(s1, 5, s2, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== "ABCDE123"
}

// =====================================================================================

static int str_remove(const char* src, int pos, int count, char* dest, int destLen)
{
    int srcLen = str_length(src);

    if (srcLen - count >= destLen) {
        printf("Error in str_remove: Result buffer not large enough!\n");
        return 0;
    }

    // copy first part from 'src' to 'dest'
    for (int i = 0; i < pos; i++) {
        dest[i] = src[i];
    }

    // copy second part from 'src' to 'dest', omitting 'count' characters
    for (int i = pos + count; i < srcLen; i++) {
        dest[i - count] = src[i];
    }

    // terminate 'dest'
    dest[srcLen - pos] = '\0';

    return 1;
}

static void exercise_03_str_remove()
{
    char result[12] = "";
    char* s = "ABCD123EFGHIJK";
    str_remove(s, 4, 3, result, sizeof (result));
    printf("Result: %s\n", result);  // <=== ABCDEFGHIJK

    s = "123456";
    str_remove(s, 3, 3, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== 123

    str_remove(s, 0, 3, result, sizeof(result));
    printf("Result: %s\n", result);  // <=== 456
}

// =====================================================================================

void exercise_zeichenkettenverarbeitung()
{
    exercise_01_str_toUpper();
    exercise_01_str_toLower();
    exercise_01_str_reverse();

    exercise_02_chr_replace();
    exercise_02_chr_append();
    exercise_02_chr_insert();
    exercise_02_chr_remove();
    
    exercise_03_str_replace();
    exercise_03_str_append();
    exercise_03_str_insert();
    exercise_03_str_remove();
}

// =====================================================================================
// End-of-File
// =====================================================================================