// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// function prototypes
static int  str_length  (const char* src);

static void chr_replace (char* src, int pos, char ch);
static int  chr_append  (const char* src, char ch, char* dest, int destLen);
static int  chr_insert  (const char* src, int pos, char ch, char* dest, int destLen);
static int  chr_remove  (const char* src, int pos, char* dest, int destLen);

static int  str_replace (const char* src, int pos, char* toReplace, char* dest, int destLen);
static int  str_append  (const char* src, char* toAppend, char* dest, int destLen);
static int  str_insert  (const char* src, int pos, char* toInsert, char* dest, int destLen);
static int  str_remove  (const char* src, int pos, int count, char* dest, int destLen);

static void exercise_01_chr_replace();
static void exercise_02_chr_append();
static void exercise_03_chr_insert();
static void exercise_04_chr_remove();

static void exercise_05_str_replace();
static void exercise_06_str_append();
static void exercise_07_str_insert();
static void exercise_08_str_remove();

// =====================================================================================

static int str_length(const char* src)
{
	int pos = 0;

	while (src[pos] != '\0') {
		pos++;
	}

	return pos;
}

// =====================================================================================

static void chr_replace(char* src, int pos, char ch) {

	int srcLen = str_length(src);

	if (pos >= srcLen) {
		return;
	}

	src[pos] = ch;
}

static void exercise_01_chr_replace()
{
	char string[10] = "ABCDE";
	// const char* string = "ABCDE";  // crashes
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
	char* string = "ABCDE";
	printf("String: %s\n", string);

	chr_append(string, '!', result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "ABCDE!"

	string = "";
	chr_append(string, '!', result, sizeof(result));
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

static void exercise_03_chr_insert()
{
	char result[7] = "";
	char* string = "ABCDE";
	printf("String: %s\n", string);

	chr_insert(string, 2, '!', result, sizeof (result));
	printf("Result: %s\n", result);  // <=== "AB!CDE"

	chr_insert(string, 0, '!', result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "!ABCDE"

	chr_insert(string, 5, '!', result, sizeof(result));
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

static void exercise_04_chr_remove()
{
	char result[5] = "";
	char* string = "ABCDE";
	printf("String: %s\n", string);

	chr_remove(string, 2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "ABDE"

	chr_remove(string, 0, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "BCDE" 

	chr_remove(string, 4, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "ABCD" 
}

// =====================================================================================
// =====================================================================================

static int str_replace(const char* src, int pos, char* toReplace, char* dest, int destLen)
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

static void exercise_05_str_replace()
{
	char result[10] = "";
	char* string1 = "123456789";
	char* string2 = "ABC";
	str_replace(string1, 3, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "123ABC789" 

	string1 = "123456";
	string2 = "ABC";
	str_replace(string1, 0, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "ABC456"

	string1 = "123456";
	string2 = "ABC";
	str_replace(string1, 3, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "123ABC"

	string1 = "123456";
	string2 = "ABCDEF";
	str_replace(string1, 0, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "ABCDEF"   
}

// =====================================================================================

static int str_append(const char* src, char* toAppend, char* dest, int destLen)
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

static void exercise_06_str_append()
{
	char result[11] = "";
	char* string1 = "12345";
	char* string2 = "ABCDE";
	str_append(string1, string2, result, sizeof (result));
	printf("Result: %s\n", result);  // <=== "12345ABCDE" 

	string1 = "12345";
	string2 = "";
	str_append(string1, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "12345" 

	string1 = "";
	string2 = "12345";
	str_append(string1, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "12345" 

	string1 = "";
	string2 = "";
	str_append(string1, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "" 
}

// =====================================================================================

static int str_insert(const char* src, int pos, char* toInsert, char* dest, int destLen)
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

static void exercise_07_str_insert()
{
	char result[9] = "";
	char* string1 = "ABCDE";
	char* string2 = "123";
	str_insert(string1, 2, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "AB123CDE"

	str_insert(string1, 0, string2, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== "123ABCDE"

	str_insert(string1, 5, string2, result, sizeof(result));
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

static void exercise_08_str_remove()
{
	char result[12] = "";
	char* string = "ABCD123EFGHIJK";
	str_remove(string, 4, 3, result, sizeof (result));
	printf("Result: %s\n", result);  // <=== ABCDEFGHIJK

	string = "123456";
	str_remove(string, 3, 3, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== 123

	str_remove(string, 0, 3, result, sizeof(result));
	printf("Result: %s\n", result);  // <=== 456
}

// =====================================================================================

void exercise_zeichenkettenverarbeitung()
{
	exercise_01_chr_replace();
	exercise_02_chr_append();
	exercise_03_chr_insert();
	exercise_04_chr_remove();
	
	exercise_05_str_replace();
	exercise_06_str_append();
	exercise_07_str_insert();
	exercise_08_str_remove();
}

// =====================================================================================
// End-of-File
// =====================================================================================