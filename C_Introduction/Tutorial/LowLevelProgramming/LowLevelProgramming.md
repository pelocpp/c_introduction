# Low-Level Programmierung in C

[Zurück](../../Markdown/Agenda.md)

---

## Quellcode des Beispiels:

[*LowLevelProgramming.c*](LowLevelProgramming.c)<br />

---

## Allgemeines

Wir betrachten in diesem Abschnitt eine Reihe von C&ndash;Funktionen,
die in die Kategorie *Low-Level Programming* fallen.

Es werden die vier Operatoren zur Bitmanipulation (engl. *bitwise operators*) 
`&`, `|`, `^` und `~` sowie die beiden
Shift-Operatoren `<<` und `>>` an entsprechenden Beispielen vorgeführt.


| Funktion | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Funktion `setBit` | `void setBit(unsigned int value, int position);`<br/>Setzt in Variable `value` das Bit an Position `pos`. |
| Funktion `clearBit` | `void clearBit(unsigned int value, int pos);`<br/>Löscht in Variable `value` das Bit an Position `pos`. |
| Funktion `isBitSet` | `bool isBitSet(unsigned int value, int pos);`<br/>Liefert `true` zurück, wenn in Variable `value` das Bit an Position `pos` gesetzt ist, andernfalls `false`. |
| Funktion `isBitCleared` | `bool isBitCleared(unsigned int value, int pos);`<br/>Liefert `true` zurück, wenn in Variable `value` das Bit an Position `pos` nicht gesetzt ist, andernfalls `false`. |

*Tabelle* 1. Exemplarische Funktionen zur Low-Level Programmierung in C.

---

[Zurück](../../Markdown/Agenda.md)

---
