# Elementare Zeichenketteroperationen: `length`, `replace` und `insert`

[Zurück](./../Exercises.md)

---

## Übersicht

Realisieren Sie ein oder mehrere Funktionen, die auf Zeichenketten operieren:

  * `length` &ndash; Berechnet die Länge einer Zeichenkette.
  * `replace` &ndash; Ersetzen eines Zeichens oder einer Zeichenkette.
  * `append` &ndash; Anhängen eines Zeichens oder einer Zeichenkette.
  * `insert` &ndash; Einfügen eines Zeichens oder einer Zeichenkette in eine andere Zeichenkette.
  * `remove` &ndash; Entfernen eines Zeichens oder einer Zeichenkette aus einer anderen Zeichenkette.

*Bemerkung*:
Die Parameter der Funktionen können bzgl. der Zeichenketten entweder den Datentyp
`char[]` oder `char*` haben.

Die Funktionen sollten folgende Schnittstelle haben:

1. für den Fall des Arbeitens mit einem einzelnen Zeichen:

```cpp
void chr_replace(char* quelle, int pos, char ch);
int  chr_insert(char* quelle, int pos, char ch, char* ziel, int length);
int  chr_remove(char* quelle, int pos, char* ziel, int length);
```

2. für den Fall des Arbeitens mit einer Zeichenkette:

```cpp
void str_append(char* ergebnis, int len, char* ziel, char* quelle);
void str_insert(char* quelle, int pos, char* toInsert, char* ziel, int lenZiel);
void str_remove(char* quelle, int pos, int count, char* ziel, int lenZiel);
```

Es folgen einige grafische Hinweise für das Realisieren dieser Funktionen:

<img src="c_string_append.svg" width="500">

*Abbildung* 1: Strategie beim Anhängen von Zeichenketten.



<img src="c_string_insert.svg" width="500">

*Abbildung* 2: Strategie beim Einfügen von Zeichenketten.

---

## Quellcode der Lösung

[*Zeichenkettenverarbeitung.c*](./Zeichenkettenverarbeitung.c)

---

[Zurück](./../Exercises.md)

---
