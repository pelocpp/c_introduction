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
  * Einen Geldbeutel mit einer Funktion `print` auf der Konsole ausgeben.
  * Einen Euro hinzufügen.
  * Einen Euro entnehmen.

---

## Beispiele

Die folgenden zwei Beispiele demonstrieren den Umgang mit der Struktur `Wallet`:

```c
01: void test()
02: {
03:     struct Wallet wallet = { 0, 0 };
04: 
05:     print(&wallet);
06: 
07:     addEurosAndCents(&wallet, 10, 50);
08:     print(&wallet);
09: 
10:     subEurosAndCents(&wallet, 5, 75);
11:     print(&wallet);
12: 
13:     unsigned long long cents = toCents(&wallet);
14:     printf("Cents: %llu\n", cents);
15: }
```

*Ausgabe*:


```
0,00 Euro
10,50 Euro
4,75 Euro
Cents: 475
```

Und noch ein zweites Beispiel:

```c
01: void exercise_wallet_02()
02: {
03:     struct Wallet wallet1 = { 3, 30 };
04:     struct Wallet wallet2 = { 3, 30 };
05: 
06:     print(&wallet1);
07:     print(&wallet2);
08: 
09:     int equal = equals(&wallet1, &wallet2);
10:     printf("Wallets are equal: %d\n", equal);
11: 
12:     subEurosAndCents(&wallet1, 3, 28);
13:     print(&wallet1);
14: 
15:     subEurosAndCents(&wallet1, 0, 1);
16:     print(&wallet1);
17: 
18:     subEurosAndCents(&wallet1, 0, 1);
19:     print(&wallet1);
20: 
21:     subEurosAndCents(&wallet1, 0, 1);
22:     print(&wallet1);
23: }
```

*Ausgabe*:


```
3,30 Euro
3,30 Euro
Wallets are equal: 1
0,02 Euro
0,01 Euro
0,00 Euro
Not enough money available in wallet!
0,00 Euro
```

---

## Quellcode der Lösung

[*Wallet.h*](./Wallet.h)<br />
[*Wallet.c*](./Wallet.c)

---

[Zurück](./../Exercises.md)

---
