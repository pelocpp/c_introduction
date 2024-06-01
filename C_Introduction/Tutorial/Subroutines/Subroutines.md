# Funktionen / Unterprogramme

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines


*Beispiel*:

```c
01: // Vorwärtsdeklaration / Forward Declaration
02: void printHello(int count, float demoWert); 
03: 
04: static void testSubroutine()
05: {
06:     int wieOft = 7;
07: 
08:     printHello(wieOft, 123.456F);   // Aufruf
09: }
10: 
11: // procedure
12: static void printHello(int count, float demoWert)
13: {
14:     printf("demoWert: %f\n", demoWert);  // %d => dezimalen Wert
15: 
16:     if (demoWert < 0.0F) {
17:         return;
18:     }
19: 
20:     for (int i = 0; i < count; ++i) {
21:         printf("Hello\n");
22:     }
23: }
24: 
25: // function
26: static int summeMalZehn(int zahl1, int zahl2)
27: {
28:     int result;
29: 
30:     result = zahl1 + zahl2;
31: 
32:     return 10 * result;
33: }
34: 
35: static void testFunction()
36: {
37:     int ergebnis = 0;
38: 
39:     int ergebnisVonPrintf = 0;
40: 
41:     ergebnis = summeMalZehn(11, 12);
42: 
43:     ergebnisVonPrintf = printf("Ergebnis: %d\n", ergebnis);
44: 
45:     printf("ergebnisVonPrintf: %d\n", ergebnisVonPrintf);
46: }
```


---

## Quellcode des Beispiels:

[*Array.c*](Subroutines.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
