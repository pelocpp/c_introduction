# Aufgabe zur Parameterübergabe mit Adressen

[Zurück](./../Exercises.md)

---

## Übersicht

Schreiben Sie eine Funktion `swap`,
die zwei `int`-Parameter `x` und `y` hat.

Ein Aufruf von `swap` soll die beiden Werte der Variablen,
die an  `swap` übergeben werden, tauschen.

Ein mögliches Hauptprogramm könnte so aussehen:

```c
01: void exercise_tausche()
02: {
03:     printf("Funktion swap\n");
04:     printf("=============\n");
05: 
06:     int n = 123;
07:     int m = 456;
08: 
09:     printf("n = % d, m = % d\n", n, m);
10: 
11:     swap(&n, &m);
12: 
13:     printf("n = % d, m = % d\n", n, m);
14: }
```

*Ausgabe*:


```
Funktion swap
=============
n =  123, m =  456
n =  456, m =  123
```


---

## Quellcode der Lösung

[*Tausche.c*](./Tausche.c)

---

[Zurück](./../Exercises.md)

---
