# Zeichen und Zeichenketten

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:

```c
001: static void strings_01()
002: {
003:     int size = sizeof(char);
004: 
005:     char ch = '?';
006: 
007:     char lf = '\n';
008: 
009:     char cr = '\r';
010: }
011: 
012: static void strings_02()
013: {
014:     // ASCII Tabelle
015: 
016:     // Symbiose:   char <=> int
017: 
018:     for (int i = 0; i <= 127; ++i) {
019: 
020:         int ascciCode = i;
021: 
022:         char ch = i;
023: 
024:         printf("Ascii-Code: %03d - Zeichen: %c\n", ascciCode, ch);
025: 
026:         // oder
027: 
028:         printf("Ascii-Code: %03d - Zeichen: %c\n", i, i);
029:     }
030: }
031: 
032: // ===========================================================================
033: 
034: static void strings_03()
035: {
036:     // Das "Null" Zeichen
037: 
038:     char ch1 = '0';     // falsch
039: 
040:     char ch2 = 0;       // perfekt
041: 
042:     char ch3 = '\0';    // auch perfekt
043: }
044:     
045: // ===========================================================================
046: 
047: static void strings_04()
048: {
049:     // Konstante Zeichenkette
050: 
051:     "ABCDE";   // hier: empty statement
052: 
053:     printf("1.: %s\n\n", "ABCDE");
054: 
055:     // Zeichenkette in einem Feld bestehend auf char-Elementen
056: 
057:     char zeichen[20];
058: 
059:     zeichen[0] = 'A';
060:     zeichen[1] = 'B';
061:     zeichen[2] = 'C';
062:     zeichen[3] = 'D';
063:     zeichen[4] = 'E';
064:     zeichen[5] = 0;
065: 
066:     printf("2.: %s\n\n", zeichen);
067: 
068:     // Zeichenkette in einem Feld bestehend auf char-Elementen
069:     // mit Initialisierung
070: 
071:     char mehrZeichen[] = { 'A', 'B', 'C', 'D', 'E', '\0' };;
072:     printf("3.: %s\n\n", mehrZeichen);
073:     
074:     // Zeichenkette in einem Feld bestehend auf char-Elementen
075:     // mit Initialisierung - ohne Terminierendes Null-Zeichen - Vorsicht !!!
076: 
077:     char nochMehrZeichen[] = { 'A', 'B', 'C', 'D', 'E' };
078:     printf("4.: %s\n\n", nochMehrZeichen);
079: 
080: 
081:     // Datentyp für eine konstante Zeichenkette: char*
082:     // (für die Sprache C repräsentiert die Adresse die Anfangsadresse der Zeichenkette)
083: 
084:     char* s = "123456789012";  // 12 Zeichen
085: 
086:     printf("5.: %s\n", s);
087: 
088:     printf("    sizeof(s):      %zu\n", sizeof(s)    );
089:     printf("    sizeof(*s):     %zu\n", sizeof(*s)   );
090:     printf("    sizeof(char):   %zu\n", sizeof(char) );
091:     printf("    sizeof(int):    %zu\n", sizeof(int)  );
092:     printf("    sizeof(int*):   %zu\n", sizeof(int*) );
093: }
094: 
095: // ===========================================================================
096: 
097: static int str_length(char* cp)   // Liefert Anzahl der Zeichen - ohne '\0' zurück
098: {
099:     int length = 0;
100: 
101:     while (*cp != '\0') {
102: 
103:         length++;
104:         cp++;
105:     }
106: 
107:     return length;
108: }
109: 
110: static void strings_05()
111: {
112:     char* kette1 = "123";
113: 
114:     // oder
115: 
116:     char kette2[20] = "123";  // Ja, da ist hinten noch Freiraum
117: 
118:     int length1 = str_length(kette1);
119: 
120:     int length2 = str_length(kette2);
121: }
122: 
123: static int str_insert(char* source, char* destination, int destinationLength, char charToInsert, int pos)
124: {
125:     // a) teste, ob bereitgestellter Puffer (Array 'destination') groß genug ist
126:     int lenSource = str_length(source);
127: 
128:     if (destinationLength < lenSource + 1 /* einzufügendes Zeichen */ + 1 /* '\0' */) {
129: 
130:         return 0;
131:     }
132: 
133:     // b) bis zur Position pos (einschließlich) alle Zeichen aus 'source' nach 'destination' umkopieren
134:     for (int i = 0; i <= pos; ++i) {
135:         destination[i] = source[i];
136:     }
137: 
138:     // c) Zeichen 'charToInsert' in 'destination' einfuegen
139:     destination[pos + 1] = charToInsert;
140: 
141:     // c) restliche Zeichen von  'source' nach 'destination' umkopieren
142:     for (int i = pos + 1; i < lenSource; ++i) {
143:         destination[i + 1] = source[i];
144:     }
145: 
146:     // d) Puffer 'destination' mit einer '\0' abschließen 
147:     destination[lenSource + 1] = '\0';
148: 
149:     return 1;
150: }
151: 
152: 
153: static void strings_06()
154: {
155:     char* kette1 = "12345";     // Konstante, kein Array, hinten gehört uns der Platz NICHT !!!
156: 
157:     // oder
158: 
159:     char kette2[20] = "12345";  // Ja, da ist hinten noch Freiraum
160: 
161:     char result[20];
162: 
163:     int succeeded = str_insert(kette1, result, 20, '?', 2);
164: }
```


---

## Quellcode des Beispiels:

[*Strings.c*](Strings.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
