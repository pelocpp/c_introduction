# Aufgabe zu Arrays: Zinsrechnung mit Berechnung des Zinseszins

[Zurück](./../Exercises.md)

---

## Übersicht

Schreiben Sie eine Funktion `doubleInterestRateWithWithAccumulation`,
die in zwei Parametern `capital` und `rate` ein Startkapital und einen Zinssatz (pro Jahr) entgegennimmt:

```c
int doubleInterestRateWithWithAccumulation(double capital, double rate, double accumulation[], int length)
```

Als Rückgabewert liefert die Funktion einen ganzzahligen Wert zurück, der beschreibt,
nach wie vielen Jahren das eingesetzte Kapital sich verdoppelt hat.

In zwei weiteren Parametern `accumulation` und `length` werden ein Array und die Länge des Arrays
an die Funktion übergeben.

Nach der Rückkehr der Funktion findet man im Array die jährliche Anhäufung
des Startkapitals und der angehäuften Zinsen vor.


*Beispiel*:

```
After 15 years, a capital of 1000.000000 with interest rate  5.00 is doubled!
 1. years: capital = 1050.00
 2. years: capital = 1102.50
 3. years: capital = 1157.62
 4. years: capital = 1215.51
 5. years: capital = 1276.28
 6. years: capital = 1340.10
 7. years: capital = 1407.10
 8. years: capital = 1477.46
 9. years: capital = 1551.33
10. years: capital = 1628.89
11. years: capital = 1710.34
12. years: capital = 1795.86
13. years: capital = 1885.65
14. years: capital = 1979.93
15. years: capital = 2078.93
```

---

## Quellcode der Lösung

[*ZinsberechnungMitArray.c*](./ZinsberechnungMitArray.c)<br />

---

[Zurück](./../Exercises.md)

---
