# Aufgabe zu einem Geldbeutel: Struktur `Wallet`


[Zurück](./../Exercises.md)

---

## Übersicht

Schreiben Sie eine Struktur `Wallet`, die einen *Geldbeutel* (*Portemonnaie*, ein aus dem Französischen stammender Begriff)
repräsentiert.
Im Geldbeutel sind Euros und Cent enthalten.
Dabei sollten nicht mehr als 99 Cent in dem Geldbeutel sein,
bei größeren Cent-Beträgen ist der Euro-Betrag entsprechend aufzurunden.

Logischerweise kann ein Geldbeutel keine negativen Geldbeträge enthalten.
Es ist bei allen Funktionen in der Realisierung der Struktur `Wallet` darauf zu achten,
dass niemals mehr Geld entnommen wird als sich in dem Geldbeutel befindet.

Folgende Aktivitäten sollten mit einem Geldbeutel möglich sein:

  * Geld hinzufügen.
  * Geld entnehmen, allerdings nicht mehr, als im Geldbeutel ist.
  * Den Inhalt zweier Geldbeutel vergleichen.
  * Nur Euros hinzufügen.
  * Nur Euros entnehmen.
  * Einen Geldbeutel mit der Funktion `print` auf der Konsole ausgeben.
  * Einen Euro hinzufügen.
  * Einen Euro entnehmen.

---

## Beispiele

Die folgenden zwei Beispiele demonstrieren den Umgang mit der Struktur `Wallet`:

```cpp
01: void test()
02: {
03:     struct Wallet wallet1 = { 123, 45 };
04:     struct Wallet wallet2 = { 3, 30 };
05:     struct Wallet wallet3 = { 3, 30 };
06: 
07:     print(&wallet1);
08: 
09:     addWallet(&wallet1, &wallet2);
10:     print(&wallet1);
11: 
12:     addWallet(&wallet1, &wallet3);
13:     print(&wallet1);
14: 
15:     unsigned long long cents = toCents(&wallet1);
16:     printf("Cents: %llu\n", cents);
17: }
```

*Ausgabe*:


```
123:45
126:75
130:05
Cents: 13005
```

Und noch ein zweites Beispiel:


```cpp
01: void test()
02: {
03:     struct Wallet wallet1 = { 0, 3 };
04:     struct Wallet wallet2 = { 0, 1 };
05: 
06:     print(&wallet1);
07: 
08:     subWallet(&wallet1, &wallet2);
09:     print(&wallet1);
10: 
11:     subWallet(&wallet1, &wallet2);
12:     print(&wallet1);
13: 
14:     subWallet(&wallet1, &wallet2);
15:     print(&wallet1);
16: 
17:     subWallet(&wallet1, &wallet2);
18:     print(&wallet1);
19: }
```

*Ausgabe*:


```
0:03
0:02
0:01
0:00
Not enough money available in wallet!
0:00
```

---

## Quellcode der Lösung

[*Wallet.c*](./Wallet.c)

---

[Zurück](./../Exercises.md)

---
