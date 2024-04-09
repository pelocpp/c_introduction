# Elementare Zeichenketteroperationen: `length`, `replace` und `insert`

[Zurück](./../Exercises.md)

---

## Übersicht

Realisieren Sie drei Funktionen, die auf Zeichenketten operieren:

  * `length` &ndash; Berechnet die Länge einer Zeichenkette.
  * `replace` &ndash; Ersetzen eines Zeichens.
  * `insert` &ndash; Einfügen einer Zeichenkette in eine andere Zeichenkette.
  * `append` &ndash; Anhängen einer Zeichenkette an eine andere Zeichenkette.

*Bemerkung*:
Die Parameter der Funktionen können bzgl. der Zeichenketten entweder den Datentyp
`char[]` oder `char*` haben.

Die drei Funktion sollten folgende Schnittstelle haben:

```cpp
// function prototypes
int length(char* quelle);
void replace(char* quelle, int pos, char ch);
void insertChar(char* quelle, int pos, char ch, char* ziel);
void append(char* quelle, int pos, char ch, char* ziel);
```



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
