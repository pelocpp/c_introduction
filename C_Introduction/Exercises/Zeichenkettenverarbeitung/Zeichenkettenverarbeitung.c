// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// function prototypes
int  strLength(char* quelle);

void chrReplace(char* quelle, int pos, char ch);
void chrRemove(char* quelle, int pos, char ch, char* ziel);

void strAppend(char* ergebnis, int len, char* ziel, char* quelle);
void strInsert(char* quelle, int pos, char* toInsert, char* ziel, int lenZiel);
void strRemove(char* quelle, int pos, int count, char* ziel, int lenZiel);

// =====================================================================================

int strLength(char* quelle)
{
	int result = 0;
	int pos = 0;

	while (quelle[pos] != '\0') {
		pos++;
		result++;
	}

	return result;
}

// =====================================================================================

void chrReplace(char* quelle, int pos, char ch) {

	int lenQuelle = strLength(quelle);

	if (pos >= lenQuelle) {
		return;
	}

	quelle[pos] = ch;
}

void exercise_zeichenkettenverarbeitung_01()
{
	//  "ABCDE", an der Position 3 das 'D' durch ein '!' ersetzen ===> "ABC!E"

	// char* quelle = "ABCDE";  // VORSICHT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//                "ABCDE" liegt im Codesegment -- hier ist ein SCHREIBEN VERBOTEN / Absturz

	char quelle[] = "ABCDE";
	// Haben wir mit quelle ein Array, das am Stack liegt
	// Es wird "ABCDE" in das Array umkopiert, bzw. das Array damit vorgelegt.

	printf("Quelle: Vorher:  %s\n", quelle);

	chrReplace(quelle, 2, '!');
	printf("Quelle: Nachher: %s\n", quelle);
}

// =====================================================

void chrRemove(char* quelle, int pos, char ch, char* ziel) {

	int lenQuelle = strLength(quelle);
	if (pos > lenQuelle) {
		return;
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
	// ziel[index] = '\0';        // oder
	ziel[lenQuelle + 1] = '\0';
}

void exercise_zeichenkettenverarbeitung_02()
{
	// "ABCDE"  , an der Position 3 ein '!' einfuegen ===> "ABC!DE"
	char* quelle = "ABCDE";
	printf("Quelle: %s\n", quelle);

	char ziel[100];
	chrRemove(quelle, 2, '!', ziel);
	printf("Ziel:   %s\n", ziel);
}

// =====================================================

void strAppend(char* ergebnis, int len, char* ziel, char* quelle)
{
	int lenZiel = strLength(ziel);

	int lenQuelle = strLength(quelle);

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

void exercise_zeichenkettenverarbeitung_append()
{
	char* kette1 = "ZIEL";

	char* kette2 = "QUELLE";

	char ergebnis[100];

	strAppend(ergebnis, 100, kette1, kette2);   // "ZIELKETTE" 

	printf("Ergebnis: %s\n", ergebnis);  // <=== "ZIELKETTE"  !!!
}

// ====================================================================

void strInsert(char* quelle, int pos, char* toInsert, char* ziel, int lenZiel)
{
	int lenQuelle = strLength(quelle);

	int lenToInsert = strLength(toInsert);

	if (lenQuelle + lenToInsert + 1 >= lenZiel) { 
		printf("Error");
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

void exercise_zeichenkettenverarbeitung_insert()
{
	char* kette1 = "ABCDE";

	char* kette2 = "123";

	// Beispiel: "ABCDE" = 5, "123" = 3 , Null = 1 ==> 

	char ergebnis[9];  // das ist ein Feld von Zeichen ==> Zeichenkette

	strInsert(kette1, 2, kette2, ergebnis, 9);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}

// =====================================================

void strRemove(char* quelle, int pos, int count, char* ziel, int lenZiel)
{
	int lenQuelle = strLength(quelle);

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

void exercise_zeichenkettenverarbeitung_remove()
{
	char* kette = "ABCD123EFGHIJK";

	char ergebnis[100];
	
	strRemove(kette, 4, 3, ergebnis, 100);

	printf("Ergebnis: %s\n", ergebnis);  // <=== "12ABC345"  !!!
}



// =====================================================




void exercise_zeichenkettenverarbeitung()
{
	//exercise_zeichenkettenverarbeitung_01();
	//exercise_zeichenkettenverarbeitung_02();
	//exercise_zeichenkettenverarbeitung_02();

	exercise_zeichenkettenverarbeitung_insert();
	// exercise_zeichenkettenverarbeitung_remove();
}

// =====================================================================================
// End-of-File
// =====================================================================================
