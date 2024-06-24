# Hashtabellen

[Zurück](./../Exercises.md)

---

## Übersicht

Eine *Hashtabelle* ist eine dynamische Datenstruktur,
die verwendet wird, um *Schlüssel* (engl. *keys*)
und ihre dazugehörigen *Werte* (engl. *values*)
effizient zu speichern und zu verwalten.

Hashtabellen lassen sich mit einem Nachschlagewerk vergleichen.
In einem Wörterbuch Deutsch &DoubleLeftRightArrow; Englisch kann das
Wort &bdquo;Übersetzer&rdquo; ein Schlüssel sein,
ihm ist der Wert &bdquo;Compiler&rdquo; zugeordnet.

Oder aber ein Schlüssel ist die Zeichenkette &bdquo;Franz&rdquo;,
sie besitzt den Wert &bdquo;franz.meier@gmx.de&rdquo;

---

## Aufbau

Eine Hashtabelle ist folgendermaßen aufgebaut:

  * Mit Hilfe von Schlüsseln (*keys*)
  werden Werte (*values*) in einer Tabelle gespeichert. Die Struktur der Tabelle ist nicht festgelegt.

  * Mit Hilfe des Schlüssels berechnet man einen Index &ndash; auch als *Hashwert* bezeichnet &ndash;,
  der eine bestimmte Position in dieser Tabelle identifiziert:

Die Hashwerte (Indizes) werden mit Hilfe einer *Hash-Funktion* bestimmt.

Die Größe der Tabelle orientiert sich an der Anzahl der Elemente,
die man in dieser Tabelle einsortieren möchte.
Bei 8 Elementen reicht folglich eine Tabellengröße bis zu maximal 8 Einträgen.
Zur Größe der Hashtabelle wird häufig eine Primzahl verwendet.

Berechnet sich für alle Schlüssel, die man mit ihren Werten in der Tabelle eintragen möchte,
ein unterschiedlicher Hashwert, kann man einfach ein Array als Datenstruktur für die Tabelle verwenden.

Wird mehreren Schlüsseln der gleiche Index in der Tabelle zugewiesen, lassen sich die Werte
nicht unmittelbar an dieselbe Stelle im Array schreiben.
Man spricht hier auch von einer *Kollision* oder einem *Konflikt*.
Eine mögliche Kollisionsstrategie besteht darin, alle Daten, die sich denselben Hashwert teilen,
mit einer Liste zu verketten.

---

## Hash-Funktion

Generell gilt für Hash-Funktionen: Je effizienter die Hash-Funktion, desto besser kann in der Tabelle gesucht werden.

Eine Funktion, die beispielsweise allen Werten die gleiche Stelle zuweist,
ist sehr ineffizient, da dann alle Werte in der gleichen Liste gespeichert werden
und die Hashtabelle nicht mehr effizienter als eine Liste ist,
die vom Anfang (bzw. Ende) bis zum gesuchten Wert durchgegangen werden muss.

Eine typische Hash-Funktion verwendet den Modulo-Operator:

*hash*(*k*) = *k* mod *p*

*hash*(*k*) ist die Hash-Funktion, 
*k* (*key*) ist der Wert, der einsortiert werden soll und *p* entspricht einer Primzahl.

---

## Ein Beispiel

Es sollen N Elemente mit beliebigen ganzzahligen, positiven Schlüsseln (vom Typ *int*) 
in einer Hash-Tabelle gespeichert werden.
Die Schlüssel seien beliebig verteilt über den Bereich 0 .. K.
Zur Speicherung der Elemente soll eine Tabelle mit M > N Werten verwendet werden.

Aus dem Schlüssel wird eine Position in der Tabelle berechnet.
Die Position eines Elements in der Tabelle mit dem Schlüssel *k* berechnen wir mit der folgenden Hash-Funktion:

*p* = *k* mod M

Damit können auch Schlüssel, die größer als M sind, in der Tabelle untergebracht werden.

Durch die Modulo-Funktion wird &ndash; anschaulich gesprochen &ndash; ein Teil des Schlüssels
&bdquo;abgehackt&rdquo; (engl. *to hash*).

Wir legen nun M = 7 Plätze und N = 3 Elemente fest, deren Positionen (Hash-Wert) in der Tabelle durch die
vorstehende Hash-Funktion berechnet werden.
Wir wollen die Werte 9, 40, und 77 in der Tabelle eintragen.
An Hand der zuvor erwähnten Hash-Funktion resultieren die Positionen

