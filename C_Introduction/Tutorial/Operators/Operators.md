# Operatoren und Ausdrücke

[Zurück](../../Markdown/Agenda.md)

---

## Vorrang (Priorität) und Stelligkeit (Assoziativität) von Operatoren

In der folgenden Tabelle sind die Rangfolge und Assoziativität von C&ndash;Operatoren aufgeführt.
Die Operatoren werden von oben nach unten in absteigender Reihenfolge aufgelistet.

<img src="OperatorsPrecedence.png" width="600">

*Tabelle* 1: Vorrang der C&ndash;Operatoren.

<sup>Entnommen aus [C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)</sup>

Zu den Begriffen:

  * *Stelligkeit*:<br />
    Der Begriff *Stelligkeit* steht für die Anzahl der Argumente eines Operators.
    Einstellige Operatoren benötigen nur einen Operanden.
    Beispiel ist etwa der Minus-Operator (`-`), um von einer Zahl (einer Variablen) den negativen Wert zu bestimmen.
    Zweistellige Operatoren benötigen zwei Operanden.
    Beispiele sind etwa die arithmetischen Operationen
    Addition, Subtraktion, Multiplikation, oder Division, oder die logischen Operationen
    &ldquo;Logisches Und&rdquo; (`&&`)  und
    &ldquo;Logisches Oder&rdquo; (`||`).

  * *Priorität* :<br />
    Zunächst einmal ganz einfach formuliert:
    Unter der *Priorität* von Operatoren versteht man die *Punkt- vor Strich*&ndash;Regel.
    Etwas allgemeiner und formaler ausgedrückt:
    Für jeden Operator wird eine *Priorität* festgelegt, indem jedem Operator ein *Rang* zugeordnet wird.
    Dieser Rang entscheidet das Gruppieren und die Auswertung von Operanden in arithmetischen Ausdrücken.
    Ausdrücke mit höherrangigen Operatoren werden zuerst ausgewertet.
    Diese (im englischen als *Operator-Precedence* bezeichnete) Rangordnung
    stellt die Assoziativität verschiedenartiger Operatoren aufgrund deren Priorität sicher.

---

## Assoziativität

Mit der *Priorität* von Operatoren beschreibt man die Reihenfolge in der Auswertung
von arithmetischen Ausdrücken mit unterschiedlichen Operatoren.
Was aber, wenn es sich um denselben Operator handelt
(oder um verschiedene Operatoren, aber mit gleichem Vorrang),
zum Beispiel

```cpp
int x = 1 - 2 - 3;
```

Besitzt `n` den Wert -4 oder 2? Okay, Sie werden vermutlich für den Wert -4 plädieren
auf Grund der Vorgehensweise: Ich lese den Ausdruck von &ldquo;links nach rechts&rdquo;.

Okay, wie sieht es mit diesem Code-Fragment aus?

```cpp
int a = 1;
int b = 2;
int c = 3;

int d;

d = c = b = a;
```

Dies ist schon eher eine subtile Form der Wertzuweisung:
Wir sprechen von einer so genannten *Mehrfachzuweisung*:
Sie wird von &ldquo;rechts nach links&rdquo; abgearbeitet,
also im vorliegenden Beispiel wird als erstes `b` der Wert von `a` zugewiesen
(also `1`), dieser Wert wird danach der Variablen `c` zugewiesen und schließlich der Variablen `d`.

Hieraus hat sich der Begriff der *Assoziativität* von Operatoren entwickelt:

  * *Assoziativität* :<br />
    Die Assoziativität gibt an, ob eine Folge von Operatoren gleichen Vorrangs von links oder von rechts abgearbeitet wird.

---

## Quellcode des Beispiels:

[*Operators.c*](Operators.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
