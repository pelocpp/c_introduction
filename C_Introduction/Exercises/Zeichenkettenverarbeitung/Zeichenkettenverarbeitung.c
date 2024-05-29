// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// TBD: Die Fehlerabfragen überprüfen

// function prototypes
static int  str_length(char* source);

static void chr_replace(char* source, int pos, char ch);
static int  chr_append(char* source, char ch, char* destination, int lenDestination);
static int  chr_insert(char* source, int pos, char ch, char* destination, int lenDestination);
static int  chr_remove(char* source, int pos, char* destination, int lenDestination);

static void str_replace(char* source, int pos, char* toReplace, char* destination, int lenDestination);
static void str_append(char* ergebnis, int len, char* destination, char* source);
static void str_insert(char* source, int pos, char* toInsert, char* destination, int lendestination);
static void str_remove(char* source, int pos, int count, char* destination, int lendestination);

static void exercise_01_chr_replace();
static void exercise_02_chr_append();
static void exercise_03_chr_insert();
static void exercise_04_chr_remove();

static void exercise_05_str_replace();
static void exercise_06_str_append();
static void exercise_07_str_insert();
static void exercise_08_str_remove();

// =====================================================================================

static int str_length(char* source)
{
	int pos = 0;

	while (source[pos] != '\0') {
		pos++;
	}

	return pos;
}

// =====================================================================================

static void chr_replace(char* source, int pos, char ch) {

	int lensource = str_length(source);

	if (pos >= lensource) {
		return;
	}

	source[pos] = ch;
}

static void exercise_01_chr_replace()
{
	// "ABCDE", an der Position 3 das 'D' durch ein '!' ersetzen ===> "ABC!E"

	// char* source = "ABCDE";  // VORSICHT !!!
	// "ABCDE" liegt im Codesegment =>
	// hier ist ein SCHREIBEN VERBOTEN / Absturz

	char source[] = "ABCDE";    // Zeichenkette liegt in einem Array (!)

	printf("Quelle: Vorher:  %s\n", source);
	chr_replace(source, 2, '!');
	printf("Quelle: Nachher: %s\n", source);
}

// =====================================================================================

static int chr_append(char* source, char ch, char* destination, int lenDestination) {

	int lenSource = str_length(source);

	if (lenDestination < lenSource + 1) {
		return 0;
	}

	// copy 'source' to 'destination'
	for (int i = 0; i < lenSource; ++i) {
		destination[i] = source[i];
	}

	// append character 'ch' at the end of 'destination'
	destination[lenSource] = ch;

	// terminate 'destination'
	destination[lenSource + 1] = '\0';

	return 1;
}

static void exercise_02_chr_append()
{
	// In "ABCDE" an der Position 3 ein '!' einfuegen ==> "ABC!DE"
	char* source = "ABCDE";
	printf("Quelle: %s\n", source);

	char result[10];
	chr_insert(source, 2, '!', result, 10);
	printf("destination:   %s\n", result);
}

// =====================================================================================

static int chr_insert(char* source, int pos, char ch, char* destination, int lenDestination) {

	int lenSource = str_length(source);

	if (pos > lenSource) {
		return 0;
	}

	if (lenDestination < lenSource + 1) {
		return 0;
	}

	// copy first part of 'source' to 'destination'
	for (int index = 0; index < pos; ++index) {
		destination[index] = source[index];
	}

	// copy character to insert into 'destination'
	destination[pos] = ch;

	// copy second part of 'source' to 'destination'
	for (int i = pos; i < lenSource; ++i) {
		destination[i + 1] = source[i];
	}

	// terminate 'destination'
	destination[lenSource + 1] = '\0';

	return 1;
}

static void exercise_03_chr_insert()
{
	// In "ABCDE" an der Position 3 ein '!' einfuegen ==> "ABC!DE"
	char* source = "ABCDE";
	printf("Quelle: %s\n", source);

	char destination[100];
	chr_insert(source, 2, '!', destination, 100);
	printf("destination:   %s\n", destination);
}

// =====================================================================================

static int chr_remove(char* source, int pos, char* destination, int length) {

	int lensource = str_length(source);

	if (pos > lensource) {
		return 0;
	}

	// copy first part of source to destination
	for (int i = 0; i < pos; ++i) {
		destination[i] = source[i];
	}

	// copy second part of source to destination, omitting character at position 'pos'
	for (int i = pos + 1; i < lensource; ++i) {
		destination[i-1] = source[i];
	}

	// terminate destination
	destination[lensource - 1] = '\0';

	return 1;
}

