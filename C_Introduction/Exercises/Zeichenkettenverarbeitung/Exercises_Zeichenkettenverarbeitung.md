# Elementare Zeichenketteroperationen: `length`, `replace`, `append`, `insert` und `remove` 

[Zurück](./../Exercises.md)

---

## Übersicht

Realisieren Sie ein oder mehrere Funktionen, die auf Zeichenketten operieren:

  * `toUpper` &ndash; Wandelt alle Kleinbuchstaben in einer Zeichenkette in Großbuchstaben um.
  * `toLower` &ndash; Wandelt alle Großbuchstaben in einer Zeichenkette in Kleinbuchstaben um.
  * `reverse` &ndash; Dreht die Reihenfolge der Zeichen in einer Zeichenkette um.

  * `length` &ndash; Berechnet die Länge einer Zeichenkette.
  * `replace` &ndash; Ersetzen eines Zeichens oder einer Zeichenkette.
  * `append` &ndash; Anhängen eines Zeichens oder einer Zeichenkette.
  * `insert` &ndash; Einfügen eines Zeichens oder einer Zeichenkette in eine andere Zeichenkette.
  * `remove` &ndash; Entfernen eines Zeichens oder einer Zeichenkette aus einer anderen Zeichenkette.

*Bemerkung*:
Die Parameter der Funktionen können bzgl. der Zeichenketten entweder den Datentyp
`char[]` oder `char*` haben. In beiden Fällen wird die Adresse des ersten Zeichens einer Zeichenkette übergeben.


##### Modifikation einer vorgegebenen Zeichenkette:

Die Funktionen dieser Aufgabengruppe sollten folgende Schnittstelle haben:


```c
static int  str_length  (const char* src);
static void str_toUpper (char* src);
static void str_toLower (char* src);
static void str_reverse (char* src); 
```

*Hinweis*:<br />
Die Funktionen in dieser Gruppe sind so konzipiert, dass das Ergebnis der Funktion
in derselben Zeichenkette abgelegt werden kann, die als Argument an die Funktion übergeben wird.

Aus diesem Grund ist der Parameter vom Typ `char*` und damit nicht vom Typ `const char*`.


##### Modifikation der Zeichenkette durch ein einzelnes Zeichen


```c
void chr_replace (char* src, int pos, char ch);
int  chr_append  (const char* src, char ch, char* dest, int destLen);
int  chr_insert  (const char* src, int pos, char ch, char* dest, int destLen);
int  chr_remove  (const char* src, int pos, char* dest, int destLen);
```

*Hinweis*:<br />
Bei der ersten Funktion `chr_replace` können Sie im ersten Parameter `src` erkennen,
dass das Schlüsselwort `const` fehlt: Das Resultat der Funktionsausführung soll
im ersten Parameter abgelegt werden. Es muss also ein Feld von Zeichen übergeben werden,
das einen schreibenden Zugriff gestattet.

In allen anderen Funktionen soll auf die Zeichen
des ersten Parameters `src` nur lesend zugegriffen werden dürfen.
Das Resultat der Funktionsausführung ist jeweils in einem Parameter `dest` abzulegen,
dessen Pufferlänge im Parameter `destLen` zur Verfügung gestellt wird.


##### Modifikation der Zeichenkette durch eine zweite Zeichenkette

*Hinweis*:<br />
Wie in der letzten Gruppe benötigen alle Funktionen dieses Abschnitts eine zusätzliche Zeichenkette,
die das Ergebnis der Berechnung aufnimmt. Diese Zeichenkette hat den Namen `dest`, die Länge des Felds
wird durch `destLen` festgelegt.


```c
int  str_replace (const char* src, int pos, const char* toReplace, char* dest, int destLen);
int  str_append  (const char* src, const char* toAppend, char* dest, int destLen);
int  str_insert  (const char* src, int pos, const char* toInsert, char* dest, int destLen);
int  str_remove  (const char* src, int pos, int count, char* dest, int destLen);
```

Es folgen einige grafische Hinweise für das Realisieren dieser Funktionen:

<img src="c_string_append.svg" width="500">

*Abbildung* 1: Strategie beim Anhängen von Zeichenketten.



<img src="c_string_insert.svg" width="500">

*Abbildung* 2: Strategie beim Einfügen von Zeichenketten.

---

## Quellcode der Lösung

[*Zeichenkettenverarbeitung.c*](./Zeichenkettenverarbeitung.c)

---

[Zurück](./../Exercises.md)

---
