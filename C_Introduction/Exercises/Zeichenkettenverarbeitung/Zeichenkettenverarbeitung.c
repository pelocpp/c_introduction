// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// function prototypes
static int  str_length(char* quelle);

static void chr_replace(char* quelle, int pos, char ch);
// static int  chr_append(char* quelle, int pos, char ch, char* ziel, int length);
static int  chr_insert(char* quelle, int pos, char ch, char* ziel, int length);
static int  chr_remove(char* quelle, int pos, char* ziel, int length);

// static void str_replace(char* quelle, int pos, char ch);
static void str_append(char* ergebnis, int len, char* ziel, char* quelle);
static void str_insert(char* quelle, int pos, char* toInsert, char* ziel, int lenZiel);
static void str_remove(char* quelle, int pos, int count, char* ziel, int lenZiel);

static void exercise_zeichenkettenverarbeitung_01_chr_replace();
static void exercise_zeichenkettenverarbeitung_02_chr_insert();
static void exercise_zeichenkettenverarbeitung_03_chr_remove();

// =====================================================================================

static int str_length(char* quelle)
{
	int pos = 0;

	while (quelle[pos] != '\0') {
		pos++;
	}

	return pos;
}

// =====================================================================================

static void chr_replace(char* quelle, int pos, char ch) {

	int lenQuelle = str_length(quelle);

	if (pos >= lenQuelle) {
		return;
	}

	quelle[pos] = ch;
}

static void exercise_zeichenkettenverarbeitung_01_chr_replace()
{
	// "ABCDE", an der Position 3 das 'D' durch ein '!' ersetzen ===> "ABC!E"

	// char* quelle = "ABCDE";  // VORSICHT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//                "ABCDE" liegt im Codesegment -- hier ist ein SCHREIBEN VERBOTEN / Absturz

	char quelle[] = "ABCDE";    // Zeichenkette liegt in einem Array (!)

	printf("Quelle: Vorher:  %s\n", quelle);
	chr_replace(quelle, 2, '!');
	printf("Quelle: Nachher: %s\n", quelle);
}

// =====================================================================================

static int chr_insert(char* quelle, int pos, char ch, char* ziel, int length) {

	int lenQuelle = str_length(quelle);

	if (pos > lenQuelle) {
		return 0;
	}

	if (length < lenQuelle + 1) {
		return 0;
	}

	// copy first part of quelle to ziel
	int index = 0;
	for (; index < pos; ++index) {
		ziel[index] = quelle[index];
	}

	// copy character to insert into ziel
	ziel[index] = ch;

	// copy second part of quelle to ziel
	for (int i = index; i < lenQuelle; ++index, ++i) {
		ziel[i + 1] = quelle[i];
	}

	// terminate ziel
	ziel[lenQuelle + 1] = '\0';   // oder ziel[index] = '\0'; 

	return 1;
}

static void exercise_zeichenkettenverarbeitung_02_chr_insert()
{
	// In "ABCDE" an der Position 3 ein '!' einfuegen ==> "ABC!DE"
	char* quelle = "ABCDE";
	printf("Quelle: %s\n", quelle);

	char ziel[100];
	chr_insert(quelle, 2, '!', ziel, 100);
	printf("Ziel:   %s\n", ziel);
}

// =====================================================================================

static int chr_remove(char* quelle, int pos, char* ziel, int length) {

	int lenQuelle = str_length(quelle);

	if (pos > lenQuelle) {
		return 0;
	}

	// copy first part of quelle to ziel
	for (int i = 0; i < pos; ++i) {
		ziel[i] = quelle[i];
	}

	// copy second part of quelle to ziel, omitting char at position 'pos'
	for (int i = pos + 1; i < lenQuelle; ++i) {
		ziel[i-1] = quelle[i];
	}

	// terminate ziel
	ziel[lenQuelle - 1] = '\0';

	return 1;
}