static void exercise_04_chr_remove()
{
	// "ABCDE", das Zeichen an der Position 2 entfernen ===> "ABDE"
	char* source = "ABCDE";
	printf("Quelle: %s\n", source);

	char destination[100];
	chr_remove(source, 2, destination, 100);
	printf("destination:   %s\n", destination);
}

// =====================================================================================
// =====================================================================================

static void str_replace(char* source, int pos, char* toReplace, char* destination, int lenDestination)
{
	//int lendestination = str_length(destination);

	//int lensource = str_length(source);

	//if (len < lendestination + lensource + 1) {
	//	printf("Puffer zu klein!\n");
	//}

	//// destination an den Anfang von Ergebnis kopieren
	//for (int i = 0; i < lendestination; i++) {

	//	ergebnis[i] = destination[i];
	//}

	//// dahinter source kopieren
	//for (int k = 0; k < lensource; k++) {
	//	ergebnis[lendestination + k] = source[k];
	//}

	//ergebnis[lendestination + lensource] = '\0';
}

static void exercise_05_str_replace()
{
	//char* kette1 = "destination";

	//char* kette2 = "source";

	//char ergebnis[100];

	//str_replace(ergebnis, 2, kette1, kette2);   // "destinationKETTE" 

	//printf("Ergebnis: %s\n", ergebnis);  // <=== "destinationKETTE"  !!!
}

// =====================================================================================

static void str_append(char* ergebnis, int len, char* destination, char* source)
{
	int lendestination = str_length(destination);

	int lensource = str_length(source);

	if (len < lendestination + lensource + 1) {
		printf("Puffer zu klein!\n");
	}

	// destination an den Anfang von Ergebnis kopieren
	for (int i = 0; i < lendestination; i++) {

		ergebnis[i] = destination[i];
	}

	// dahinter source kopieren
	for (int k = 0; k < lensource; k++) {
		ergebnis[lendestination + k] = source[k];
	}

	ergebnis[lendestination + lensource] = '\0';
}

static void exercise_06_str_append()
{
	char* kette1 = "destination";

	char* kette2 = "source";

	char ergebnis[100];

	str_append(ergebnis, 100, kette1, kette2);   // "destinationKETTE" 

	printf("Ergebnis: %s\n", ergebnis);  // <=== "destinationKETTE"  !!!
}

// =====================================================================================

static void str_insert(char* source, int pos, char* toInsert, char* destination, int lendestination)
{
	int lensource = str_length(source);

	int lenToInsert = str_length(toInsert);

	if (lensource + lenToInsert + 1 >= lendestination) {
		printf("Error: Result buffer not large enough\n");
		return;
	}

	// copy first part into destination
	for (int i = 0; i < pos; i++) {

		destination[i] = source[i];
	}

	// copy string to insert into destination
	for (int i = 0; i < lenToInsert; i++) {

		destination[pos + i] = toInsert[i];
	}

	// copy remainder of source into destination
	for (int i = pos; i < lensource; i++) {

		destination[lenToInsert + i] = source[i];
	}

	// terminate destination
	destination[lensource + lenToInsert] = '\0';
}

static void exercise_07_str_insert()
{
	char* kette1 = "ABCDE";

	char* kette2 = "123";

	// Beispiel: "ABCDE" = 5, "123" = 3 , Null = 1 ==> 

	char ergebnis[10];  // das ist ein Feld von Zeichen ==> Zeichenkette

	str_insert(kette1, 2, kette2, ergebnis, 10);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}

// =====================================================================================

static void str_remove(char* source, int pos, int count, char* destination, int lendestination)
{
	int lensource = str_length(source);

	if (lensource - count > lendestination) {
		printf("Error");
		return;
	}

	// copy first part into destination
	for (int i = 0; i < pos; i++) {

		destination[i] = source[i];
	}

	// copy second part into destination
	for (int i = pos + count; i < lensource; i++) {

		destination[i - count] = source[i];
	}

	// terminate destination
	destination[lensource - pos + 1] = '\0';
}

static void exercise_08_str_remove()
{
	char* kette = "ABCD123EFGHIJK";

	char ergebnis[100];

	str_remove(kette, 4, 3, ergebnis, 100);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}

// =====================================================================================

void exercise_zeichenkettenverarbeitung()
{
	//exercise_01_chr_replace();
	//exercise_02_chr_append();
	//exercise_03_chr_insert();
	exercise_04_chr_remove();
	//
	//exercise_05_str_replace();
	//exercise_06_str_append();
	//exercise_07_str_insert();
	//exercise_08_str_remove();
}

// =====================================================================================
// End-of-File
// =====================================================================================