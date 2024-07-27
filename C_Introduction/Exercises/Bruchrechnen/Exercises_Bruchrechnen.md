# Bruchrechnen

[Zurück](./../Exercises.md)

---

## Übersicht

In dieser Aufgabe erinnern wir uns an die vergangenen Zeiten unser Schulausbildung.
Wir schreiben ein Programm, das Brüche addieren und subtrahieren kann, zum Beispiel

$\frac{1}{3} + \frac{4}{3} = \frac{5}{3}$

Einen Bruch selbst stellen mit einer Strukturvariablen des Typs `struct Fraction` dar:

```c
struct Fraction
{
	int numerator;
	int denominator;
};
```

Die englischen Bezeichner `numerator` und `denominator` stehen im Deutschen
für Zähler und Nenner.

Wenn wir zwei Brüche mit gleichem Nenner addieren,
werden die beiden Zähler addiert und der Nenner beibehalten,
wie wir im ersten Beispiel gesehen haben.

Bei der Addition von Brüchen mit verschiedenen (ungleichen) Nennern müssen
die beiden Brüche zunächst so geändert (erweitert) werden,
dass die zwei Brüche demgleichen Nennern besitzen.

Diesen neuen Nenner nennt man auch &bdquo;Hauptnenner&rdquo;.
Am einfachsten kann man den Hauptnenner ausrechnen,
indem man die Nenner der Brüche multipliziert.

Wir betrachten das an einem Beispiel:

&times;

$\frac{1}{3} + \frac{3}{4} = \frac{1 &times; 4}{3 * 4} + \frac{3 * 3}{4 * 3} = \frac{4}{12} + \frac{9}{12} = \frac{13}{12}$





---

## Quellcode der Lösung

[*HarmonischeReihe.c*](./HarmonischeReihe.c)

---

[Zurück](./../Exercises.md)

---