static void exercise_zeichenkettenverarbeitung_03_chr_remove()
{
	// "ABCDE", das Zeichen an der Position 2 entfernen ===> "ABDE"
	char* quelle = "ABCDE";
	printf("Quelle: %s\n", quelle);

	char ziel[100];
	chr_remove(quelle, 2, ziel, 100);
	printf("Ziel:   %s\n", ziel);
}

// =====================================================================================

static void str_append(char* ergebnis, int len, char* ziel, char* quelle)
{
	int lenZiel = str_length(ziel);

	int lenQuelle = str_length(quelle);

	if (len < lenZiel + lenQuelle + 1) {
		printf("Puffer zu klein!\n");
	}

	// Ziel an den Anfang von Ergebnis kopieren
	for (int i = 0; i < lenZiel; i++) {

		ergebnis[i] = ziel[i];
	}

	// dahinter Quelle kopieren
	for (int k = 0; k < lenQuelle; k++) {
		ergebnis[lenZiel + k] = quelle[k];
	}

	ergebnis[lenZiel + lenQuelle] = '\0';
}

static void exercise_zeichenkettenverarbeitung_append()
{
	char* kette1 = "ZIEL";

	char* kette2 = "QUELLE";

	char ergebnis[100];

	str_append(ergebnis, 100, kette1, kette2);   // "ZIELKETTE" 

	printf("Ergebnis: %s\n", ergebnis);  // <=== "ZIELKETTE"  !!!
}

// =====================================================================================

static void str_insert(char* quelle, int pos, char* toInsert, char* ziel, int lenZiel)
{
	int lenQuelle = str_length(quelle);

	int lenToInsert = str_length(toInsert);

	if (lenQuelle + lenToInsert + 1 >= lenZiel) {
		printf("Error: Result buffer not large enough\n");
		return;
	}

	// copy first part into ziel
	for (int i = 0; i < pos; i++) {

		ziel[i] = quelle[i];
	}

	// copy string to insert into ziel
	for (int i = 0; i < lenToInsert; i++) {

		ziel[pos + i] = toInsert[i];
	}

	// copy remainder of quelle into ziel
	for (int i = pos; i < lenQuelle; i++) {

		ziel[lenToInsert + i] = quelle[i];
	}

	// terminate ziel
	ziel[lenQuelle + lenToInsert] = '\0';
}

static void exercise_zeichenkettenverarbeitung_insert()
{
	char* kette1 = "ABCDE";

	char* kette2 = "123";

	// Beispiel: "ABCDE" = 5, "123" = 3 , Null = 1 ==> 

	char ergebnis[10];  // das ist ein Feld von Zeichen ==> Zeichenkette

	str_insert(kette1, 2, kette2, ergebnis, 10);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}

// =====================================================================================

static void str_remove(char* quelle, int pos, int count, char* ziel, int lenZiel)
{
	int lenQuelle = str_length(quelle);

	if (lenQuelle - count > lenZiel) {
		printf("Error");
		return;
	}

	// copy first part into ziel
	for (int i = 0; i < pos; i++) {

		ziel[i] = quelle[i];
	}

	// copy second part into ziel
	for (int i = pos + count; i < lenQuelle; i++) {

		ziel[i - count] = quelle[i];
	}

	// terminate ziel
	ziel[lenQuelle - pos + 1] = '\0';
}

static void exercise_zeichenkettenverarbeitung_remove()
{
	char* kette = "ABCD123EFGHIJK";

	char ergebnis[100];

	str_remove(kette, 4, 3, ergebnis, 100);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}

// =====================================================================================

void exercise_zeichenkettenverarbeitung()
{
	exercise_zeichenkettenverarbeitung_01_chr_replace();
	exercise_zeichenkettenverarbeitung_02_chr_insert();
	exercise_zeichenkettenverarbeitung_03_chr_remove();

	//exercise_zeichenkettenverarbeitung_insert();
	//exercise_zeichenkettenverarbeitung_remove();
}

// =====================================================================================
// End-of-File
// =====================================================================================