# Binäre Darstellung ganzer Zahlen

[Zurück](./../Exercises.md)

---

## Übersicht

Das Binärsystem, auch Dualsystem oder Zweiersystem genannt, ist ein Zahlensystem, das nur
zwei verschiedene Ziffern &ndash; in der Regel 0 und 1 &ndash; zur Darstellung von Zahlen benutzt.
Die Ziffernfolge 1101 zum Beispiel, stellt nicht (wie im Dezimalsystem) die
Tausendeinhundertundeins dar, sondern die Dreizehn, denn im Binärsystem berechnet sich der
Wert durch

<pre>
1101<sub>2</sub> = 1 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup> = 8 + 4 + 1 = 13<sub>10</sub>
</pre>

Erstellen Sie eine Funktion `binaryConvert`, die den Wert einer ganzen Zahl in ihre binäre
Darstellung konvertieren kann. Verwenden Sie folgende Schnittstelle für die Funktion:

```c
// compute prime numbers
int binaryConvert (int number, char binary[], int len);
```

Der Parameter `number` steht für die zu konvertierende Zahl.
Das Resultat ist in einer Nullterminierten Zeichenkette abzulegen.
Das `char`-Array für diese Zeichenkette wird im zweiten
Parameter `binary` übergeben.
Die Länge dieses Felds wird durch den dritten Parameter `len` spezifiziert.

Die Funktion `binaryConvert` liefert auch ein Resultat zurück, nämlich die Anzahl der binären
Ziffern 0 und 1, die zur Darstellung der Zahl im Binärsystem notwendig sind. 

---

## Quellcode der Lösung

[*BinaryConversion.c*](./BinaryConversion.c)

---

[Zurück](./../Exercises.md)

---
