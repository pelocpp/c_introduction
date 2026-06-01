# Eine Studentendatenbank

[Zurück](./../Exercises.md)

---

## Übersicht

Schreiben Sie ein Programm, das die Verwaltung einer Studentendatenbank simuliert.

Es darf ein Array von Strukturen zum Einsatz kommen.

Weitere Themenschwerpunkte sind:

  * Funktionszeiger, `void*` Parameter
  * Funktion `qsort`
  * Datei-Operationen (`fopen`, `fgets`, `fclose`)
  * String-Operationen (`strtok`, `strtoull`, `strtoul`, `strlen`, `strcpy_s`)
  * Speicherverwaltungsfunktionen `malloc` und `free`

---

## Beschreibung

Nehmen wir an, wir möchten eine Datenbank für Studenten erstellen.
Der Einfachheit wird jedem Student eine eindeutige ID, einen Namen sowie ein Abschlussjahr zugeordnet.

```cpp
struct student
{
    const char* m_name;
    uint32_t    m_id;
    uint16_t    m_passingYear;
};
```

Wir deklarieren eine Datenbank &ndash; ein einfaches Array genügt für unsere Zwecke &ndash; für die Studenten.

```cpp
#define MAX_DATABASE_SIZE 30

Student g_studentsDatabase[MAX_DATABASE_SIZE];
size_t  g_index = 0;
```

Wir füllen dieses Array mit dem Inhalt einer Textdatei:

```
121, Hans , 1987
122, Anton , 1988
123, Michael, 1985
124, Thomas, 1986
125, Andreas, 1981
126, Klaus, 1982
127, Fritz, 1989
128, Gerhard, 1986
```

Nun verfügen wir über eine Sammlung von Studenten.
Diese einzeln nach spezifischen Informationen zu durchsuchen, ist möglicherweise nicht effizient.
Beispielsweise könnten wir uns eine Liste von Studenten wünschen, die nach ihrem Abschlussjahr sortiert ist.
Oder wir benötigen eine Liste der Studentennamen, sortiert nach dem Namen selbst, um ein einfaches Nachschlagen zu ermöglichen.

In diesem Beispiel werden wir das Studenten-Array mithilfe der Funktion `qsort` sortieren, die in der Bibliothek `stdlib.h` verfügbar ist.
Doch ein bloßer Aufruf von `qsort` mit dem Array als Argument genügt nicht,
da `qsort` keinerlei Kenntnis darüber besitzt, wie zwei Studenten zu vergleichen sind.

Stattdessen erwartet `qsort` einen Funktionszeiger als Parameter.
Dieser dient dazu, zwei Studenten-Objekte miteinander zu vergleichen.

Diese Art von Vergleichsfunktion besitzt für `qsort` den folgenden Prototyp:

```cpp
int (*compare) (const void *, const void *);
```

Die Funktion empfängt zwei Zeiger auf Objekte, die miteinander verglichen werden sollen.

Die Anforderungen an die Vergleichsfunktion lauten wie folgt:

  * Sind die Objekte gleich, gibt die Funktion 0 zurück.
  * Soll das erste Objekt im sortierten Array vor dem zweiten Objekt platziert werden, gibt die Funktion eine negative ganze Zahl zurück.
  * Soll das erste Objekt im sortierten Array nach dem zweiten Objekt platziert werden, gibt die Funktion eine positive ganze Zahl zurück.

In diesem Beispiel werden wir zwei Vergleichsfunktionen `sortByPassingYear` und `sortByName` definieren,
die an `qsort` übergeben werden, damit das Studenten-Array unseren Wünschen entsprechend sortiert werden kann.

#### Sortieren nach Abschlussjahr

Das Sortieren nach dem Abschlussjahr ist einfach. Die Objekte, auf die die `void`-Zeiger verweisen,
werden in `struct student`-Objekte umgewandelt.
Wenn anschließend das zweite Abschlussjahr vom ersten Abschlussjahr subtrahiert wird, ist die Anforderung an die Vergleichsfunktion erfüllt.

```cpp
int sortByPassingYear (const void* a, const void* b);
```

#### Sortieren nach Namen

Der Name des Schülers mit der geringeren Zeichenanzahl wird als vorrangig betrachtet.
Falls die Namen gleich lang sind, ist ein zeichenweiser Vergleich durchzuführen, um zu bestimmen, welcher Name an erster Stelle steht:

```cpp
int sortByName (const void* a, const void* b);
```

#### Funktionen `qsort`

Nachdem die Vergleichsfunktionen definiert sind, kann das Array von Studentenobjekten nach dem Namen sortiert werden:

```cpp
qsort (g_students, MAX_STD_SIZE, sizeof(struct student), sortByName);
```

oder nach dem Abschlussjahr:

```cpp
qsort(g_students, MAX_STD_SIZE, sizeof(struct student), sortByPassingYear);
```

*Hinweis*:<br />
Der zweite Parameter beschreibt die Länge des zu sortierenden Arrays. Je nachdem wir Sie Ihre Realisierung gestalten,
kann das eine Zählervariable `g_index` oder eine fest vorgegebene Längenangabe `MAX_STD_SIZE` sein.

---

## Quellcode der Lösung

[*StudentsDatabase.h*](./StudentsDatabase.h)<br />
[*StudentsDatabase.c*](./StudentsDatabase.c)<br />
[*Main_StudentsDatabase.c*](./Main_StudentsDatabase.c)

---

[Zurück](./../Exercises.md)

---
