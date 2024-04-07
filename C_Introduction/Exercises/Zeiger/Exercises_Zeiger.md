# Aufgabe zum Datentyp *Zeiger* (*Pointer*)

[Zurück](./../Exercises.md)

---

## Übersicht

Bestimmen Sie die Bildschirmausgabe des nachstehenden Algorithmus,
ohne das Programm jedoch auszuführen:

```
01: #include <stdio.h>
02: 
03: void calculate (int* a, int b)
04: {
05:     *a = 4;
06:     b = b + *a;
07:     printf("%d - %d\n", *a, b);
08: }
09: 
10: void main()
11: {
12:     int a = 3;
13:     int b = 5;
14: 
15:     calculate(&a, b);
16:     printf("%d - %d\n", a, b);
17: 
18:     calculate(&b, a);
19:     printf("%d - %d\n", a, b);
20: }
```

Verwenden Sie als Hilfestellung eine &bdquo;*Variablentabelle*&rdquo;:
Führen Sie das Programm &bdquo;im Kopf&rdquo; Zeile für Zeile aus
und notieren Sie dabei die aktuellen Werte der Variablen in dieser Tabelle,
um auf diese Weise die jeweiligen `printf`-Anweisungen nachvollziehen zu können.


<img src="c_pointer_tabelle_stack.svg" width="300">

*Abbildung* 1: &bdquo;*Variablentabelle*&rdquo; zum Verifizieren der Programmausführung.

---

## Quellcode der Lösung

[*Zeiger.c*](./Zeiger.c)

---

[Zurück](./../Exercises.md)

---
