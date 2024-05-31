# Einführung in die Arbeitsweise der Werkzeuge

[Zurück](../../Markdown/Agenda.md)

---

## Erläuterungen

C ist eine Programmiersprache, die den vom Entwickler geschriebenen Quelltext des Programms (*Editor*)
zunächst mittels eines *Übersetzers* (*Compiler*)
in ein ausführbares Programm (*Maschinencode*) umgewandelt.

Erst dann kann das Programm ausgeführt werden.

In der *Visual Studio* Entwicklungsumgebung sind alle notwendigen Werkzeuge (Editor, Übersetzer, Debugger)
vorhanden bwz. integriert.

## &bdquo;Hello World&rdquo;

Der Quelltext für ein &bdquo;Hello World&rdquo; Programm sieht so aus:

#### Datei [*HelloWorld.c*](HelloWorld.c):

```cpp
#include <stdio.h>

int main()
{
    printf("HelloWorld\n");

    return 0;
}
```

Erstellen Sie mit der *Visual Studio* Entwicklungsumgebung ein C++&ndash;Projekt
und bringen Sie das Programm zum Laufen. Sie sollten dann folgende Ausgabe erhalten:

<img src="HelloWorld.png" width="600">

*Bemerkung*:<br />
Ja, Sie haben richtig gelesen: Ein **C++**&ndash;Projekt.
Die Dateiendungen &ndash; also in unserem Fall &bdquo;*.c*&rdquo;  &ndash; entscheiden darüber,
welcher Compiler gestartet wird!

---

## Quellcode des Beispiels:

[*HelloWorld.c*](HelloWorld.c)

---

[Zurück](../../Markdown/Agenda.md)

---