9 &#x2794; 2<br />
40 &#x2794; 5<br />
77 &#x2794; 0

In *Abbildung* 1 können wir erkennen, dass diese 3 Werte in einer Hash-Tabelle abgelegt werden können,
die einfach durch ein Array gegeben ist:

<img src="c_hash_01.svg" width="200">

*Abbildung* 1. Beispiel einer Hash-Tabelle mit 3 Einträgen. 

Werte haben also immer eine feste Position in der Hash-Tabelle, die von ihrem Schlüssel abhängt.


---

## Kollisionen

Leider stimmt die Annahme nicht immer, dass alle Schlüssel zu verschiedenen Positionen
in der Tabelle führen. Es können so genannte &bdquo;Konflikte&rdquo; oder &bdquo;Kollisionen&rdquo; auftreten.

Wir ändern unser Beispiel nun wie folgt ab:

13 &#x2794; 6<br />
19 &#x2794; 5<br />
34 &#x2794; 6 = Konflikt<br />
43 &#x2794; 1<br />
92 &#x2794; 1 = Konflikt<br />

Wir haben die Schlüssel absichtlich so gewählt, dass es bei Anwendung der Hash-Funktion
zu Konflikten kommt:

<img src="c_hash_02.svg" width="450">

*Abbildung* 2. Beispiel einer Hash-Tabelle, die Konflikte aufweist.

Die zuletzt dargestellten Situationen werden als *Konflikt* oder *Kollision*
bezeichnet. Es gibt verschiedenen Strategien, um Kollisionen aufzulösen.

---

## Kollisionsauflösung mit Verkettung

Hashtabellen mit Verkettung (engl. *separate chaining*) sind so strukturiert,
dass jeder Eintrag eine dynamische Datenstruktur aufnehmen kann &ndash; beispielsweise eine Liste.

Ein Schlüssel wird dann in dieser Datenstruktur eingetragen oder gesucht.
So ist es problemlos möglich, mehrere Schlüssel mit demselben Hashwert abzulegen,
was allerdings zu mehr oder weniger verlängerten Zugriffszeiten führt.

<img src="c_hash_03.svg" width="650">

*Abbildung* 3. Beispiel einer Hash-Tabelle und Kollisionsauflösung durch Verkettung.


---

## Beispiele zu den Abbildungen

*Beispiel*:

```cpp
01: void exercise_hash_table()
02: {
03:     _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
04: 
05:     initHashTable(hashTable, Limit);
06:     fillHashTable(hashTable);
07:     printHashTable(hashTable, Limit);
08: 
09:     size_t key = 1;
10:     Element* result;
11:     size_t pos;
12:     search(key, hashTable, &result, &pos);
13:     if (result != NULL) {
14:         printf("Key %zu: Value = %s\n", key, result->m_value);
15:     }
16:     else {
17:         printf("Key %zu not found!\n", key);
18:     }
19: 
20:     key = 0;
21:     search(key, hashTable, &result, &pos);
22:     if (result != NULL) {
23:         printf("Key %zu: Value = %s\n", key, result->m_value);
24:     }
25:     else {
26:         printf("Key %zu not found!\n", key);
27:     }
28: 
29:     releaseHashTable(hashTable, Limit);
30: }
```

*Ausgabe*:


```
Index |  Key   | Value
======|========|======
    0 |      0 |    77
    2 |      2 |     9
    5 |      5 |    40
```


oder im Falle von Kollisionen:


```
Index |  Key   | Value
======|========|======
    1 |     43 |    43   ==>      92 |    92
    5 |     19 |    19
    6 |     13 |    13   ==>      34 |    34
```



---

## Quellcode der Lösung

[*HashTable.h*](./HashTable.h)<br />
[*HashTable.c*](./HashTable.c)<br />
[*HashTableMainInt.c*](./HashTableMainInt.c)

[*HashTableEx.h*](./HashTableEx.h)<br />
[*HashTableEx.c*](./HashTableEx.c)<br />
[*HashTableMainString.c*](./HashTableMainString.c)

[*HashTableMain.c*](./HashTableMain.c)

---

## Literaturhinweise


Einige Anregungen zu den Beispielen aus diesem Abschnitt stammen aus dem Artikel

[Hashtabelle](https://simpleclub.com/lessons/fachinformatikerin-hashtabelle) (abgerufen am 21.06.2024).


---

[Zurück](./../Exercises.md)

---
