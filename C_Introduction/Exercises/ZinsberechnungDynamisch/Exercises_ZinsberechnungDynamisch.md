# Aufgabe zur dynamischen Speicherverwaltung: Zinsrechnung mit Berechnung des Zinseszins

[Zurück](./../Exercises.md)

---

## Übersicht

Schreiben Sie eine Funktion `doubleCapitalWithWithAccumulation`,
die in zwei Parametern `capitalStock` ein Startkapital und in `interestRate` einen Zinssatz (pro Jahr) entgegennimmt:

```c
int doubleCapitalWithWithAccumulation(double capitalStock, double interestRate)
```

Als Rückgabewert liefert die Funktion einen ganzzahligen Wert zurück, der beschreibt,
nach wie vielen Jahren das eingesetzte Kapital sich verdoppelt hat.

Im Rumpf der Funktion wird, wenn die Anzahl der Jahre bekannt ist, nach denen sich das eingesetzte Kapital verdoppelt hat,
dynamisch ein `double`-Feld dieser Länge angelegt.


In dem Feld werden pro Jahr das aktuell vorhandene Kapital (inkl. Zinsanhäufung) abgelegt und am Ende der Berechnung
in der Konsole ausgegeben.

*Beispiel*:

```
CapitalStock: 1000.00, CapitalStock: 4.00
 1. Year: 1040.00
 2. Year: 1081.60
 3. Year: 1124.86
 4. Year: 1169.86
 5. Year: 1216.65
 6. Year: 1265.32
 7. Year: 1315.93
 8. Year: 1368.57
 9. Year: 1423.31
10. Year: 1480.24
11. Year: 1539.45
12. Year: 1601.03
13. Year: 1665.07
14. Year: 1731.68
15. Year: 1800.94
16. Year: 1872.98
17. Year: 1947.90
18. Year: 2025.82
Doubled capital stock in 18 years.
```

---

## Quellcode der Lösung

[*ZinsberechnungDynamisch.c*](./ZinsberechnungDynamisch.c)<br />

---

[Zurück](./../Exercises.md)

---
