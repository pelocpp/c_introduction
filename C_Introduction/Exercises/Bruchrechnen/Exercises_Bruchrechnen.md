# Bruchrechnen

[Zurück](./../Exercises.md)

---

## Übersicht

Literatur hinzuzufügen




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
dass die zwei Brüche den gleichen Nennern besitzen.

Diesen neuen Nenner nennt man auch &bdquo;Hauptnenner&rdquo;.
Am einfachsten kann man den Hauptnenner ausrechnen,
indem man die Nenner der Brüche multipliziert.

Wir betrachten das an einem Beispiel:

$\frac{1}{3} + \frac{3}{4} = \frac{1 * 4}{3 * 4} + \frac{3 * 3}{4 * 3} = \frac{4}{12} + \frac{9}{12} = \frac{13}{12}$

Eine Subtraktion zweier Brüche geht genauso wie die Addition.
Wenn die Nenner gleich sind, sind die Zähler von einander abziehen und der Nenner ist beizubehalten.

Sind die Nenner verschieden, muss zunächst der Hauptnenner berechnet werden.
Mit dem Hauptnenner sind die Brüche entsprechend zu erweitern, dann sind die Zähler von einander abzuziehen
(mit beibehaltenem Hauptnenner).

Eine Multiplikation von Brüchen wiederum gestaltet sich sehr einfach.
Brüche werden multipliziert, indem man sowohl die Zähler als auch die Nenner miteinander multipliziert.
Das Ergebnis kürzt man, wenn möglich:

$\frac{1}{2} * \frac{3}{4} = \frac{3}{8}$

oder 

$\frac{2}{8} * \frac{2}{8} = \frac{4}{64} = \frac{1}{16}$

---

## Quellcode der Lösung

[*Bruchrechnen.c*](./Bruchrechnen.c)

---

[Zurück](./../Exercises.md)

---
