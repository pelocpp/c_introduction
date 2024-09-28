# Strukturen

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*1. Beispiel*: Definition einer Struktur


```c
01: struct time
02: {
03:     int hours;
04:     int minutes;
05:     int seconds;
06: };
07: 
08: typedef struct time Time;
```

*2. Beispiel*: ZUgriff auf die Elemente einer Struktur


```c
01: Time now;
02: now.hours = 11;
03: now.minutes = 9;
04: now.seconds = 33;
```


*3. Beispiel*: Unterschiedliche Möglichkeiten der Initialisierung


```c
01: // ----------------------
02: // using initializer list
03: 
04: Time t1 = { 9, 15, 30 };
05: 
06: Time t2 = { 9 };
07: 
08: // -------------------------------------------
09: // designated initializers for aggregate types
10: 
11: Time t3 = { .hours = 10, .minutes = 30, .seconds = 59};
12: 
13: Time t4 = { .hours = 10 };
14: 
15: Time t5 = { .seconds = 10 };
16: 
17: Time t6 = { .seconds = 20, .minutes = 30, .hours = 12 };
```

---

## Quellcode des Beispiels:

[*Structs.c*](Structs.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
