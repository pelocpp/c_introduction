# Hashtabellen

[Zurück](./../Exercises.md)

---

// https://simpleclub.com/lessons/fachinformatikerin-hashtabelle

## Übersicht

Eine *Hashtabelle* ist eine dynamische Datenstruktur,
die verwendet wird, um *Schlüssel* (engl. *keys*)
und ihre dazugehörigen *Werte* (engl. *values*)
zu speichern und zu verwalten.

Hashtabellen lassen sich mit einem Nachschlagewerk vergleichen.
In einem Wörterbuch Deutsch &DoubleLeftRightArrow; Englisch kann das
Wort &bdquo;Übersetzer&rdquo; ein Schlüssel sein,
ihm ist der Wert &bdquo;Compiler&rdquo; zugeordnet.


---

## Aufbau

Eine Hashtabelle ist folgendermaßen aufgebaut:

Mit Hilfe von Schlüsseln (*keys*)
werden Werte (*values*) in einer Tabelle gespeichert.

Mit Hilfe des Schlüssels berechnet man einen Index &ndash; auch als *Hashwert* bezeichnet &ndash;,
der eine bestimmte Position in dieser Tabelle identifiziert:

<img src="c_hash_01.svg" width="250">

*Abbildung* 1. xxx 

Die Hashwerte* (Indizes) werden mit Hilfe einer Hash-Funktion bestimmt.

Die Größe der Tabelle orientiert sich an der Anzahl der Elemente,
die man in dieser Tabelle einsortieren möchte.

Bei 8 Elementen reicht folglich eine Tabellengröße bis zu maximal 8 Einträgen.
Zur Größe der Hashtabelle wird häufig eine Primzahl verwendet.

Berechnet sich für alle Schlüssel, die man mit ihren Werten in der Tabelle eintragen möchte,
ein unterschiedlicher Hashwert, kann man einfach ein Array als Datenstruktur für die Tabelle verwenden.

Wird mehreren Schlüsseln der gleiche Index in der Tabelle zugewiesen, lassen sich die Werte
nicht unmittelbar an dieselbe Stelle im Array schreiben.
Man spricht hier auch von einer so genannten *Kollision*.
Eine mögliche Kollisionsstrategie besteht darin, alle Daten, die sich denselben Hashwert teilen,
mit einer Liste zu verketten.

---

## Hash-Funktion

Generell gilt für Hash-Funktionen: Je effizienter die Hash-Funktion, desto besser kann in der Tabelle gesucht werden.

Eine Funktion, die beispielsweise allen Werten die gleiche Stelle zuweist, ist sehr ineffizient, da dann alle Werte in der gleichen Liste gespeichert werden und die Hashtabelle nicht mehr effizienter als eine Liste ist, die vom Anfang (bzw. Ende) bis zum gesuchten Wert durchgegangen werden muss.

Eine typische Hash-Funktion verwendet den Modulo:

*hash*(*k*) = *k* mod *p*

*hash*(*k*) ist die Hash-Funktion, 
*k* (*key*) ist der Wert, der einsortiert werden soll und *p* entspricht einer Primzahl.

Um nun den Schlüssel eines Wertes herauszufinden, wird der Wert (*value*) in die Hash-Funktion eingesetzt.
In den Tabelleneintrag des Schlüssels kann dann der Wert eingetragen werden.

---

## Ein Beispiel

Es sollen N Elemente mit beliebigen ganzzzahligen, positiven Schlüsseln (vom Typ *int*) 
in einer Hash-Tabelle gespeichert werden.
Die Schlüssel seien beliebig verteilt über den Bereich 0 .. K.
Zur Speicherung der Elemente soll eine Tabelle mit M > N Werten verwendet werden.

Aus dem Schlüssel wird eine Position in der Tabelle berechnet.
Die Position eines Elements mit dem Schlüssel *k* in der Tabelle berechnen wird mit der folgenden Hash-Funktion:

*p* = *k* mod M

Damit können auch Schlüssel, die größer als M sind, in der Tabelle untergebracht werden.

Durch die Modulo-Funktion wird &ndash; anschaulich gesprochen &ndash; ein Teil des Schlüssels
&bdquo;abgehackt&rdquo; (engl. *to hash*).

Wir legen nun M = 7 Plätze und N = 3 Elemente fest, deren Positionen (Hash-Wert) in der Tabelle durch die
vorstehende Hash-Funktion berechnet werden.

Wir wollen die Werte 9, 40, und 77 in der Tabelle eintragen.
An Hand der Hash-Funktion resultieren die Positionen

9 &#x2794; <br />
40 &#x2794; 5<br />
77 &#x2794; 0

<img src="c_hash_02.svg" width="500">

*Abbildung* 2. xxx 


Werte haben also immer eine feste Position in der Hash-Tabelle, die von ihrem Schlüssel abhängt.


---

## Kollisionen

Leider stimmt die Annahme nicht, dass alle Schlüssel zu verschiedenen Positionen
in der Tabelle führen. Es kann ein so genannter &bdquo;Konflikt&rdquo; auftreten.

Wir ändern unser Beispiel nun wie folgt ab:

13 &#x2794; 6<br />
19 &#x2794; 5<br />
34 &#x2794; 6 = Konflikt<br />
43 &#x2794; 1<br />
92 &#x2794; 1 = Konflikt<br />


<img src="c_hash_03.svg" width="650">

*Abbildung* 3. xxx 



Die zuletzt dargestellten Situationen werden als *Konflikt* oder *Kollision*
bezeichnet. Es gibt verschiedenen Strategien, um Kollisionen aufzulösen.

---

## Direkte Verkettung bei Kollisionsauflösung mit Verkettung

Hashtabellen mit Verkettung (engl. *separate chaining*) sind so strukturiert,
dass jeder Eintrag eine dynamische Datenstruktur aufnehmen kann &ndash; beispielsweise eine Liste.

Ein Schlüssel wird dann in dieser Datenstruktur eingetragen oder gesucht.
So ist es problemlos möglich, mehrere Schlüssel mit demselben Hashwert abzulegen,
was allerdings zu mehr oder weniger verlängerten Zugriffszeiten führt.

BILD

---





```
```

---

## Quellcode der Lösung

[*HashTable.h*](./HashTable.h)
[*HashTable.c*](./HashTable.c)
[*HashTableMain.c*](./HashTableMain.c)

---

[Zurück](./../Exercises.md)

---
