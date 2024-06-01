# Arrays auswerten: Summe, Minimum und Maximum

[Zurück](./../Exercises.md)

---

## Übersicht

Entwerfen Sie ein Programm zur Berechnung der Summe sowie der kleinsten und größten Zahl
in einem ganzzahligen Feld.

Das Feld &ndash; mit einer überschaubaren Länge von beispielsweise 10 Elementen &ndash;
ist dabei zunächst mit Zufallszahlen im Bereich von 1 bis 100 (einschließlich) vorzubelegen.

Zufallszahlen können Sie in C so erzeugen:

```c
int zahl = rand();
```

Um die Bibliotheksfunktion `rand` benutzen zu können,
müssen Sie die `#include`-Datei `<stdlib.h>` inkludieren.

Möchten Sie wirklich &bdquo;zufällige Zahlen&rdquo; erzeugen,
müssen Sie den Zufallszahlengenerator mit einer &bdquo;zufälligen&rdquo; Startzahl initialisieren.
Dies geht so:

```c
#include <time.h>
...
time_t t;
srand((unsigned) time(&t));
```

Geben Sie das Resultat in der Konsole aus.

*Beispiel*:

```
Summe
=====
44
47
51
88
56
78
87
25
78
50

Summe: 604

Minumum
=======
44
47
51
88
56
78
87
25
78
50

Minimum: 25

Maximum
=======
44
47
51
88
56
78
87
25
78
50

Maximum: 88
```

---

## Quellcode der Lösung

[*ArraySumMinMax.c*](./ArraySumMinMax.c)<br />


---

[Zurück](./../Exercises.md)

---
