// =====================================================================================
// Zeichenkettenverarbeitung.c
// =====================================================================================

#include <stdio.h>

// function prototypes
int length(char* quelle);
void replace(char* quelle, int pos, char ch);
void insert(char* quelle, int pos, char ch, char* ziel);

int length(char* quelle)
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

void replace(char* quelle, int pos, char ch) {

	int lenQuelle = length(quelle);

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

	replace(quelle, 2, '!');
	printf("Quelle: Nachher: %s\n", quelle);
}

// =====================================================

void insert(char* quelle, int pos, char ch, char* ziel) {

	int lenQuelle = length(quelle);
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
	insert(quelle, 2, '!', ziel);
	printf("Ziel:   %s\n", ziel);
}

void exercise_zeichenkettenverarbeitung()
{
	exercise_zeichenkettenverarbeitung_01();
	exercise_zeichenkettenverarbeitung_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================