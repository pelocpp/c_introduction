# Datentypen, Variablen and Konstanten

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

Wir betrachten:

  * Elementare Datentypen (`int`, `short`, `long`, `long long`, `char`, `float`, `double`, `char`)
  * Wertebereiche, `sizeof`-Operator
  * Vorzeichenlose und -behaftete Werte
  * Konstanten
  * Zeichenkettenkonstanten (`char*`)


*Ausgabe des Beispiels*:

```
sizeof (int):         4
sizeof (long):        4
sizeof (short):       2
sizeof (long long):   8
sizeof (size_t):      8

Maximum Values
unsigned char:        255
unsigned short:       65535
unsigned int:         4294967295
unsigned long:        4294967295
unsigned long long:   18446744073709551615
size_t:               18446744073709551615

Maximum Values
signed char:          127
signed short:         32767
signed int:           2147483647
signed long:          2147483647
signed long long:     9223372036854775807

Minumum Values
signed char:          -128
signed short:         -32768
signed int:           -2147483648
signed long:          -2147483648
signed long long:     -9223372036854775808
```

---

## Quellcode des Beispiels:

[*DatatypesVariablesConstants.c*](DatatypesVariablesConstants.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
