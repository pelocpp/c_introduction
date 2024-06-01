# Strukturen

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:


```c
001: //static void initTime(struct Time time, int hours, int minutes, int seconds)
002: //{
003: //    time.hours = hours;
004: //    time.minutes = minutes;
005: //    time.seconds = seconds;
006: //}
007: 
008: static void initTime(struct Time* time, int hours, int minutes, int seconds)
009: {
010:     // a) Passt -- etwas schwer lesbar
011:     (*time).hours = hours;
012:     (*time).minutes = minutes;
013:     (*time).seconds = seconds;
014: 
015:     // b) Eine alternative Syntax -- besser lesbar -- Symbol: "Pfeil"
016:     time->hours = hours;
017:     time->minutes = minutes;
018:     time->seconds = seconds;
019: 
020: }
021: 
022: static void printTime(struct Time* time)
023: {
024:     printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
025: }
026: 
027: //static void printTime(struct Time time)
028: //{
029: //    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
030: //}
031: 
032: // ===========================================================================
033: 
034: static void structs_01()
035: {
036:     struct Time now;
037: 
038:     now.hours = 11;
039:     now.minutes = 9;
040:     now.seconds = 33;
041: 
042:     struct Time than;
043: 
044:     than.hours = 17;
045:     than.minutes = 0;
046:     than.seconds = 0;
047: 
048:     printTime(&now);
049:     printTime(&than);
050: }
051: 
052: static void structs_02()
053: {
054:     struct Time now = { 9, 0, 0 };
055:     printTime(&now);
056: 
057:     struct Time than = { .hours = 12, .minutes = 15, .seconds = 0 };
058:     printTime(&than);
059: 
060:     struct Time later = { .seconds = 0, .minutes = 0, .hours = 17 };
061:     printTime(&later);
062: }
063: 
064: static void structs_03()
065: {
066:     struct Time now = { 0 };
067: 
068:     printTime(&now);
069: }
070: 
071: static void printZahlen(int* feld, int len)
072: {
073:     // ...
074: }
075: 
076: //static void printZahlen(int feld[], int len)
077: //{
078: //    // ...
079: //}
080: //
081: //static void printZahlen(int feld[100], int len)
082: //{
083: //    // ...
084: //}
085: 
086: static void structs_04()
087: {
088:     int zahlen[100];
089: 
090:     printZahlen(zahlen, 100);
091: }
092: 
093: struct Zahlen
094: {
095:     int daten[100];
096: };
097: 
098: static void tueWas(struct Zahlen zahlen)
099: {
100:     zahlen.daten[0] = 100;
101: }
102: 
103: static void structs_05()
104: {
105:     struct Zahlen zahlen = { 1 };
106: 
107:     tueWas(zahlen);
108: }
109: 
110: static void structs_06()
111: {
112:     // Bei Strukturen sieht der Compiler / hat die Runtime
113:     // auch die Information der Länge der Struktur
114: 
115:     struct Time t1 = { 0, 0, 0 };
116:     struct Time t2 = { 0, 0, 0 };
117:     t1 = t2;            // Wertzuweisung
118: 
119:     struct Zahlen zahlen1;
120:     struct Zahlen zahlen2 = { 0 };
121:     zahlen1 = zahlen2;  // Wertzuweisung
122: }
123: 
124: static void structs_07()
125: {
126:     // Aufruf von initTime :
127: 
128:     // 2 Möglichkeiten des AUFRUFS :
129: 
130:     // A) 
131:     // Eine Struktur-Variable, die auf dem STACK liegt
132:     struct Time time;
133: 
134:     initTime(&time, 1, 2, 3);
135: 
136:     // B)
137:     // Eine Struktur-Variable, die auf dem HEAP liegt
138:     struct Time* pt = (struct Time*) malloc(sizeof(struct Time));
139: 
140:     initTime(pt, 1, 2, 3);
141: 
142:     free(pt);
143: }
```


---

## Quellcode des Beispiels:

[*Structs.c*](Structs.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
