# Aufgabe zum Pascal’schen Dreieck

[Zurück](./../Exercises.md)

---

## Übersicht

Das *Pascal’sche Dreieck* ist eine Form der grafischen Darstellung der Binomialkoeffizienten $`\binom{n}{k}`$.
Der Name des Dreiecks geht auf den französischen Mathematiker *Blaise Pascal* zurück.

Mathematisch könnte man diese Beobachtung auch aus der Gleichung

$$ \binom{n+1}{k+1} = \binom{n}{k} + \binom{n}{k+1} $$

ableiten. Die Variable *n* kann man als Zeilenindex, die zweite Variable *k* als Spaltenindex interpretieren.
Die Zählung beginnt mit Null, also erste Zeile *n* = 0, erste Spalte *k* = 0.
Beginnt man an den Rändern mit dem Wert 1, so ergeben sich auf diese Weise genau die Binomialkoeffizienten:

<img src="PascalTriangle_01.png" width="450">

*Abbildung* 1. Das *Pascal’sche Dreieck* und Binomialkoeffizienten.

In dieser Aufgabe sollen die Binomialkoeffizienten berechnet werden, und zwar auf Basis der Ablage 
der Werte in einem zweidimensionalen C-Array.
Die Ränder, also der jeweils erste und letzte Wert einer Reihe werden mit dem Wert 1 vorbelegt.
Alle anderen Werte werden durch einen &bdquo;Blick&rdquo; in die darüberliegende Zeile berechnet:
Ein zu berechnender Wert ergibt sich durch die Summe der beiden unmittelbar darüberliegenden Werte,
siehe dazu auch *Abbildung* 2:


<img src="PascalTriangle_02.png" width="450">

*Abbildung* 2. Berechnung der Werte eines *Pascal’schen Dreiecks*.

## Aufgabe

Schreiben Sie zwei Funktionen `createPascalTriangle` und  `printPascalTriangle`,
die ein *Pascal’sche Dreieck* berechnen und in der Konsole ausgeben.

Beide Funktionen haben einen ganzzahligen Wert als Parameter, der die Anzahl der Zeilen festlegt.
Verwenden Sie in der Realisierung ein zweidimensionales Feld in C.

Eine mögliche Ausgabe des Programms könnte für 8 Zeilen so aussehen:

```
  1   0   0   0   0   0   0   0
  1   1   0   0   0   0   0   0
  1   2   1   0   0   0   0   0
  1   3   3   1   0   0   0   0
  1   4   6   4   1   0   0   0
  1   5  10  10   5   1   0   0
  1   6  15  20  15   6   1   0
  1   7  21  35  35  21   7   1
```


*Bemerkung*: Sie werden die Beobachtung machen, dass zur Berechnung eines *Pascal’schen Dreiecks*
nicht alle Werte des zweidimensionalen Felds benötigt werden.
Eine verbesserte Realisierung finden Sie im Abschnitt *Jagged Arrays* (*zackige Felder*) vor.


---

## Quellcode der Lösung

[*PascalTriangle.c*](./PascalTriangle.c)

---

[Zurück](./../Exercises.md)

---
