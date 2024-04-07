# Aufgabe zum &ldquo;Abtippen&rdquo;: Summe von zwei Zahlen

[Zurück](./../Exercises.md)

---

## Übersicht

Erstelle folgendes Programm:

```cpp
#include <stdio.h>

int main()
{
    int zahl1;
    int zahl2;
    int ergebnis;

    printf("Bitte erste Zahl eingeben:");
    scanf_s("%d", &zahl1);

    printf("Bitte zweite Zahl eingeben:");
    scanf_s("%d", &zahl2);

    ergebnis = zahl1 + zahl2;

    printf("Ergebnis: %d + %d = %d\n", zahl1, zahl2, ergebnis);

    getchar(); /* Damit bleibt das Ausgabefenster offen, bis man eine Taste drueckt. */
}
```

*Erläuterungen*:

Teste das Programm nun mit verschiedenen Eingaben, z. B. `20000` und `30000`, `-20000` und
`-30000`, `1000000000` (1 Milliarde) und `2000000000` (2 Milliarden)
Was fällt auf?

*Anmerkungen*:
  * Damit man sich während der Programmlaufzeit Daten speichern kann, werden Variable
    verwendet (z. B. `zahl1`, `zahl2`, `ergebnis`). Diese müssen ganz am Anfang definiert werden.
  * Variable haben einen nach gewissen Regeln frei wählbaren Namen, einen Datentypen,
   der bestimmt, was für Werte dort gespeichert werden können und einen Wert.
  * Die Variablen `zahl1`, `zahl2` und `ergebnis` sind vom Typ `int` und können somit ganzzahlige
    Werte speichern.
  * Mit der Anweisung `scanf_s_` kann man Werte vom Benutzer des Programms eingeben lassen.
  * Variablen kann man mit „=“ neue Werte zuweisen, z. B. `ergebnis = zahl1 + zahl2`.
    Mit `printf` kann man die Werte von Variablen auch wieder in der Konsole ausgeben, dazu braucht
    man die Formatanweisung `%d`.


---

## Quellcode der Lösung

[*ErsteSchritte.c*](./ErsteSchritte.c)<br />


---

[Zurück](./../Exercises.md)

---

