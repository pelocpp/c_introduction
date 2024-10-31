# Zeichen und Zeichenketten

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

Wir betrachten:

  * Zeichen
  * ASCII-Tabelle
  * Zeichenketten
  * Terminierende Null
  * Konstante und nicht-konstante Zeichenketten

---

## Zeichen

Zeichen werden in C auf den Datentyp `char` abgebildet.


*Beispiel*:

```c
01: void test()
02: {
03:     char ch;
04:     int n;
05: 
06:     ch = 'A';
07:     printf("%c\n", ch);
08: 
09:     ch = '*';
10:     printf("%c\n", ch);
11: 
12:     n = ch;
13:     printf("%c\n", ch);
14: 
15:     ch = 65;                 // ASCII table: 'A' == 65
16:     printf("%c\n", ch);
17: }

```

*Ausführung*:

```
A
*
*
A
```

Man beachte in dem Beispiel den Zusammenhang der beiden Datentypen `char` und `int`,
siehe dazu auch die ASCII-Tabelle:

<img src="ASCII_Table.png" width="700" />

*Abbildung* 1: Die ASCII_Tabelle.

ASCII steht für *American Standard Code for Information Interchange*.
Die Zeichen 0 bis 127 wurden schon vor langer Zeit festgelegt, als der ASCII-Code noch ein 7 Bit-Code
war. Später hat IBM einen erweiterten ASCII-Code mit 8 Bit eingeführt, der zusätzlich die Zeichen 128 bis
255 umfasst.

---

## Zeichenketten

Hier müssen wir unterscheiden:

  * Konstante Zeichenketten werden in der Programmiersprache C auf den Datentyp `const char*` abgebildet.

  * Datenbereiche für Zeichenketten werden auf den Datentyp `char buffer[]` oder `const char buffer[]` abgebildet.
    Im ersten Fall kann man den Datenbereich ändern, im zweiten Fall nicht.

Es stehen in C auch Funktionen für Verkettung, Vergleich, Kopie usw. zur Verfügung.

Diese so genannten &bdquo;Zeichenkettenverarbeitungsfunktionen&rdquo; gehören zur C-Bibliothek CRT (*C-Runtime-Library*).


Der Begriff der &bdquo;*terminierenden Null*&rdquo; ist zu betrachten.

---

## Quellcode des Beispiels:

[*Strings.c*](Strings.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
