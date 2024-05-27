# Aufgabe zur teuflischen Folge

[Zurück](./../Exercises.md)

---

## Übersicht

Die teuflische Folge oder auch als das &bdquo;Collatz-Problem&rdquo; oder auch als &bdquo;3*n* + 1&rdquo;&ndash;Vermutung bezeichnet,
ist ein ungelöstes mathematisches Problem und wird dem Mathematiker *Lothar Collatz* zugeschrieben.

Unter einer *Zahlenfolge* (auch Zahlenreihe) verstehen wir in der Mathematik eine Auflistung
von endlich (oder auch unendlich) vielen fortlaufenden Zahlen.
Die Zahl mit der Nummer *i* &ndash; man sagt hier auch: mit dem Index *i* &ndash; wird *i*.-tes Glied der Folge genannt.

Bei dem Problem geht es um Zahlenfolgen, die nach einem sehr einfachen Bildungsgesetz konstruiert werden.
Gegeben ist eine beliebige natürliche Startzahl *n*, aus der eine Folge von Zahlen nach den folgenden zwei Regeln gebildet wird:

  * Ist die Zahl *n* gerade, so ist die nächste Zahl gleich der Hälfte der Zahl.
  * Ist die Zahl *n* ungerade, so wird die Zahl mit 3 multipliziert und um 1 erhöht

Merkwürdigerweise erreicht diese Folge nach endlich vielen Schritten immer die Zahl 1.
Man kann die Vermutung auch so betrachten:
Jede Folge mündet in den Zyklus 4, 2, 1 &ndash; egal, mit welcher Startzahl man die Folge startet.

Wählen wir zum Beispiel den Startwert 7, so lautet die Folge

7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1.

Schreiben Sie ein C-Programm, das zu einem fest im Programm eingebauten Startwert alle Folgenglieder in der Konsole ausgibt.

Eine mögliche Ausgabe des Programms könnte so aussehen:

```
Teuflische Zahlenfolge
======================
Start: 7

  1: Zahl = 22
  2: Zahl = 11
  3: Zahl = 34
  4: Zahl = 17
  5: Zahl = 52
  6: Zahl = 26
  7: Zahl = 13
  8: Zahl = 40
  9: Zahl = 20
 10: Zahl = 10
 11: Zahl = 5
 12: Zahl = 16
 13: Zahl = 8
 14: Zahl = 4
 15: Zahl = 2
 16: Zahl = 1
```

---

## Quellcode der Lösung

[*TeuflischeFolge.c*](./TeuflischeFolge.c)

---

[Zurück](./../Exercises.md)

---
