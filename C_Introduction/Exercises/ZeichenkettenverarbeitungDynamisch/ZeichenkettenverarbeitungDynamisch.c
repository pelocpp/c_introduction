// =====================================================================================
// ZeichenkettenverarbeitungDynamisch.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>

static int str_length(char* s)
{
	int length = 0;
	while (s[length] != '\0') length++;
	return length;
}

static char* str_append_01(char* original, char* toAppend)
{
	// Berechne Länge des Ergebnisstrings
	int lenTotal = str_length(original) + str_length(toAppend) + 1;

	// Speicher fuer Ergebniszeichenkette reservieren
	char* result = malloc(sizeof(char) * lenTotal);
	if (result == NULL) return NULL;

	// Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
	int i = 0;
	while (original[i] != '\0') {
		result[i] = original[i];
		i++;
	}

	// Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
	int j = 0;
	while (toAppend[j] != '\0') {
		result[i] = toAppend[j];
		j++;
		i++;
	}

	// terminierende Null anhängen
	result[i] = '\0';

	return result;
}

static int str_append_02(char* original, char* toAppend, char** result)
{
	// Berechne Länge des Ergebnisstrings
	int lenTotal = str_length(original) + str_length(toAppend) + 1;

	// Speicher fuer Ergebniszeichenkette reservieren
	char* tmp = malloc(sizeof(char) * lenTotal);
	if (result == NULL) return -1;

	// Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
	int i = 0;
	while (original[i] != '\0') {
		tmp[i] = original[i];
		i++;
	}

	// Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
	int j = 0;
	while (toAppend[j] != '\0') {
		tmp[i] = toAppend[j];
		j++;
		i++;
	}

	// Terminierende Null anhängen
	tmp[i] = '\0';

	// Heap-Zeigervariable nach aussen reichen
	*result = tmp;

	return lenTotal;
}

void exercise_zeichenkettenverarbeitung_dynamisch()
{
	char* result = NULL;

	// 1. Variante: einfachere Betrachtung
	result = str_append_01("Hello ", "World!");
	printf("Ergebnis 1: %s\n", result);
	free(result);

	// 2. Variante: Rückgabe des Ergebnisses durch einen Adress-Parameter
	result = NULL;
	int length = str_append_02("Hello ", "World!", &result);
	printf("Ergebnis 2: %s (Length: %d)\n", result, length);
	free(result);
}

// =====================================================================================
// End-of-File
// =====================================================================================
