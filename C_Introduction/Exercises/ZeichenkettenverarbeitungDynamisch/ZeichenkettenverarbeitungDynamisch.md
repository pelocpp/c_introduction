# Aufgabe zur Zeichenkettenverarbeitung mit dynamisch allokiertem Speicher

[Zurück](./../Exercises.md)

---

## Übersicht

Wir betrachten folgenden C-Funktionsprototyp:


```c
void str_append(char* original, char* toAppend);
```

Es sollen zwei Zeichenketten aneinander angehängt werden,
also das Ergebnis eines str_append-Funktionsaufrufs angewendet auf die beiden 
Zeichenketten `"Hello "` und `"World!"` sollte die Resultatzeichenkette
 `"Hello World!"` bilden.

Im Prinzip sollte die Aufgabenstellung einfach verständlich sein,
die einzig noch zu klärende Frage dürfte sein: &bdquo;Wohin mit der Ergbniszeichenkette?&rdquo;

Dies wollen wir mit den Möglichkeiten der dynamischen Speicherverwaltung in C,
also mit den beiden Bibliotheksfunktionen `malloc` und `free` angehen.

In einer ersten Verfeinerung der Funktionsschnittstelle `str_append`
könnte folgende beiden Schnittstellen zum Ziel führen:


```c
char* str_append(char* original, char* toAppend)
```

oder


```c
int str_append(char* original, char* toAppend, char** result);
```

In der ersten der beiden Schnittstellen wird das Ergebnis
(das auf der Halde durch `malloc` gebildet worden ist)
als Ergebnis der Funktion zurückgeliefert.

In einer zweiten Variante wird der Heap-Zeiger durch einen Adressparamter (hier: `result`)
zurückgeliefert. Der damit noch zur Verfügung stehende Rückgabewert
könnte dann zum Beispiel die Länge der Ergbniszeichenkette zurücklieferen.

Realisieren Sie eine der beiden `str_append`-Varianten.

Beispiel:


```c
01: void exercise()
02: {
03: 	char* result = NULL;
04: 
05: 	result = str_append("Hello ", "World!");
06: 	printf("Ergebnis: %s\n", result);
07: 	free(result);
08: }
```

*Ausgabe*:


```
Ergebnis: Hello World!
```

---

## Quellcode der Lösung

[*Tausche.c*](./ZeichenkettenverarbeitungDynamisch.c)

---

[Zurück](./../Exercises.md)

---
