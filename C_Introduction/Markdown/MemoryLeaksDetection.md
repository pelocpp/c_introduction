# Memory Leaks Detection in C

[Zurück](./Agenda.md)

---

[Quellcode / Klasse `BigData`](MoveSemantics.cpp)

---

Ein einfacher Memory Leak Detektor ist in der *C Run-time Library* (*CRT*) integriert.

Details seiner Funktionsweise sind hier beschrieben:

https://learn.microsoft.com/en-us/cpp/c-runtime-library/find-memory-leaks-using-the-crt-library?view=msvc-170

Um ihn in einem C++-Programm zu aktivieren,
sind am Anfang der C++-Quelldatei folgende Zeilen hinzuzufügen:

```cpp
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
```

Die endgültige Aktivierung findet in der `main`-Funktion statt:

```cpp
int main() {

    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    // statements of c program 

    return 0;
}
```


Sind im Programm Memory Leaks vorhanden, werden diese &ndash; bei Ausführung des Programms mit dem Debugger &ndash; im *Output*-Fenster angezeigt.
So hinterlässt beispielsweise die Anweisung

```cpp
// create a new node
struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
if (item == (struct ListItem*)0) {
    return;
}
```

ohne korrespondierende `free`-Anweisung folgende Ausgaben im *Output*-Fenster nach der Programmausführung:

```cpp
Dumping objects ->
C:\Development\...\VerketteteListe.c(280) : {79} normal block at 0x00000280A89AD140, 16 bytes long.
 Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD 
Object dump complete.
```

---

[Zurück](./Agenda.md)

---
